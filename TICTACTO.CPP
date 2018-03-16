#include<iostream.h>
#include<conio.h>

char c[3][3];

void Input1(char c[3][3])
{
	int x,y;
	cout<<"Player 1's turn:: Enter coordinates: ";
	cin>>x>>y;
	if(c[x][y]!=' ')
	{
		cout<<"Illegal move\n";
		Input1(c);
	}
	else c[x][y]='x';
}

void Input2(char c[3][3])
{
	int x,y;
	cout<<"Player 2's turn:: Enter coordinates: ";
	cin>>x>>y;
	if(c[x][y]!=' ')
	{
		cout<<"Illegal move\n";
		Input2(c);
	}
	else c[x][y]='o';
}

int check(char g,char c[3][3])
{
	if(c[0][0]==g&&c[0][1]==g&&c[0][2]==g) return 1;
	else if(c[1][0]==g&&c[1][1]==g&&c[1][2]==g) return 1;
	else if(c[2][0]==g&&c[2][1]==g&&c[2][2]==g) return 1;
	else if(c[0][0]==g&&c[1][0]==g&&c[2][0]==g) return 1;
	else if(c[0][1]==g&&c[1][1]==g&&c[2][1]==g) return 1;
	else if(c[0][2]==g&&c[1][2]==g&&c[2][2]==g) return 1;
	else if(c[0][0]==g&&c[1][1]==g&&c[2][2]==g) return 1;
	else if(c[2][0]==g&&c[1][1]==g&&c[0][2]==g) return 1;
	else return 0;
}

void main()
{
	clrscr();
	int k=0,m=0;
	cout<<"TIC-TAC-TOE\n";
	cout<<"Player 1 will give cross x\n";
	cout<<"Player 2 will give circle o\n";
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			c[i][j]=' ';
	cout<<"Game position coordinates:\n";
	cout<<"(0,0) (0,1) (0,2)\n(1,0) (1,1) (1,2)\n(2,0) (2,1) (2,2)\n";
	while(k==0)
	{
		clrscr();
		cout<<"TIC-TAC-TOE\n";
		cout<<"Player 1 will give cross x\n";
		cout<<"Player 2 will give circle o\n";
		cout<<"Game position coordinates:\n";
		cout<<"(0,0) (0,1) (0,2)\n(1,0) (1,1) (1,2)\n(2,0) (2,1) (2,2)\n";
		for(i=0;i<3;i++)
		{
			cout<<"---------------\n";
			for(j=0;j<3;j++)
			{
				cout<<"| "<<c[i][j]<<" |";
			}
			cout<<"\n";
		}
		cout<<"---------------\n";
		if(m%2==0) Input1(c);
		else Input2(c);
		if(check('x',c)||check('o',c))
		{
			k=1;
			break;
		}
		if(m==8)
		{
			k=2;
			break;
		}
		m++;
	}
	if(k==1&&m%2==0) cout<<"Player 1 wins\n";
	if(k==1&&m%2!=0) cout<<"Player 2 wins\n";
	if(k==2) cout<<"Match drawn\n";
	for(i=0;i<3;i++)
		{
			cout<<"---------------\n";
			for(j=0;j<3;j++)
			{
				cout<<"| "<<c[i][j]<<" |";
			}
			cout<<"\n";
		}
		cout<<"---------------\n";
	getch();
}