#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>

#include <iostream>
#include <iomanip>
#include<thread>

using tcp = boost::asio::ip::tcp;

void Log(boost::system::error_code ec)
{
    //std::cerr << (ec ? "Error: " : "OK")
    std::cerr << "[" << std::setw(14) << std::this_thread::get_id() << "]"
        << (ec ? "Error: " : "OK")
        << (ec ? ec.message() : "")
        << std::endl;
}

void OnConnect(boost::system::error_code ec)
{
    Log(ec);
}

int main()
{
    std::cerr << "[" << std::setw(14) << std::this_thread::get_id() << "] main"
        << std::endl;

    // Always start with an I/O context object.
    boost::asio::io_context ioc{};


    // Create an I/O object. Every Boost.Asio I/O object API needs an io_context
    //as the first paramter
    tcp::socket socket{ ioc };

    // A 'falsey' error_code means "no error".
    // Under the hood, socket.connect uses I/O context to talk to the socket
    //and get a response back. The response id saved in ec.

    boost::system::error_code ec{};
    //auto address{
    //    boost::asio::ip::address::from_string("1.1.1.1")
    //};
    //tcp::endpoint endpoint{ address, 80 };
    //socket.connect(endpoint, ec);

    tcp::resolver resolver{ ioc };
    auto resolverIt{ resolver.resolve("google.com", "80", ec) };

    if (ec) {
        //std::cerr << "Error: " << ec.message() << std::endl;
        Log(ec);
        return -1;
    }
    //else {
    //    std::cout << "OK" << std::endl;
    //    return 0;
    //}

    //socket.connect(*resolverIt, ec);
    //if (ec) {
    //    Log(ec);
    //    return -2;
    //}
    //Log(ec);

    socket.async_connect(*resolverIt, OnConnect);

    //We must call io_context::run for asynchronous callbacks to run.
    //ioc.run();

    std::thread thread{ [&ioc]() {
        std::cerr << "["
            << std::setw(14) << std::this_thread::get_id()
            << "] ioc.run()"
            << std::endl;
        ioc.run();
} };
    thread.join();
    return 0;

}