# Subjects Management System

This is a C++ program that can perform basic CRUD operations on a subject management system that can be used by any student to keep track of their academic performances.

## Overview

This program contains a class called ‘Subject’ from which objects for each subject is created; This class has public members that hold the necessary subject details, i.e. Subject ID, Subject Code, Marks in DA1, DA2, DA3, CAT1, CAT2, FAT and the Overall Percentage. This class also contains public member functions to perform the necessary CRUD operations. These member functions are:

* create() →This is used to create a new entry
* read() → This is used to display either the entire list of subjects or any particular subject of choice

* update() → This is used to update any specific previous entry given by the user
* del() → This is used to delete any specific previous entry given by the user

## Structure

* Upon executing the above code, it shows a menu driven display from which the user can select an operation of their choice. This then initiates the specific CRUD operation an takes the necessary inputs as needed.
* Upon completing the necessary task, it goes back to the menu driven display for any further operation to take place. This process continues till the user chooses to quit the program.

## Use

This script can be used by any university student to keep a track of their subjects and courses and to track it the same directly in their terminal

Additional features such as assignment tracking, cgpa calculation, ToDo lists can be added to the above project.
