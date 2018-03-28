#include<stdio.h>
struct student
{
	int id;
	int t_time;
	int c_time;
	int a_time;
	int s_time;
};
float tat=0,wt=0;
int timer=0;
void algo(struct student *s)
{
	if(s->s_time==-1)
	{
		s->s_time=timer;
	}
	timer++;
	s->t_time--;
	if(s->t_time==0)
	{
		s->c_time=timer;
		tat=tat+(s->c_time-s->a_time);
		wt=wt+(s->c_time-s->s_time);
	}
}
int main()
{
	struct student a,b,c;
	int i=0;	
	a.id=2132;
	a.t_time=2;
	a.a_time=0;
	a.s_time=-1;
	b.id=2102;
	b.t_time=4;
	b.a_time=0;
	b.s_time=-1;
	c.id=2453;
	c.t_time=8;
	c.a_time=0;
	c.s_time=-1;
	int time=a.t_time+b.t_time+c.t_time;
	for(i=0;i<time;i++)
	{
		if(a.t_time>b.t_time && a.t_time>c.t_time)
		{
			algo(&a);
		}
		else if(b.t_time>a.t_time && b.t_time>c.t_time)
		{
			algo(&b);
		}
		else if(c.t_time>a.t_time && c.t_time>b.t_time)
		{
			algo(&c);
		}
		else if(a.t_time==b.t_time)
		{
			if(a.id<b.id)
			{
				algo(&a);
			}
			else
			{
				algo(&b);
			}
		}
		else if(a.t_time==c.t_time)
		{
			if(a.id<c.id)
			{
				algo(&a);
			}
			else
			{
				algo(&c);
			}
		}
		else if(b.t_time==c.t_time)
		{
			if(b.id<c.id)
			{
				algo(&b);
			}
			else
			{
				algo(&c);
			}
		}
	}
	printf("\nThe average turnaround time is-: %f",tat/3);
	printf("\nThe average waiting time is-: %f",wt/3);
}
