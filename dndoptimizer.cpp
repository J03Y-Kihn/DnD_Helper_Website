#include <iostream>
#include <vector>
#include <bits/stdc++.h> // for sort()
#include <string.h>

using namespace std;

//Functions
void class_evaluations();
void outputRanking(vector<pair<double, string>> ranks);

double check_artificer();
double check_barb();
double check_bard();
double check_bloodhunter(); //wait to do this later since not official dnd
double check_cleric();
double check_druid();
double check_fighter();
double check_monk();
double check_paladin();
double check_ranger();
double check_rogue();
double check_sorcerer();
double check_warlock();
double check_wizard();


//Global Variables
double STRENGTH, DEXTERITY, CONSTITUTION, INTELLIGENCE, WISDOM, CHARISMA;

int main(int agrc, char* argv[]){

    cout << "Welcome to the D&D 5e Class Picker Helper!" << endl;
    bool continues = true;
    while(continues){
        //add textfile functionality?
        
        bool correct = false;
        string response;
        while(!correct){
            cout << "Input your character's stats in this order:  STR DEX CON INT WIS CHA" << endl;
            cin >> STRENGTH;
            cin >> DEXTERITY;
            cin >> CONSTITUTION;
            cin >> INTELLIGENCE;
            cin >> WISDOM;
            cin >> CHARISMA;
            if(STRENGTH < 21 && DEXTERITY < 21 && CONSTITUTION < 21 && INTELLIGENCE < 21 && WISDOM < 21 && CHARISMA < 21){
                if(STRENGTH > 0 && DEXTERITY > 0 && CONSTITUTION > 0 && INTELLIGENCE > 0 && WISDOM > 0 && CHARISMA > 0){
                    correct = true;
                }
                else{
                    cout << "!ERROR: One of your stats is lower than 1! Try Again." << endl;
                }
            }
            else{
                cout << "!ERROR: One of your stats is higher than 20! Try Again." << endl;
            }
        }
        class_evaluations();

        while(response !=  "n" && response != "y"){
            cout << "Would you like to enter in stats again? (y/n)" << endl;
            cin >>response;
            if(response == "n"){
                continues = false;
            }
        }       
    }


    return 1;
}

//functionality to only check specific classes?

void class_evaluations(){

    vector<pair<double, string>> ranking;

    //calculating the value for all the classes
    double temp1 = check_artificer();
    ranking.push_back(make_pair(temp1, "Artificer"));
    double temp2 = check_barb();
    ranking.push_back(make_pair(temp2, "Barbarian"));
    double temp3 = check_bard();
    ranking.push_back(make_pair(temp3, "Bard"));
    double temp4 = check_bloodhunter(); //wait to do this later since not official dnd
    ranking.push_back(make_pair(temp4, "BloodHunter"));
    double temp5 = check_cleric();
    ranking.push_back(make_pair(temp5, "Cleric"));
    double temp6 = check_druid();
    ranking.push_back(make_pair(temp6, "Druid"));
    double temp7 = check_fighter();
    ranking.push_back(make_pair(temp7, "Fighter"));
    double temp8 = check_monk();
    ranking.push_back(make_pair(temp8, "Monk"));
    double temp9 = check_paladin();
    ranking.push_back(make_pair(temp9, "Paladin"));
    double temp10 = check_ranger();
    ranking.push_back(make_pair(temp10, "Ranger"));
    double temp11 = check_rogue();
    ranking.push_back(make_pair(temp11, "Rogue"));
    double temp12 = check_sorcerer();
    ranking.push_back(make_pair(temp12, "Sorcerer"));
    double temp13 = check_warlock();
    ranking.push_back(make_pair(temp13, "Warlock"));
    double temp14 = check_wizard();
    ranking.push_back(make_pair(temp14, "Wizard"));


    //sorting the classes based on highest value
    sort(ranking.begin(), ranking.end(), greater<pair<double, string>>());

    outputRanking(ranking);

}

void outputRanking(vector<pair<double, string>> ranks){

    cout << "Here are the result for our calculation.  Based on the stats provided this is the order that we would pick classes.\nThe numbers next to each class is how well each class is rated." << endl;
    //outputing the ranking
    for(int i=0; i<ranks.size(); i++){
        cout << ranks.at(i).second << " " << ranks.at(i).first << endl;
    }
}
//possibly save the multipliers in a global variable and reduce this to a singular function
//can also, help reduce length of eval function

// formula is Sum(stat/10 *mult)
//maybe change sum to the average of the sum?

//new version is taking top 2 stats only
//add
double check_artificer(){
    //return (STRENGTH/10)*1 + (DEXTERITY/10)*2 + (CONSTITUTION/10)*2 + (INTELLIGENCE/10)*2.5 + (WISDOM/10)*1 + (CHARISMA/10)*1;
    return (INTELLIGENCE/10*2+DEXTERITY/10*1.5)/2;
}
double check_barb(){
    //return ((STRENGTH/10)*2.5 + CONSTITUTION/10*2 + DEXTERITY/10*1.5 + INTELLIGENCE/10*1 + WISDOM/10*1 + CHARISMA/10*1);
    return (STRENGTH/10*2+CONSTITUTION/10*1.5)/2;
}
double check_bard(){
    //return (STRENGTH/10)*1 + CONSTITUTION/10*2 + DEXTERITY/10*2 + INTELLIGENCE/10*1.5 + WISDOM/10*1.5 + CHARISMA/10*2.5;
    return (CHARISMA/10*2+DEXTERITY/10*1.5)/2;
}
double check_bloodhunter(){
    //return (STRENGTH/10)*1 + CONSTITUTION/10*2 + DEXTERITY/10*2.5 + INTELLIGENCE/10*1 + WISDOM/10*2 + CHARISMA/10*1;
    return (DEXTERITY/10*2+CONSTITUTION/10*1.5)/2;
}
double check_cleric(){
    //return (STRENGTH/10)*2 + CONSTITUTION/10*2 + DEXTERITY/10*1 + INTELLIGENCE/10*1.5 + WISDOM/10*2.5 + CHARISMA/10*1;
    return (WISDOM/10*2+CONSTITUTION/10*1.5)/2;
}
double check_druid(){
    //return (STRENGTH/10)*1 + CONSTITUTION/10*2 + DEXTERITY/10*2 + INTELLIGENCE/10*1.5 + WISDOM/10*2.5 + CHARISMA/10*1;
    return (WISDOM/10*2+CONSTITUTION/10*1.5)/2;
}
double check_fighter(){
    //return (STRENGTH/10)*2.5 + CONSTITUTION/10*2 + DEXTERITY/10*1 + INTELLIGENCE/10*1 + WISDOM/10*1.5 + CHARISMA/10*1;
    return (STRENGTH/10*2+DEXTERITY/10*1.5)/2;
}
double check_monk(){
    //return (STRENGTH/10)*1 + CONSTITUTION/10*2 + DEXTERITY/10*2.5 + INTELLIGENCE/10*1 + WISDOM/10*2 + CHARISMA/10*1;
    return (DEXTERITY/10*2+WISDOM/10*1.5)/2;  //double check this was tied between wis and con
}
double check_paladin(){ 
    //return (STRENGTH/10)*2.5 + CONSTITUTION/10*2 + DEXTERITY/10*1 + INTELLIGENCE/10*1 + WISDOM/10*1.5 + CHARISMA/10*2.5;
    return (CHARISMA/10*2+CONSTITUTION/10*1.5)/2;
}
double check_ranger(){
    //return (STRENGTH/10)*1 + CONSTITUTION/10*2 + DEXTERITY/10*2.5 + INTELLIGENCE/10*1.5 + WISDOM/10*2 + CHARISMA/10*1;
    return (DEXTERITY/10*2+WISDOM/10*1.5)/2;
}
double check_rogue(){
    //return (STRENGTH/10)*1 + CONSTITUTION/10*2 + DEXTERITY/10*2.5 + INTELLIGENCE/10*1.5 + WISDOM/10*1.5 + CHARISMA/10*1.5;
    return (DEXTERITY/10*2+CHARISMA/10*1.5)/2;
}
double check_sorcerer(){
    //return (STRENGTH/10)*1 + CONSTITUTION/10*2 + DEXTERITY/10*2 + INTELLIGENCE/10*1.5 + WISDOM/10*1.5 + CHARISMA/10*2.5;
    return (CHARISMA/10*2+CONSTITUTION/10*1.5)/2;
}
double check_warlock(){
    //return (STRENGTH/10)*1 + CONSTITUTION/10*2 + DEXTERITY/10*2 + INTELLIGENCE/10*1 + WISDOM/10*1.5 + CHARISMA/10*2.5;
    return (CHARISMA/10*2+CONSTITUTION/10*1.5)/2;
}
double check_wizard(){
    //return (STRENGTH/10)*1 + CONSTITUTION/10*2 + DEXTERITY/10*2 + INTELLIGENCE/10*2.5 + WISDOM/10*1.5 + CHARISMA/10*1;
    return (INTELLIGENCE/10*2+DEXTERITY/10*1.5)/2;
}