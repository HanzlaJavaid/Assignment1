///Hanzla Javaid 2018271 
///Decipher code..
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	char characters[66];
	int key[66];
	for(int i=0;i<66;i++)
	{
		key[i]=0;
		characters[i]=0;
	}
	characters[0]='0';
	key[0]=0;
	characters[1]='1';
	key[1]=1;
	characters[2]='2';
	key[2]=2;
	characters[3]='3';
	key[3]=3;
	characters[4]='4';
	key[4]=4;
	characters[5]='5';
	key[5]=5;
	characters[6]='6';
	key[6]=6;
	characters[7]='7';
	key[7]=7;
	characters[8]='8';
	key[8]=8;
	characters[9]='9';
	key[9]=9;
	int count=10;
	fstream file("charactersandkeys.txt");
	while(!file.eof())
	{
		char in1=0;
		int in2;
		file>>in1;
		//cout<<in1;
		characters[count]=in1;
		key[count]=count;
		++count;
	}
		
	ifstream ifile("output.txt");;
	string infile="";
	ifile>>infile;
	int keyy;
	for(int i=0;i<66;i++)
	{
		if(infile[0]==characters[i])
		{
			keyy=key[i];
			break;
		}
	}
	keyy=(keyy-13)%66;
	while(!ifile.eof())
	{
		string temp="";
		ifile>>temp;
		infile+=temp;
	}
	int j=0;
	string decyphertext="";

	int i=0;
	while(infile[i]!='\0')
	{
		int j;
		for(j=0;j<66;j++)
		{
			char a=infile[i];
			char b=characters[j];
			if(a==b)
			{
			break;	
			}
		}
		j=(j-keyy)%66;
		if(key[j]==0)
		{
			cout<<" ";
		}
		else
		cout<<characters[j];
		decyphertext+=characters[j];
		++i;
	}
	
	//cout<<decyphertext;
}
