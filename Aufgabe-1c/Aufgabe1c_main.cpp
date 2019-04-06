#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Aufgabe1c_List.h"
#include "Aufgabe1c_tweet.h"
using namespace std;

int main(void)
{
	List<tweet> Tweets;
	string Text;
	
	Tweets.format("Tweet\n--->\n", "\n", "\n--->\n");
	while (true)
	{
		cout << "\nNachricht: ";
		getline(cin, Text);
		if (Text == "quit") break;
		Tweets.InsertFront(tweet(Text));

		cout << Tweets;
	}

	return 0;
}