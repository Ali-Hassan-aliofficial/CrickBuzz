#include<iostream>
#include<string>
#include"Header.h"
using namespace std;
int main()
{
	int returnvalue;
	int input;

	////player Pointer
	player* player_obj;
	////using Dma
	player_obj = new player[11];

	//for (int i = 0; i < 11; i++)
	//{
	//	player_obj[i].addPlayer();
	//}

	//player_obj->save_to_file(player_obj, 11);

	////match pointer
	Match* matchObj;
	matchObj = new Match[6];

	Team* team;
	team = new Team[6];

	//team->setteamcoach();
	//team->setteamcapt();
	//for (int i = 0; i < 11; i++)
	//{
	//	player_obj[i].addPlayer();
	//}
	system("Color 0N");
	cout << "\n\n*****************************************************************************" << endl;
	cout << "                 WelCome to CricBuzz Application" << endl;

	cout << "*****************************************************************************" << endl;
	cout << "\n\n\t\t Login " << endl;
	team->login();

	system("cls");

	cout << "1. Display Team List. " << endl;
	cout << "2. Display Team Ranking. " << endl;
	cout << "3. Add a Player to Team. " << endl;
	cout << "4. Display Team Players. " << endl;
	cout << "5. Display Team Coachs. " << endl;
	cout << "6. Display Team Captains. " << endl;
	cout << "7. Update Team's Coach. " << endl;
	cout << "8. Update Team's Captain. " << endl;
	cout << "9. Remove Player from Team. " << endl;
	cout << "10. Update PLayer. " << endl;
	cout << "11. Display Scheduled Match. " << endl;
	cout << "12. Conduct a Match. " << endl;
	cout << "13. Display Recent Matches. " << endl;
	cout << "14. News. " << endl;
	cout << "\n\n Press any Key to EXIST. " << endl;

	cout << "\n Enter the Option : \t";
	cin >> input;
	int index = 0;
	system("cls");

	switch (input)
	{
	case 1:
		team->displayTeams();
		break;
	case 2:
		team->displayteamrank();
		break;
	case 3:
		team->addPlayer();
		break;
	case 4:
		team->displayTeam();
		break;
	case 5:
		cout << "\n\tCoachs : " << endl;
		while (index < 6)
		{
			cout << team->getteamcoach(index) << endl;
			index++;
		}
		index = 0;
		break;
	case 6:
		cout << "\n\tCaptains : " << endl;
		while (index < 6)
		{
			cout << team->getteamcapt(index) << endl;
			index++;
		}
		break;
	case 7:
		team->updateCoach(player_obj, 11);
		break;
	case 8:
		team->updateCaptain(player_obj, 11);
		break;
	case 9:
		team->removePlayer(player_obj, 11);
		break;
	case 10:
		team->updatePlayer(player_obj, 11);
		break;
	case 11:
		matchObj->displayRecentMatches(matchObj, 6);
		break;
	case 12:
		matchObj->ConductMatch(matchObj, 6);
		break;
	case 13:
		matchObj->displayUpcomingMatches(matchObj, 6);
		break;
	default:
		cout << "Wrong! Input." << endl;

	}
	system("pause");
}