#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct Employee {
    int id;
    char name[30];
    float salary;
};

int main() {

    int fd;

    struct Employee emp;

    // Create the file
    fd = open("employee.dat", O_CREAT | O_RDWR | O_TRUNC, 0644);

    if (fd < 0) {
        perror("File creation failed");
        return 1;
    }

    // Employee 1
    emp.id = 101;
    strcpy(emp.name, "Anshuman Gupta");
    emp.salary = 50000;
    write(fd, &emp, sizeof(emp));

    // Employee 2
    emp.id = 102;
    strcpy(emp.name, "Rahul Sharma");
    emp.salary = 55000;
    write(fd, &emp, sizeof(emp));

    // Employee 3
    emp.id = 103;
    strcpy(emp.name, "Shreya Gupta");
    emp.salary = 60000;
    write(fd, &emp, sizeof(emp));

    printf("Employee records written successfully.\n");

    // Update second employee
    emp.id = 102;
    strcpy(emp.name, "Rahul Sharma");
    emp.salary = 65000;

    lseek(fd, sizeof(struct Employee), SEEK_SET);

    write(fd, &emp, sizeof(emp));

    printf("Second employee record updated.\n\n");

    // Read all records
    lseek(fd, 0, SEEK_SET);

    printf("Employee Records:\n\n");

    while (read(fd, &emp, sizeof(emp)) > 0) {

        printf("ID     : %d\n", emp.id);
        printf("Name   : %s\n", emp.name);
        printf("Salary : %.2f\n\n", emp.salary);

    }

    close(fd);

    return 0;
}
