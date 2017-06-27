/********************************************************************
 * Description:  This C++ file contains the function definitions for
 *               all the llist class member functions, including the
 *               constructor and destructor.
 ********************************************************************/

#include "llist.h"

/*********************************************************************
 *
 * Function Name:        readfile
 *
 * Description:          reads from the default file
 *
 * Parameters:           none
 *
 * Return Values:        0: success
 *
 *********************************************************************/
int llist::readfile() {
  int     tyob = 0;
  char    tname[NAME_SIZE], taddress[ADDRESS_SIZE], telno[TELNO_SIZE];
  string  line;

    /* check to see if debug mode is defined, if it is print the necessary information */
  #ifdef DEBUGMODE
  cout << "Method Called: readfile" << endl;
  cout << "Passing Parameters: \nnone" << endl;
  #endif

  ifstream myfile(filename);
  while( !myfile.eof() ) {
    getline(myfile, line);
    strcpy(tname, line.c_str());

    getline(myfile, line);
    strcpy(taddress, line.c_str());

    getline(myfile, line);
    stringstream(line) >> tyob;

    getline(myfile, line);
    strcpy(telno, line.c_str());

    if( strcmp(tname, "") != 0 && tyob > 0) {
      addRecord(tname, taddress, tyob, telno);
    }
  }
  myfile.close();
  return 0;
}

/*********************************************************************
 *
 * Function Name:        writefile
 *
 * Description:          writes to the default file
 *
 * Parameters:           none
 *
 * Return Values:        0: success
 *
 *********************************************************************/
int llist::writefile() {
  record  *ptemp;

  /* check to see if debug mode is defined, if it is print the necessary information */
  #ifdef DEBUGMODE
  cout << "Method Called: writefile" << endl;
  cout << "Passing Parameters: \nnone" << endl;
  #endif

  ofstream myfile(filename);
  for( ptemp = start ; ptemp != NULL ; ptemp = (ptemp -> next) ) {
      myfile << (ptemp -> name) << endl;
      myfile << (ptemp -> address) << endl;
      myfile << (ptemp -> yearofbirth) << endl;
      myfile << (ptemp -> telno) << endl;
  }
  myfile.close();
  return 0;
}

/*********************************************************************
 *
 * Function Name:        reverse
 *
 * Description:          recursively reverses the linked list of
 *                       records that currently exists
 *
 * Parameters:           pstart (record *) pointer to start
 *
 * Return Values:        ptemp (record *) the new start value
 *
 *********************************************************************/
record* llist::reverse(record *pstart) {
  record  *ptemp;

  /* check to see if debug mode is defined, if it is print the necessary information */
  #ifdef DEBUGMODE
  cout << "Method Called: reverse" << endl;
  cout << "Passing Parameters: \n" << pstart << endl;
  #endif

  if(pstart == NULL) {
    ptemp = NULL;
  } else if(pstart -> next == NULL) {
    ptemp = pstart;
  } else {
    ptemp = reverse(pstart -> next);
    pstart -> next -> next = pstart;
    pstart -> next = NULL;
  }
  return ptemp;
}

/*********************************************************************
 *
 * Function Name:        cleanup
 *
 * Description:          destroys all the records in the linked list
 *                       and resets the start of the list to NULL
 *
 * Parameters:           none
 *
 * Return Values:        none
 *
 *********************************************************************/
void llist::cleanup() {
  record  *ptemp, *next;

  /* check to see if debug mode is defined, if it is print the necessary information */
  #ifdef DEBUGMODE
  cout << "Method Called: cleanup" << endl;
  cout << "Passing Parameters:\nnone " << endl;
  #endif

  ptemp = start;
  while( ptemp != NULL ) {
    next = (ptemp -> next);
    free(ptemp);
    ptemp = next;
  }
  start = NULL;
}

/*********************************************************************
 *
 * Function Name:        menu
 *
 * Description:          prompts the user to enter a menu option
 *                       based on what they want to do
 *
 * Parameters:           none
 *
 * Return Values:        returnval (int): 0, continue
 *                                        1, stop
 *
 *********************************************************************/
int llist::menu() {
  int     menunum = 0, returnval = 0, tyob, i=0;
  char    tname[NAME_SIZE], taddr[ADDRESS_SIZE], telno[TELNO_SIZE];
  llist   copy;
  string  temp, buffer = "";

  /* check to see if debug mode is defined, if it is print the necessary information */
  #ifdef DEBUGMODE
  cout << "Method Called: menu" << endl;
  cout << "Passing Parameters:\nnone " << endl;
  #endif

  cout << "==============================================================================" << endl;
  cout << "0\tAdd Record" << endl;
  cout << "1\tModify Record using Name" << endl;
  cout << "2\tPrint Record using Name" << endl;
  cout << "3\tList Records" << endl;
  cout << "4\tDelete Record using Name" << endl;
  cout << "5\tReverse the list" << endl;
  cout << "6\tCreate a Copy" << endl;
  cout << "7\tClear Records" << endl;
  cout << "8\tQuit" << endl;
  cout << "==============================================================================" << endl;
  cout << "What would you like to do today? " << endl;
  cin >> menunum;

  if(!cin.good()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Exit 0: Please enter a number that corresponds to one of the menu choices." << endl;
  } else {
    switch(menunum) {
      case 0:
        cout << "Name: ";
        cin.ignore();
        getline(cin, buffer);
        strcpy(tname, buffer.c_str());
        cout << "Address: ";
        while(getline(cin, buffer)) {
          if(buffer == "") {
              break;
          } else if (i > 0) {
              temp += " " + buffer;
          } else {
              temp += buffer;
          }
          i++;
        }
        strcpy(taddr, temp.c_str());
        cout << "Year of Birth: ";
        getline(cin, buffer);
        stringstream(buffer) >> tyob;
        cout << "Telephone Number: ";
        getline(cin, buffer);
        strcpy(telno, buffer.c_str());
        if(addRecord(tname, taddr, tyob, telno) == 0) {
          cout << "Record added successfully." << endl;
        } else {
          cout << "Record could not be added." << endl;
        }
        break;
      case 1:
        cout << "Name: ";
        cin.ignore();
        getline(cin, buffer);
        strcpy(tname, buffer.c_str());

        cout << "Address: ";
        while(getline(cin, buffer)) {
          if(buffer == "") {
            break;
          } else if (i > 0) {
            temp += " " + buffer;
          } else {
            temp += buffer;
          }
          i++;
        }
        strcpy(taddr, temp.c_str());
        cout << "Telephone Number: ";
        getline(cin, buffer);
        strcpy(telno, buffer.c_str());
        i = modifyRecord(tname, taddr, telno);
        if(i == 0) {
          cout << i << " Records were successfully modified." << endl;
        } else if(i > 0) {
            cout << i << " Record(s) was successfully modified." << endl;
        } else {
            cout << "No records found with the name |" << tname << "|." << endl;
        }
        break;
      case 2:
        cout << "Name: ";
        cin.ignore();
        getline(cin, buffer);
        strcpy(tname, buffer.c_str());
        i = printRecord(tname);
        if(i == 0) {
          cout << "No records found with the name |" << tname << "|." << endl;
        }
        break;
      case 3:
        cout << *this << endl;
        break;
      case 4:
        cout << "Name: ";
        cin.ignore();
        getline(cin, buffer);
        strcpy(tname, buffer.c_str());
        i = deleteRecord(tname);
        if(i == 0) {
          cout << "No records found with the name |" << tname << "|." << endl;
        } else if( i == 1 ) {
          cout << "1 Record was deleted." << endl;
        } else {
            cout << i << " Records were deleted." << endl;
        }
        break;
      case 5:
        reverse();
        cout << "The list has been successfully reversed." << endl;
        break;
      case 6:
        copy = *this;
        cout << "A copy has been successfully created." << endl;
        break;
      case 7:
        cleanup();
        cout << "This list has been cleaned up." << endl;
        break;
      case 8:
        if(strcmp(filename, "") == 0) {
          cout << "The list was unable to be written to a text document because filename is undefined." << endl;
        } else if(writefile() == 0) {
          cout << "The list was successfully written to " << filename << "." << endl;
        } else {
          cout << "This list was unable to be written to " << filename << "." << endl;
        }
        cleanup();
        returnval++;
        cout << "Goodbye!" << endl;
        break;
      default:
        cout << "Exit 1: Please enter a number that corresponds to one of the menu choices." << endl;
        break;
      }
  }
  return returnval;
}

/*********************************************************************
 *
 * Function Name:        llist
 *
 * Description:          llist constructor, initializes the class
 *                       variables with the default filename
 *
 * Parameters:           none
 *
 * Return Values:        none
 *
 *********************************************************************/
llist::llist() {
  start = NULL;
  ifstream f(filename);
  if(f.good()) { //if file exists, read it
    readfile();
  }
}

/*********************************************************************
 *
 * Function Name:        llist
 *
 * Description:          llist overloaded constructor, initializes
 *                       the class variables with the filename given
 * Parameters:           none
 *
 * Return Values:        none
 *
 *********************************************************************/
llist::llist(char ufilename[]) {
  start = NULL;
  strcpy(filename, ufilename);
  ifstream f(filename);
  if(f.good()) {
    readfile();
  }
}

/*********************************************************************
 *
 * Function Name:        ~llist
 *
 * Description:          destructor, deallocates the entire linked
 *                       list
 *
 * Parameters:           none
 *
 * Return Values:        none
 *
 *********************************************************************/

llist::~llist() {
  record *ptemp = start;
  while( ptemp != NULL ) {
    record *next = ptemp -> next;
    delete ptemp;
    ptemp = next;
  }
  delete start;
}

/*********************************************************************
 *
 * Function Name:        addRecord
 *
 * Description:          adds records to the end of the list, even if
 *                       the name already exists
 *
 * Parameters:           ppstart (struct record **): start record
 *                       uname (char []): name
 *                       uaddr (char []): address
 *                       uyob (int): year of birth
 *                       utelno (char []): telephone number
 *
 * Return Values:        (int) : 0 if success
 *********************************************************************/
int llist::addRecord(char uname[], char uaddr[], int uyob, char utelno[]) {
  record *ptemp;

  /* check to see if debugmode is defined, if it is print necessary information */
  #ifdef DEBUGMODE
  cout << "Method Called: addRecord" << endl;
  cout << "Passing Parameters: " << endl;
  cout << uname << endl;
  cout << uaddr << endl;
  cout << uyob << endl;
  cout << utelno << endl;
  #endif

  /* if the list is empty, create a new record and add the info to it */
  if (start == NULL) {
    start = new record();
    (start -> next) = NULL;
    strcpy((start-> name), uname);
    strcpy((start-> address), uaddr);
    (start-> yearofbirth) = uyob;
    strcpy((start-> telno), utelno);
  } else { // add record to end of list
    for( ptemp = start ; (ptemp -> next) != NULL ; ptemp = (ptemp -> next) );
    (ptemp -> next) = new record();
    (ptemp -> next) -> next = NULL;
    strcpy( ((ptemp -> next) -> name), uname);
    strcpy( ((ptemp -> next) -> address), uaddr);
    ((ptemp -> next) -> yearofbirth) = uyob;
    strcpy( ((ptemp -> next) -> telno), utelno);
  }
  return 0;
}

/*********************************************************************
 *
 * Function Name:        printRecord
 *
 * Description:          prints all records in the database associated
 *                       to the name entered
 *
 * Parameters:           uname (char []): name
 *
 * Return Values:        count (int) : number of records printed
 *
 *********************************************************************/
int llist::printRecord(char uname[]) {
  record  *ptemp;
  int     count = 1;

  #ifdef DEBUGMODE
  cout << "Method Called: printRecord"<< endl;
  cout << "Passing Parameters: " << endl;
  cout << uname;
  #endif

  ptemp = start;
  for( ptemp = start ; ptemp != NULL ; ptemp = (ptemp -> next)) {
    if(strcmp( (ptemp -> name), uname) == 0) { // print Record if found, increase count
      cout << "====== " << count << " ======" << endl;
      cout << "Name: " << (ptemp -> name) << endl;
      cout << "Address: " << (ptemp -> address) << endl;
      cout << "Year of Birth: " << (ptemp -> yearofbirth) << endl;
      cout << "Telephone Number: " << (ptemp -> telno) << endl;
      count++;
    }
  }
  return count; // return number of records found
}

/*********************************************************************
 *
 * Function Name:        modifyRecord
 *
 * Description:          modifies all records in database with the
 *                       same name based on the info entered
 *
 * Parameters:           uname (char []): name
 *                       uaddr (char []): address
 *                       utelno (char []): telephone number
 *
 * Return Values:        count (int): number of records modified
 *
 *********************************************************************/

int llist::modifyRecord(char uname[], char uaddr[], char utelno[]) {
  record  *ptemp;
  int     count = 0;

  #ifdef DEBUGMODE
  cout << "Method Called: modifyRecord" << endl;
  cout << "Passing Parameters: " << endl;
  cout << uname << endl;
  cout << uaddr << endl;
  cout << utelno << endl;
  #endif

  ptemp = start;
  for( ptemp = start ; ptemp != NULL ; ptemp = (ptemp -> next)) {
    if(strcmp( (ptemp -> name), uname) == 0) { // if name matches, inc count, update address and telephone number
      count++;
      strcpy( (ptemp -> address), uaddr);
      strcpy( (ptemp -> telno), utelno);
    }
  }
  return count; // return number of records updated
}

/***********************************************************************
 *
 * Function Name:        deleteRecord
 *
 * Description:          deletes all records in database based on name
 *                       entered
 *
 * Parameters:           uname (char []): name
 *
 * Return Values:        count (int) : number of records deleted
 *
 ***********************************************************************/
int llist::deleteRecord(char uname[]) {
  record  *ptemp, *previous, *deletethis;
  int     count = 0;

  #ifdef DEBUGMODE
  cout << "Method Called: deleteRecord" << endl;
  cout << "Passing Parameters: " << endl;
  cout << uname << endl;
  #endif

  ptemp = start;
  previous = start;
  while( ptemp != NULL ) {
    if(strcmp(ptemp -> name, uname) == 0) {
      if(ptemp == start) { // if the record is the first record
        start = ptemp -> next;
        deletethis = ptemp;
        ptemp = start;
      } else { // else if the record is not the first record
        if((ptemp->next->next == NULL) && (strcmp(ptemp->next->name, uname) == 0)) {
          previous->next = NULL;
          delete ptemp -> next;
          delete ptemp;
          ptemp = NULL;
        } else {
          previous->next = ptemp->next;
          previous = ptemp;
          ptemp = previous -> next;
          delete previous;
        }
      }
      count++;
    } else {
      previous = ptemp;
      ptemp = ptemp -> next;
    }
  }
  return count; // return number of records deleted
}

/***********************************************************************
 *
 * Function Name:        reverse
 *
 * Description:          initiates the recursive reverse of the linked
 *                       list
 *
 * Parameters:           none
 *
 * Return Values:        none
 *
 ***********************************************************************/
void llist::reverse() {
  start   = reverse(start);
}

/***********************************************************************
 *
 * Function Name:        operator<<
 *
 * Description:          overloads the output operator so that it is
 *                       able to print linked lists of records
 *
 * Parameters:           os (ostream &) : reference to an output stream
 *                       myll (const llist &) : constant reference to
 *                       my linked list of records
 *
 * Return Values:        os (ostream &) : complete output stream
 *
 ***********************************************************************/
ostream& operator<<(ostream &os, const llist &myll) {
  record  *ptemp;
  int     i = 1;

  if(myll.start == NULL) {
    os << "List is empty" << endl;
  }

  for (ptemp = myll.start ; ptemp != NULL ; ptemp = (ptemp -> next)) {
    os << "====== " << i << " ======" << endl;
    os << (ptemp -> name) << endl;
    os << (ptemp -> address) << endl;
    os << (ptemp -> yearofbirth) << endl;
    os << (ptemp -> telno) << endl;
    i++;
  }
  return os;
}

/***********************************************************************
 *
 * Function Name:        operator=
 *
 * Description:          overloads the assignment operator so that it is
 *                       able to create a copy of the linked list given
 *
 * Parameters:           original (const llist &) : original list
 *
 * Return Values:        (llist &) : copied list
 *
 ***********************************************************************/
llist& llist::operator=(const llist &original) {
  record  *ptemp;

  if(original.start == NULL) {
    this->start = NULL;
  }

  for (ptemp = original.start; ptemp != NULL; ptemp = (ptemp -> next)) {
    this->addRecord((ptemp->name), (ptemp -> address), (ptemp ->yearofbirth), (ptemp ->telno));
  }

  return *this; //return new linked list that is a copy
}
