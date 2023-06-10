class doc_directory{
    public:
    doctor*first;

    void print_directory(){
        doctor*temp=first;
        if(temp==NULL){
            cout<<"Directory Empty\n";
            return;
        }
        while(temp){
            cout<<"Name - "<<temp->name<<"\n"<<"Department - "<<temp->department<<"\n"<<"Emplyment Type - "<<temp->employment_type<<"\n"<<"Rating - "<<temp->feedback<<"\n"<<"Phone No.- "<<temp->phone_no<<"\n"<<"Email ID - "<<temp->email_id<<"\n"<<"No. of Patients - "<<temp->no_of_patients<<"\n";
            if (temp->availability_ona_day) cout<<"Availability - YES\n\n";
            else cout<<"Availability - NO\n\n";
            temp=temp->next;
        }
    }

    string search(long long int phno){
        doctor*temp=first;
        while(temp){
            if(temp->phone_no==phno)
            return temp->name;
            temp=temp->next;
        }
        return "Not Found";
    }
    string search(string str){
        doctor*temp=first;
        while(temp){
            if(temp->name==str || temp->email_id==str || temp->department==str) 
            return temp->name;
            temp=temp->next;
        }
        return "Not Found";
    }

    void new_appointment(){
        // Declaration Start
        doctor*doc=new doctor;
        cout<<"Enter doctor name: ";
        string s;
        cin>>s;

        doctor*t=first;
        while(t){
            if(t->name==s) {
                cout<<"Doctor Already Exists\n";
                delete(doc);
                return;
            }
            t=t->next;
        }
        
        doc->name=s;
        doc->next=NULL;

        cout<<"Enter doctor department: ";
        string dep; cin>>dep;
        doc->department = dep;

        cout<<"Enter doctor employment type: ";
        string emp; cin>>emp;
        doc->employment_type = emp;

        cout<<"Enter doctor phone no.: ";
        long long int ph; cin>>ph;
        doc->phone_no = ph;

        cout<<"Enter doctor Email ID: ";
        string e; cin>>e;
        cout<<endl;
        doc->email_id = e;

        doc->no_of_patients = 0;

        doc->feedback = 0;
        for(int i=0;i<7;i++)
        doc->availability_ona_day[i] = true;
        // Declaration End

        if(first==NULL){
        first=doc;
        return;
        }
        doctor*temp=first;
        if(temp->name>doc->name){
        doc->next=temp;
        first=doc;
        return;
        }
        while(temp){
            if(temp->name < doc->name)
            if(temp->next){
                if(temp->next->name>doc->name){
                    doc->next=temp->next;
                    temp->next=doc;
                    break;
                }
            }
            if(temp->next==NULL){
                if(temp->name!=doc->name)
                temp->next=doc;
                break;
            }
            temp=temp->next;
        }
    }

    void resigning(string nme){
        if(first->name==nme){
        first=first->next;
        return;
        }
        doctor*temp=first;
        while(temp){
            if(temp->next)
            if(temp->next->name==nme){
                doctor*del=temp->next;
                temp->next=del->next;
                delete(del);
                return;
            }
            temp=temp->next;
        }
    }

    void update_phone_no(string nme,long long int phn){
        doctor*temp=first;
        while(temp){
            if(temp->name==nme){
                temp->phone_no=phn;
                return;
            }
            temp=temp->next;
        }
        cout<<"Doctor not found\n";
    }
    void update_email_id(string nme,string e){
        doctor*temp=first;
        while(temp){
            if(temp->name==nme){
                temp->email_id=e;
                return;
            }
            temp=temp->next;
        }
        cout<<"Doctor not found\n";
    }
    void update_feedback(string nme,long long int f){
        doctor*temp=first;
        while(temp){
            if(temp->name==nme){
                temp->feedback=f;
                return;
            }
            temp=temp->next;
        }
        cout<<"Doctor not found\n";
    }
    void update_availability(string nme,int i,bool b){
        doctor*temp=first;
        while(temp){
            if(temp->name==nme){
                temp->availability_ona_day[i]=b;
                return;
            }
            temp=temp->next;
        }
        cout<<"Doctor not found\n";
    }
    void update_no_patients(string nme,int n){
        doctor*temp=first;
        while(temp){
            if(temp->name==nme){
                temp->no_of_patients=n;
                return;
            }
            temp=temp->next;
        }
        cout<<"Doctor not found\n";
    }
};