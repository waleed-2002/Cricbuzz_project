#include<iostream> 
#include<string>			//string library
#include<fstream>		    //file operation library
#include<ctime>

using namespace std;

class Player //abstract player class
{
protected:
	//varriables as required
	string name;
	int shirt_no;
	double average;
	int ranking_T20;
	int ranking_ODI;
	int ranking_TEST;
	int total_runs;
	int matches_played;
	int total_wickets;

public:
	// making pure virtual function by assigning zero value to them
	virtual void addPlayer() = 0;
	virtual void removePlayer() = 0;
	virtual	void searchPlayer() = 0;
	virtual void updatePlayer() = 0;
};

class Team :public Player
{
protected:
	//member variables
	string team_Name;
	string Team_Ranking;
	int total_Players;
	int Matches_won;
	int Matches_lost;
	string team_Captain;
	string team_Coach;
	string Admin_Username;
	string Admin_Password;
	int count_player;
public:
	void addPlayer() //func to add player
	{
		char choice;
		int i = 0;
		ofstream player_data("Players Data.txt", ios::app); //using append to right after previous text 
		ofstream rank("Ranking.txt", ios::app);

		cout << "\n\t----Welcome to Add Player Section----\n\n";
		do
		{
			count_player++;
			//taking data
			cout << "Enter Player Name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter Shirt No: ";
			cin >> shirt_no;
			cout << "Enter Average: ";
			cin >> average;
			cout << "Enter ICC Ranking in T20 Format: ";
			cin >> ranking_T20;
			cout << "Enter ICC Ranking in ODI Format: ";
			cin >> ranking_ODI;
			cout << "Enter ICC Ranking in Test Match Format: ";
			cin >> ranking_TEST;
			cout << "Enter Total Runs: ";
			cin >> total_runs;
			cout << "Enter Matches Played: ";
			cin >> matches_played;
			cout << "Enter Total Wickets: ";
			cin >> total_wickets;

			if (rank.is_open()) //check for file opening
			{
				rank << name << endl << ranking_T20 << endl << ranking_ODI << endl << ranking_TEST << endl;
			}
			else
			{
				cout << "Ranking File is not opened!\n";
			}

			if (player_data.is_open())  //check for file opening
			{
				//storing data on file
				player_data << name << endl << shirt_no << endl << average << endl << ranking_T20 << endl;
				player_data << ranking_ODI << endl << ranking_TEST << endl << total_runs << endl;
				player_data << matches_played << endl << total_wickets << endl /*<< bat_style << endl << bowl_style << endl*/;
			}
			else
			{
				cout << "Unable to create Player file\n";
			}
			cout << "Do  you want to Add more player (Y/N): "; //choice to add more player
			cin >> choice;

		} while (choice == 'Y' || choice == 'y');

		//closing files
		player_data.close();
		rank.close();
	}
	void removePlayer() //func to remove player
	{
		int i = 0;
		string temp_name, compare_name;//storing user 
		cout << "\n\t----Welcome to Remove Player Section----\n\n";
		cout << "Enter Player name: ";
		cin.ignore();
		getline(cin, temp_name); //taking player name whom data will delete

		ofstream temp("text.txt"); //opening file
		ifstream removePlayer("Players Data.txt"); //opening file
		int count_line = 0; //var to count line of record to be deleted

		while (!removePlayer.eof()) //loop to search player by name
		{
			getline(removePlayer, compare_name); //reading from file
			if (compare_name == temp_name)
			{
				while (count_line != 11) // loop to ignore search player data
				{
					count_line++;
					getline(removePlayer, compare_name);
				}
			}
			if (!removePlayer.eof()) //check for prevent duplicate entry
			{
				temp << compare_name << endl; //Writing on file
			}
			//i++;
		}
		temp.close(); //closing temporary file
		removePlayer.close(); //closing original file

		remove("Players Data.txt"); //removing original file that contain all data
		rename("text.txt", "Players Data.txt"); //renaming file 2333333333333

	}
	void searchPlayer() //func to search player
	{
		string temp_name, compare_data;//storing user 
		cout << "\n\t----Welcome to Search Player Section----\n\n";
		cout << "Enter Player name: ";
		cin.ignore();
		getline(cin, temp_name); //taking player name whom data will search
		ifstream removePlayer("Players Data.txt");
		int count_line = 0; //var to count line of record to be searched
		while (!removePlayer.eof()) //loop to search player by name
		{
			getline(removePlayer, compare_data); //reading from file
			if (compare_data == temp_name)
			{
				int i = 0;
				while (count_line != 8) // loop to ignore search player data
				{
					count_line++;
					if (i == 0)
					{
						cout << "\nName: " << compare_data << endl;
					}
					i++;
					getline(removePlayer, compare_data);

					if (i == 1)
					{
						cout << "Shirt No: ";
					}
					else if (i == 2)
					{
						cout << "Average: ";
					}
					else if (i == 3)
					{
						cout << "ICC Ranking in T20 Format: ";
					}
					else if (i == 4)
					{
						cout << "ICC Ranking in ODI Format: ";
					}
					else if (i == 5)
					{
						cout << "ICC Ranking in Test Format: ";
					}
					else if (i == 6)
					{
						cout << "Total Runs: ";
					}
					else if (i == 7)
					{
						cout << "Matches Played: ";
					}
					else if (i == 8)
					{
						cout << "Total Wickets: ";
					}

					cout << compare_data << endl;
				}
			}
		}
		removePlayer.close();
	}
	void updatePlayer() //func to update player
	{
		int choice = 0;
		string temp_name, compare_name;//storing user 
		cout << "\n\t----Welcome to Update Player Section----\n\n";
		cout << "Enter Player name: ";
		cin.ignore();
		getline(cin, temp_name); //taking player name whom data will delete

		ofstream temp("text.txt"); //opening file
		ifstream updatePlayer("Players Data.txt"); //opening file
		int count_line = 0; //var to count line of record to be deleted

		while (!updatePlayer.eof()) //loop to search player by name
		{
			getline(updatePlayer, compare_name); //reading from file
			if (compare_name == temp_name)
			{
				cout << "\nWhich Data you want to edit:\n\n";
				cout << "Press 1 for Player Name\nPress 2 for Shirt No\nPress 3 for Average\nPress 4 for ICC Ranking in T20 Format\n";
				cout << "Press 5 for ICC Ranking in ODI Format\nPress 6 for ICC Ranking in Test Match Format\nPress 7 for Total Runs\n";
				cout << "Press 8 for Matches Played\nPress 9 for Total Wickets\nPress 10 for Bat style\nPress 11 for Bowl style\n\nChoice: ";
				cin >> choice;
				cout << endl;
				switch (choice)
				{
				case 1:
					cout << "Enter Player Name: ";
					cin.ignore();
					getline(cin, name);
					getline(updatePlayer, compare_name);
					temp << name << endl;
					count_line++;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 2:
					cout << "Enter Shirt No: ";
					cin >> shirt_no;
					temp << compare_name << endl;
					temp << shirt_no << endl;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 3:
					cout << "Enter Average: ";
					cin >> average;
					for (int i = 0; i < 2; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;
					}
					temp << average << endl;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 4:
					cout << "Enter ICC Ranking in T20 Format: ";
					cin >> ranking_T20;
					for (int i = 0; i < 3; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;
					}
					temp << ranking_T20 << endl;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 5:
					cout << "Enter ICC Ranking in ODI Format: ";
					cin >> ranking_ODI;
					for (int i = 0; i < 4; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;
					}
					temp << ranking_ODI << endl;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 6:
					cout << "Enter ICC Ranking in Test Match Format: ";
					cin >> ranking_TEST;
					for (int i = 0; i < 5; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;			
					}
					temp << ranking_TEST;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 7:
					cout << "Enter Total Runs: ";
					cin >> total_runs;
					for (int i = 0; i < 6; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;
					}
					temp << total_runs << endl;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 8:
					cout << "Enter Matches Played: ";
					cin >> matches_played;
					for (int i = 0; i < 7; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;
					}
					temp << matches_played << endl;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 9:
					cout << "Enter Total Wickets: ";
					cin >> total_wickets;
					for (int i = 0; i < 8; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;
					}
					temp << total_wickets << endl;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 10:
					for (int i = 0; i < 9; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;
					}
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 11:
					/*cout << "Enter Bowl style: ";
					cin >> bowl_style;*/
					for (int i = 0; i < 10; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;
					}
					/*temp << bowl_style << endl;*/
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				default:

					break;
				}
			}

			if (!updatePlayer.eof()) //check for prevent duplicate entry
			{
				temp << compare_name << endl; //Writing on file
			}
			//i++;
		}
		temp.close(); //closing temporary file
		updatePlayer.close(); //closing original file

		remove("Players Data.txt"); //removing original file that contain all data
		rename("text.txt", "Players Data.txt"); //renaming file

	}
	void updateCaptain() //func to update captain
	{
		string temp_name;//storing user 

		cout << "\n\t----Welcome to Update Captain Section----\n\n";
		cout << "Enter Current Captain name: ";
		cin.ignore();
		getline(cin, team_Captain); //taking player name whom data will delete

		ofstream temp("text.txt"); //opening file
		ifstream updatecap("captains.txt"); //opening file
		int count_line = 0; //var to count line of record to be deleted
		string new_cap;

		while (!updatecap.eof())
		{
			getline(updatecap, temp_name);

			if (temp_name == team_Captain)
			{
				cout << "Enter New Captain: ";
				cin.ignore();
				getline(cin, new_cap);
				getline(updatecap, temp_name);
				temp << new_cap << endl;
				count_line++;
			}
			if (!updatecap.eof())
			{
				temp << temp_name << endl;
			}
		}
		temp.close(); //closing temporary file
		updatecap.close(); //closing original file

		if (count_line == 0) //if wrong input
			cout << "No Result Found!\n";
		 

		remove("captains.txt"); //removing original file that contain all data
		rename("text.txt", "captains.txt"); //renaming file
	}
	void updateCoach() //func to update coach
	{
		string temp_name;//storing user 

		cout << "\n\t----Welcome to Update Coach Section----\n\n";
		cout << "Enter Current Coach name: ";
		cin.ignore();
		getline(cin, team_Coach); //taking player name whom data will delete

		ofstream temp("text.txt"); //opening file
		ifstream updatecoach("coaches.txt"); //opening file
		int count_line = 0; //var to count line of record to be deleted
		string new_coach;

		while (!updatecoach.eof())
		{
			getline(updatecoach, temp_name);

			if (temp_name == team_Coach)
			{
				cout << "Enter New Coach: ";
				cin.ignore();
				getline(cin, new_coach);
				getline(updatecoach, temp_name);
				temp << new_coach << endl;
				count_line++;
			}
			if (!updatecoach.eof())
			{
				temp << temp_name << endl;
			}
		}

		temp.close(); //closing temporary file
		updatecoach.close(); //closing original file

		if (count_line == 0) //if wrong input
			cout << "No Result Found!\n";

		remove("coaches.txt"); //removing original file that contain all data
		rename("text.txt", "coaches.txt"); //renaming file
	}
	void displayTeam() //func to display team
	{
		string temp_name;
		cout << "\n\t----Welcome to Display Teams Section----\n\n";
		int count_line = 0;
		cout << "Enter Name of the team: ";
		cin.ignore();
		getline(cin, team_Name);
		ifstream team("teams.txt");
		while (!team.eof())
		{
			getline(team, temp_name);
			if (team_Name == temp_name)
			{
				while (count_line != 15) // loop to display team data
				{
					count_line++;
					getline(team, temp_name);
					cout << count_line << ". " << temp_name << endl;
				}
			}
		}
		team.close();
	} 
};


class Match : public Team
{
protected:
	string team1;
	string team2;
	string date;
	string venue;
	string match_type;
	string tournament_Name;
	string commentators[2];
	string Umpires[2];
	string Match_status;
	string weather;   
public:
	void conductMatch()
	{
		int ch = 0, i = 0;
		int count_line = 0;
		cout << "Press 1 if you want to Conduct an already Schedule Match\nPress 2 if you want to schedule a new match\n\nChoice: ";
		cin >> ch;
		if (ch == 1)
		{
			ifstream conduct("upcoming.txt");

			cout << "\n---Upcoming Matches---\n\n";
			string extract;


			while (!conduct.eof()) // loop to ignore search player data
			{
				getline(conduct, extract);
				count_line++;
				if (i == 0)
				{
					cout << " " << extract << endl;
				}
				else if (i == 1)
				{
					cout << "\2nd Team:";
				}
				else if (i == 2)
				{
					cout << "\nDate: ";
				}
				else if (i == 3)
				{
					cout << "Venue: ";
				}
				else if (i == 5)
				{
					for (int i = 0; i < 2; i++)
					{
						cout << i + 1 << " Commentator: ";
						getline(conduct, extract);
						cout << extract << endl;
					}
					for (int i = 0; i < 2; i++)
					{
						cout << "Enter " << i + 1 << " Umpires: ";
						getline(conduct, extract);
						cout << extract << endl;
					}
				}
				else if (i == 5)
				{
					cout << "Weather: ";
				}

				cout << extract << endl;
			}
			conduct.close(); //closing file
		}
		else if (ch == 2)
		{
			scheduleMatch(); //func call
		}
		else
		{
			cout << "Invalid Choice!\n";
		}

	} // properly functioning
	void scheduleMatch()
	{
		int ch = 0;
		cout << "\n\t----Welcome to Schedule Match Section----\n\n";
		cout << "Press 1 for Single Match\nPress 2 for Tournament\n\nChoice: ";
		cin >> ch;

		string team[9] = { "Pakistan","India","New Zealand","South Africa","Bangladesh","Australia","West Indies","England","Sri-lanka" };

		if (ch == 1)
		{
			cout << "\nEnter Match Type(ODI, T20, Test)\n\nChoice: ";
			cin >> match_type;

			if (match_type == "T20" || match_type == "t20")
			{
				cout << "\n\t---Available Teams For T20---\n\n";
				int z = 0;

				if (z == 0) //loops for random teams
				{
					for (int i = 0; i < 5; i++)
					{
						cout << team[i] << endl;
					}
					z++;
				}
				else
				{
					for (int i = 0; i > 4; i--)
					{
						cout << team[i] << endl;
					}
					z = 0;
				}
				cout << "\n\nEnter 1st Team  Name from above Menu: ";
				cin.ignore();
				getline(cin, team1);

				cout << "\nEnter 2nd Team  Name from above Menu: ";
				getline(cin, team2);

				cout << "Enter Date (DD-MM-YYYY): ";
				getline(cin, date);

				cout << "Enter Venue: ";
				getline(cin, venue);

				for (int i = 0; i < 2; i++)
				{
					cout << "Enter " << i + 1 << " Commentator: ";
					cin.ignore();
					getline(cin, commentators[i]);
				}

				for (int i = 0; i < 2; i++)
				{
					cout << "Enter " << i + 1 << " Umpires: ";
					cin.ignore();
					getline(cin, Umpires[i]);
				}

				cout << "Enter Match Status (Current/Recent): ";
				getline(cin, Match_status);

				cout << "Weather: ";
				cin >> weather;

				ofstream M("ODI-Matches.txt", ios::app);
				ofstream recent("Recent.txt", ios::app);
				ofstream upcome("upcoming.txt", ios::app);

				if (M.is_open())
				{
					M << team1 << endl << team2 << endl << date << endl << venue << endl  /*sitting_capacity << endl*/;
					for (int i = 0; i < 2; i++)
					{
						M << commentators[i] << endl;
					}
					for (int i = 0; i < 2; i++)
					{
						M << Umpires[i] << endl;
					}
					M << Match_status << endl << weather << endl;
				}
				if (Match_status == "Recent" || Match_status == "recent") //check for storing data in recent or upcoming
				{
					recent << team1 << endl << team2 << endl << date << endl << venue << /*endl << sitting_capacity <<*/ endl;
					for (int i = 0; i < 2; i++)
					{
						recent << commentators[i] << endl;
					}
					for (int i = 0; i < 2; i++)
					{
						recent << Umpires[i] << endl;
					}
					recent << Match_status << endl << weather << endl;
				}
				else
				{
					upcome << team1 << endl << team2 << endl << date << endl << venue << endl /*<< sitting_capacity << endl*/;
					for (int i = 0; i < 2; i++)
					{
						upcome << commentators[i] << endl;
					}
					for (int i = 0; i < 2; i++)
					{
						upcome << Umpires[i] << endl;
					}
					upcome << Match_status << endl << weather << endl;
				}
				//closing files
				M.close();
				recent.close();
				upcome.close();
			}
			else if (match_type == "ODI")
			{
				cout << "\n\t---Available Teams For ODI---\n\n";
				int z = 0;

				if (z == 0) //loops for random teams
				{
					for (int i = 0; i < 5; i++)
					{

						cout << team[i] << endl;
					}
					z++;
				}
				else
				{
					for (int i = 0; i > 4; i--)
					{
						cout << team[i] << endl;
					}
					z = 0;
				}
				cout << "\n\nEnter 1st Team  Name from above Menu: ";
				cin.ignore();
				getline(cin, team1);

				cout << "\nEnter 2nd Team  Name from above Menu: ";
				getline(cin, team2);

				cout << "Enter Date (DD-MM-YYYY): ";
				getline(cin, date);

				cout << "Enter Venue: ";
				getline(cin, venue);

				/*cout << "Enter Sitting Capacity: ";
				cin >> sitting_capacity;*/

				for (int i = 0; i < 2; i++)
				{
					cout << "Enter " << i + 1 << " Commentator: ";
					cin.ignore();
					getline(cin, commentators[i]);
				}

				for (int i = 0; i < 3; i++)
				{
					cout << "Enter " << i + 1 << " Umpires: ";
					cin.ignore();
					getline(cin, Umpires[i]);
				}

				cout << "Enter Match Status (Current/Recent): ";
				getline(cin, Match_status);

				cout << "Weather: ";
				cin >> weather;

				ofstream M("ODI-Matches.txt", ios::app);
				ofstream recent("Recent.txt", ios::app);
				ofstream upcome("upcoming.txt", ios::app);

				if (M.is_open())
				{
					M << team1 << endl << team2 << endl << date << endl << venue << endl /*<< sitting_capacity << endl*/;
					for (int i = 0; i < 2; i++)
					{
						M << commentators[i] << endl;
					}
					for (int i = 0; i < 3; i++)
					{
						M << Umpires[i] << endl;
					}
					M << Match_status << endl << weather << endl;
				}
				if (Match_status == "Recent" || Match_status == "recent") //check for storing data in recent or upcoming
				{
					recent << team1 << endl << team2 << endl << date << endl << venue << endl/* << sitting_capacity << endl*/;
					for (int i = 0; i < 2; i++)
					{
						recent << commentators[i] << endl;
					}
					for (int i = 0; i < 3; i++)
					{
						recent << Umpires[i] << endl;
					}
					recent << Match_status << endl << weather << endl;
				}
				else
				{
					upcome << team1 << endl << team2 << endl << date << endl << venue << endl /*<< sitting_capacity << endl*/;
					for (int i = 0; i < 2; i++)
					{
						upcome << commentators[i] << endl;
					}
					for (int i = 0; i < 3; i++)
					{
						upcome << Umpires[i] << endl;
					}
					upcome << Match_status << endl << weather << endl;
				}
				//closing files
				M.close();
				recent.close();
				upcome.close();
			}
			else if (match_type == "Test")
			{
				cout << "\n\t---Available Teams For Test---\n\n";
				int z = 0;

				if (z == 0) //loops for random teams
				{
					for (int i = 0; i < 5; i++)
					{
						i * 2;
						cout << team[i] << endl;
					}
					z++;
				}
				else
				{
					for (int i = 0; i > 4; i--)
					{
						cout << team[i] << endl;
					}
					z = 0;
				}
				cout << "\n\nEnter 1st Team  Name from above Menu: ";
				cin.ignore();
				getline(cin, team1);

				cout << "\nEnter 2nd Team  Name from above Menu: ";
				getline(cin, team2);

				cout << "Enter Date (DD-MM-YYYY): ";
				getline(cin, date);

				cout << "Enter Venue: ";
				getline(cin, venue);

				/*cout << "Enter Sitting Capacity: ";
				cin >> sitting_capacity;*/

				for (int i = 0; i < 2; i++)  //loop to take both commentators in file
				{
					cout << "Enter " << i + 1 << " Commentator: ";
					cin.get();
					getline(cin, commentators[i]);
				}

				for (int i = 0; i < 3; i++) //loop to take all 3 umpires in file
				{
					cout << "Enter " << i + 1 << " Umpires: ";
					cin.get();
					getline(cin, Umpires[i]);
				}

				cout << "Enter Match Status (Current/Recent): ";
				getline(cin, Match_status);

				cout << "Weather: ";
				cin >> weather;

				ofstream M("Test-Matches.txt", ios::app);
				ofstream recent("Recent.txt", ios::app);
				ofstream upcome("upcoming.txt", ios::app);

				if (M.is_open())
				{
					M << team1 << endl << team2 << endl << date << endl << venue << endl /*<< sitting_capacity << endl*/;
					for (int i = 0; i < 2; i++) //loop to add both commentators in file
					{
						M << commentators[i] << endl;
					}
					for (int i = 0; i < 3; i++) //loop to add all 3 umpires in file
					{
						M << Umpires[i] << endl;
					}
					M << Match_status << endl << weather << endl;
				}
				if (Match_status == "Recent" || Match_status == "recent") //check for storing data in recent or upcoming
				{
					recent << team1 << endl << team2 << endl << date << endl << venue << endl /*<< sitting_capacity << endl*/;
					for (int i = 0; i < 2; i++)
					{
						recent << commentators[i] << endl;
					}
					for (int i = 0; i < 3; i++)
					{
						recent << Umpires[i] << endl;
					}
					recent << Match_status << endl << weather << endl;
				}
				else
				{
					upcome << team1 << endl << team2 << endl << date << endl << venue << endl /*<< sitting_capacity << endl*/;
					for (int i = 0; i < 2; i++)
					{
						upcome << commentators[i] << endl;
					}
					for (int i = 0; i < 3; i++)
					{
						upcome << Umpires[i] << endl;
					}
					upcome << Match_status << endl << weather << endl;
				}
				//closing files
				M.close();
				recent.close();
				upcome.close();
			}
		}
		else if (ch == 2)
		{
			int opt = 0;
			cout << "Press 1 for PSL\nPress 2 for IPL\n\nChoice: ";
			cin >> opt;

			if (ch == 1)
			{
				tournament_Name = "PSL";
				string psl[6] = { "Lahore Qalandar","Karachi Kings","Quetta Qladiator","Multan Sultan","Peshawer Zalmi","Islamabad United" };

				cout << "\n---Team for PSL---\n";
				for (int i = 0; i < 6; i++)
				{
					cout << i + 1 << ". " << psl[i] << endl;
				}

				cout << "\n\nEnter 1st Team  Name from above Menu: ";
				cin.ignore();
				getline(cin, team1);

				cout << "\nEnter 2nd Team  Name from above Menu: ";
				getline(cin, team2);

				cout << "Enter Date (DD-MM-YYYY): ";
				getline(cin, date);

				cout << "Enter Venue: ";
				getline(cin, venue);

				/*cout << "Enter Sitting Capacity: ";
				cin >> sitting_capacity;*/

				for (int i = 0; i < 2; i++)  //loop to take both commentators in file
				{
					cout << "Enter " << i + 1 << " Commentator: ";
					cin.get();
					getline(cin, commentators[i]);
				}

				for (int i = 0; i < 3; i++) //loop to take all 3 umpires in file
				{
					cout << "Enter " << i + 1 << " Umpires: ";
					cin.get();
					getline(cin, Umpires[i]);
				}
				cout << "Weather: ";
				cin >> weather;

				ofstream P("PSL.txt", ios::app);
				ofstream upcome("upcoming.txt", ios::app);

				if (P.is_open()) //writing in psl file
				{
					P << team1 << endl << team2 << endl << date << endl << venue << endl /*<< sitting_capacity << endl*/;
					for (int i = 0; i < 2; i++) //loop to add both commentators in file
					{
						P << commentators[i] << endl;
					}
					for (int i = 0; i < 3; i++) //loop to add all 3 umpires in file
					{
						P << Umpires[i] << endl;
					}
					P << Match_status << endl << weather << endl;
				}
				//writing in upcoming file as well
				upcome << team1 << endl << team2 << endl << date << endl << venue << endl/* << sitting_capacity << endl*/;
				for (int i = 0; i < 2; i++)
				{
					upcome << commentators[i] << endl;
				}
				for (int i = 0; i < 3; i++)
				{
					upcome << Umpires[i] << endl;
				}
				upcome << Match_status << endl << weather << endl;

				upcome.close();
				P.close();

			}
			else if (opt == 2)
			{
				tournament_Name = "IPL";
				string ipl[6] = { "Royal Challenger Banglore","Chennai Super Kings","Mumbai Indians","Sunrise Hyderabad","Kings XI Punjab","Delhi Daredevils" };

				cout << "\n---Team for PSL---\n";
				for (int i = 0; i < 6; i++)
				{
					cout << i + 1 << ". " << ipl[i] << endl;
				}

				cout << "\n\nEnter 1st Team  Name from above Menu: ";
				cin.ignore();
				getline(cin, team1);

				cout << "\nEnter 2nd Team  Name from above Menu: ";
				getline(cin, team2);

				cout << "Enter Date (DD-MM-YYYY): ";
				getline(cin, date);

				cout << "Enter Venue: ";
				getline(cin, venue);

				/*cout << "Enter Sitting Capacity: ";
				cin >> sitting_capacity;*/

				for (int i = 0; i < 2; i++)  //loop to take both commentators in file
				{
					cout << "Enter " << i + 1 << " Commentator: ";
					cin.get();
					getline(cin, commentators[i]);
				}

				for (int i = 0; i < 3; i++) //loop to take all 3 umpires in file
				{
					cout << "Enter " << i + 1 << " Umpires: ";
					cin.get();
					getline(cin, Umpires[i]);
				}
				cout << "Weather: ";
				cin >> weather;

				ofstream P("IPL.txt", ios::app);
				ofstream upcome("upcoming.txt", ios::app);

				if (P.is_open()) //writing in ipl file
				{
					P << team1 << endl << team2 << endl << date << endl << venue << endl /*<< sitting_capacity << endl*/;
					for (int i = 0; i < 2; i++) //loop to add both commentators in file
					{
						P << commentators[i] << endl;
					}
					for (int i = 0; i < 3; i++) //loop to add all 3 umpires in file
					{
						P << Umpires[i] << endl;
					}
					P << weather << endl;
				}
				//writing in upcoming file as well
				upcome << team1 << endl << team2 << endl << date << endl << venue << endl /*<< sitting_capacity << endl*/;
				for (int i = 0; i < 2; i++)
				{
					upcome << commentators[i] << endl;
				}
				for (int i = 0; i < 3; i++)
				{
					upcome << Umpires[i] << endl;
				}
				upcome << weather << endl;

				upcome.close();
				P.close();

			}
			else
			{
				cout << "Invalid choice!\n";
			}
		}
		else
		{
			cout << "Invalid Choice!\n";
		}
	}
	void updateWorldRecords()
	{
		int choice = 0;
		string temp_name, search_name;
		string player;
		bool br2 = false;
		char ch;

		cout << "\n\t----Welcome to Update World Records Section----\n\n";
		do {
			cout << "\nPress 1 Most runs\nPress 2 Highest score\nPress 3 Most sixes\nPress 4 Most fours\nPress 5 Most centuries\nPress 6 Highest batting average\nPress 7 Best batting strike rate\nPress 8 Most wickets\nPress 9 Best bowling avg\nPress 10 Best bowling avg\nPress 11 for Back to main menu\n\nChoice: ";
			cin >> choice;
			if (choice == 11) //check for exit
			{
				break;
			}

			ifstream team("WC-Record.txt"); //openning file
			ofstream temp("text.txt"); //openning file

			if (!team.is_open()) //if not opened
			{
				cout << "Team Ranking File is not opened\n";
			}
			else
			{
				while (!team.eof())
				{
					switch (choice)
					{
					case 1:
						search_name = "Most runs";

						if (temp_name == search_name)
						{
							cout << "Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 2:
						search_name = "Highest score";

						if (temp_name == search_name)
						{
							cout << "Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 3:
						search_name = "Most sixes";

						if (temp_name == search_name)
						{
							cout << "Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 4:
						search_name = "Most fours";

						if (temp_name == search_name)
						{
							cout << "Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 5:
						search_name = "Most centuries";

						if (temp_name == search_name)
						{
							cout << "Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 6:
						search_name = "Highest batting average";

						if (temp_name == search_name)
						{
							cout << "Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 7:
						search_name = "Best batting strike rate";

						if (temp_name == search_name)
						{
							cout << "Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 8:
						search_name = "Most wickets";

						if (temp_name == search_name)
						{
							cout << "Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 9:
						search_name = "Best bowling avg";

						if (temp_name == search_name)
						{
							cout << "Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 10:
						search_name = "Best bowling";

						if (temp_name == search_name)
						{
							cout << "Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;

					default:
						cout << "Invalid Choice!\n";
						break;
					}
					getline(team, temp_name);
					temp << temp_name << endl;
				}

				temp.close(); //closing temporary file
				team.close(); //closing original file

				remove("WC-Record.txt"); //removing original file that contain all data
				rename("text.txt", "WC-Record.txt"); //renaming file

				cout << "Are you want to Update more records(Y/N): ";
				cin >> ch;

			}
		} while (ch == 'Y' || ch == 'y');
	}
	void updateTeamRanking()
	{
		string temp_name, search_name;
		int choice = 0, R = 0;  //R=0 for storing new ranking
		cout << "\n\t----Welcome to Update Team Ranking Section----\n\n";
		cout << "Enter Team Name: ";
		cin.ignore();
		getline(cin, search_name);

		int count_line = 0;

		ifstream team("Team Ranking.txt"); //openning file
		ofstream temp("text.txt"); //openning file

		if (!team.is_open())
		{
			cout << "Team Ranking File is not opened\n";
		}
		else
		{
			while (!team.eof())
			{
				getline(team, temp_name);

				if (temp_name == search_name)
				{
					temp << temp_name << endl;
					cout << "\n\nPress 1 to update T20 Ranking\nPress 2 to update ODI Ranking\nPress 3 to update Test Ranking\nChoice: ";
					cin >> choice;
					switch (choice)
					{
					case 1:
						getline(team, temp_name);
						cout << "Previous T20 Ranking: " << temp_name << endl; //displaying previous ranking
						cout << "Enter New Ranking: ";
						cin >> R; //taking ranking
						temp << R << endl;
						break;
					case 2:
						for (int i = 0; i < 2; i++) //loop to write data before updated one
						{
							getline(team, temp_name);
							if (i < 1)  //check for write data before updated one
							{
								temp << temp_name << endl;
							}
						}
						cout << "Previous ODI Ranking: " << temp_name << endl; //displaying previous ranking
						cout << "Enter New Ranking: ";
						cin >> R; //taking ranking
						temp << R << endl;
						break;
					case 3:
						for (int i = 0; i < 3; i++) //loop to write data before updated one
						{
							getline(team, temp_name);
							if (i < 2)  //check for write data before updated one
							{
								temp << temp_name << endl;
							}
						}
						cout << "Previous Test Ranking: " << temp_name << endl; //displaying previous ranking
						cout << "Enter New Ranking: ";
						cin >> R; //taking ranking
						temp << R << endl;
						break;
					default:
						cout << "Invalid choice!\n";
						break;
					}
					getline(team, temp_name); //updated key!
					count_line++;
				}

				temp << temp_name << endl;
			}

			temp.close(); //closing temporary file
			team.close(); //closing original file

			if (count_line == 0) //if wrong input
				cout << "No Result Found!\n";

			remove("Team Ranking.txt"); //removing original file that contain all data
			rename("text.txt", "Team Ranking.txt"); //renaming file
		}
	}
	void updatePlayerRanking()
	{
		string search_name, temp_name;
		cout << "\n\t----Welcome to Update Player Ranking Section----\n\n";
		cout << "Enter Player name: ";
		cin.ignore();
		getline(cin, search_name);

		ifstream rank("Ranking.txt"); //opening file
		ofstream temp("text.txt"); //opening temporary file

		int R = 0;
		int count_line = 0; //var to count line of record to be deleted
		int choice = 0;
		while (!rank.eof())
		{
			getline(rank, temp_name);

			if (temp_name == search_name)
			{
				temp << temp_name << endl;
				cout << "\n\nPress 1 to update T20 Ranking\nPress 2 to update ODI Ranking\nPress 3 to update Test Ranking\nChoice: ";
				cin >> choice;
				switch (choice)
				{
				case 1:
					getline(rank, temp_name);
					cout << "Previous T20 Ranking: " << temp_name << endl; //displaying previous ranking
					cout << "Enter New Ranking: ";
					cin >> R; //taking ranking
					temp << R << endl;
					break;
				case 2:
					for (int i = 0; i < 2; i++) //loop to write data before updated one
					{
						getline(rank, temp_name);
						if (i < 1)  //check for write data before updated one
						{
							temp << temp_name << endl;
						}
					}
					cout << "Previous ODI Ranking: " << temp_name << endl; //displaying previous ranking
					cout << "Enter New Ranking: ";
					cin >> R; //taking ranking
					temp << R << endl;
					break;
				case 3:
					for (int i = 0; i < 3; i++) //loop to write data before updated one
					{
						getline(rank, temp_name);
						if (i < 2)  //check for write data before updated one
						{
							temp << temp_name << endl;
						}
					}
					cout << "Previous Test Ranking: " << temp_name << endl; //displaying previous ranking
					cout << "Enter New Ranking: ";
					cin >> R; //taking ranking
					temp << R << endl;
					break;
				default:
					cout << "Invalid choice!\n";
					break;
				}
				getline(rank, temp_name); //updated key!
				count_line++;
			}

			temp << temp_name << endl;
		}

		temp.close(); //closing temporary file
		rank.close(); //closing original file

		if (count_line == 0) //if wrong input
			cout << "No Result Found!\n";

		remove("Ranking.txt"); //removing original file that contain all data
		rename("text.txt", "Ranking.txt"); //renaming file
	}
	void displayUpcomingMatches()
	{
		system("color 4F");
		ifstream up("upcoming.txt");
		int count_line = 0, i = 0;
		string extract;
		cout << "\n\t************************\n\n"
			<< "		   	       UPCOMING MATCHES\n\n"
			<< "\t************************\n";

		while (!up.eof()) // loop to ignore search player data
		{
			getline(up, extract);
			if (i == 0)
			{
				if (extract != "\0")
				{
					cout << "\n\tFIRST TEAM			|			 ";
				}
			}
			else if (i == 1)
			{
				cout << "\n\tSECOND TEAM			|			 ";
			}
			else if (i == 2)
			{
				cout << "\n\tDATE				|			 ";
			}
			else if (i == 3)
			{
				cout << "\n\tVENUE				|			 ";
			}
			else if (i == 4)
			{
				cout << "\n\tCAPACITY			|			 ";
			}
			else if (i == 5)
			{
				cout << "\n\tMATCH FORMAT			|			 ";
			}
			else if (i == 6)
			{
				cout << "\n\tCOMMENTATOR			|			 ";
			}
			else if (i == 7)
			{
				cout << "\n\tCOMMENTATOR			|			 ";
			}
			else if (i == 8)
			{
				cout << "\n\t1st UMPIRE			|                        ";
			}
			else if (i == 9)
			{
				cout << "\n\t2nd UMPIRE                      |                        ";
			}
			else if (i == 10)
			{
				cout << "\n\t3rd UMPIRE                      |                        ";
			}
			else if (i == 11)
			{
				cout << "\n\tMATCH STATUS                    |                        ";
			}
			else if (i == 12)
			{
				cout << "\n\tWEATHER                         |                        ";
				i = -1;
			}

			cout << extract << endl;
			if (i == -1)
			{
				cout << "\n\n\t************************\n";
			}
			i++;
		}
		up.close(); //closing file
	}
	void displayRecentMatches()
	{
		system("color 2F");
		ifstream recent("Recent.txt");
		int count_line = 0, i = 0;
		string extract;
		while (!recent.eof()) // loop to ignore search player data
		{
			getline(recent, extract);
			if (i == 0)
			{
				if (extract != "\0")
				{
					cout << "\n\tFIRST TEAM			|			 ";
				}
			}
			else if (i == 1)
			{
				cout << "\n\tSECOND TEAM			|			 ";
			}
			else if (i == 2)
			{
				cout << "\n\tDATE				|			 ";
			}
			else if (i == 3)
			{
				cout << "\n\tVENUE				|			 ";
			}
			else if (i == 4)
			{
				cout << "\n\tCAPACITY			|			 ";
			}
			else if (i == 5)
			{
				cout << "\n\tMATCH FORMAT			|			 ";
			}
			else if (i == 6)
			{
				cout << "\n\tCOMMENTATOR			|			 ";
			}
			else if (i == 7)
			{
				cout << "\n\tCOMMENTATOR			|			 ";
			}
			else if (i == 8)
			{
				cout << "\n\t1st UMPIRE			|                        ";
			}
			else if (i == 9)
			{
				cout << "\n\t2nd UMPIRE                      |                        ";
			}
			else if (i == 10)
			{
				cout << "\n\t3rd UMPIRE                      |                        ";
			}
			else if (i == 11)
			{
				cout << "\n\tMATCH STATUS                    |                        ";
			}
			else if (i == 12)
			{
				cout << "\n\tWEATHER                         |                        ";
				i = -1;
			}

			cout << extract << endl;
			if (i == -1)
			{
				cout << "\n\n\t************************\n";
			}
			i++;
		}
		recent.close(); //closing file
	}


};
int credential(string user, string pass) //fucntion for checking credentials
{
	string temp_user, temp_pass; //temporary variable 
	int access = 0;
	ifstream Admin("admin.txt"); //opening credentials file (username, password)
	if (!Admin.is_open()) //if not opened
	{
		cout << "File is not opened\n";
	}
	else
	{
		Admin >> temp_user; //input username from file
		Admin >> temp_pass; //input password from file
		if (temp_user == user && temp_pass == pass) //check for credentials
		{
			access++; //increment for access add, remove player etc...
		}
	}
	Admin.close(); //closing file
	return access; //return access
}

//driver code
int main()
{
	int choice = 0, access = 0;

	Team t1; //obj of team
	string user, password;
	bool BreakMenu = false;
	Match m1; //obj of match
	do
	{
		system("color 6F");
		cout << "\t--Welcome to cricbuzz!--\n\n";
		cout << "Press 1 to Login in\nPress 2 Display Teams\nPress 3 for Display Recent Matches\nPress 4 Displaying Upcoming Matches"
			<< "\nPress 5 Search Player\nPress 6 Exit\nChoice: ";
		cin >> choice; //taking choice
		system("cls");
		switch (choice) //compairing choice
		{
		case 1:
			cout << "\nEnter Username: ";
			cin >> user;
			cout << "\nEnter Password: ";
			cin >> password;
			access = credential(user, password);
			if (access == 1)
			{
				int ch = 0;
				do
				{
					//displaying menu for updation
					cout << "\nPress 1 for Add Player\nPress 2 for Remove Player\nPress 3 Search Player\nPress 4 Update Player";
					cout << "\nPress 5 Display Matches\nPress 6 Update Captain\nPress 7 Update Coach\nPress 8 Update World Record\nPress 9 Conduct Match\nPress 10 to Update Palyer Ranking\nPress 11 to Update Team Ranking\nChoice: ";
					cin >> ch; //taking choice
					system("cls");
					switch (ch)
					{
					case 1:
						t1.addPlayer();
						break;
					case 2:
						t1.removePlayer();
						break;
					case 3:
						t1.searchPlayer();
						break;
					case 4:
						t1.updatePlayer();
						break;
					case 5:
						t1.displayTeam();
						break;
					case 6:
						t1.updateCaptain();
						break;
					case 7:
						t1.updateCoach();
						break;
					case 8:
						m1.updateWorldRecords();
						break;
					case 9:
						m1.conductMatch();
						break;
					case 10:
						m1.updatePlayerRanking();
						break;
					case 11:
						m1.updateTeamRanking();
						break;
					case 12:
						BreakMenu = true;
						break;
					default:
						cout << "Choice is incorrect!\n";
						break;
					}
					cout << "\n\n\t";
					system("pause");
					system("cls");
				} while (!BreakMenu);
			}
			else
			{
				cout << "Wrong Username or Password\n";
			}
			break;
		case 2:
			t1.displayTeam();
			break;
		case 3:
			m1.displayRecentMatches();
			break;
		case 4:
			m1.displayUpcomingMatches();
			break;
		case 5:
			m1.searchPlayer();
			break;
		case 6:
			BreakMenu = true;
			break;
		default:
			break;
		}
		cout << "\n\n\t";
		system("pause");
		system("cls");
	} while (!BreakMenu);
	system("pause>0");
	return 0;
}