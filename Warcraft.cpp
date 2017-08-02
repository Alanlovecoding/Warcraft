// 真终极版.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
#include<iostream>
#include<memory>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;
string wushi_name[6]={"","dragon","ninja","iceman","lion","wolf"};//1:dragon   2:ninja  3:iceman   4:lion  5:wolf
int R,K;                                //arrow的攻击力R; lion掉忠诚度的值K.
string wuqi[3]={"sword","bomb","arrow"};
class fighter
{
public:
 int num;
   int blood;
   fighter(int m):num(0),blood(m){};
};
class Army
{
public:
 string color;
 int blood;
 int num;
 int turn;
 int symbol;
 fighter dragon,ninja,iceman,lion,wolf;
 Army(string cc,int m,int a,int b,int c,int d,int e,int sym):dragon(a),ninja(b),iceman(c),lion(d),wolf(e)
 {
  color=cc;
  blood=m;
  num=0;
  turn=1;
  symbol=sym;
 };
 void make_a_dragon(int m){
  dragon.num++;
  num++;
  blood-=dragon.blood;
  cout<<setfill('0')<<setw(3)<<m<<":00 "<<color<<" dragon "<<num<<" born\n";
  float morale=0.0;
  morale=float(blood) / dragon.blood;
  cout<<"Its morale is "<<setiosflags(ios::fixed) << setprecision(2)<<morale<<endl;           //可能需要四舍五入，到时候再处理。
 }
 //setiosflags(ios::fixed) << setprecision(2) << morale<<

 void make_a_lion(int m){
  lion.num++;
  num++;
  blood-=lion.blood;
  cout<<setfill('0')<<setw(3)<<m<<":00 "<<color<<" lion "<<num<<" born\n";
  cout<<"Its loyalty is "<<blood<<endl;

 }
 void make_a_iceman(int m){
     iceman.num++;
     num++;
  blood-=iceman.blood;
  cout<<setfill('0')<<setw(3)<<m<<":00 "<<color<<" iceman "<<num<<" born\n";
 }
 void make_a_ninja(int m){
     ninja.num++;
     num++;
  blood-=ninja.blood;
  cout<<setfill('0')<<setw(3)<<m<<":00 "<<color<<" ninja "<<num<<" born\n";
 }
 void make_a_wolf(int m){
  wolf.num++;
  num++;
  blood-=wolf.blood;
  cout<<setfill('0')<<setw(3)<<m<<":00 "<<color<<" wolf "<<num<<" born\n";
  }

};

class CCreature              //武士的基类，并由此派生出五个武士类。
{

public:
 int array_time;         //array使用的次数。
 int name;
 Army * army;          //武士所在的阵营。
 int blood;          //武士的生命值。
 int num;            //武士的编号。
 int attack_;        //武士的攻击力。
 int attack_sword;             //武士所拿的武器的攻击力。
 bool WhetherHaveBomb;            //表示是否含有炸弹和弓箭
 bool WhetherHaveArrow;
 CCreature(){};             //name表示武士的类型，1:dragon   2:ninja  3:iceman   4:lion  5:wolf
 CCreature(int array_t,int name1,Army *pp,int n,int m,int att,int atta,bool w1,bool w2):array_time(array_t),name(name1),army(pp),blood(n),num(m),attack_(att),attack_sword(atta),
  WhetherHaveBomb(w1),WhetherHaveArrow(w2){};
 virtual void attack(CCreature *p){};            //利用多态来简化程序。
 virtual void hurted(int power){};
 virtual void fightback(CCreature *p){};

};
class Cdragon:public CCreature                           //dragon类.
{
public:
 float morale;                //dragon的士气值。
   int addr;
   Cdragon(int array_t,int name1,Army * pp,int bloo,int nu,int att,int atta,bool w1,bool w2,float mo,int add)
   :CCreature(array_t,name1,pp,bloo,nu,att,atta,w1,w2),morale(mo),addr(add)
 {};
   virtual void attack(CCreature *p){
    p->hurted(attack_+attack_sword);
   }
   virtual void hurted(int power){
    blood-=power;
   }
   virtual void fightback(CCreature *p){
    p->hurted(attack_/2+attack_sword);
   }
};
class Cninja:public CCreature                          //ninja类.
{
public:
 Cninja(int array_t,int name1,Army *pp,int n,int m,int att,int atta,bool w1,bool w2):CCreature(array_t,name1,pp,n,m,att,atta,w1,w2){};
 virtual void attack(CCreature *p){
      p->hurted(attack_+attack_sword);
     }
   virtual void hurted(int power){
      blood-=power;
     }
   virtual void fightback(CCreature *p){
      p->hurted(attack_/2+attack_sword);
     }
 };
class Ciceman:public CCreature                         //iceman类。
{
	public:
 int step;                      //表示冰人当前已经前进的步数。
 Ciceman(int array_t,int name1,Army *pp,int n,int m,int att,int atta,bool w1,bool w2,int step1):CCreature(array_t,name1,pp,n,m,att,atta,w1,w2),step(step1){};
 virtual void attack(CCreature *p){
      p->hurted(attack_+attack_sword);
       }
   virtual void hurted(int power){
      blood-=power;
     }
   virtual void fightback(CCreature *p){
      p->hurted(attack_/2+attack_sword);
     }
};
class Clion:public CCreature
{
public:
   int loyalty;                             //loyalty表示狮子的忠诚度。
   Clion(int array_t,int name1,Army *pp,int n,int m,int att,int atta,bool w1,bool w2,int loy):CCreature(array_t,name1,pp,n,m,att,atta,w1,w2),loyalty(loy){};
   virtual void attack(CCreature *p){
       p->hurted(attack_+attack_sword);
      }
   virtual void hurted(int power){
       blood-=power;
      }
   virtual void fightback(CCreature *p){
       p->hurted(attack_/2+attack_sword);
      }
};
class Cwolf:public CCreature
{
	public:
 Cwolf(int array_t,int name1,Army *pp,int n,int m,int att,int atta,bool w1,bool w2):CCreature(array_t,name1,pp,n,m,att,atta,w1,w2){};
  virtual void attack(CCreature *p){
       p->hurted(attack_+attack_sword);
      }
     virtual void hurted(int power){
       blood-=power;
      }
     virtual void fightback(CCreature *p){
       p->hurted(attack_/2+attack_sword);
      }
};
class CCity
{
public:
 int blood;
 int enemy_num;              //用来表示基地的敌军武士的数量。
 string flag;
 string lastbattle;
 CCreature * red,*blue;
 string who_get_bonus;
 CCity(){
  blood=0;
  enemy_num=0;
  flag="no";
  lastbattle="no";
  who_get_bonus="no";
  red=NULL;
  blue=NULL;
 }
};

int main(){
   int datacase=0;                    //datacase表示数据的组数。
   cin>>datacase;
   int temp=datacase;
 while(datacase--){
  CCity City[22];                   //生成这些城市并进行初始化。
     CCreature * creature[1000];
     int NUM=0;                      //NUM表示总共的武士数量。
  Cdragon * Crea_dragon;
  Ciceman * Crea_iceman;
  Cninja * Crea_ninja;
  Clion * Crea_lion;
  Cwolf * Crea_wolf;
  //五个临时的指向武士的指针来过渡。
     int time=0;
     int T;                 //要求输出从0时0分开始，到时间T为止(包括T) 的所有事件。T以分钟为单位，0 <= T <= 5000
     int N;                 //两个司令部之间一共有N个城市
  int blood=0;            //每个司令部一开始都有blood个生命元
  int a,b,c,d,e;    //五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000
  cin>>blood>>N>>R>>K>>T; //要求输出从0时0分开始，到时间T为止(包括T) 的所有事件。T以分钟为单位，0 <= T <= 5000
  cin>>a>>b>>c>>d>>e;
  int A,B,C,D,E;
     cin>>A>>B>>C>>D>>E;//dragon 、ninja、iceman、lion、wolf 的攻击力。它们都大于0小于等于10000
  cout<<"Case ";
    cout<<temp-datacase<<":"<<endl;
  Army red("red",blood,a,b,c,d,e,1),blue("blue",blood,a,b,c,d,e,2);    //完成初始化。1 for red,2 for blue;
  CCreature * red_reach_blue=NULL,*blue_reach_red=NULL;
  for(time=0;;time++){    //时间的前进。
	  if(time*60>T) break;
  //0时的事情。
  bool whethermake=0;                                              //表示是否制造武士
   if(red.turn==5){
     if(red.blood>=red.dragon.blood){
      whethermake=true;
      red.make_a_dragon(time);
      float mora=0.0;
      mora=float(red.blood) / red.dragon.blood;
        Crea_dragon =new Cdragon(0,1,&red,red.dragon.blood,red.num,A,(red.num%3==0)?A/5:0,(red.num%3==1)?true:false,(red.num%3==2)?true:false, mora,0);
        City[0].red=Crea_dragon;                         //表示0号城市也就是红方基地有一名dragon类的武士。
        creature[++NUM]=Crea_dragon;
     }
   }
   if(red.turn==1){
	   if(red.blood>=red.iceman.blood){
		   whethermake=true;
		   red.make_a_iceman(time);
		   Crea_iceman=new Ciceman(0,3,&red,red.iceman.blood,red.num,C,(red.num%3==0)?C/5:0,(red.num%3==1)?true:false,(red.num%3==2)?true:false,0);
		   City[0].red=Crea_iceman;
		   creature[++NUM]=Crea_iceman;
	   }
   }
   if(red.turn==2){
	   if(red.blood>=red.lion.blood){
		   whethermake=true;
		   red.make_a_lion(time);
		   Crea_lion=new Clion(0,4,&red,red.lion.blood,red.num,D,0,false,false,red.blood);
		   City[0].red=Crea_lion;
		   creature[++NUM]=Crea_lion;
	   }
   }
   if(red.turn==3){
	   if(red.blood>=red.wolf.blood){
		   whethermake=true;
		   red.make_a_wolf(time);
		   Crea_wolf=new Cwolf(0,5,&red,red.wolf.blood,red.num,E,0,false,false);
		   City[0].red=Crea_wolf;
		   creature[++NUM]=Crea_wolf;
	   }
   }
   if(red.turn==4){
	   if(red.blood>=red.ninja.blood){
		   whethermake=true;
		   red.make_a_ninja(time);
		   int ifhavesword=(red.num%3==0)+(red.num%3==2);
		   bool w1=false,w2=false;
		   if(red.num%3==0 || red.num%3==1) w1=true;
		   if(red.num%3==2 || red.num%3==1) w2=true;
		   Crea_ninja=new Cninja(0,2,&red,red.ninja.blood,red.num,B,int(B/5)*ifhavesword,w1,w2);
		   City[0].red=Crea_ninja;
		   creature[++NUM]=Crea_ninja;
	   }
   }
if( whethermake){
	if(red.turn==5) red.turn=1;
	else red.turn++;
}
  whethermake=0;
     if(blue.turn==4){
  	   if(blue.blood>=blue.iceman.blood){
  		   whethermake=true;
  	       blue.make_a_iceman(time);
  		   Crea_iceman=new Ciceman(0,3,&blue,blue.iceman.blood,blue.num,C,(blue.num%3==0)?C/5:0,(blue.num%3==1)?true:false,(blue.num%3==2)?true:false,0);
  		   City[N+1].blue=Crea_iceman;
  		   creature[++NUM]=Crea_iceman;
  	   }
     }
     if(blue.turn==1){
  	   if(blue.blood>=blue.lion.blood){
  		   whethermake=true;
  		   blue.make_a_lion(time);
  		   Crea_lion=new Clion(0,4,&blue,blue.lion.blood,blue.num,D,0,false,false,blue.blood);
  		   City[N+1].blue=Crea_lion;
  		   creature[++NUM]=Crea_lion;
  		  // Clion * pp=(Clion *)City[N+1].blue;
  		 //  cout<<pp->loyalty<<endl;
  	   }
     }
     if(blue.turn==5){
  	   if(blue.blood>=blue.wolf.blood){
  		   whethermake=1;
  		   blue.make_a_wolf(time);
  		   Crea_wolf=new Cwolf(0,5,&blue,blue.wolf.blood,blue.num,E,0,false,false);
  		   City[N+1].blue=Crea_wolf;
  		   creature[++NUM]=Crea_wolf;
  	   }
     }
     if(blue.turn==3){
  	   if(blue.blood>=blue.ninja.blood){
  		   whethermake=true;
  		   blue.make_a_ninja(time);
  		   int ifhavesword=(blue.num%3==0)+(blue.num%3==2);
  		   bool w1=false,w2=false;
  	       if(blue.num%3==0 || blue.num%3==1) w1=true;
  		   if(blue.num%3==2 || blue.num%3==1) w2=true;
  		   Crea_ninja=new Cninja(0,2,&blue,blue.ninja.blood,blue.num,B,int(B/5)*ifhavesword,w1,w2);
  		   City[N+1].blue=Crea_ninja;
  		   creature[++NUM]=Crea_ninja;
  	   }
     }
     if(blue.turn==2){
          if(blue.blood>=blue.dragon.blood){
        	  whethermake=1;
              blue.make_a_dragon(time);
              float mora=0.0;
              mora=float(blue.blood) / blue.dragon.blood;
              Crea_dragon =new Cdragon(0,1,&blue,blue.dragon.blood,blue.num,A,(blue.num%3==0)?A/5:0,(blue.num%3==1)?true:false,(blue.num%3==2)?true:false, mora,N+1);
              City[N+1].blue=Crea_dragon;                         //表示0号城市也就是红方基地有一名dragon类的武士。
              creature[++NUM]=Crea_dragon;

          }
     }

     if(whethermake){
    	 if(blue.turn==5) blue.turn=1;
    	 else blue.turn++;
     }//制造武士部分完成。
//以下是每小时的第五分钟发生的事情。
     if(time*60+5>T) break;
     for(int i=0;i<=N+1;i++){
    	 if(City[i].red){
    		 if(i<N+1){
    			 if(City[i].red->name==4){
    			    Crea_lion=(Clion *)City[i].red;              //用强制类型转换来得到的lion的loyalty.
    			    if( Crea_lion->loyalty<=0){
    			        cout<<setfill('0')<<setw(3)<<time<<":05 "<<"red"<<" lion "<<Crea_lion->num<<" ran away\n";
    			        City[i].red=NULL;
    			     }
    		 }
    	 }
    }
 if(City[i].blue){
	 if(i>0){
		 if(City[i].blue->name==4){
		    Crea_lion=(Clion *)City[i].blue;
		    if( Crea_lion->loyalty<=0){
		        cout<<setfill('0')<<setw(3)<<time<<":05 "<<"blue"<<" lion "<<Crea_lion->num<<" ran away\n";
		        City[i].blue=NULL;
		     		   }
		     	  }
	 }
 }

}//每个整点05分lion逃跑时间完成。
//以下是10分发生的时候：武士前进到某一城市。
     if(time*60+10>T) break;
     for(int i=N;i>=0;--i){
    	if(City[i].red){
    		City[i+1].red=City[i].red;
    		City[i].red=NULL;
    		if(City[i+1].red->name==3)  {            //iceman的情况。
    	    		Ciceman * pppp=(Ciceman*)City[i+1].red;
    	    		pppp->step++;
    	    		if(pppp->step==2){
    	    			pppp->attack_+=20;
    	    			if(pppp->blood>9)  pppp->blood-=9;
    	    			else pppp->blood=1;
    	    			pppp->step=0;
    	    		}
    	    	}
    	}


     }
     for(int i=1;i<=N+1;++i){
    	 if(City[i].blue){
    		 City[i-1].blue=City[i].blue;
    		 City[i].blue=NULL;
    		if(City[i-1].blue->name==3)  {
    		     	     		Ciceman * pppp=(Ciceman*)City[i-1].blue;
    		     	     		pppp->step++;
    		     	     		if(pppp->step==2){
    		     	     	       pppp->attack_+=20;
    		     	     		   if(pppp->blood>9)  pppp->blood-=9;
    		     	     		   else pppp->blood=1;
    		     	      			pppp->step=0;
    		     	     		}
    		     	     	}
    	 }


     }//为了避免重复，先将武士移动到下一个位置，然后再进行输出。

     bool endif=0;
     for(int i=0;i<=N+1;++i){
    	 if(i==0 && City[0].blue!=NULL){
    		 City[0].enemy_num++;
    		 int tmp=City[i].blue->name;                       //reached blue headquarter with 20 elements and force 30
    		 cout<<setfill('0')<<setw(3)<<time<<":10 blue "<<wushi_name[tmp]<<" "<<City[i].blue->num
    		 <<" reached red headquarter with "<<City[i].blue->blood<<" elements and force "<<City[i].blue->attack_<<endl;
    		 if(City[0].enemy_num==2){
    			 endif=true;
    			 cout<<setfill('0')<<setw(3)<<time<<":10 red headquarter was taken"<<endl;
    		 }
    		 blue_reach_red=City[0].blue;
    		 City[0].blue=NULL;
    	 }
    	 if(i>0 && i<N+1){
    		 if(City[i].red){
    			 int tmp=City[i].red->name;
    			 cout<<setfill('0')<<setw(3)<<time<<":10 red "<<wushi_name[tmp]<<" "<<City[i].red->num
    			 <<" marched to city "<<i<<" with "<<City[i].red->blood<<" elements and force "<<City[i].red->attack_<<endl;
    		 }
    		 if(City[i].blue){
    			 int tmp=City[i].blue->name;
    			 cout<<setfill('0')<<setw(3)<<time<<":10 blue "<<wushi_name[tmp]<<" "<<City[i].blue->num
    		     <<" marched to city "<<i<<" with "<<City[i].blue->blood<<" elements and force "<<City[i].blue->attack_<<endl;
    		 }
    	 }
    	 if(i==N+1 && City[N+1].red!=NULL){
    		 City[N+1].enemy_num++;
    		 int tmp=City[i].red->name;
    		 cout<<setfill('0')<<setw(3)<<time<<":10 red "<<wushi_name[tmp]<<" "<<City[i].red->num
   			 <<" reached blue headquarter with "<<City[i].red->blood<<" elements and force "<<City[i].red->attack_<<endl;
    		 if(City[N+1].enemy_num==2){
    			 endif=true;
    			 cout<<setfill('0')<<setw(3)<<time<<":10 blue headquarter was taken"<<endl;
    		 }
    		 red_reach_blue=City[N+1].red;
    		 City[N+1].red=NULL;
    	}
     }       //10分发生的事情完成。
     //以下是20分钟的事情：每个城市产出10个生命元。生命元留在城市，直到被武士取走。
     if(endif) break;
     if(time*60+20>T) break;
     for(int i=1;i<=N+1;++i){
    	 City[i].blood+=10;
     }
     //以下是30分钟发生的事情。//000:30 red iceman 1 earned 10 elements for his headquarter
     //000:30 blue lion 1 earned 10 elements for his headquarter
     if(time*60+30>T) break;
     for(int i=1;i<=N;++i){
    	 if(City[i].red!=NULL && City[i].blue==NULL){
    		 red.blood+= City[i].blood;
    		 int tmp=City[i].red->name;
    		 cout<<setfill('0')<<setw(3)<<time<<":30 red "<<wushi_name[tmp]<<" "<<City[i].red->num<<" earned "<<City[i].blood
    	     <<" elements for his headquarter"<<endl;
    		 City[i].blood=0;
    	 }
    	 if(City[i].red==NULL && City[i].blue!=NULL){
    		 blue.blood+=City[i].blood;
    		 int tmp=City[i].blue->name;
    		 cout<<setfill('0')<<setw(3)<<time<<":30 blue "<<wushi_name[tmp]<<" "<<City[i].blue->num<<" earned "<<City[i].blood
    		 <<" elements for his headquarter"<<endl;
    		 City[i].blood=0;
    	 }
     }

//下面是武士放箭。35分钟发生的事情。
     if(time*60+35>T) break;
     for(int i=1;i<=N;++i){
    	 if(City[i].red){
    		if(City[i].red->WhetherHaveArrow==true && City[i+1].blue!=NULL){
    		   City[i+1].blue->hurted(R);
    		   City[i].red->array_time++;
    		   //if(City[i].red->array_time==3) City[i].red->WhetherHaveArrow=false;
    	    }
    	 }
    	if(City[i].blue){
    		if(City[i].blue->WhetherHaveArrow==true && City[i-1].red!=NULL){
    		   City[i-1].red->hurted(R);
    		   City[i].blue->array_time++;
    		   //if(City[i].blue->array_time==3) City[i].blue->WhetherHaveArrow=false;
            }
    	}
    	 //先进行攻击，再进行输出，以免先有被杀之后无法进行放箭的行为。
     }
     for(int i=1;i<=N;++i){
    	 if(City[i].red){
    	 if(City[i].red->WhetherHaveArrow==true && City[i+1].blue!=NULL){
    		 if(City[i+1].blue->blood<=0){
    			// City[i+1].blue=NULL;
    			 int tmp=City[i].red->name;
    			 int tmp1=City[i+1].blue->name;
    			 cout<<setfill('0')<<setw(3)<<time<<":35 red "<<wushi_name[tmp]<<" "<<City[i].red->num
    			 <<" shot and killed blue "<<wushi_name[tmp1]<<" "<<City[i+1].blue->num<<endl;
    		 }
    		 else {
    			 int tmp=City[i].red->name;
    			 cout<<setfill('0')<<setw(3)<<time<<":35 red "<<wushi_name[tmp]<<" "<<City[i].red->num<<" shot"<<endl;
    		 }
    		 if(City[i].red->array_time==3) City[i].red->WhetherHaveArrow=false;
    	 }
    	 }
    	 if(City[i].blue){
    	 if(City[i].blue->WhetherHaveArrow==true && City[i-1].red!=NULL){
    		 if(City[i-1].red->blood<=0){
    			// City[i-1].red=NULL;
    			 int tmp=City[i].blue->name;
    			 int tmp1=City[i-1].red->name;
    			 cout<<setfill('0')<<setw(3)<<time<<":35 blue "<<wushi_name[tmp]<<" "<<City[i].blue->num
    			 <<" shot and killed red "<<wushi_name[tmp1]<<" "<<City[i-1].red->num<<endl;
    		 }
    		 else {
    			 int tmp=City[i].blue->name;
    			 cout<<setfill('0')<<setw(3)<<time<<":35 blue "<<wushi_name[tmp]<<" "<<City[i].blue->num<<" shot"<<endl;
    		 }
    		 if(City[i].blue->array_time==3) City[i].blue->WhetherHaveArrow=false;
    	 }
    	 }

     }//35分钟的事情完成。
      //在每个小时的第38分，拥有bomb的武士评估是否应该使用bomb。如果是，就用bomb和敌人同归于尽。
//拥有bomb的武士，在战斗开始前如果判断自己将被杀死（不论主动攻击敌人，或者被敌人主动攻击都可能导致自己被杀死，
//而且假设武士可以知道敌人的攻击力和生命值），那么就会使用bomb和敌人同归于尽。武士不预测对方是否会使用bomb。
     if(time*60+38>T) break;
     for(int i=1;i<=N;++i){
    	 if(City[i].red && City[i].blue){
    		 if(City[i].flag=="red" || (City[i].flag=="no")+(i%2==1)==2){   //red first
    			 bool whether_use_bomb=false;
    			 if(City[i].red->blood>0 && City[i].blue->blood>0 && City[i].red->WhetherHaveBomb==true){
    				 int tmp_shanghai=City[i].red->attack_+City[i].red->attack_sword;
    				 if(City[i].blue->blood>tmp_shanghai){
    					 if(City[i].blue->name!=2)
    				    {int tmp_shanghai2=(int)(City[i].blue->attack_/2)+City[i].blue->attack_sword;
    				    if(tmp_shanghai2>=City[i].red->blood) whether_use_bomb=true;}
    		 	     }
    				 if(whether_use_bomb){
    					 int tmp=City[i].red->name;
    					 int tmp1=City[i].blue->name;
    					 cout<<setfill('0')<<setw(3)<<time<<":38 red "<<wushi_name[tmp]<<" "<<City[i].red->num
    					 <<" used a bomb and killed blue "<<wushi_name[tmp1]<<" "<<City[i].blue->num<<endl;
    					 City[i].red=NULL;
    					 City[i].blue=NULL;
    				 }
    			 }
    			 if(!whether_use_bomb){
    				if(City[i].red->blood>0 && City[i].blue->blood>0 && City[i].blue->WhetherHaveBomb){
    				 int tmp_shanghai=City[i].red->attack_+City[i].red->attack_sword;
    				 if(tmp_shanghai>=City[i].blue->blood){
    					 int tmp=City[i].blue->name;
    					 int tmp1=City[i].red->name;
    					 cout<<setfill('0')<<setw(3)<<time<<":38 blue "<<wushi_name[tmp]<<" "<<City[i].blue->num
    					 <<" used a bomb and killed red "<<wushi_name[tmp1]<<" "<<City[i].red->num<<endl;
    					 City[i].red=NULL;
    					 City[i].blue=NULL;
    				 }
    				}
    			 }
    		 }
    		 else{   //blue first
    			 bool whether_use_bomb=0;
    			 if(City[i].red->blood>0 && City[i].blue->blood>0 && City[i].blue->WhetherHaveBomb==true){
    				 int tmp_shanghai=City[i].blue->attack_+City[i].blue->attack_sword;
    				 if(City[i].red->blood>tmp_shanghai){
    					 if(City[i].red->name!=2){
    				    int tmp_shanghai2=(int)(City[i].red->attack_/2)+City[i].red->attack_sword;
    				    if(tmp_shanghai2>=City[i].blue->blood)  whether_use_bomb=true;}
    				 }
    				 if(whether_use_bomb){
    					 int tmp=City[i].blue->name;
    					 int tmp1=City[i].red->name;
    					 cout<<setfill('0')<<setw(3)<<time<<":38 blue "<<wushi_name[tmp]<<" "<<City[i].blue->num
    					 <<" used a bomb and killed red "<<wushi_name[tmp1]<<" "<<City[i].red->num<<endl;
    					 City[i].red=NULL;
    					 City[i].blue=NULL;
    				 }
    			 }
    			 if(!whether_use_bomb){
    			   if( City[i].red->blood>0 && City[i].blue->blood>0 && City[i].red->WhetherHaveBomb==true){
    				 int tmp_shanghai=City[i].blue->attack_+City[i].blue->attack_sword;
    				 if(tmp_shanghai>=City[i].red->blood){
    					 int tmp=City[i].red->name;
    					 int tmp1=City[i].blue->name;
    					 cout<<setfill('0')<<setw(3)<<time<<":38 red "<<wushi_name[tmp]<<" "<<City[i].red->num
    					 <<" used a bomb and killed blue "<<wushi_name[tmp1]<<" "<<City[i].blue->num<<endl;
    					 City[i].red=NULL;
    					 City[i].blue=NULL;
    				 }
    			   }
    			 }
    		 }
    	 }
     }            //38预测是否使用bomb完成。
//以下是最为激烈又最复杂的的战争时刻40分钟。
     if(time*60+40>T) break;
     int red_blood_get=0,blue_blood_get=0;
     for(int i=1;i<=N;++i){

    	 if(City[i].red && !City[i].blue){          //只有红方武士
    		 if(City[i].red->blood<=0)
    			 City[i].red=NULL;
    	 }
    	 if(!City[i].red && City[i].blue){          //只有蓝方武士
    		 if(City[i].blue->blood<=0)
    			 City[i].blue=NULL;
    	 }
    	 if(City[i].red && City[i].blue){


    		 //这个城市有两个武士。（可能有一个甚至两个被箭杀死）。
    		 if(City[i].red->blood<=0 && City[i].blue->blood<=0){       //两个都被箭杀死了,什么都不会发生，没有发生战斗。
    			 City[i].red=NULL;
    			 City[i].blue=NULL;
    		 }


    	 else if(City[i].red->blood<=0 && City[i].blue->blood>0){         //红方武士被箭杀死了。
    		// City[i].red=NULL;   先把它留着会有一些用处。
    			 //先看是否有（9）的发生。
    		 City[i].who_get_bonus="blue";
    			 if(City[i].blue->name==1){
    				 Cdragon * tmp= (Cdragon *)City[i].blue;
    				 tmp->morale+=0.2;
    				 if(City[i].flag=="blue" || (City[i].flag=="no")+(i%2==0)==2){
    					 //如果是dragon主动进攻胜利的话，他可能会呐喊。
    					 //003:40 blue dragon 2 yelled in city 4
                        if(tmp->morale>0.8)
                           cout<<setfill('0')<<setw(3)<<time<<":40 blue dragon "<<City[i].blue->num<<" yelled in city "<<i<<endl;
    				 }
    			 }    //以上为如果存活的是dragon。
    			 if(City[i].blue->name==5){
    				 if(City[i].blue->WhetherHaveArrow==false  &&  City[i].red->WhetherHaveArrow==true){
    					 City[i].blue->WhetherHaveArrow=true;
    					 City[i].blue->array_time=City[i].red->array_time;
    				 }
    				 if(City[i].blue->WhetherHaveBomb==false && City[i].red->WhetherHaveBomb==true){
    					 City[i].blue->WhetherHaveBomb=true;
    				 }
    				 if(City[i].blue->attack_sword==0 && City[i].red->attack_sword>0){
    					 City[i].blue->attack_sword=City[i].red->attack_sword;
    				 }
    			 }//以上为如果存活的是wolf,它会缴获对方的武器。
    			 //10) 武士获取生命元( elements )
    			 //输出样例：001:40 blue dragon 2 earned 10 elements for his headquarter
    			 blue_blood_get+=City[i].blood;
    			 int tmp=City[i].blue->name;
    			 cout<<setfill('0')<<setw(3)<<time<<":40 blue "<<wushi_name[tmp]<<" "<<City[i].blue->num
    		         <<" earned "<<City[i].blood<<" elements for his headquarter"<<endl;
    			 City[i].blood=0;
    			 City[i].red=NULL;     //red武士可以消亡了。
    			 if(City[i].lastbattle=="blue"){
    				 //城市的旗子变化等等。11) 旗帜升起
    				 //输出样例：004:40 blue flag raised in city 4
    				 if(City[i].flag!="blue"){
    					 City[i].flag="blue";
    					 cout<<setfill('0')<<setw(3)<<time<<":40 blue flag raised in city "<<i<<endl;
    				 }
    			 }
    			  else City[i].lastbattle="blue";

    	 }

    	 else if(City[i].red->blood>0 && City[i].blue->blood<=0){                           //蓝方武士被箭杀死了。
    		 City[i].who_get_bonus="red";
    		 if(City[i].red->name==1){
    			 Cdragon * tmp= (Cdragon *)City[i].red;
    			 tmp->morale+=0.2;
    			 if(City[i].flag=="red" || (City[i].flag=="no")+(i%2==1)==2){
    				 if(tmp->morale>0.8)
    					 cout<<setfill('0')<<setw(3)<<time<<":40 red dragon "<<City[i].red->num<<" yelled in city "<<i<<endl;
    			 }
    		 }
    		 if(City[i].red->name==5){
    		    if(City[i].red->WhetherHaveArrow==0  &&  City[i].blue->WhetherHaveArrow==1){
    		       City[i].red->WhetherHaveArrow=1;
    		       City[i].red->array_time=City[i].blue->array_time;
    		    }
    		    if(City[i].red->WhetherHaveBomb==0 && City[i].blue->WhetherHaveBomb==1){
    		       City[i].red->WhetherHaveBomb=1;
    		    }
    		    if(City[i].red->attack_sword==0 && City[i].blue->attack_sword>0){
    		       City[i].red->attack_sword=City[i].blue->attack_sword;
    		    }
    	     }
    		 red_blood_get+=City[i].blood;
    		 int tmp=City[i].red->name;
    		 cout<<setfill('0')<<setw(3)<<time<<":40 red "<<wushi_name[tmp]<<" "<<City[i].red->num
    		     <<" earned "<<City[i].blood<<" elements for his headquarter"<<endl;
    		 City[i].blood=0;
    		 City[i].blue=NULL;
    		 if(City[i].lastbattle=="red"){
    		    if(City[i].flag!="red"){
    		       City[i].flag="red";
    		       cout<<setfill('0')<<setw(3)<<time<<":40 red flag raised in city "<<i<<endl;
    		    }
    		 }
    		 else City[i].lastbattle="red";
    	 }

    	 else {               //这是双方都存活的状态。
    		 string winner="no";
    		 int red_ori_blood=City[i].red->blood,blue_ori_blood=City[i].blue->blood;
    		 //战斗时只有血量发生变化，提前存一下后面可以用。
    		 if(City[i].flag=="red" || (City[i].flag=="no")+(i%2==1)==2){                  //red先手。
                 City[i].red->attack(City[i].blue);
                 City[i].red->attack_sword=(int)(City[i].red->attack_sword*4/5);
               //  6) 武士主动进攻
                 //输出样例：000:40 red iceman 1 attacked blue lion 1 in city 1 with 20 elements and force 30
                 cout<<setfill('0')<<setw(3)<<time<<":40 red "<<wushi_name[City[i].red->name]<<" "
                     <<City[i].red->num<<" attacked blue "<<wushi_name[City[i].blue->name]<<" "<<City[i].blue->num
                     <<" in city "<<i<<" with "<<City[i].red->blood<<" elements and force "<<City[i].red->attack_<<endl;
    			 if(City[i].blue->blood<=0)  winner="red";
    			 else {
    				 if(City[i].blue->name==2){
    					 winner="no";
    				 }
    				 else{
    					  City[i].blue->fightback(City[i].red);
    					  City[i].blue->attack_sword=(int)(City[i].blue->attack_sword*4/5);
    					  //7) 武士反击
    					  //输出样例：001:40 blue dragon 2 fought back against red lion 2 in city 1
    					  cout<<setfill('0')<<setw(3)<<time<<":40 blue "<<wushi_name[City[i].blue->name]
    					      <<" "<<City[i].blue->num<<" fought back against red "<<wushi_name[City[i].red->name]
    					      <<" "<<City[i].red->num<<" in city "<<i<<endl;
    				      if(City[i].red->blood<=0) winner="blue";
    				 }

    			 }
    		 }
    		 else {                                                                        //blue先手。
    			 City[i].blue->attack(City[i].red);
    			 City[i].blue->attack_sword=(int)(City[i].blue->attack_sword*4/5);
    			 cout<<setfill('0')<<setw(3)<<time<<":40 blue "<<wushi_name[City[i].blue->name]<<" "
    			     <<City[i].blue->num<<" attacked red "<<wushi_name[City[i].red->name]<<" "<<City[i].red->num
    			     <<" in city "<<i<<" with "<<City[i].blue->blood<<" elements and force "<<City[i].blue->attack_<<endl;
    			 if(City[i].red->blood<=0)  winner="blue";
    			 else {
    				 if(City[i].red->name==2){
    					 winner="no";
    				 }
    				 else{
    					 City[i].red->fightback(City[i].blue);
    					 City[i].red->attack_sword=(int)(City[i].red->attack_sword*4/5);
    					 cout<<setfill('0')<<setw(3)<<time<<":40 red "<<wushi_name[City[i].red->name]
    			             <<" "<<City[i].red->num<<" fought back against blue "<<wushi_name[City[i].blue->name]
    			             <<" "<<City[i].blue->num<<" in city "<<i<<endl;
    					  if(City[i].blue->blood<=0) winner="red";
    				 }
    			 }
    		 }
    		 if(winner=="no"){   //如果双方战平。
    			 City[i].lastbattle="no";
    			 if(City[i].red->name==1){                  //red dragon 的情况。
    				 Cdragon * pp=(Cdragon *)City[i].red;
    				 pp->morale-=0.2;
    				 if(City[i].flag=="red" || (City[i].flag=="no")+(i%2==1)==2){
    					 if(pp->morale>0.8)
    						cout<<setfill('0')<<setw(3)<<time<<":40 red dragon "<<City[i].red->num<<" yelled in city "<<i<<endl;
    				 }
    			 }
    			 if(City[i].red->name==4){                  //red lion的情况。
    				 Clion * ppp=(Clion *)City[i].red;
    				 ppp->loyalty-=K;
    			 }
    			 if(City[i].blue->name==4){
    				 Clion * ppp=(Clion *)City[i].blue;
    				 ppp->loyalty-=K;
    			 }
    			 if(City[i].blue->name==1){                 //blue dragon 的情况。
    				 Cdragon * pp=(Cdragon *)City[i].blue;
    				 pp->morale-=0.2;
    				 if(City[i].flag=="blue" || (City[i].flag=="no")+(i%2==0)==2){
    					 if(pp->morale>0.8)
    						cout<<setfill('0')<<setw(3)<<time<<":40 blue dragon "<<City[i].blue->num<<" yelled in city "<<i<<endl;
    				 }
    			 }
    	     }

    		 else if(winner=="red"){             //红方获胜。
    			 //8) 武士战死
    			// 输出样例：001:40 red lion 2 was killed in city 1
    			 cout<<setfill('0')<<setw(3)<<time<<":40 blue "<<wushi_name[City[i].blue->name]<<" "
    			     <<City[i].blue->num<<" was killed in city "<<i<<endl;


    			 if(City[i].blue->name==4){                 //blue死的是lion的情况。
    				 City[i].red->blood+=blue_ori_blood;
    			 }
    			if(City[i].red->name==1){                    //red胜利的是dragon。
    				 Cdragon * pp=(Cdragon *)City[i].red;
    				 pp->morale+=0.2;
    				 if(City[i].flag=="red" || (City[i].flag=="no")+(i%2==1)==2){
    					 if(pp->morale>0.8)
    						 cout<<setfill('0')<<setw(3)<<time<<":40 red dragon "<<City[i].red->num<<" yelled in city "<<i<<endl;
    				 }
    			}
    			 if(City[i].red->name==5){                     //red胜利的是wolf。
    			    if(City[i].red->WhetherHaveArrow==false  &&  City[i].blue->WhetherHaveArrow==true){
    			       City[i].red->WhetherHaveArrow=true;
    			       City[i].red->array_time=City[i].blue->array_time;
    			    }
    			    if(City[i].red->WhetherHaveBomb==false && City[i].blue->WhetherHaveBomb==true){
    			       City[i].red->WhetherHaveBomb=true;
    			    }
    			    if(City[i].red->attack_sword==0 && City[i].blue->attack_sword>0){
    			       City[i].red->attack_sword=City[i].blue->attack_sword;
    			    }
    			 }
    			 red_blood_get+=City[i].blood;     //武士获取生命元。
    			 cout<<setfill('0')<<setw(3)<<time<<":40 red "<<wushi_name[City[i].red->name]<<" "<<City[i].red->num
    			     <<" earned "<<City[i].blood<<" elements for his headquarter"<<endl;
    			 City[i].blood=0;
    			 if(City[i].lastbattle=="red"){            //旗帜升起。
    			    if(City[i].flag!="red"){
    			       City[i].flag="red";
    			       cout<<setfill('0')<<setw(3)<<time<<":40 red flag raised in city "<<i<<endl;
    			    }
    			 }
    			 else City[i].lastbattle="red";
    			 City[i].blue=NULL;                        //死亡的武士消亡了。
    		 }

    		 else{                        //blue 获胜。
    			 cout<<setfill('0')<<setw(3)<<time<<":40 red "<<wushi_name[City[i].red->name]<<" "
    			     <<City[i].red->num<<" was killed in city "<<i<<endl;

    			 if(City[i].red->name==4){                 //red死的是lion的情况。
    			    City[i].blue->blood+=red_ori_blood;
    			 }
    			 if(City[i].blue->name==1){
    				 Cdragon * pp=(Cdragon *)City[i].blue;
    				 pp->morale+=0.2;
    				 if(City[i].flag=="blue" || (City[i].flag=="no")+(i%2==0)==2){
    					 if(pp->morale>0.8)
    					    cout<<setfill('0')<<setw(3)<<time<<":40 blue dragon "<<City[i].blue->num<<" yelled in city "<<i<<endl;
    				 }
    			 }
    			 if(City[i].blue->name==5){
    				 if(City[i].blue->WhetherHaveArrow==false  &&  City[i].red->WhetherHaveArrow==true){
    				    City[i].blue->WhetherHaveArrow=true;
                        City[i].blue->array_time=City[i].red->array_time;
    				 }
    				 if(City[i].blue->WhetherHaveBomb==false && City[i].red->WhetherHaveBomb==true){
    				    City[i].blue->WhetherHaveBomb=true;
    				 }
    				 if(City[i].blue->attack_sword==0 && City[i].red->attack_sword>0){
    				    City[i].blue->attack_sword=City[i].red->attack_sword;
    				 }
    			 }
    			blue_blood_get+=City[i].blood;     //武士获取生命元。
    			cout<<setfill('0')<<setw(3)<<time<<":40 blue "<<wushi_name[City[i].blue->name]<<" "<<City[i].blue->num
    		        <<" earned "<<City[i].blood<<" elements for his headquarter"<<endl;
     		    City[i].blood=0;
     		   if(City[i].lastbattle=="blue"){
     		       if(City[i].flag!="blue"){
     		          City[i].flag="blue";
     		          cout<<setfill('0')<<setw(3)<<time<<":40 blue flag raised in city "<<i<<endl;
     		       }
     		   }
     		   else City[i].lastbattle="blue";
     		  City[i].red=NULL;                        //死亡的武士消亡了。
    		 }
    		 City[i].who_get_bonus=winner;
    	 }
   }




     }


     //接下来进行奖励。
         	 //for red
         	 for(int j=N;j>=1;--j){
         		 if(City[j].who_get_bonus=="red"){
         			 if(red.blood>=8){ City[j].red->blood+=8;red.blood-=8;}
         			 else break;
         		 }
         	 }
         	 for(int j=1;j<=N;++j){
         		 if(City[j].who_get_bonus=="blue"){
         			 if(blue.blood>=8) {City[j].blue->blood+=8;blue.blood-=8;
}
         			 else break;
         		 }
         	 }
         	 for( int j=1;j<=N;++j){
         		 City[j].who_get_bonus="no";
         	 }
         	 red.blood+=red_blood_get;
         	 blue.blood+=blue_blood_get;
         		 /*if(City[i].who_get_bonus=="blue"){
         			 if(blue.blood>=8) City[i].blue->blood+=8;
         			 City[i].who_get_bonus="no";
         		 }*/


//下面是50分钟发生的事情。司令部报告它拥有的生命元数量。
//000:50 100 elements in red headquarter
//000:50 120 elements in blue headquarter
         	if(time*60+50>T) break;
     cout<<setfill('0')<<setw(3)<<time<<":50 "<<red.blood<<" elements in red headquarter"<<endl;
     cout<<setfill('0')<<setw(3)<<time<<":50 "<<blue.blood<<" elements in blue headquarter"<<endl;
//50分钟的事件完成。
//下面是55分钟的事件：在每个小时的第55分，每个武士报告其拥有的武器情况。
//000:55 blue wolf 2 has arrow(2),bomb,sword(23)
//000:55 blue wolf 4 has no weapon
//000:55 blue wolf 5 has sword(20)
     if(time*60+55>T) break;
     for(int i=1;i<=N;++i){
    	 //for red
         if(City[i].red){
        	 bool have1=false,have2=false,have3=false;
        	 have1=City[i].red->WhetherHaveArrow;
        	 have2=City[i].red->WhetherHaveBomb;
        	 if(City[i].red->attack_sword>0) have3=true;
        	 else have3=false;
        	 if(!have1 && !have2 && !have3){//000:55 blue wolf 4 has no weapon
        		 int tmp=City[i].red->name;
        		 cout<<setfill('0')<<setw(3)<<time<<":55 red "<<wushi_name[tmp]<<" "<<City[i].red->num<<" has no weapon"<<endl;
        	 }
        	 else {//000:55 blue wolf 2 has arrow(2),bomb,sword(23)
        		 int tmp=City[i].red->name;
        		 cout<<setfill('0')<<setw(3)<<time<<":55 red "<<wushi_name[tmp]<<" "<<City[i].red->num<<" has ";
        		 if(have1) cout<<"arrow("<<3-City[i].red->array_time<<")";
        		 if(have2){
        			 if(have1) cout<<",bomb";
        			 else cout<<"bomb";
        		 }
        		 if(have3){
        			 if(have1 || have2) cout<<",sword("<<City[i].red->attack_sword<<")";
        			 else cout<<"sword("<<City[i].red->attack_sword<<")";
        		 }
        		 cout<<endl;
        	}
         }
     }
     if(red_reach_blue){
    	 bool have1=false,have2=false,have3=false;
    	 have1=red_reach_blue->WhetherHaveArrow;
    	 have2=red_reach_blue->WhetherHaveBomb;
    	 if(red_reach_blue->attack_sword>0) have3=true;
    	 else have3=false;
    	 if(!have1 && !have2 && !have3){
    	    int tmp=red_reach_blue->name;
    	    cout<<setfill('0')<<setw(3)<<time<<":55 red "<<wushi_name[tmp]<<" "<<red_reach_blue->num<<" has no weapon"<<endl;
      	 }
    	 else {
    	         		 int tmp=red_reach_blue->name;
    	         		 cout<<setfill('0')<<setw(3)<<time<<":55 red "<<wushi_name[tmp]<<" "<<red_reach_blue->num<<" has ";
    	         		 if(have1) cout<<"arrow("<<3-red_reach_blue->array_time<<")";
    	         		 if(have2){
    	         			 if(have1) cout<<",bomb";
    	         			 else cout<<"bomb";
    	         		 }
    	         		 if(have3){
    	         			 if(have1 || have2) cout<<",sword("<<red_reach_blue->attack_sword<<")";
    	         			 else cout<<"sword("<<red_reach_blue->attack_sword<<")";
    	         		 }
    	         		 cout<<endl;
    	         	}

     }
    //red 武器情况报告完毕。
     if(blue_reach_red){
        	 bool have1=false,have2=false,have3=false;
        	 have1=blue_reach_red->WhetherHaveArrow;
        	 have2=blue_reach_red->WhetherHaveBomb;
        	 if(blue_reach_red->attack_sword>0) have3=true;
        	 else have3=false;
        	 if(!have1 && !have2 && !have3){
        	    int tmp=blue_reach_red->name;
        	    cout<<setfill('0')<<setw(3)<<time<<":55 blue "<<wushi_name[tmp]<<" "<<blue_reach_red->num<<" has no weapon"<<endl;
          	 }
        	 else {
        	         		 int tmp=blue_reach_red->name;
        	         		 cout<<setfill('0')<<setw(3)<<time<<":55 blue "<<wushi_name[tmp]<<" "<<blue_reach_red->num<<" has ";
        	         		 if(have1) cout<<"arrow("<<3-blue_reach_red->array_time<<")";
        	         		 if(have2){
        	         			 if(have1) cout<<",bomb";
        	         			 else cout<<"bomb";
        	         		 }
        	         		 if(have3){
        	         			 if(have1 || have2) cout<<",sword("<<blue_reach_red->attack_sword<<")";
        	         			 else cout<<"sword("<<blue_reach_red->attack_sword<<")";
        	         		 }
        	         		 cout<<endl;
        	         	}

         }
     for(int i=1;i<=N;++i){ //for blue
    	 if(City[i].blue){
    		 bool have1=false,have2=false,have3=false;
    		 have1=City[i].blue->WhetherHaveArrow;
          	 have2=City[i].blue->WhetherHaveBomb;
          	 if(City[i].blue->attack_sword>0) have3=true;
    	     else have3=false;
          	if(!have1 && !have2 && !have3){//000:55 blue wolf 4 has no weapon
       		   int tmp=City[i].blue->name;
          	   cout<<setfill('0')<<setw(3)<<time<<":55 blue "<<wushi_name[tmp]<<" "<<City[i].blue->num<<" has no weapon"<<endl;
       	    }
          	 else {//000:55 blue wolf 2 has arrow(2),bomb,sword(23)
          		   int tmp=City[i].blue->name;
          	       cout<<setfill('0')<<setw(3)<<time<<":55 blue "<<wushi_name[tmp]<<" "<<City[i].blue->num<<" has ";
          	       if(have1) cout<<"arrow("<<3-City[i].blue->array_time<<")";
          	       if(have2){
          	         if(have1) cout<<",bomb";
          	         else cout<<"bomb";
          	       }
          	       if(have3){
          	         if(have1 || have2) cout<<",sword("<<City[i].blue->attack_sword<<")";
          	         else cout<<"sword("<<City[i].blue->attack_sword<<")";
          	       }
          	       cout<<endl;
          	 }
    	 }
     }      //blue 武器情况报告完毕
}             //对应的是时间的那个大括号
  for(int j=1;j<=NUM;++j){
	  if(creature[j]){
		  delete creature[j];
	  }
  }

  }             //对应的是datacase的那个大括号
return 0;
}