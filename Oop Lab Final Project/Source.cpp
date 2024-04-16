#include<iostream>
#include<string>
#include<fstream>
#include"Header.h"
using namespace std;

//default constructer
player::player()
{
	this->Average = 0;
	this->ICC_ranking = "null";
	this->Matches_played = 0;
	this->Name = "null";
	this->runs = 0;
	this->Shirt_No = 0;
	this->wickets = 0;

}

int player::addPlayer()
{
	cout << "\nEnter Name : ";
	cin >> Name;
	cout << "Enter ICC_ranking : ";
	cin >> ICC_ranking;
	cout << "Enter Matches_played : ";
	cin >> Matches_played;
	cout << "Enter Runs : ";
	cin >> runs;
	cout << "Enter Average : ";
	cin >> Average;
	cout << "Enter Shirt_No : ";
	cin >> Shirt_No;
	cout << "Enter wickets : ";
	cin >> wickets;

	return 1;
}

//remove player
int player::removePlayer(player Player[], int size)
{
	string name;
	int index;

	cout << "Enter the Name of the player which you want to remove : ";
	cin >> name;

	for (int i = 0; i < size; i++)
	{
		if (name == Player[i].Name)
		{
			//storing the index of the palyer which we want to remove
			index = i;
			break;
		}
	}
	//deleting the player
	for (int j = index; j < size; j++)
	{
		for (int k = 0; k < size; k++)
		{
			Player[j] = Player[k];
		}
	}

	return 1;
}
//***********************************************************************************************
//search player
int player::searchPlayer()
{
	string name;
	int index;
	string reading;

	ifstream read;
	read.open("player.txt", ios::app);

	cout << "Enter the Name of the player which you want to Search : ";
	cin >> name;

	//searching player
	for (int i = 0; i < 11; i++)
	{
		read >> reading;

		if (name == reading)
		{
			return i;
		}
	}

	return -1;

}

//update player
void player::updatePlayer(player Player[], int size)
{
	string name;
	int index;
	int returnvalue;

	cout << "Enter the Name of the player which you want to Update : ";
	cin >> name;

	//searching player
	for (int i = 0; i < size; i++)
	{
		if (name == Player[i].Name)
		{
			returnvalue = addPlayer();
		}
	}
	if (returnvalue == 1)
	{
		cout << "\n Player has been SuccessFully Updated. :)" << endl;
	}
	save_to_file(Player, size);
}

//save  to file function
void player::save_to_file(player Player[], int size)
{
	ofstream write;
	write.open("player.txt", ios::app);

	for (int i = 0; i < size; i++)
	{
		write << Player[i].Name << " ";
		write << Player[i].ICC_ranking << " ";
		write << Player[i].Average << " ";
		write << Player[i].Matches_played << " ";
		write << Player[i].runs << " ";
		write << Player[i].Shirt_No << " ";
		write << Player[i].wickets << " ";
		write << endl;
	}

	write.close();
}

//read from file
void player::read_from_file(player Player[], int size)
{
	ifstream read("player.txt");

	string input;

	int i = 0;
	if (read.is_open())
		while (!(read.eof()) && i < 11)
		{
			read >> Player[i].Name;
			read >> Player[i].ICC_ranking;
			read >> Player[i].Average;
			read >> Player[i].Matches_played;
			read >> Player[i].runs;
			read >> Player[i].Shirt_No;
			read >> Player[i].wickets;
			i++;
		}

	read.close();
}

//Setters
void player::setName(string Name)
{
	this->Name = Name;
}
void player::setICCrank(string ICC_ranking)
{
	this->ICC_ranking = ICC_ranking;
}
void player::setaverage(float Average)
{
	this->Average = Average;

}
void player::setshirt_no(int Shirt_no)
{
	this->Shirt_No = Shirt_No;
}
void player::setwickets(int wickets)
{
	this->wickets = wickets;
}
void player::setmatchesplayed(int Matches_played)
{
	this->Matches_played = Matches_played;
}

//Getters
string player::getname()
{
	return Name;
}
string player::geticcrank()
{
	return ICC_ranking;
}
float player::getaverage()
{
	return Average;
}
int player::getshirtno()
{
	return Shirt_No;
}
int player::getwickets()
{
	return wickets;
}
void player::setruns(int runs)
{
	this->runs = runs;
}
int player::getruns()
{
	return runs;
}
int player::getmatchesplayed()
{
	return Matches_played;
}


//*******************************************************************************************
//**************************************"    TEAM     "*****************************************************
//*******************************************************************************************
//default constructer
Team::Team() :player()
{
	this->Total_matches_won = 0;
	this->Total_matches_lost = 0;
	this->No_of_Players = 0;
	this->Team_Captain[0] = "null";
	this->Team_Coach[0] = "null";
	this->Admin_Username = "null";
	this->Admin_Password = "null";
}
void Team::login()
{
	cout << "Enter UserName : ";
	cin >> Admin_Username;
	cout << "Enter passward:\t";
	cin >> Admin_Password;

	while (Admin_Username != "admin" || Admin_Password != "admin")
	{
		cout << "\t\t\tWrong ! Enter username again:\t";
		cin >> Admin_Username;
		cout << "\t\t\tEnter passward again:\t";
		cin >> Admin_Password;
	}

	cout << "\nSuccessFully Logged In." << endl;

}

//int Team::displayMatches()
//{
//	/*this function will further display all previous and upcoming matches along
//	with all details*/
//}

void Team::save_to_file(player Player[], int size, int teamNo)
{

	ofstream file;

	switch (teamNo)
	{
	case 1:
		file.open("Pakistan.txt", ios::app);
		file << team_name << endl;
		file << Team_Captain[0] << endl;
		file << Team_Coach << endl;
		player::save_to_file(Player, 11);
		file.close();
		break;

	case 2:
		file.open("India.txt", ios::app);
		file << team_name << endl;
		file << Team_Captain[1] << endl;
		file << Team_Coach << endl;
		player::save_to_file(Player, 11);
		file.close();
		break;

	case 3:
		file.open("Newzealand.txt", ios::app);
		file << team_name << endl;
		file << Team_Captain[2] << endl;
		file << Team_Coach << endl;
		player::save_to_file(Player, 11);
		file.close();
		break;

	case 4:
		file.open("England.txt", ios::app);
		file << team_name << endl;
		file << Team_Captain[3] << endl;
		file << Team_Coach << endl;
		player::save_to_file(Player, 11);
		file.close();
		break;

	case 5:

		file.open("Australia.txt", ios::app);
		file << team_name << endl;
		file << Team_Captain[4] << endl;
		file << Team_Coach << endl;
		player::save_to_file(Player, 11);
		file.close();
		break;

	case 6:
		file.open("Srilanka.txt", ios::app);
		file << team_name << endl;
		file << Team_Captain[5] << endl;
		file << Team_Coach << endl;
		player::save_to_file(Player, 11);
		file.close();
		break;

	default:
		break;

	}

}
int Team::updateCaptain(player Player[], int size)
{
	ofstream write;
	int teamNo;
	string CaptainName;

	cout << "******************* TEAMS *******************" << endl;
	cout << "1. Pakistan" << endl;
	cout << "2. India" << endl;
	cout << "3. Newzealand" << endl;
	cout << "4. England" << endl;
	cout << "5. Australia" << endl;
	cout << "6. Srilanka" << endl;

	cout << "Enter the Captain's Team Number you want to Update :";
	cin >> teamNo;
	cout << "Enter the name: ";
	cin >> CaptainName;
	switch (teamNo)
	{
	case 1:
		Team_Captain[0] = CaptainName;
		save_to_file(Player, 11, 1);
		break;

	case 2:
		Team_Captain[1] = CaptainName;
		save_to_file(Player, 11, 2);
		break;

	case 3:
		Team_Captain[2] = CaptainName;
		save_to_file(Player, 11, 3);

		break;

	case 4:
		Team_Captain[3] = CaptainName;
		save_to_file(Player, 11, 4);

		break;

	case 5:
		Team_Captain[4] = CaptainName;
		save_to_file(Player, 11, 5);

		break;

	case 6:
		Team_Captain[5] = CaptainName;
		save_to_file(Player, 11, 6);

		break;

	default:
		break;
	}
	return 0;
}
int Team::updateCoach(player Player[], int size)
{
	ofstream write;
	int teamNo;
	string CoachName;

	cout << "******************* TEAMS *******************" << endl;
	cout << "1. Pakistan" << endl;
	cout << "2. India" << endl;
	cout << "3. Newzealand" << endl;
	cout << "4. England" << endl;
	cout << "5. Australia" << endl;
	cout << "6. Srilanka" << endl;

	cout << "Enter the Coach's Team Number you want to Update :";
	cin >> teamNo;
	cout << "Enter the name: ";
	cin >> CoachName;

	switch (teamNo)
	{
	case 1:
		Team_Coach[0] = CoachName;
		save_to_file(Player, 11, 1);
		break;

	case 2:
		Team_Coach[1] = CoachName;
		save_to_file(Player, 11, 2);
		break;

	case 3:
		Team_Coach[2] = CoachName;
		save_to_file(Player, 11, 3);

		break;

	case 4:
		Team_Coach[3] = CoachName;
		save_to_file(Player, 11, 4);

		break;

	case 5:
		Team_Coach[4] = CoachName;
		save_to_file(Player, 11, 5);

		break;

	case 6:
		Team_Coach[5] = CoachName;
		save_to_file(Player, 11, 6);

		break;

	default:
		break;
	}
	return 0;
}
void Team::displayTeams()
{
	cout << "\n******************* TEAMS *******************" << endl;
	cout << "\n1. Pakistan" << endl;
	cout << "2. India" << endl;
	cout << "3. Newzealand" << endl;
	cout << "4. England" << endl;
	cout << "5. Australia" << endl;
	cout << "6. Srilanka" << endl;
}
void Team::displayteamrank()
{
	cout << "\n   TEAMS \t\t\t Ranking" << endl;
	cout << "\n1. Pakistan \t\t\t     1" << endl;
	cout << "2. India  \t\t\t     2" << endl;
	cout << "3. Newzealand \t\t\t     3" << endl;
	cout << "4. England \t\t\t     4" << endl;
	cout << "5. Australia \t\t\t     5" << endl;
	cout << "6. Srilanka \t\t\t     6" << endl;
}
void Team::displayTeam()
{
	/*  cout << "\n\n****************************************\n\n";
	  cout << "Player Name\tShirt \t ICC Rank   Total Runs   Match Played   Total Wickets   Stike Rate\n\n";
	  cout << "-------------------------------------------------------------------------------------------------------------------------\n\n";
	  for (int i = 0; i < size; i++)
	  {
		  cout << Players[i].getname() << "\t   " << Players[i].getshirtno() << "\t   "
			  << Players[i].geticcrank() << "\t\t"
			  << "\t\t" << Players[i].getruns() << "\t\t"
			  << Players[i].getmatchesplayed() << "\t    " << Players[i].getwickets()
			  << "\t\t" << Players[i].getruns() << "\t\t" << endl;
	  }
		  cout << "\n\n-------------------------------------------------------------------------------------------------------------------------\n\n\n";*/

	displayTeams();

	ifstream read;
	string reading;
	int number;

	cout << "Which Team do you want to display : " << endl;
	cin >> number;
	switch (number)
	{
	case 1:
		read.open("Pakistan.txt");

		read >> reading;
		cout << "Pakistan Team's Captain: " << reading << endl;
		read >> reading;
		cout << "Pakistan Team's Coach : " << reading << endl;
		cout << "Players : " << endl;
		while (!(read.eof()))
		{
			read >> reading;
			cout << reading << endl;
		}

		break;

	case 2:
		read.open("India.txt");

		read >> reading;
		cout << "India Team's Captain: " << reading << endl;
		read >> reading;
		cout << "India Team's Coach : " << reading << endl;
		cout << "Players : " << endl;
		while (!(read.eof()))
		{
			read >> reading;
			cout << reading << endl;
		}
		break;

	case 3:

		read.open("Newzealand.txt", ios::app);

		read >> reading;
		cout << "New zealand Team's Captain: " << reading << endl;
		read >> reading;
		cout << "New zealand Team's Coach : " << reading << endl;
		cout << "Players : " << endl;
		while (!(read.eof()))
		{
			read >> reading;
			cout << reading << endl;
		}

		break;

	case 4:
		read.open("England.txt", ios::app);

		read >> reading;
		cout << "England Team's Captain: " << reading << endl;
		read >> reading;
		cout << "England Team's Coach : " << reading << endl;
		cout << "Players : " << endl;
		while (!(read.eof()))
		{
			read >> reading;
			cout << reading << endl;
		}

		break;
	case 5:
		read.open("Australia.txt", ios::app);

		read >> reading;
		cout << "Australia Team's Captain: " << reading << endl;
		read >> reading;
		cout << "Australia Team's Coach : " << reading << endl;
		cout << "Players : " << endl;
		while (!(read.eof()))
		{
			read >> reading;
			cout << reading << endl;
		}
		break;

	case 6:
		read.open("Srilanka.txt", ios::app);

		read >> reading;
		cout << "Srilanka Team's Captain: " << reading << endl;
		read >> reading;
		cout << "Srilanka Team's Coach : " << reading << endl;
		cout << "Players : " << endl;
		while (!(read.eof()))
		{
			read >> reading;
			cout << reading << endl;
		}

		break;
	default:
		break;
	}

}
void Team::setnoofplayer(int No_of_players)
{
	this->No_of_Players = No_of_players;
}
int Team::getnoofplayer()
{
	return No_of_Players;
}
void Team::setteamname(string team_name)
{
	this->team_name = team_name;
}
string Team::getteamname()
{
	return team_name;
}
void Team::settotalmatchesW(int Total_matches_won)
{
	this->Total_matches_won;
}
int Team::gettotalmatchesW()
{
	return Total_matches_won;
}
void Team::settotalmatchesL(int Total_matches_lost)
{
	this->Total_matches_lost = Total_matches_lost;

}
int Team::gettotalmatchesL()
{
	return Total_matches_lost;
}
void Team::setteamcapt()
{
	this->Team_Captain[0] = "Babar Azam";
	this->Team_Captain[1] = "Virat Kohli";
	this->Team_Captain[2] = "Kane WilliamSon";
	this->Team_Captain[3] = "Ben Stokes";
	this->Team_Captain[4] = "Aaron Finch";
	this->Team_Captain[5] = "Dimuth Karunnaratne";
}
string Team::getteamcapt(int index)
{
	return Team_Captain[index];
}
void Team::setteamcoach()
{
	this->Team_Coach[0] = "Saqlain Mushtaq";
	this->Team_Coach[1] = "Rahul David";
	this->Team_Coach[2] = "Gray Stead";
	this->Team_Coach[3] = "Brendon Mccullum";
	this->Team_Coach[4] = "Andrew Mcdonal";
	this->Team_Coach[5] = "Chris Silverwood";
}
string Team::getteamcoach(int index)
{
	return Team_Coach[index];
}
void Team::setadmin_username(string Admin_username)
{
	this->Admin_Username = Admin_Username;
}
string Team::getusername()
{
	return Admin_Username;
}
void Team::setpassword(string Admin_password)
{
	this->Admin_Password = Admin_Password;
}
string Team::getpassword()
{
	return Admin_Password;
}
//*******************************************************************************************
//**************************************"    MATCH     "*****************************************************
//*******************************************************************************************
//default constructer
Match::Match()
{
	this->team1 = "null";
	this->team2 = "null";
	this->Match_status = "null";
	this->tournament_name = "null";
	this->Umpires[0] = "null";
	this->venue = "null";
	this->Commentators[0] = "null";
	this->date = "null";
	this->match_type = "null";

}
void Match::matchMenu(Match matchObj[], int size)
{

	int option = 0;

	cout << "1. Conduct Already Shedule Match" << endl;
	cout << "2. Shedule New Match" << endl << endl;

	cout << "Enter Option : ";
	cin >> option;

	if (option == 0)
	{
		ConductMatch(matchObj, 6);
	}
	else if (option == 1)
	{
		scheduleMatch(matchObj, 6);
	}

}

void Match::ConductMatch(Match matchObj[], int size)
{

	int option = 0;

	for (int i = 0; i < matchIndex; i++)
	{
		cout << i << " - " << matchObj[matchIndex].team1 << " vs " << matchObj[matchIndex].team2 << endl;
	}

	cout << endl << "Enter Option  : ";
	cin >> option;

	cout << "Match Conducting " << option << endl;

}

void Match::displayUpcomingMatches(Match matchObj[], int size)
{

	for (int i = 0; i < matchIndex; i++)
	{
		cout << matchObj[matchIndex].team1 << " vs " << matchObj[matchIndex].team2 << endl;
	}

}

void Match::scheduleMatch(Match matchObj[], int size)
{

	cout << "Enter Team 1 Name : ";
	cin >> matchObj[matchIndex].team1;

	cout << "Enter Team 2 Name : ";
	cin >> matchObj[matchIndex].team2;

	cout << "Enter Match Date : ";
	cin >> matchObj[matchIndex].date;

	cout << "Enter Match Type : ";
	cin >> matchObj[matchIndex].match_type;

	cout << "Enter Tournament Name : ";
	cin >> matchObj[matchIndex].tournament_name;

	matchIndex++;

}

void Match::displayRecentMatches(Match matchObj[], int size)
{
	cout << "Enter Team 1 Name : ";
	cout << matchObj[matchIndex].team1;

	cout << "Enter Team 2 Name : ";
	cout << matchObj[matchIndex].team2;

	cout << "Enter Match Date : ";
	cout << matchObj[matchIndex].date;

	cout << "Enter Match Type : ";
	cout << matchObj[matchIndex].match_type;

	cout << "Enter Tournament Name : ";
	cout << matchObj[matchIndex].tournament_name;
}
