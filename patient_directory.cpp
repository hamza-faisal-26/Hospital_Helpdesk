bool cmp(patient a,patient b){
    return b.name>a.name;
}

class pat_directory{
    public:
    vector<patient> v;

    void admission(){
        patient pt;
        cout<<"Enter patient name: ";
        string n;
        cin>>n;

        for (auto it:v) {
            if (it.name==n) {
                cout<<"Patient already exists\n";
                return;
            }
        }

        pt.name = n;

        cout<<"Enter patient department: ";
        string dep; cin>>dep;
        pt.department = dep;

        cout<<"Enter patient employment type: ";
        string emp; cin>>emp;
        pt.employment_type = emp;

        cout<<"Enter patient phone no.: ";
        long long int ph; cin>>ph;
        pt.phone_no = ph;

        cout<<"Enter patient Email ID: ";
        string e; cin>>e;
        pt.email_id = e;

        cout<<"Enter patient Address: ";
        string a; cin>>a;
        pt.address = a;

        pt.ethics_rating = 0;
        v.push_back(pt);
        sort(v.begin(),v.end(),cmp);
    }

    void print_directory(){
        if (v.size()==0) {
            cout<<"Empty Directory\n";
            return;
        }
        for(auto it:v)
        cout<<"Name - "<<it.name<<"\n"<<"Department - "<<it.department<<"\n"<<"Emplyment Type - "<<it.employment_type<<"\n"<<"Rating - "<<it.ethics_rating<<"\n"<<"Phone No.- "<<it.phone_no<<"\n"<<"Email ID - "<<it.email_id<<"\n"<<"Address - "<<it.address<<"\n\n";
    }

    string search (long long int ph) {
        for (auto it:v) {
            if (it.phone_no==ph) return it.name;
        }
        return "Not Found";
    }
    string search (string str) {
        for (auto it:v) {
            if (it.name==str || it.department==str || it.email_id==str || it.address==str) return it.name;
        }
        return "Not Found";
    }

    void deletion(string n) {
        auto iter=v.end();
        for (auto it=v.begin(); it!=v.end(); ++it) {
            if (it->name==n) iter = it;
        }
        v.erase(iter);
    }

    void update_phone_no(string nme,long long int phn){
        for (auto it:v) {
            if (it.name==nme) {
                it.phone_no=phn;
                return;
            }
        }
        cout<<"Patient not found\n";
    }
    void update_email_id(string nme,string e){
        for (auto it:v) {
            if (it.name==nme) {
                it.email_id=e;
                return;
            }
        }
        cout<<"Patient not found\n";
    }
    void update_address(string nme,string a){
        for (auto it:v) {
            if (it.name==nme) {
                it.address=a;
                return;
            }
        }
        cout<<"Patient not found\n";
    }
    void update_ethics_rating(string nme,long long int r){
        for (auto it:v) {
            if (it.name==nme) {
                it.ethics_rating=r;
                return;
            }
        }
        cout<<"Patient not found\n";
    }
};