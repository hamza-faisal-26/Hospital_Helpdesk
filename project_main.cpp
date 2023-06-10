#include<bits/stdc++.h>
using namespace std;
#include"human.cpp"
#include"doctor.cpp"
#include"patient.cpp"
#include"doctor_directory.cpp"
#include"patient_directory.cpp"
doc_directory d1;
pat_directory d2;
#include"feedback.cpp"
feedback_functions feed;
#include"appointment_management.cpp"
appointment_mngmt m;



int main(){
    d1.new_appointment();
    d2.admission();
    m.appoint_doctor("Hamza","Asif");
    m.print_all_past_appointments();
    return 0;
}