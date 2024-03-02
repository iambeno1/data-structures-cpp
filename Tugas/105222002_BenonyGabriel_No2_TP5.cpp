#include <iostream>
using namespace std;

typedef struct StudentData
{
    string studentID;
    string name;
    string major;
    float GPA;
    StudentData* next;
    StudentData* prev;
} Student;

Student* AddToFront(Student* head, string studentID, string name, string major, float GPA)
{
    Student* newStudent = new Student;
    newStudent->studentID = studentID;
    newStudent->name = name;
    newStudent->major = major;
    newStudent->GPA = GPA;

    if (head == nullptr)
    {
        head = newStudent;
    }
    else
    {
        newStudent->next = head;
        head->prev = newStudent;
        head = newStudent;
    }
    cout << "Mahasiswa ditambahkan di awal daftar." << endl;
    return head;
}

Student* AddToLast(Student* head, string studentID, name, string major, float GPA)
{
    Student* newStudent = new Student;
    newStudent->studentID = studentID;
    newStudent->name = name;
    newStudent->major = major;
    newStudent->GPA = GPA;

    if (head == nullptr)
    {
        head = newStudent;
    }
    else
    {
        Student* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newStudent;
        newStudent->prev = current;
    }
    cout << "Mahasiswa ditambahkan di akhir daftar." << endl;
    return head;
}

Student* AddBefore(Student* head, string keyStudentID, string studentID, name, string major, float GPA)
{
    Student* newStudent = new Student;
    newStudent->studentID = studentID;
    newStudent->name = name;
    newStudent->major = major;
    newStudent->GPA = GPA;

    Student* current = head;
    while (current != nullptr)
    {
        if (current->studentID == keyStudentID)
        {
            if (current->prev != nullptr)
            {
                current->prev->next = newStudent;
                newStudent->prev = current->prev;
            }
            newStudent->next = current;
            current->prev = newStudent;
            if (current == head)
            {
                head = newStudent;
            }
            cout << "Mahasiswa ditambahkan di depan mahasiswa dengan ID " << keyStudentID << endl;
            return head;
        }
        current = current->next;
    }
    cout << "Mahasiswa dengan ID " << keyStudentID << " tidak ditemukan." << endl;
    return head;
}

Student* DeleteStudent(Student* head, string keyStudentID)
{
    Student* current = head;
    while (current != nullptr)
    {
        if (current->studentID == keyStudentID)
        {
            if (current->prev != nullptr)
            {
                current->prev->next = current->next;
            }
            if (current->next != nullptr)
            {
                current->next->prev = current->prev;
            }
            if (current == head)
            {
                head = current->next;
            }
            delete current;
            cout << "Mahasiswa dengan ID " << keyStudentID << " dihapus." << endl;
            return head;
        }
        current = current->next;
    }
    cout << "Mahasiswa dengan ID " << keyStudentID << " tidak ditemukan." << endl;
    return head;
}

void ShowForward(Student* head)
{
    Student* current = head;
    while (current != nullptr)
    {
        cout << "Student ID: " << current->studentID << endl;
        cout << "Name: " << current->name << endl;
        cout << "Major: " << current->major << endl;
        cout << "GPA: " << current->GPA << endl;
        cout << endl;
        current = current->next;
    }
}

void ShowBackward(Student* head)
{
    Student* current = head;
    while (current != nullptr)
    {
        cout << "Student ID: " << current->studentID << endl;
        cout << "Name: " << current->name << endl;
        cout << "Major: " << current->major << endl;
        cout << "GPA: " << current->GPA << endl;
        cout << endl;
        current = current->prev;
    }
}