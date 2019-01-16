#include <stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#define rows 15
#define cols 30
struct food
{
  int x,y;
  char val;
};
struct poison
{
  int x,y;
  char val;
};
struct snake
{
  int x,y;
  char val;
  struct snake *next;
};
void printing(char ssk[rows][cols])
{
	int j,i;
for( i=0;i<rows;i++)
  {
    for(j=0;j<cols;j++)
    {
      printf("%c",ssk[i][j]);
    }
    printf("\n");
  }
  return;
}


struct snake *setlen(struct snake *rambo)
{
  struct snake *ptr,*n;
  n=(struct snake *)malloc(sizeof (struct snake));
  n->x=5;
  n->y=15;
  n->val='@';
  n->next=NULL;
  rambo=n;
  ptr=rambo;
  n=(struct snake *)malloc(sizeof (struct snake));
  n->x=6;
  n->y=15;
  n->val='*';
  n->next=NULL;
  while(ptr->next!=NULL)
  {
    ptr=ptr->next;
  }
  ptr->next=n;
   ptr=rambo;
  n=(struct snake *)malloc(sizeof (struct snake));
  n->x=7;
  n->y=15;
  n->val='*';
  n->next=NULL;
  while(ptr->next!=NULL)
  {
    ptr=ptr->next;
  }
  ptr->next=n;
  ptr=rambo;
  n=(struct snake *)malloc(sizeof (struct snake));
  n->x=8;
  n->y=15;
  n->val='*';
  n->next=NULL;
  while(ptr->next!=NULL)
  {
    ptr=ptr->next;
  }
  ptr->next=n;

  return rambo;
}


struct food* setfood(struct food *ann)
{
	srand(time(NULL));
  ann->x=rand()%rows;
  ann->y=rand()%cols;
  ann->val='0';
  if(ann->x==0)
  ann->x=ann->x+1;
  if(ann->x==rows||ann->x==rows-1)
  ann->x=ann->x-2;
  if(ann->y==0)
  ann->y=ann->y+1;
  if(ann->y==cols||ann->y==cols-1)
  ann->y=ann->y-2;
  return ann;
}


struct poison* setpoi(struct poison *ppp)
{
	srand(time(NULL));
  ppp->x=rand()%rows;
  ppp->y=rand()%cols;
  ppp->val='p';
  if(ppp->x==0)
  ppp->x=ppp->x+1;
  if(ppp->x==rows||ppp->x==rows-1)
  ppp->x=ppp->x-2;
  if(ppp->y==0)
  ppp->y=ppp->y+1;
  if(ppp->y==cols||ppp->y==cols-1)
  ppp->y=ppp->y-2;
  return ppp;
}

struct snake *up(struct snake *rambo)
{
	struct snake *ptr,*temp1,*temp2;
	int tx=rambo->x;
	if(tx==0)
	{
		tx=rows-1;
	}
	int ty=rambo->y;
	ptr=rambo;
	while(ptr!=NULL)
	{
		int t1=ptr->x;
		ptr->x=tx;
		tx=t1;
		int t2=ptr->y;
		ptr->y=ty;
		ty=t2;
		ptr=ptr->next;
	}
	rambo->x=rambo->x-1;	
	return rambo;
}



struct snake *down(struct snake *rambo)
{
	struct snake *ptr,*temp1,*temp2;
	int tx=rambo->x;
	if(tx==rows-1)
	{
		tx=0;
	}
	int ty=rambo->y;
	ptr=rambo;
	while(ptr!=NULL)
	{
		int t1=ptr->x;
		ptr->x=tx;
		tx=t1;
		int t2=ptr->y;
		ptr->y=ty;
		ty=t2;
		ptr=ptr->next;
	}
	rambo->x=rambo->x+1;	
	return rambo;
}



struct snake *left(struct snake *rambo)
{
struct snake *ptr,*temp1,*temp2;
	int tx=rambo->x;
	int ty=rambo->y;
	if(ty==0)
	{
		ty=cols-1;
	}
	ptr=rambo;
	while(ptr!=NULL)
	{
		int t1=ptr->x;
		ptr->x=tx;
		tx=t1;
		int t2=ptr->y;
		ptr->y=ty;
		ty=t2;
		ptr=ptr->next;
	}
	rambo->y=rambo->y-1;	
	return rambo;
}



struct snake *right(struct snake *rambo)
{
	struct snake *ptr,*temp1,*temp2;
	int tx=rambo->x;
	int ty=rambo->y;
	if(ty==cols-1)
	{
		ty=0;
	}
	ptr=rambo;
	while(ptr!=NULL)
	{
		int t1=ptr->x;
		ptr->x=tx;
		tx=t1;
		int t2=ptr->y;
		ptr->y=ty;
		ty=t2;
		ptr=ptr->next;
	}
	rambo->y=rambo->y+1;	
	return rambo;
}



struct snake *grow(struct snake *rambo)
{
	struct snake *ptr,*n;
	ptr=rambo;
  n=(struct snake *)malloc(sizeof (struct snake));
  n->val='*';
  n->next=NULL;
  while(ptr->next!=NULL)
  {
    ptr=ptr->next;
  }
  n->x=ptr->x;
  n->y=ptr->y;
  ptr->next=n;
  return rambo;
}


struct snake *reloadsnake(struct snake *rambo,char ssk[])
{
	rambo=NULL;
	struct snake *ptr,*n;
	int i=0,a,b;
 while(*(ssk+i)!='f')
  {
    a=0;
    a=a*10+atoi(ssk+i);
  while(*(ssk+i)!=' ')
  {   
    i++;
  }
  i++;
  b=0;
    b=b*10+atoi(ssk+i);
  while(*(ssk+i)!=' ')
  {   
    i++;
  }
  i+=3;
  
  if(rambo==NULL)
  {
  	n=(struct snake *)malloc(sizeof (struct snake));
  n->x=a;
  n->y=b;
  n->val='@';
  n->next=NULL;
  rambo=n;
  }
  else
  {
  	ptr=rambo;
  n=(struct snake *)malloc(sizeof (struct snake));
  n->x=a;
  n->y=b;
  n->val='*';
  n->next=NULL;
  while(ptr->next!=NULL)
  {
    ptr=ptr->next;
  }
  ptr->next=n;
  }
  }
  return rambo;
}



struct food *reloadfood(struct food *ann,char ssk[])
{
	int i=0,a,b;
	while(*(ssk+i)!='f')
{
  i++;
}
i+=2;
ann->x=atoi(ssk+i);
while(*(ssk+i)!=' ')
{
  i++;
}
i++;
 ann->y=atoi(ssk+i);
ann->val='0';
return ann;
}



int main()
{
  FILE *fp=fopen("snake.txt","r");
  int i,j,count=0;
  int pf=1;
  char input='w',pi='s';
  struct snake *rambo=NULL,*ptr,*save;
  struct food *ann=(struct food*)malloc(sizeof(struct food));
  struct poison *ppp=(struct poison*)malloc(sizeof(struct poison));
  char load;
  
  printf("Enter 1 to new game");
  if(fp!=NULL)
  {
  	printf("\nEnter 2 to open saved file");
  }
  scanf("%c",&load);
  char str[1000];
  if(load=='2')
  {
  	fscanf(fp,"%[^\n]s",str);
  	rambo=reloadsnake(rambo,str);
  	ann=reloadfood(ann,str);
  }
  else if(load=='1')
  {
  rambo=setlen(rambo);
   ann=setfood(ann);
  }
  fclose(fp);
  char board[rows][cols];
  int dummy[rows][cols];
   for( i=0;i<rows;i++)
  {
    for( j=0;j<cols;j++)
    {if(i==0||i==rows-1)
    {
      board[i][j]='-';
    }
    else if(j==0||j==cols-1)
    {
      board[i][j]='|';
    }
    else
      board[i][j]=' ';
      
      dummy[i][j]=0;
    }   
  }
  ptr=rambo;
  while(ptr!=NULL)
  {
  	
    board[ptr->x][ptr->y]=ptr->val;
    if(ptr!=rambo)
    {
    	dummy[ptr->x][ptr->y]=1;
	}
    ptr=ptr->next;
  }
  board[ann->x][ann->y]=ann->val;
  printing(board);
  while(dummy[rambo->x][rambo->y]!=1&&input!='x')
  {
  	ptr=rambo;
  while(ptr!=NULL)
  {
  	if(board[ptr->x][ptr->y]=='*'||board[ptr->x][ptr->y]=='@')
    board[ptr->x][ptr->y]=' ';
    
    dummy[ptr->x][ptr->y]=0;
    ptr=ptr->next;
  }
  ptr=rambo;
  if(kbhit()){
    input=getch();
  }
  	if(input=='w'&&pi!='s')
  	{
  	rambo=up(rambo);
  		pi=input;
    }
  	else if(input=='s'&&pi!='w')
  	{
	rambo=down(rambo);
		pi=input;
    }
	else if(input=='a'&&pi!='d')
	{
	rambo=left(rambo);
		pi=input;
    }
	else if(input=='d'&&pi!='a')
	{
	rambo=right(rambo);
		pi=input;
    }
	else
	{
	printf("plz enter something else or x to save and exit");
    }
  ptr=rambo;
  while(ptr!=NULL)
  {
  	if(board[ptr->x][ptr->y]=='-')
  	{
  		board[ptr->x][ptr->y]='-';
    }
    else if(board[ptr->x][ptr->y]=='|')
  	{
  		board[ptr->x][ptr->y]='|';
    }
    else
    board[ptr->x][ptr->y]=ptr->val;
    
    if(ptr!=rambo)
    dummy[ptr->x][ptr->y]=1;
    ptr=ptr->next;
  }
  
   if(rambo->x==ann->x&&rambo->y==ann->y)
  {
  	
  	ann=setfood(ann);
  	rambo=grow(rambo);
  	board[ann->x][ann->y]=ann->val;
  	count++;
  }
  if(count==3&&pf==1)
  {
  	ppp=setpoi(ppp);
  	board[ppp->x][ppp->y]=ppp->val;
  	dummy[ppp->x][ppp->y]=1;
  	pf=0;
  }
  	if(ppp->x==ann->x&&ppp->y==ppp->y)
  	{
  		dummy[ppp->x][ppp->y]=0;
  		board[ann->x][ann->y]=ann->val;
  		ppp=setpoi(ppp);
  	board[ppp->x][ppp->y]=ppp->val;
  	dummy[ppp->x][ppp->y]=1;
	  }
	  
	  
    if(count==6&&pf==0)
    {
    	int times=rand()%5;
    	if(times<3)
    	times+=2;
    	while(times--)
    	{
  		ppp=setpoi(ppp);
  		board[ppp->x][ppp->y]=ppp->val;
  		dummy[ppp->x][ppp->y]=1;
  		pf=0;
  		if(ppp->x==ann->x&&ppp->y==ppp->y)
  		{
  		dummy[ppp->x][ppp->y]=0;
  		board[ann->x][ann->y]=ann->val;
  		ppp=setpoi(ppp);
  		board[ppp->x][ppp->y]=ppp->val;
  		dummy[ppp->x][ppp->y]=1;
	 	 }
		}
		pf=1;
	}
  if(count==8&&pf==1)
  {
  	pf=0;
  	 for( i=0;i<rows;i++)
  {
    for( j=0;j<cols;j++)
    {if(i==0||i==rows-1)
    {
      dummy[i][j]=1;
    }
    else if(j==0||j==cols-1)
    {
      dummy[i][j]=1;
    }
	else   {
	}
  }
  }
}
  Sleep(100);
  system("cls");
  printing(board);
  }
  if(input=='x')
  {
  	//"15 15 , 16 15 , 17 15 , 18 15 , f 10 10";
   char ssk[100];
   save=rambo;
   int l=0;
    while(save!=NULL)
      {
        int a=save->x;
        int b=save->y;
        int count=log10(a);
        int p=0;
        while(a!=0)
        {
          char rem=(a%10)+48;
          ssk[l+count]=rem;
          count--;
          p++;
          a/=10;
        }
        l=l+p;
        ssk[l++]=' ';
        count=log10(b);
        p=0;
        while(b!=0)
        {
          char rem=(b%10)+48;
          ssk[l+count]=rem;
          count--;
          b/=10;
          p++;
        }
        
        l=l+p;
        ssk[l++]=' ';
        ssk[l++]=',';
        ssk[l++]=' ';
        ssk[l]='\0';
        save=save->next;
      } 
   ssk[l++]='f';
   ssk[l++]='1';
   ssk[l++]='0';
   ssk[l++]=' ';
   ssk[l++]='1';
   ssk[l++]='0';
   ssk[l]='\0';
   
  fp=fopen("snake.txt","w");
  fprintf(fp,ssk);
  fclose(fp);
  }
  else
  remove("snake.txt");
  printf("\n your score is -> %d",count);
} 
