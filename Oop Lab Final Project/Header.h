#pragma once
#include<iostream>
#include<string>
using namespace std;

class player
{
	string Name;
	string ICC_ranking;
	float Average;
	int  Shirt_No, runs, wickets, Matches_played;

public:
	//default constructer
	player();

	//Setters
	void setName(string Name);
	void setICCrank(string ICC_ranking);
	void setaverage(float Average);
	void setshirt_no(int shirt_no);
	void setruns(int runs);
	void setwickets(int wickets);
	void setmatchesplayed(int Matches_played);

	//Getters
	string getname();
	string geticcrank();
	float getaverage();
	int getshirtno();
	int getruns();
	int getwickets();
	int getmatchesplayed();

	//other functions
	int addPlayer();
	int removePlayer(player Player[], int size);
	int searchPlayer();
	void updatePlayer(player Player[], int size);
	void save_to_file(player Player[], int size);
	void read_from_file(player Player[], int size);


};
class Team :public player
{
	int  No_of_Players;
	string team_name;
	int team_rank;
	int Total_matches_won, Total_matches_lost;
	//string Team_Captain, Team_Coach;
	string Admin_Username;
	string Admin_Password;
public:

	string Team_Captain[6];
	string Team_Coach[6];

	Team();
	//int displayMatches();

	void login();

	//setters
	void setnoofplayer(int no_of_players);
	void setteamname(string team_name);
	void settotalmatchesW(int Total_matches_won);
	void settotalmatchesL(int Total_matches_lost);
	void setteamcapt();
	void setteamcoach();
	void setadmin_username(string Admin_username);
	void setpassword(string Admin_password);

	//getters
	int getnoofplayer();
	string getteamname();
	int gettotalmatchesW();
	int gettotalmatchesL();
	string getteamcapt(int index);
	string getteamcoach(int index);
	string getusername();
	string getpassword();

	//other functions
	void displayTeams();
	void displayteamrank();
	int updateCaptain(player Player[], int size);
	int updateCoach(player Player[], int size);
	void displayTeam();

	void save_to_file(player Player[], int size, int teamNo);


};
static int matchIndex = 0;

class Match :public Team
{
	string team1, team2, date, venue, match_type, tournament_name;
	string Commentators[3], Umpires[3];
	string Match_status;

public:
	//default constructer
	Match();

	void ConductMatch(Match matchObj[], int size);
	void scheduleMatch(Match matchObj[], int size);
	void matchMenu(Match matchObj[], int size);
	void displayUpcomingMatches(Match matchObj[], int size);

	void displayRecentMatches(Match matchObj[], int size);

};

