#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

//// forward declaration ////

float sum_salary;

class NegativeNumberException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Negative number of villages not allowed!";
    }
};

class NegativeSalaryException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Updating salary results in a negative total salary!";
    }
};

//// declaring the three main classes////

class AdministrativeEntity
{
public:
   string name;
   int id;
   int level;
public:
    AdministrativeEntity(const string & name, int id, int level)
        : name(name), id(id), level(level) {} 
};


class AdministrativePersonnel
{
public:
  string name;
  string id;
  int securitystatus;
  int dateofbirth;
  string email;
  int authorizationlevel;
  float salary;
public:
  AdministrativePersonnel(const string & name,const string & id, int securitystatus,int dateofbirth,const string & email,int authorizationlevel,float salary)
        : name(name), id(id), securitystatus(securitystatus),dateofbirth(dateofbirth),email(email),authorizationlevel(authorizationlevel),salary(salary) {}
        friend class RepublicOffice;
};

class RepublicOffice {
private:
    vector<AdministrativeEntity*> list1;
    vector<AdministrativePersonnel*> list2;
public:
    RepublicOffice() {}
    void addEntity(AdministrativeEntity* entity)
    {
        list1.push_back(entity);
    }
    void addPersonnel(AdministrativePersonnel* personnel)
    {
        list2.push_back(personnel);
    }
    void printEntities() 
    {
        cout<<""<<endl;
        cout<<"THESE ARE ALL THE ADMINISTRATIVE ENTITIES IN THE REPUBLIC OFFICE OF INDIA"<<endl;
        cout<<""<<endl;
        for (AdministrativeEntity* e : list1) 
        {
                cout<<e->name<<endl;
        }
    }
    void printPersonnel() 
    {
        cout<<""<<endl;
        cout<<"THESE ARE ALL THE ADMINISTRATIVE PERSONNELS IN THE REPUBLIC OFFICE OF INDIA"<<endl;
        cout<<""<<endl;
        for (AdministrativePersonnel* p : list2) 
        {
                  cout<<p->name<<endl;         
        }
    }

    void total_salary()
    {
        cout<<""<<endl;
        cout<<"THESE ARE ALL total fund for salary in THE ADMINISTRATIVE PERSONNELS IN THE REPUBLIC OFFICE OF INDIA"<<endl;
        cout<<""<<endl;
        for (AdministrativePersonnel* p : list2) 
        {
                  sum_salary = sum_salary + p->salary;        
        }
        cout<<sum_salary<<endl;

    }


    void update_salary()
    {
        float cut;
        cout << "Enter the amount: ";
        cin >> cut;
        for (AdministrativePersonnel* p : list2)
        {
            p->salary = p->salary - cut;
        }

        // Calculate the updated sum_salary
        float updated_sum_salary = 0.0;
        for (AdministrativePersonnel* p : list2)
        {
            updated_sum_salary = updated_sum_salary + p->salary;
        }

        if (updated_sum_salary < 0)
        {
            // Rollback the salary updates
            for (AdministrativePersonnel* p : list2)
            {
                p->salary = p->salary + cut;
            }
            throw NegativeSalaryException();
        }

        std::cout << "Salary updated" << std::endl;
    }
};

class municipalities : public AdministrativeEntity
{
protected:
    string municipalhead;
    int numberofvillages;

public:
    municipalities(const string& name, int id, int level,
                    const string& municipalhead, int numberofvillages)
        : AdministrativeEntity(name, id, level),
          municipalhead(municipalhead),
          numberofvillages(numberofvillages) {}

    void updateNumberOfVillages()
    {
        cout << "Enter the new number of villages: ";
        int newNumber;
        cin >> newNumber;

        if (newNumber < 0)
        {
            throw NegativeNumberException();
        }

        numberofvillages = newNumber;
        cout << "Updated" << endl;
    }      
          
};

class district : public AdministrativeEntity
{
public:
    vector <municipalities*> municipalities_list;
    string districtmagistratename;
    string deputydistricthead;
    int noofwards;

public:
    district(const string &name, int id, int level,
             const string &districtmagistratename,const string &deputydistricthead, int noofwards)
        : AdministrativeEntity(name, id, level),
          districtmagistratename(districtmagistratename),
          deputydistricthead(deputydistricthead),
          noofwards(noofwards) {}

    void addmunicipalities(municipalities* muni)
    {
        municipalities_list.push_back(muni);
        cout<<muni->name<<" municipality has been added to district jurisdiction"<<endl;
    }    
    
    void displaymunicipalities(district* dis)
    {
        cout << "municipalities in the district: " << dis->name<<endl;
        for (const auto& muni : municipalities_list)
        {
            cout << "- " << muni->name << endl; 
        }
    }      
};


class  StateGovernment : public AdministrativeEntity
{
protected:
vector <district*> district_list;
string headOfstate;
string headOfgov;
int term;
public:
    
    StateGovernment(const string &name, int id, int level,const string &headOfstate,const string &headOfgov, int term)
        : AdministrativeEntity(name, id, level), headOfstate(headOfstate), headOfgov(headOfgov), term(term) {}
    
    void addDistrict(district* dis)
    {
        district_list.push_back(dis);
        cout<<dis->name<<" district has been added to state government jurisdiction"<<endl;
    }    
    void displaydistricts()
    {
        cout << "districts in the state Government: " << endl;
        for (const auto& dis : district_list)
        {
            cout << "- " << dis->name << endl;
        }
    }

};

class CentralGovernment : public AdministrativeEntity 
{
public:
    vector<StateGovernment*> state_list;
    string headOfstate;
    string headOfgov;
    int term;

public:
    CentralGovernment(const string& name, int id, int level, const string& headOfstate, const string& headOfgov, int term)
        : AdministrativeEntity(name, id, level), headOfstate(headOfstate), headOfgov(headOfgov), term(term) {}

    void addState(StateGovernment* state)
    {
        state_list.push_back(state);
        cout<<state->name<<" state has been added to central government jurisdiction"<<endl;
    }    
    
    void displayStates()
    {
        cout << "States in the Central Government: " << endl;
        for (const auto& state : state_list)
        {
            cout << "- " << state->name << endl; 
        }
    }

};


/// now making all the derived classes from administrative personnel ////

class MunicipalHead : public AdministrativePersonnel
{
public:
    string municipalityName;
    int numberOfWards;
    string department;

public:
    // Constructor for the MunicipalHead class
    MunicipalHead(const string &name, const string &id, int securitystatus, int dateofbirth, const string &email,
                  int authorizationlevel, float salary, const string &municipalityName, int numberOfWards,
                  const string &department)
        : AdministrativePersonnel(name, id, securitystatus, dateofbirth, email, authorizationlevel, salary),
          municipalityName(municipalityName),
          numberOfWards(numberOfWards),
          department(department)
    {}
};

class DistrictMagistrate : public AdministrativePersonnel
{
public:
    vector<MunicipalHead*> municipalities_list;
    string districtName;
    string divisionName;
    int numberOfSubdivisions; 

public:
    // Constructor for the DistrictMagistrate class
    DistrictMagistrate(const string& name, const string& id, int securitystatus, int dateofbirth, const string& email,
                       int authorizationlevel, float salary, const string& districtName, const string& divisionName,
                       int numberOfSubdivisions)
        : AdministrativePersonnel(name, id, securitystatus, dateofbirth, email, authorizationlevel, salary),
          districtName(districtName),
          divisionName(divisionName),
          numberOfSubdivisions(numberOfSubdivisions)
    {}

    void addmunicipalhead(MunicipalHead* muni)
    {
        municipalities_list.push_back(muni);
        cout<<muni->name<<" state has been added to central government jurisdiction"<<endl;
    }          
    
    void displaymunicipalhead()
    {
        cout << "municipal head under dm " << endl;
        for (const auto& muni : municipalities_list)
        {
            cout << "- " << muni->name << endl; 
        }
    }


};

class ChiefMinister : public AdministrativePersonnel
{
public:
    std::vector<DistrictMagistrate*> districtMagistrate_list;
    std::string partyName;
    int yearsInOffice;

public:
    // Constructor for the ChiefMinister class
    ChiefMinister(const string& name, const string& id, int securitystatus, int dateofbirth, const string& email,
                  int authorizationlevel, float salary, const string& partyName, int yearsInOffice)
        : AdministrativePersonnel(name, id, securitystatus, dateofbirth, email, authorizationlevel, salary),
          partyName(partyName),
          yearsInOffice(yearsInOffice)
    {}

    void adddms(DistrictMagistrate* dm)
    {
        districtMagistrate_list.push_back(dm);
        cout<<dm->name<<" dm has been added to chiefminister jurisdiction"<<endl;
    }    
    
    void displaydms()
    {
        cout << "dms under chiefminister " << endl;
        for (const auto& dis : districtMagistrate_list)
        {
            cout << "- " << dis->name << endl; 
        }
    }

};

class PrimeMinister : public AdministrativePersonnel
{
public:
    vector<ChiefMinister*> ChiefMinister_list;
    string partyName;
    int yearsInOffice;

public:
    // Constructor for the PrimeMinister class
    PrimeMinister(const string& name, const string& id, int securitystatus, int dateofbirth, const string& email,
                  int authorizationlevel, float salary, const string& partyName, int yearsInOffice)
        : AdministrativePersonnel(name, id, securitystatus, dateofbirth, email, authorizationlevel, salary),
          partyName(partyName),
          yearsInOffice(yearsInOffice)
    {}

    void addchiefministers(ChiefMinister* Chief)
    {
        ChiefMinister_list.push_back(Chief);
        cout<<Chief->name<<" state has been added to central government jurisdiction"<<endl;
    }    
    
    void displaychiefministers()
    {
        cout << "chief ministers under primeminister " << endl;
        for (const auto& chief : ChiefMinister_list)
        {
            cout << "- " << chief->name << endl; 
        }
    }

    
};
 
int main()
{

    cout<<""<<endl;
    cout<<"WELCOME TO INDIAN REPUBLIC SIMULATION USING OOPS"<<endl;
    cout<<""<<endl;

    RepublicOffice office;

    // Creating objects of CentralGovernment
    CentralGovernment centralGov("Central Govt", 1, 1, "President", "Prime Minister", 5);
    office.addEntity(&centralGov);


    // Creating objects of StateGovernment
    StateGovernment stateGov1("Karnataka", 2, 2, "anurag", "nandan", 4);
    StateGovernment stateGov2("HimachalPradesh", 3, 2, "shekhar", "date", 3);
    office.addEntity(&stateGov1);
    office.addEntity(&stateGov2);

    // Creating objects of district
    district district1("leh", 4, 3, "keecha suddepa", "rohan", 10);
    district district2("Dharwad", 5, 3, "prabhas", "kolhar", 8);
    office.addEntity(&district1);
    office.addEntity(&district2);

    // Creating objects of municipalities
    municipalities municipality1("Municipality 1", 1, 3, "Municipal Head 1", 10);
    municipalities municipality2("Municipality 2", 1, 3, "Municipal Head 1", 10);
    office.addEntity(&municipality1);
    office.addEntity(&municipality2);





    // Creating objects of PrimeMinister
    PrimeMinister pm("Prime Minister", "PM001", 2, 1985, "pmindia.com", 5, 20000.0, "BJP", 3);
    office.addPersonnel(&pm);

    // Creating objects of ChiefMinister
    ChiefMinister cm1("Chief Minister 1", "CM001", 2, 1978, "cm1@example.com", 4, 18000.0, "Party XYZ", 5);
    ChiefMinister cm2("Chief Minister 2", "CM002", 3, 1982, "cm2@example.com", 3, 16000.0, "Party PQR", 4);
    office.addPersonnel(&cm1);
    office.addPersonnel(&cm2);

    // Creating objects of DistrictMagistrate
    DistrictMagistrate dm1("District Magicout.flush();strate 1", "DM001", 1990, 2, "dm1@example.com", 4,30000 ,"District 1", "Division 1", 3);
    DistrictMagistrate dm2("District Magistrate 2", "DM002", 1995, 3, "dm2@example.com", 3,20000 ,"District 2", "Division 2", 4);
    office.addPersonnel(&dm1);
    office.addPersonnel(&dm2);

    // Creating objects of Municipal head
    MunicipalHead mh1("Municipal Head 1", "MH001", 2, 1988, "mh1@example.com", 4,5000 ,"Municipality 1", 10, "Department A");
    MunicipalHead mh2("Municipal Head 2", "MH002", 3, 1992, "mh2@example.com", 3,6000,"Municipality 2", 8, "Department B");
    office.addPersonnel(&mh1);
    office.addPersonnel(&mh2);

    centralGov.addState(&stateGov1);
    centralGov.addState(&stateGov2);
    stateGov1.addDistrict(&district1);
    stateGov2.addDistrict(&district2);;
    district1.addmunicipalities(&municipality1);
    district2.addmunicipalities(&municipality2);

    pm.addchiefministers(&cm1);
    pm.addchiefministers(&cm2);
    cm1.adddms(&dm1);
    cm2.adddms(&dm2);
    dm1.addmunicipalhead(&mh1);
    dm2.addmunicipalhead(&mh2);


    centralGov.displayStates();
    stateGov1.displaydistricts();
    stateGov2.displaydistricts();
    district1.displaymunicipalities(&district1);
    district2.displaymunicipalities(&district2);

    pm.displaychiefministers();
    cm1.displaydms();
    cm2.displaydms();
    dm1.displaymunicipalhead();
    dm2.displaymunicipalhead();
    try
    {
     municipality1.updateNumberOfVillages();
    }
    catch (const NegativeNumberException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
     municipality2.updateNumberOfVillages();
    }
    catch (const NegativeNumberException& e)
    {
        std::cerr << e.what() << std::endl;
    }


    office.printEntities();

    cout << "\nPersonnel in Republic Office: " << endl;
    office.printPersonnel();

    office.total_salary();
    
    try
    {
       office.update_salary();
    }
    catch (const NegativeSalaryException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
} 