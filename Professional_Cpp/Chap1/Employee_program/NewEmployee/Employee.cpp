#include "pch.h"
#include "Employee.h"
#if __has_include("Employee.g.cpp")
#include "Employee.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::NewEmployee::implementation
{
    Employee::Employee()
    {
        InitializeComponent();
    }

    int32_t Employee::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void Employee::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void Employee::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
