# Moore_CSCI2270_FinalProject
Project Summary:
This project will create a social messaging system where the user will log into a profile and from there either post messages to a public message board, send messages to specific profiles, delete their posts to the public message board, or delete a private incoming message.  When first running the program, the user will type in their user name.  This will create an account that they will use until they close the program or select to sign into another profile.  The messages created by the user will be stored within structs that contain information such as the creator and recipient of the message.  When the user selects to view all of the messages accessable to them, the messages will appear in oldest first order of private messages and then the same order for public messages.  This means that the most recent message sent to them privately will be displayed at the bottom and then after all private messages have been displayed the public messages will be displayed in the same fashion.

How to Run:
  All code for this project is in the MessageSender folder assoiated with this repository.  After downloading this repo, all the necessary files are in the Message Sender folder.  To run, navigate a terminal window to the directory containing the files named MessageSender.cpp, SenderFunctions.cpp and SenderFunctions.h. Then run the command "make". Then run the program by using the command "./MsgSend".  
  When the program is run it begins by reading in from a file named "Messages.txt".  It parses the data in the file and sets up the program accordingly.  If the file is blank it will still run, but a file by that name does need to be in the directory.  First the user is prompted to input a username.  The user inputs anything that they wish as long as they do not use the * or % characters.  The usernames that are already incorpoorated into the program are Nick, Scott, and admin.  Choosing any of these usernames will allow for their pre-constructed conversations to be visible.  While logging in, any username not in the system will automatically generate a new user.  They will not be able to see private conversations that were pre-constructed.  After logging in, the user may select the options in the main menu with the number keys coresponding to the number beside that choice in the menu.  After selecting an appropriate command from the main menu, the user will be prompted with printed statements as to what to do to complete the selected function.

Dependencies:
No special dependencies.

System Requirements:  Computer that can run and compile a C++ program.  No special dependencies.

Group Members:
This project is created by Nicholas Moore and Scott Schubert

Contributors:

Open issues/bugs:
Enhancement request:  A password system that requires a user to enter a password when logging in.  
Bugs: When deleting posts, it only deletes the content of the struct and doesn't remove it from the linked list oddly.  Therefore, when logged in as admin these post print out blank.  Current fix is that upon saving to text file at completion of program there's a check which doesn't write it to file.  Therefore fixes problem only between run times.
