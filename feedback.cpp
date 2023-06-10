class feedback_functions{
    public:
    void rate_doctor(doctor*temp){
        double rt;
        cout<<"How would you rate the doctor out of 10 :";
        cin>>rt;
        cout<<endl;
        if(temp->feedback==0)
        temp->feedback=rt;
        else
        temp->feedback=(rt+temp->feedback)/2;
    }


    void rate_patient(string nme){
        double rt;
        cout<<"How would you rate the patients behaviour out of 10 :";
        cin>>rt;
        cout<<endl;
        for(auto it:d2.v){
            if(it.name==nme){
                if(it.ethics_rating==0)
                it.ethics_rating=rt;
                else
                it.ethics_rating=(rt+it.ethics_rating)/2;
            }
        }
    }
};