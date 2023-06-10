class appointment_mngmt{
    public:
    vector<pair<string,string>> v;

    void appoint_doctor(string pat,string doc){
        int f=0,ch=0;
        for(auto it:d2.v){
            if(pat==it.name){
                f=1;
                break;
            }
        }
        if(f==0){
            cout<<"Patient not found in directory\n";
            cout<<"Enter the details of patient in Directory\n";
            d2.admission();
        }
        doctor*temp=d1.first;
        f=0;
        while(temp){
            if(temp->name==doc){
                ch=1;
                for(int i=0;i<7;i++){
                    if(temp->availability_ona_day[i]==true){
                        cout<<"Appointment fixed on Day "<<i<<endl;
                        pair<string,string> p(pat,doc);
                        v.push_back(p);
                        f=1;
                        temp->past_patients.push_back(pat);
                        temp->no_of_patients++;
                        feed.rate_patient(pat);
                        return;
                    }
                }
                if(f==0)
                cout<<"Doctor busy for the next week\n";
            }
            temp=temp->next;
        }
        if(ch==0)
        cout<<"Doctor with that name does not exist\n";
    }


void print_past_visited(string doc){
    doctor*temp=d1.first;
    while(temp){
        if(temp->name==doc){
            for(auto it:temp->past_patients)
            cout<<it<<" ";
            if(temp->past_patients.size()==0)
            cout<<"No past patients/n";
            else cout<<endl;
        }
        temp=temp->next;
    }
}

void print_all_past_appointments(){
    for(auto it:v){
        cout<<it.first<<" met the doctor "<<it.second<<endl;
    }
    if(v.size()==0)
    cout<<"No past appointments till date";
}

};