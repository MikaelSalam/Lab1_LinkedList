
#include <iostream>
#include <string>
using namespace std;
// -----------------------------
// Data Model
// -----------------------------
struct User {
    string username;
    string password; 
    User* next;
    
    User(string u, string p) {
        username = u;
        password = p;
        next = nullptr;
    }
};

bool insertUser(User*& head, const string& username, const string& password);
User* findUser(User* head, const string& username);
bool authenticate(User* head, const string& username, const string& password);
bool removeFront(User*& head);
bool removeByUsername(User*& head, const string& username );
void clearList(User*& head);
size_t size(User* head);
void printUsers(User* head );

int main() {
  
    User* head = nullptr;

    insertUser(head,"Jake","51015");
    insertUser(head,"Sam","@2025");
    insertUser(head,"Kile","12345");
    insertUser(head,"Andy","@nDy1");
    insertUser(head,"Olivia","01ivi@");

    cout << "User List: " <<endl;
    printUsers(head);
    cout << endl;

    cout << "Finding User \n" ;
    User* user = findUser(head,"Sam");
    if(user != nullptr){
        cout << "User Found : " << user -> username <<endl;
    }else{
        cout << "User Not Found "<< endl;
    }
    cout << endl;

    cout << "Authenticate. \n";
    cout << "Authenticate Jake / 51015 : " << (authenticate (head, "Jake", "51015" )? "Success" : "Fail" ) <<endl;
    cout << "Authenticate Will / Wi11y : " << (authenticate (head, "Will", "W1lly" )? "Success" : "Fail" ) <<endl;
    cout << endl;

    cout << "Removing Front. \n";
    cout << "List Before Removing Front. \n";
    printUsers(head);
    removeFront(head);
    cout << "List after removing front : \n";
    printUsers(head);
    cout << endl;

    cout << "Removing By Username. \n";
    removeByUsername(head , "Andy");
    cout << "List after removing by username : \n";
    printUsers(head);
    cout << endl;
    

    cout << "Counting List. \n";
    cout << "Size of list : "<< size(head) << endl;
    cout << endl;

    cout << "Clearing List. \n";
    clearList(head);
    cout << "List after clearing list : "<< endl;
    printUsers(head);


    return 0;
}

// -----------------------------
// Core API — implement these
// -----------------------------

//InsertUser Runtime: O(n)//
bool insertUser(User*& head, const string& username, const string& password) {
    
    User* current = head;
    while(current != nullptr){
        if(current->username == username){
            return false;
        }
        current = current->next;
    }
    
    User* newUser = new User(username , password);
    if(head == nullptr){
        head = newUser;
        return true;
    }
    
    User* end = head;
    while(end->next != nullptr){
        end = end->next;
    }
    end->next = newUser;
    return true;
}

// Find User runtime : O(n) //
User* findUser(User* head, const string& username) {
    
    User* current = head;
    while(current != nullptr){
        if(current->username == username){
            return current;
        }
        current = current->next;
    }

    return nullptr;
}

//Authicate Runtime : O(n)//
bool authenticate(User* head, const string& username, const string& password) {
    
    User* current = head;
    while(current != nullptr){
        if(current->username == username && current->password == password){
            return true;
        }
        current = current->next;
    }
    return false;
}

//RemoveFront runtime : O(1)//
bool removeFront(User*& head) {
    User* current = head;
    if(current == nullptr){
        return false;
    }

    User* temp = head;
    head = head->next;
    delete temp;
    return true;

}

//Remove by Username runtime: O(n)//
bool removeByUsername(User*& head, const string& username) {
    
    if(head == nullptr){
        return false;
    }

    if(head->username == username){
        User*temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    
    User* current = head;
    while(current -> next != nullptr){
        if(current -> next -> username == username){
            User* temp = current -> next;
            current -> next = current -> next -> next;
            delete temp;
            return true;
        }
        current = current->next;
    }
    return false;
}

// Clearlist runtime: O(n)//
void clearList(User*& head) {
    
    User* current = head;
    while(current != nullptr){
        User* temp = current->next;
        delete current;
        current = temp;
    }
    head = nullptr;
}

// Size runtime : O(n)//
size_t size(User* head) {
    
    size_t count = 0;
    User* current = head;
    while(current != nullptr){
        count++;
        current = current->next;
    }
    
    return count;
}

//PrintUsers runtime: O(n)//
void printUsers(User* head) {
    
    User* current = head;
    if(current == nullptr){
        cout << "List is Empty" <<endl;
        return;
    }

    while(current != nullptr){
        cout << current -> username ;
        if(current -> next != nullptr){
            cout << " -> " ;
        }
        current = current -> next;
    }
    cout << " -> End " <<endl;
    
}
