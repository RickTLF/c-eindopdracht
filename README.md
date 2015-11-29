# c-eindopdracht
This repository contains a phone book project in c. It allows a user to view, add, delete, lookup or edit contacts.

The project makes use of two structs: Contact and PhoneBook. PhoneBook contains an array of Contacts and updates the array accordingly.

You do not need to create Contact structs. PhoneBook takes care of that automatically.

the Lookup function does not work properly. You are only able to look up a contact via their names.
This will be eidited soon.

Furthermore, the Project creates a text file or reads a specified text file and inserts contacts
in the PhoneBook struct. However, after you selected quit, the file will be overwriten.

Even if you decide not to quit and close the application, contents will be saved in file just 
in case. In other words: if you you've created a contact: Joe Blue and decided to close the
application without quiting properly, contact will be saved in file.

Error handling is still poor - will be improved soon.
