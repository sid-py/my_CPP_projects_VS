

import <iostream>;
import employee;

using namespace std;
using namespace Records;

int main() {
	cout << "Testing the Employee Class." << endl;

	Employee emp{ "Megan", "Fox" };
	emp.setFirstName("Regen");
	emp.setLastName("Schulte");
	emp.setEmployeeNumber(7859);
	emp.setSalary(49'652);
	emp.promote();
	emp.promote(500);
	emp.hire();
	emp.display();
}