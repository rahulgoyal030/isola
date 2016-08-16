#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vec; 
typedef vector<ll> vecl; 
const int INF   = 1000000001;
const ll  INFL  = 1000000000000000001;
#define loop(i,a,b) for(i=a;i<b;i++)
#define fill(a,i) memset(a,i,sizeof(a))
#define M 1000000007
#define pb push_back
#define popb pop_back
#define pf push_front
#define mp make_pair
#define fi first
#define sec second
#define debug(x) cout << '>' << #x << '=' << x << endl;
#define sz(x) ((int)x.size())
#define si(n) scanf("%d",&n)
#define gi(n) printf("%d\n",n)
#define sl(n) scanf("%I64d",&n)
#define gl(n) printf(" %I64d\n",n)
#define sll(n) scanf("%lld",&n)
#define gll(n) printf("%lld\n",n)
#define nl() printf("\n")
#define pi 3.14159
#define fread freopen("abc1.txt","r",stdin)
#define fwrite freopen("out.txt","w",stdout);
#define limit 1000009
vector< pii > output;
int a[8][8];
int mark[8][8];
int my, player;
int maxi=0,maxj=0,maxvalue=0;
int maxdepth =5;
int checkResult(int x, int y)
{
	int c=0;
	for(int i=x-1;i<=x+1 ; i++)
	{
		for(int j=y-1;j<=y+1;j++)
		{
			
			if(a[i][j]==0 && i>=0 && i<7 && j>=0 && j<7  && (i!=x|| j!=y))
			{
				c++;
			}
	    }
		
	}
	
	return c;
      
}

int check(int x, int y,int depth)
{
	int res = checkResult(x,y);
	
	res = res-depth;
	
	return res;
}

int maxmove(int x, int y, int move , int depth)
{
	vector < pii> v;
	int maxv=0; 
	a[x][y]=0;
	for(int i=x-1;i<=x+1 ; i++)
	{
		for(int j=y-1;j<=y+1;j++)
		{		
			if(a[i][j]==0 && i>=0 && i<7 &&j>=0 && j<7 && (i!=x|| j!=y)  )
			{
				
				a[i][j]=move;
				int res = check(i,j,depth);      
			    
			   // debug(i);
			   // debug(j);
			   // debug(res);
			   // nl();
			    
			    if(depth<=maxdepth)
			    res += maxmove(i,j,move,depth+1);
			  
				a[i][j]=0;
				
				if(res>maxv)
				{
					maxv=res;
					
					if(depth==0)
					{
						maxi=i;
						maxj=j;
						//debug(i);
						//debug(j);
					}
				}			
				
			}
	    }
		
	}
	
	return maxv;
		
}


int main()
{
  fread;	
 
  int i,j,myx,myy , plax,play;
  loop(i,0,7)
  loop(j,0,7)
  {
	  cin>>a[i][j];
  }
  
  int turn ;
  cin>>turn;
  
  if(turn==1)
  {
	  my=1;
	  player=2;
  }
  else
  {
	  my=2;
	  player=1;
  }
  
  loop(i,0,7)
  loop(j,0,7)
  {
	  if(a[i][j]==my)
	  {
		  myx=i;
		  myy=j;
	  }
	  if(a[i][j]==player)
	  {
		  plax=i;
		  play=j;
	  }
	  
  }
   debug(myx);
   debug(myy);
  fill(mark,0);
  maxmove(myx,myy , my , 0);
  
  cout<<maxi<<" "<<maxj<<endl;
  
  
  maxi=0; maxj=0;
  debug(plax);
  debug(play);
  maxmove(plax , play , -1 , 0 );
  cout<<maxi<<" "<<maxj<<endl;
  
  return 0;
}




