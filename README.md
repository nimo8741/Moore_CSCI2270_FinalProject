# Moore_CSCI2270_FinalProject
Project Summary:
This project will create a social messaging system where the user will log into a profile and from there either post messages to a public message board, send messages to specific profiles, delete their most recent post to the public message board, or delete a private incoming message.  When first running the program, the user will type in their user name.  This will create an account that they will use until they close the program or select to sign into another profile.  The messages created by the user will be stored within structs that contain information such as the creator and recipient of the message.  When the user selects to view all of the messages accessable to them, the messages will appear in reverse incoming order of private messages and then reverse incoming order for public messages.  This means that the most recent message sent to them privately will be displayed first and then after all private messages have been displayed the public messages will be displayed in the same fashion.

How to Run:
All code for this project is in the MessageSender folder assoiated with this repository.  The user must first make a clone of this repository and open the files named MessageSender.cpp, SenderFunctions.cpp and SenderFunctions.h. When the program is run, the user is prompted to input a username.  The user input anything that they wish as long as they do not use the * or % characters.  The usernames that are already incorpoorated into the program are Marcus, Nick, Phil, Scott, and admin.  Choosing any of these usernames will result in private messages being shown as their are pre-constructed conversations between these usernames.  Any other choice of username will work, but at the cost of no private messages being shown to them.  After logging in, the user may select the options in the main menu with the number keys cooresponding to the number beside that choice in the menu.  After selecting an appropriate command from the main menu, the user will be prompted with printed statements as to what to do to complete the selected function.

Dependencies:
No special dependencies.

System Requirements:  Computer that can run and compile a C++ program.  No special dependencies.

Group Members:
This project is created by Nicholas Moore and Scott Schubert

Contributors:

Open issues/bugs:
Enhancement request:  A password system that requires a user to enter a password when logging in.  
Bugs: We have not found any yet.
