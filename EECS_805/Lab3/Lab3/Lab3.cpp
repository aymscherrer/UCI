// Lab3
// Aymeric

//ASSIGNMENT 1

#include "stdafx.h"

#define MAX 10  /* Size of the array */

void init_array(int *array, int value);
void copy_array(int *array1, int *array2);

#if 0
int main() {
	int  array_1[MAX];				// array of a size of MAX
	int *array_ptr = array_1;		// pointer to the address &array_1[0]

	int init_value = 0x5A;
	int i;

	init_array(array_1, init_value);

	for (i = 0; i < MAX; i++, array_ptr++) {		// show what is inside the array
		printf("i = %d, value in array = %x \n", i, *array_ptr);
	}

	return 0;
}

#endif

//ASSIGNMENT 2

#if 0

int main()
{
	int  array_1[MAX];
	int  array_2[MAX];

	int *array_ptr1 = array_1;			// pointer to the address &array_1[0]
	int *array_ptr2 = array_2;			// pointer to the address &array_2[0]

	int init_value = 0x5A;
	int i;

	printf("Initializing the array1 to init_value \n");

	/* Initializing the array */
	init_array(array_1, init_value);

	printf("copy array_1 to array_2 \n");

	/* copy array_1 to array_2 */
	copy_array(array_1, array_2);

	for (i = 0; i < MAX; i++, array_ptr2++) {		// show what is inside the array
		printf("i = %d, value in array2 = %x \n", i, *array_ptr2);
	}

	return 0;
}

#endif

//ASSIGNMENT 3

#if 0

//Structure

struct employeeInformation {
	int age;
	int employee_number;
	int salary;
	int year_of_hire;
};

//Initialize Functions

void showEmployeeInformation(employeeInformation *eInformation, int size);

int main()
{
	int i= 0;
	int nbEmployee = 3;					// number of employee

	struct employeeInformation employeeInfo[3];
	
	struct employeeInformation *eInfo;
	eInfo = employeeInfo;				//pointer to employeeInfor[0];

	//1st employee
	employeeInfo[0].age = 35;
	employeeInfo[0].employee_number = 1234;
	employeeInfo[0].salary = 50000;
	employeeInfo[0].year_of_hire = 1980;

	//2nd employee
	employeeInfo[1].age = 46;
	employeeInfo[1].employee_number = 5678;
	employeeInfo[1].salary = 55000;
	employeeInfo[1].year_of_hire = 1983;

	//3rd employee
	employeeInfo[2].age = 30;
	employeeInfo[2].employee_number = 2345;
	employeeInfo[2].salary = 4000;
	employeeInfo[2].year_of_hire = 1990;

	// b

	for (i = 0; i < 3; i++) {
		printf("\n\n Employee information : %d \n", i + 1);
		printf("\n Employee number = %d", employeeInfo[i].employee_number);
		printf("\n Age = %d", employeeInfo[i].age);
		printf("\n Salary = %d", employeeInfo[i].salary);
		printf("\n Year of hire = %d", employeeInfo[i].year_of_hire);
	}

	printf("\n\n -- Using function to show employees' information -- \n\n");

	showEmployeeInformation(eInfo, nbEmployee);

	return 0;
}

void showEmployeeInformation(employeeInformation *eInformation, int size) {
	int i;

	for (i = 0; i < size; i++, eInformation++) {
		printf("\n Employee number = %d", eInformation->employee_number);
		printf("\n Salary = %d", eInformation->salary);
	}
}

#endif

//ASSIGNMENT 4

#if 1
struct power_control {
	unsigned int GPS_mode : 1;
	unsigned int vibrate_mode : 1;
	unsigned int bluetooth_mode : 1;
	unsigned int wifi_mode : 1;
	unsigned int reserved : 28;
};

union access {
	unsigned whole_int;
	struct power_control control_access;
};

enum boolean {
	DISABLE,
	ENABLE,
};

void power(boolean power, access *accessControl);
void powerWifiBluetooth(boolean power, access *accessControl);

int main() {
	access access_control;
	access *ptrAccessControl;
	ptrAccessControl = &access_control;

	//test to disable all bits
	access_control.whole_int = 0x0000;

	printf("\n ===== all bit to 0 ==========\n");
	printf("\n GPS_mode : %x", access_control.control_access.GPS_mode);
	printf("\n vibrate_mode : %x", access_control.control_access.vibrate_mode);
	printf("\n bluetooth_mode : %x", access_control.control_access.bluetooth_mode);
	printf("\n wifi_mode : %x", access_control.control_access.wifi_mode);
	printf("\n ===============================\n");

	//test to enable GPS_mode
	access_control.control_access.GPS_mode = 1;

	printf("\n ===== GPS_mode to 1 ==========\n");
	printf("\n GPS_mode : %x", access_control.control_access.GPS_mode);
	printf("\n vibrate_mode : %x", access_control.control_access.vibrate_mode);
	printf("\n bluetooth_mode : %x", access_control.control_access.bluetooth_mode);
	printf("\n wifi_mode : %x", access_control.control_access.wifi_mode);
	printf("\n ===============================\n");
	
	//use the function power to ENABLE all the controls
	power(ENABLE, ptrAccessControl);

	printf("\n ===== controls ENABLE ==========\n");
	printf("\n GPS_mode : %x", access_control.control_access.GPS_mode);
	printf("\n vibrate_mode : %x", access_control.control_access.vibrate_mode);
	printf("\n bluetooth_mode : %x", access_control.control_access.bluetooth_mode);
	printf("\n wifi_mode : %x", access_control.control_access.wifi_mode);
	printf("\n ===============================\n");

	//use the function power to DISABLE all the controls
	power(DISABLE, ptrAccessControl);

	printf("\n ===== Controls DISABLE ==========\n");
	printf("\n GPS_mode : %x", access_control.control_access.GPS_mode);
	printf("\n vibrate_mode : %x", access_control.control_access.vibrate_mode);
	printf("\n bluetooth_mode : %x", access_control.control_access.bluetooth_mode);
	printf("\n wifi_mode : %x", access_control.control_access.wifi_mode);
	printf("\n ===============================\n");

	//use the function powerWifiBluetooth to ENABLE wifi_control and bluetooth control
	powerWifiBluetooth(ENABLE, ptrAccessControl);

	printf("\n ===== wifi and bluetooth ENABLE ==========\n");
	printf("\n GPS_mode : %x", access_control.control_access.GPS_mode);
	printf("\n vibrate_mode : %x", access_control.control_access.vibrate_mode);
	printf("\n bluetooth_mode : %x", access_control.control_access.bluetooth_mode);
	printf("\n wifi_mode : %x", access_control.control_access.wifi_mode);
	printf("\n ===============================\n");

	//use the function powerWifiBluetooth to DISABLE wifi_control and bluetooth control
	powerWifiBluetooth(DISABLE, ptrAccessControl);

	printf("\n ===== wifi and bluetooth DISABLE ==========\n");
	printf("\n GPS_mode : %x", access_control.control_access.GPS_mode);
	printf("\n vibrate_mode : %x", access_control.control_access.vibrate_mode);
	printf("\n bluetooth_mode : %x", access_control.control_access.bluetooth_mode);
	printf("\n wifi_mode : %x", access_control.control_access.wifi_mode);
	printf("\n ===============================\n");

	return 0;
}

//functions assignment 4

// Enable or disable all the controls 
void power(boolean power, access *accessControl) {
	if (power) {
		accessControl->whole_int = 0xFFFF;
	}
	else {
		accessControl->whole_int = 0x0000;
	}
}

// Enable or disable the wifi and the bluetooth
void powerWifiBluetooth(boolean power, access *accessControl) {
	if (power) {
		accessControl->control_access.wifi_mode = 1;
		accessControl->control_access.bluetooth_mode = 1;
	}
	else {
		accessControl->control_access.wifi_mode = 0;
		accessControl->control_access.bluetooth_mode = 0;
	}
}


#endif

// Functions

void init_array(int *array, int value) {
	int i;

	for (i = 0; i < MAX; i++, array++)
		*array = value;
}

void copy_array(int *array1, int *array2) {

	while (*array1) {
		*(array2++) = *(array1++);
	}
}
