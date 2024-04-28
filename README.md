# Computer room reservation system
## Background Introduction
There are several computer rooms with different specifications in the school, but due to frequent collisions during use, we are now developing a computer room reservation system to solve this problem
## Identity Introduction
Use this program in three different identities
- Student representative: Applying to use the computer room
- Teacher: Review student appointment applications
- Administrator: Create accounts for students and teachers
## Introduction to the computer room
There are a total of 3 rooms in the computer room
- Machine room 1- maximum capacity of 20 people
- Machine room 2- maximum capacity of 50 people
- Machine room 3- maximum capacity of 100 people
## Application Introduction
- The administrator is responsible for clearing the applied orders every week
- Students can make appointments for the use of the computer room in the next week, with dates from Monday to Friday. When making an appointment, they need to choose the appointment time slot (morning, afternoon)
- The teacher will review the appointment and determine whether it has been approved or not based on the actual situation
## Specific system requirements
- First, enter the login interface and choose the login identity or function:
  - Student representatives
  - Teacher
  - Administrator
  - Exit the login interface
- Each identity needs to be verified. Once verified, enter the submenu
  - Students need to input: student ID, name, login password
  - The teacher needs to input: employee ID, name, and login password
  - The administrator needs to input: administrator name, login password
- Specific functions of students
  - Apply for reservation - make an appointment for the computer room
  - View Your Appointment - Check Your Appointment Status
  - View all appointments - View all appointment information and appointment status
  - Cancel Appointment - Cancel one's own appointment, both successful and pending appointments can be cancelled
  - Log out login - Log out login
- Specific functions of teachers
  - View all appointments - View all appointment information and appointment status
  - Review appointments - Review student appointments
  - Log out login - Log out login
- Specific functions of administrators
  - Add Account - To add a student or teacher's account, it is necessary to check if the student ID or teacher employee ID is duplicate
  - View Account - You can choose to view all information about students or teachers
  - View data center - View information for all data centers
  - Clear Appointment - Clear all appointment records
  - Log out login - Log out login