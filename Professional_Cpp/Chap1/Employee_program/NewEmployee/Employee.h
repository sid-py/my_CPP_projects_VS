#pragma once

#include "Employee.g.h"

namespace winrt::NewEmployee::implementation
{
    struct Employee : EmployeeT<Employee>
    {
        Employee();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::NewEmployee::factory_implementation
{
    struct Employee : EmployeeT<Employee, implementation::Employee>
    {
    };
}
