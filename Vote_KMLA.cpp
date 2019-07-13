#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>


//멍청한 input 예외처리

#pragma warning(suppress : 4996) 

using namespace std;

struct candidate {
	string name;
	int ord;
	int polls;
	int points;
};

candidate candidate_1[15];
candidate candidate_2[5];

int n;
int voters;

//int candidate_1[15] = { 0, };


bool sf(candidate a, candidate b)
{
	if (a.polls != b.polls)
	{
		return a.polls > b.polls;
	}
	else
	{
		return a.name > b.name;
	}	
}


void cadidate_input()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &candidate_1[i].ord);
		cin >> candidate_1[i].name;
	}
}

void voter_num_input()
{
	scanf("%d", &voters);
}

void vote_1()
{
	for (int i = 0; i < voters; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		candidate_1[a-1].polls++;
		candidate_1[b-1].polls++;
		candidate_1[c-1].polls++;
		
	}	
	sort(candidate_1, candidate_1 + n, sf); //동석차 예외 처리
	/*for (int i = 0; i < n; i++)
	{
		cout << candidate_1[i].name << endl;
	}*/

	for (int i = 0; i < 3; i++)
	{
		candidate_2[i].name = candidate_1[i].name;
		candidate_2[i].ord = candidate_1[i].ord;
		candidate_2[i].polls = candidate_1[i].polls;
	}
}

void vote_2()
{
	for (int i = 0; i < voters; i++)
	{
		for (int j = 0; j < voters; j++)
		{
			scanf("%d",)
		}
	}
}


int main()
{
	memset(&candidate_1, 0, sizeof(struct candidate));
	memset(&candidate_2, 0, sizeof(struct candidate));
	cadidate_input();
	voter_num_input();
	vote_1();
	return 0;
}