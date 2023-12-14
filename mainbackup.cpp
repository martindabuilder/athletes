#include <iostream>
#include <string>
#include <random> // za generirane na random chislo
#include <stdio.h>
#include <stdlib.h> // za exit i za sluchaen rezultat
#include <fstream>  // vzimane na informaciq ot file
using namespace std;

// alt shift f za preravnqvane na vs redove
const int max_total_athletes = 35;
const int max_disciplines = 5;
const int max_athletes_per_discipline = 7;

struct Athlete // stuct za atleta
{
    string number;
    string name;
    int age;
    string country;
    string discipline;
    float best_career_result;
    float best_year_result;
    int wc_participations; // svetovno purvenstvo, uchastiq
    float current_result;  // za poslednata extra zadacha
};

Athlete added_athletes_data[35];

// funkcii za polzvane vuv maina
void AddAthletes(int &current_count) // dobavqna na atleti i sledene na segashniq im broi v masiva
{
    Athlete new_athlete;
    if (max_total_athletes > current_count)
    {
        bool valid_discipline, valid_country;
        random_device rd; // sluchaen nomer na atlet 1 do 35
        mt19937 rng(rd());
        uniform_int_distribution<int> distribution(1, 35);

        new_athlete.number = to_string(distribution(rng));
        cout << "Athlete Number " << new_athlete.number << endl;

        cout << "Enter athlete's name: ";
        cin.ignore();
        getline(cin, new_athlete.name);

        cout << "Enter athlete's age: ";
        cin >> new_athlete.age;

        cout << "Choose athlete's country: 1.Albania, 2.Bosnia and Herzegovina, 3.Bulgaria, 4.Greece, 5.Kosovo, 6.North Macedonia, 7.Montenegro: ";
        while (!valid_country)
        {
            getline(cin, new_athlete.country);
            if (new_athlete.country == "Albania" ||
                new_athlete.country == "Bosnia and Herzegovina" ||
                new_athlete.country == "Bulgaria" ||
                new_athlete.country == "Greece" ||
                new_athlete.country == "Kosovo" ||
                new_athlete.country == "North Macedonia" ||
                new_athlete.country == "Montenegro")
            {
                valid_country = true;
            }
            else if (!valid_country)
            {
                cout << "No such country is available." << endl;
                cout << "Enter a valid country: \n";
                cin.clear();
            }
        }

        cout << "Enter the athletes discipline: 200m Sprint, Relay 4x400, Shot Put, High Jump, Triple Jump: ";
        while (!valid_discipline)
        {
            getline(cin, new_athlete.discipline);
            if (new_athlete.discipline == "200m Sprint" ||
                new_athlete.discipline == "Relay 4x400" ||
                new_athlete.discipline == "Shot Put" ||
                new_athlete.discipline == "High Jump" ||
                new_athlete.discipline == "Triple Jump")
            {
                valid_discipline = true;
            }
            else if (!valid_discipline)
            {
                cout << "No such discipline is available" << endl;
                cout << "Enter a valid discipline: \n";
                cin.clear();
            }
        }

        cout << "Enter athlete's best career results: ";
        cin >> new_athlete.best_career_result;

        cout << "Enter athlete's best year results: ";
        cin >> new_athlete.best_year_result;

        cout << "Enter athlete's world championship participations: ";
        cin >> new_athlete.wc_participations;

        cout << "Athlete has been added successfully. \n";
        added_athletes_data[current_count] = new_athlete;
        current_count++;
    }

    else if (max_total_athletes <= current_count)
    {
        cout << "Error: You have reached the max allowed athletes \n";
    }
}

void DisplayAthletes(Athlete added_athletes_data[], int current_count)
{
    if (current_count <= 0) // proverka dali ima vuvedeni atleti po nachalo
    {
        cout << "No athletes have been added yet" << endl;
        return; // vrushta se v nachaloto ako nqma atleti
    }
    else
    {
        cout << "Displaying all participating athletes..." << endl;
        for (int i = 0; i < current_count; i++)
        {
            cout << "-----------------------------------------------------" << endl;
            cout << "Number: " << added_athletes_data[i].number << endl;
            cout << "Name: " << added_athletes_data[i].name << endl;
            cout << "Age: " << added_athletes_data[i].age << endl;
            cout << "Country: " << added_athletes_data[i].country << endl;
            cout << "Discipline: " << added_athletes_data[i].discipline << endl;
            cout << "Best Career Result: " << added_athletes_data[i].best_career_result << endl;
            cout << "Best Year Result: " << added_athletes_data[i].best_year_result << endl;
            cout << "WC Participations: " << added_athletes_data[i].wc_participations << endl;
            cout << "-----------------------------------------------------" << endl;
        }
    }
}

// izvejdane na atleta s nai mnogo uchastiq v svetovnoto purvenstvo
void Most_Participations(Athlete added_athletes_data[], int current_count)
{
    int most_part = 0;
    if (current_count <= 0) // proverka dali ima vuvedeni atleti po nachalo, ako nqma se vrushta v nachaloto
    {
        return;
    }

    else // ako ima dobaveni atleti koda produljava tuk
    {
        cout << "The athlete with the most world championship participations is: \n";
        for (int i = 0; i < current_count; i++) // ako ima atleti produljavame tuk
        {
            if (added_athletes_data[i].wc_participations > added_athletes_data[most_part].wc_participations)
            {
                most_part = i;
            }
        }
        cout << "-----------------------------------------------------" << endl;
        cout << "Name: " << added_athletes_data[most_part].name << endl;
        cout << "Number: " << added_athletes_data[most_part].number << endl;
        cout << "World Championship Participations: " << added_athletes_data[most_part].number << endl;
        cout << "-----------------------------------------------------" << endl;
    }
}

// tursene na atleti ot dadeni durjavi
void Search_By_Country(Athlete added_athletes_data[], int current_count)
{
    string country_search;
    bool found_country = false;
    if (current_count <= 0) // proverka dali ima vuvedeni atleti po nachalo, ako nqma se vrushta v nachaloto
    {
        cout << "No athletes have been added yet" << endl;
        return; // proverka dali ima dobaveni atleti
    }

    else // ako ima dobaveni atleti produljava kum tozi kod
    {
        cout << "Enter the country you wish to search for: \n";
        cin >> country_search;
        for (int i = 0; i < current_count; i++)
        {
            if (country_search == added_athletes_data[i].country)
            {
                cout << "-----------------------------------------------------" << endl;
                cout << "Number: " << added_athletes_data[i].number << endl;
                cout << "Name: " << added_athletes_data[i].name << endl;
                cout << "Age: " << added_athletes_data[i].age << endl;
                cout << "Discipline: " << added_athletes_data[i].discipline << endl;
                cout << "Best Career Result: " << added_athletes_data[i].best_career_result << endl;
                cout << "Best Year Result: " << added_athletes_data[i].best_year_result << endl;
                cout << "WC Participations: " << added_athletes_data[i].wc_participations << endl;
                cout << "-----------------------------------------------------" << endl;
                found_country = true;
            }
            else if (!found_country)
            {
                cout << "There are no athletes from " << country_search << endl;
                return;
            }
        }
    }
}

// sortirane po azbuchen red, bez da se izvejda na ekrana
void Sort_By_Alphabetical_Order(Athlete added_athletes_data[], int current_count)
{
    int tempswap;
    for (int i = 0; i < current_count; i++)
    {
        for (int j = 0; j << current_count; j ++)
        {
            added_athletes_data[i].discipline = tempswap;
            added_athletes_data[i].discipline = added_athletes_data[j].discipline;
            added_athletes_data[j].discipline = tempswap;
        }
    }
}

/*

//podmenu dopulnitelna podtocka - case 4
void Submenu()
{

}

//izvejdane na sportisti po disciplini podredeni po nai dobriq si godishen rezultat
//BYR = best year result
void Sort_Athletes_By_BYR 

//Търсене и извеждане на спортистите до въведена възраст подредени по име;
void Search_Till_Age()


void DOPULNENIQ YIPE

void Load_From_File()

void Save_To_File()
*/

// glavna funkciq za pokazvane na menuto i opciite v nego
void DisplayMenu()
{
    cout << "World Athletics Championship Information System \n";
    cout << "1. Add Athletes \n";
    cout << "2. Display all available athletes \n";
    cout << "3. Search for athletes by their country \n";
    cout << "4. Extra athlete information \n";
    cout << "5. Ongoing tournament \n";
    cout << "6. Save to File \n";
    cout << "7. Exit the program \n";
}

void CloseProgram()
{
    int Input;
    cout << "Do you want to exit the program?" << endl;
    cout << "0 - no, 1 - yes" << endl;
    cin >> Input;

    if (Input == 0)
    {
        return; // Nishto ne stava, programata se vrushta v menuto
    }

    else if (Input == 1) // zatvarq programata
    {
        cout << "Exiting the program..." << endl;
        exit(0);
    }
    else // ne stava nishto, dava opciqta da se opita otnovo
    {
        cout << "Invalid input. Please enter 0 or 1." << endl;
        CloseProgram();
    }
}

int main()
{
    int user_choice, current_count = 0;
    Athlete athletes[max_total_athletes]; // struct AThlete svurzana s masiv athletes s razmer maxtotalathletes
    do
    {
        DisplayMenu();
        cout << "Enter your choice: ";
        cin >> user_choice;
        switch (user_choice)
        {
        case 1:
        {
            int n;
            cout << "Enter the amount of athletes you want to add" << endl;
            cin >> n;
            if (n < max_total_athletes)
                for (int i = 0; i < n; i++)
                {
                    AddAthletes(current_count);
                }
            break;
        }

        case 2:
        {
            DisplayAthletes(added_athletes_data, current_count);
            Most_Participations(added_athletes_data, current_count);
            break;
        }

        case 3:
        {
            Search_By_Country(added_athletes_data, current_count);
            break;
        }

        case 4:
        {
            break;
        }

        case 5:
        {
            break;
        }

        case 6:
        {
            break;
        }

        case 7:
            CloseProgram();
            break;
        }
    } while (user_choice != 7);
    return 0;
}