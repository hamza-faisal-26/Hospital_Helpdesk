class doctor: public human{
    public:
    int no_of_patients;
    double feedback;
    bool availability_ona_day[7];
    vector <string> past_patients;
    doctor*next;
};