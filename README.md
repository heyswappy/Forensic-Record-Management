
# Forensic-Record-Storage
A C++ program to manage forensic records.
A user can be of type admin, doctor or investigator.
All the above users can manage the records of criminals and dead bodies.

### Password Class
Attempts at saving the passwords more securely by
1. Salting the passwords
2. Hashing the newly salted string
Whenever the passwords are needed to be checked only the final hash value matters. The real password is never stored anywhere in the disk or main memory.

### Admin User Class
1. Can create admin, doctor, investigator, criminal or body records.
2. Can view doctor, investigator, criminal and body data.
3. Can delete doctor, investigator, criminal and body data.

### Doctor User Class
1. Can create body records.
2. Can view body records.
3. Can edit body records.

### Investigator User Class
1. Can create criminal records.
2. Can view criminal records.
3. Can edit criminal records.

### Criminal Data Class
Save the details of criminals.

### Eternal Data Class
Save the details of killed entities.
