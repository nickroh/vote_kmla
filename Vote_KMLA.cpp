#include <fstream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>


//멍청한 input 예외처리

#pragma warning(suppress : 4996) 

using namespace std;

struct candidate {
	int ord;
	int polls;
	int points;
};

candidate candidate_1[15];
candidate candidate_2[5];

FILE *stream;
FILE *stream2;

int n;
int voters;

int num;

int vote_2[500][10];

//int candidate_1[15] = { 0, };


bool sf(candidate a, candidate b)
{
	if (a.polls != b.polls)
	{
		return a.polls > b.polls;
	}
	else
	{
		return a.ord < b.ord;
	}
}

void file_open()// candidate ord.. // not only file_open --> file open & vote_2
{
	// ifstream in("C:\Users\roh51\Desktop\Codying\test.txt");
	// string s;

	// if (in.is_open())
	// {
 //    in >> s;
 //    cout << "File Found " << endl;
 //    }
 //    else 
 //    {
 //    cout << "Error File Not Found ----" << endl;
 //    }

 //    in.open();

 //    int a;
 //    int num;

 //    fi.get(a);
 //    num=a;

 //    for(int i=0;i<num;i++)
 //    {
 //    	for(int j=0;j<n;j++)
 //    	{
 //    		fi.get(a);	
 //    	}
 //    }


	stream2 = freopen("C:\\Users\\roh51\\Desktop\\Codying\\test.txt", "r", stdin);
	if (!stream2)
	{
		printf("Error -- File Not Found");
		exit(0517);
	}
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			scanf("%d", &vote_2[i][j]);
		}
	}
	/*for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			printf("%d", vote_2[i][j]);
		}
		puts("");
	}*/
}


void cadidate_input()
{
	printf("후보자는 몇명인가요?");
	scanf(" %d", &n);
	for (int i = 0; i < n; i++)
	{	
		printf("%d 번째 후보자의 번호를 입력해주세요",i+1);
		scanf(" %d", &candidate_1[i].ord);
	}
}

void voter_num_input()
{
	printf("투표자는 몇명인가요?");
	scanf("%d", &voters);
}

void voting_2_part2(int num_a, int num_b)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (vote_2[i][j] == num_a)
			{
				candidate_2[0].points++;
				break;
			}
			if (vote_2[i][j] == num_b)
			{
				candidate_2[1].points++;
				break;
			}
		}
	}
	sort(candidate_2, candidate_2 + 2, sf);
	cout << "당선자는 " <<candidate_2[0].ord << "번 입니다!!" << endl;
}

void voting_2(int a_num, int b_num, int c_num)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (vote_2[i][j] == a_num)
			{
				candidate_2[0].points++;
				break;
			}
			if (vote_2[i][j] == b_num)
			{
				candidate_2[1].points++;
				break;
			}
			if (vote_2[i][j] == c_num)
			{
				candidate_2[2].points++;
				break;
			}
		}
	}
	sort(candidate_2, candidate_2 + 3, sf);
	//cout << candidate_2[0].ord << endl;
	//cout << candidate_2[1].ord << endl;
	voting_2_part2(candidate_2[0].ord, candidate_2[1].ord);
}

void vote_1()
{
	stream=freopen("C:\\Users\\roh51\\Desktop\\Codying\\points.txt", "r", stdin);
	if (!stream)
	{
		printf("Error File Not Found");
		exit(0517);
	}
	for (int i = 0; i < voters; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		candidate_1[a - 1].polls++;
		candidate_1[b - 1].polls++;
		candidate_1[c - 1].polls++;

	}
	fclose(stream);

	sort(candidate_1, candidate_1 + n, sf); //동석차 예외 처리
	/*for (int i = 0; i < n; i++)
	{
		cout << candidate_1[i].ord << endl;
	}*/

	for (int i = 0; i < 3; i++)
	{
		candidate_2[i].ord = candidate_1[i].ord;
		candidate_2[i].polls = candidate_1[i].polls;
	}
}

//void vote_2()
//{
//	for (int i = 0; i < voters; i++)
//	{
//		for (int j = 0; j < voters; j++)
//		{
//			scanf("%d", )
//		}
//	}
//}


int main()
{
	memset(&candidate_1, 0, sizeof(struct candidate));
	memset(&candidate_2, 0, sizeof(struct candidate));

	cadidate_input();
	voter_num_input();
	vote_1();;
	file_open();
	voting_2(candidate_2[0].ord, candidate_2[1].ord, candidate_2[2].ord);
	return 0;
}