#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
class Gun
{
    public:
    int damage=50;
    int points=2;
    int count=0;
    
    public:
    void incount()
    {
        count++;
    }
}G;
class Bat
{
    public:
    int damage=25;
    int points=5;
    int count=0;
    
    public:
    void incount()
    {
        count++;
    }
}B;
class Axe
{
    public:
    int damage=40;
    int points=4;
    int count=0;
    
    public:
    void incount()
    {
        count++;
    }
}A;
void intro();
void intro2();
int level1();
int level2();
int practice();
int level3();
bool status=false;
string name;
int p_health=100,z_health=100,p_attack,z_attack=5,weapon,weapon2,power;
int main()
{
   
    status= true;
    char ch;
    cout<<"Enter name:";
    cin>>name;
    intro();
}
void intro()
{   
    char ch;
    cout<<"Welcome "<<name<<endl;
    cout<<"You need to kill zombies YAY!!!!"<<endl;
    cout<<"When propmted enter a number in the given range"<<endl;
    cout<<"If your number and the computer generated number match you'll lose 5 HP"<<endl;
    cout<<"20 zombie attacks will kill you"<<endl;
    cout<<"After each hit you need to choose a weapon, corresponding to the weapon you'll get certain points after a kill"<<endl;
    cout<<"\t\t\t===REMEMBER YOU CAN USE=== \n\t\t\t===A GUN ONLY TWICE===\n\t\t\t===A BAT ONLY 4 TIMES===\n\t\t\t===AN AXE ONLY THRICE===="<<endl;
    // cout<<"After attaining 100 points you can unlock a power up which will reduce the opponents health by 50%"<<endl;
    cout<<"Would you like to practice first or start playing(p/y/n)";
    cin>>ch;
    if(ch=='y')
    {
        level1();
    }
    else if(ch=='n')
    {
        cout<<"HOPE TO SEE YOU SOON"<<endl;
        cout<<"BYE!!!!!"<<endl;
    }
    else
    {
        cout<<"\n\nWelcome to the practice session"<<endl;
        cout<<"You'll have unlimited life here (although you will be shown the health bar for your understanding) but the zombie will not. It will have a fixed life of 100HP."<<endl;
        cout<<"You will have to enter a no. in the range from 0-80.Follow the same instructions as given above"<<endl;
        cout<<"To leave the practice session at any point enter 'e'"<<endl;
        cout<<"GOOD LUCK!!!";
        practice();
        cout<<endl<<"CONGRATULATIONS YOU JUST KILLED A ZOMBIE"<<endl;
        cout<<"Would you like to practice forward(if you press 'n' you will be sent to the first level.To exit the game press 'e') (y/n/e):";
        cin>>ch;
        if(ch=='y')
        {
            level2();
        }
        else if(ch=='e')
        {
            exit(0);
        }
        else
        {
            cout<<"HOPE TO SEE YOU SOON"<<endl;
            cout<<"BYE!!!!!"<<endl;
        }
    }
    
    
    
}
void intro2()
{
    char ch;

    cout<<name<<"!! You killed the level 1 zombies YAY!!!!"<<endl;
    cout<<"Level 2 zombies have much more health"<<endl;
    // cout<<"You have "<<150-power<<" points left to unlock the next powerup"<<endl;
    cout<<"After each hit you need to choose a weapon the weapons will have the same amount of damage and"<<endl;
    cout<<"4 Zombie attacks will kill you"<<endl;
    cout<<"\t\t\t===REMEMBER YOU CAN USE=== \n\t\t\t===A GUN ONLY TWICE===\n\t\t\t===A BAT ONLY 4 TIMES===\n\t\t\t===AN AXE ONLY THRICE===="<<endl;
    // cout<<"After attaining the required points you can unlock a power up which will reduce the opponents health by 40%"<<endl;
    cout<<"Would you like to start (y/n):";
    cin>>ch;
    if(ch=='y')
    {
        level2();
    }
    else
    {
        cout<<"HOPE TO SEE YOU SOON"<<endl;
        cout<<"BYE!!!!!"<<endl;
    }
}
int level1()
{
    while(z_health>0)
    {
        // if(power==100)
        // {
        //     cout<<"You can use the powerup";
        //     status= true;
        //     cout<<"\nTo use the powerup press 4 when choosing weapon";
        // }
        if(p_health<0)
        {
            p_health=0;
            return 0;
        }
        if(z_health<0)
        {
            z_health=0;
            return 0;
        }
        cout<<"\n\t\t\t===LEVEL 1====\n";
        cout<<"Health = "<<p_health<<"\t Zombie = "<<z_health<</*"\tPower = "<<power<<*/endl;
        cout<<"1)Gun(Damage=50 HP\tPoints=2x) \n2)Bat(Damage=25 HP \tpoints=5x) \n3)Axe(Damage=40 HP \tpoints=4x)"<<endl;
        cout<<"Enter weapon number:";
        cin>>weapon;
        switch(weapon)
        {
            //GUN
            case 1:
                    if(G.count==2)
                    {
                        cout<<"A gun can only be used 2 times!!!!!";
                        break;
                    }
                    cout<<"\nEnter attack number(1-20):";
                    cin>>p_attack;
                    if((20<p_attack)||(p_attack<0))
                    {
                        cout<<"Please enter a number between the given range"<<endl;
                        break;
                    }
                    if(p_attack==z_attack)//reduce players health
                    {
                    p_health=p_health-5;
                    cout<<"\nOOH THAT MUST'VE HURT HOPE YOU AREN'T INFECTED";
                    z_attack=z_attack+5;
                    if(z_attack>20)
                    {
                        z_attack-=9;
                    }
                    else if(z_attack<0)
                    {
                        z_attack+=2;
                    }


                    if(p_health==0)
                    {
                        cout<<endl<<"\nOOH YOU GOT INFECTED";
                        
                        return 0;
                    }
                    }
                else
                {
                    z_health-=G.damage;//reduce zombie health
                    cout<<"\nGREAT JOB YOU'VE HIT THE ZOMBIE";
                    // power=power + power;
                    // power=p_attack*G.points;//increase power
                    //make number randomer
                    z_attack=z_attack+5;
                    if(z_attack>20)
                    {
                        z_attack-=9;
                    }
                    else if(z_attack<0)
                    {
                        z_attack+=2;
                    }
                }
                G.incount();
            break; 
                // CASE 2 BAT
            case 2:
                
                    if(B.count==4)
                    {
                        cout<<"A bat can only be used 4 times!!!!!";break;
                    }
                cout<<"\nEnter attack number(1-20):";
                cin>>p_attack;
                if((20<p_attack)||(p_attack<0))
                    {
                        cout<<"Please enter a number between the given range"<<endl;
                        break;
                    }
                if(p_attack==z_attack)
                {
                    p_health-=5;
                    cout<<"\nTHE ZOMBIE ATTACKED YOU, YOU JUST LOST 5HP";
                    if(p_health==0)
                    {
                        cout<<endl<<"OOH YOU GOT INFECTED";
                        return 0;
                    }
                }
                else
                {
                    z_health-=B.damage;
                    cout<<"\nGREAT JOB YOU'VE HIT THE ZOMBIE";
                    // power=power+power;
                    // power=p_attack*B.points;
                    //make number randomer
                    z_attack=z_attack+5;
                    if(z_attack>20)
                    {
                        z_attack-=9;
                    }
                    if(z_attack<0)
                    {
                        z_attack+=2;
                    }
                }
                B.incount();
            break;
            // CASE 3 AXE
            case 3:
                    if(A.count==3)
                    {
                        cout<<"An axe can only be used 3 times!!!!!";
                        break;
                    }
                cout<<"\nEnter attack number(1-20):";
                cin>>p_attack;
                if((20<p_attack)||(p_attack<0))
                    {
                        cout<<"Please enter a number between the given range"<<endl;
                        break;
                    }
                if(p_attack==z_attack)
                {
                    p_health-=5;
                    cout<<"\nTHE ZOMBIE ATTACKED YOU, YOU JUST LOST 5HP";
                    if(p_health==0)
                    {
                        cout<<endl<<"OOH YOU GOT INFECTED";
                        return 0;
                    }
                }
                else
                {
                    z_health-=A.damage;
                    cout<<"GREAT JOB YOU'VE HIT THE ZOMBIE";
                    // power=power+power;
                    // power=p_attack*A.points;
                    //make number randomer
                    z_attack=z_attack+5;
                    if(z_attack>20)
                    {
                        z_attack-=9;
                    }
                    if(z_attack<0)
                    {
                        z_attack+=2;
                    }
                }
                A.incount();
            break;
            case 4:
                z_health=0.5*z_health;
            break;
            default:
                cout<<"\nSorry invalid input";
            break;
        }
        
    }
	// power+=power;
    cout<<endl<<"CONGRATULATIONS YOU JUST KILLED A ZOMBIE. HOPE YOU'RE READY FOR THE NEXT ROUND"<<endl;
    p_health-=5;
    intro2();
    return 0;
}
int level2()
{
	// cout<<power<<endl;
    G.count=0;
    B.count=0;
    A.count=0;
    z_health=200;
    z_attack=5;
    while(z_health>0)
    {
        // if(power==150)
        // {
        //     cout<<"You can use the powerup";
        //     status= true;
        //     cout<<"\nTo use the powerup press 4 when choosing weapon";
        // }
        if(p_health<0)
        {
            p_health=0;
            return 0;
        }
        cout<<"\n\t\t\t===LEVEL 2===\n";
        cout<<"Health = "<<p_health<<"\t Zombie = "<<z_health<</*"\tPower = "<<power<<*/endl;
        cout<<"1)Gun(Damage=50 hp\tPoints=2x) \n2)Bat(Damage=25 HP \tpoints=5x) \n3)Axe(Damage=40 HP \tpoints=4x)\n";
        cout<<"Enter weapon number:";
        cin>>weapon;
        switch (weapon)
        {
        case 1:
                if(G.count==2)
                {
                    cout<<"A gun can only be used 2 times!!!!!";
                    break;
                }
            cout<<"Enter attack number(1-10):";
            cin>>p_attack;
            if((10<p_attack)||(p_attack<0))
                    {
                        cout<<"Please enter a number between the given range"<<endl;
                        break;
                    }
            if(p_attack==z_attack)
            {
                p_health=p_health-30;
                cout<<"OOH THAT MUST'VE HURT, HOPE YOU AREN'T INFECTED";
            }
            else
            {
                z_health-=G.damage;
                cout<<"GREAT JOB YOU'VE HIT THE ZOMBIE";
                // power=power+power;
                // power=p_attack*G.points;
            }
            G.incount();
            z_attack=z_attack+5;
            if(z_attack>10)
            {
                z_attack-=3;
            }
            else if(z_attack<0)
            {
                z_attack+=2;
            }
            if(p_health==0)
            {
                cout<<endl<<"OOH YOU GOT INFECTED";                    
                return 0;
            }
        break;
        case 2:
                    if(B.count==4)
                    {
                        cout<<"A bat can only be used 4 times!!!!!";
                        break;
                    }
            cout<<"Enter attack number(1-10):";
            cin>>p_attack;
            if((10<p_attack)||(p_attack<0))
                    {
                        cout<<"Please enter a number between the given range"<<endl;
                        break;
                    }
            if(p_attack==z_attack)
            {
                p_health-=25;
                cout<<"THE ZOMBIE ATTACKED YOU, YOU JUST LOST 25 HP";
                if(p_health==0)
                {
                    cout<<endl<<"OOH YOU GOT INFECTED";
                    return 0;
                }
            }
            else
            {
                z_health-=B.damage;
                cout<<"GREAT JOB YOU'VE HIT THE ZOMBIE";
                // power=p_attack*B.points;
                // power=power+power;
            }
            B.incount();
            z_attack=z_attack+5;
            if(z_attack>10)
            {
                z_attack-=3;
            }
            else if(z_attack<0)
            {
                z_attack+=2;
            }
        break;
        case 3:
                    if(A.count==3)
                    {
                        cout<<"An axe can only be used 3 times!!!!!";
                        break;
                    }
            cout<<"Enter attack number (1-10):";
            cin>>p_attack;
            if((10<p_attack)||(p_attack<0))
                    {
                        cout<<"Please enter a number between the given range"<<endl;
                        break;
                    }
            if(p_attack==z_attack)
            {
                p_health-=25;
                cout<<"THE ZOMBIE ATTACKED YOU, YOU JUST LOST 25 HP";
                if(p_health==0)
                {
                    cout<<endl<<"OOH YOU GOT INFECTED";
                    return 0;
                }
            }
            else
            {
                z_health-=A.damage;
                cout<<"GREAT JOB YOU'VE HIT THE ZOMBIE";
                // power=p_attack*A.points;
                // power=power+power;
            }
            A.incount();
            z_attack=z_attack+5;
            if(z_attack>10)
            {
                z_attack-=3;
            }
            else if(z_attack<0)
            {
                z_attack+=2;
            }
        break;
        case 4:
            z_health=0.4*z_health;
        break;
        default:
            cout<<"Invalid input!!!!";
            break;
        }
    }
	// power+=power;
    cout<<"YES!!!!!!!!!!!!"<<endl;
    cout<<"YOU KILLED THE LEVEL 2 ZOMBIE"<<endl;
    p_health-=10;
    level3();
}
int level3()
{      
    G.count=0;
    B.count=0;
    A.count=0;
    z_attack=3;    
    z_health=250;
    while(z_health>0)
    {
        // if(power==100)
        // {
        //     cout<<"You can use the powerup";
        //     status= true;
        //     cout<<"\nTo use the powerup press 4 when choosing weapon";
        // }
        if(p_health<0)
        {
            p_health=0;
            return 0;
        }
        if(z_health<0)
        {
            z_health=0;
            return 0;
        }


        cout<<"\n\t\t\t===LEVEL 3====\n";
        cout<<"Health = "<<p_health<<"\t Zombie = "<<z_health<</*"\tPower = "<<power<<*/endl;
        cout<<"1)Gun(Damage=50 hp\tPoints=2x) \n2)Bat(Damage=25 HP \tpoints=5x) \n3)Axe(Damage=40 HP \tpoints=4x)"<<endl;
        cout<<"Enter weapon number:";
        cin>>weapon;

        switch(weapon)
        {
            case 1: 

             if(G.count==2)
                {
                    cout<<"A gun can only be used 2 times!!!!!";
                    break;
                }
            cout<<"Enter attack number(1-5):";
            cin>>p_attack;
            if((5<p_attack)||(p_attack<0))
            {
                cout<<"Please enter a number between the given range"<<endl;
                break;
            }
            if(p_attack==z_attack)
            {
                p_health=p_health-40;
                cout<<"OOH THAT MUST'VE HURT, HOPE YOU AREN'T INFECTED";
            }
            else
            {
                z_health-=G.damage;
                cout<<"GREAT JOB YOU'VE HIT THE ZOMBIE";
                // power=power+power;
                // power=p_attack*G.points;
            }                             
            G.incount();
            z_attack=z_attack+10;
            if(z_attack>10)
            {
                z_attack-=3;
            }
            else if(z_attack<0)
            {
                z_attack+=2;
            }
            if(p_health==0)
            {
                cout<<endl<<"OOH YOU GOT INFECTED";                    
                return 0;
            }
             break;


            case 2:
               if(B.count==4)
                    {
                        cout<<"A bat can only be used 4 times!!!!!";
                        break;
                    }
            cout<<"Enter attack number(1-10):";
            cin>>p_attack;
            if((10<p_attack)||(p_attack<0))
                    {
                        cout<<"Please enter a number between the given range"<<endl;
                        break;
                    }
            if(p_attack==z_attack)
            {
                p_health-=25;
                cout<<"THE ZOMBIE ATTACKED YOU, YOU JUST LOST 25 HP";
                if(p_health==0)
                {
                    cout<<endl<<"OOH YOU GOT INFECTED";
                    return 0;
                }
            }
            else
            {
                z_health-=B.damage;
                cout<<"GREAT JOB YOU'VE HIT THE ZOMBIE";
                // power=p_attack*B.points;
                // power=power+power;
            }
            B.incount();
            z_attack=z_attack+5;
            if(z_attack>10)
            {
                z_attack-=3;
            }
            else if(z_attack<0)
            {
                z_attack+=2;
            }
        break;

            case 3:
              if(A.count==3)
                    {
                        cout<<"An axe can only be used 3 times!!!!!";
                        break;
                    }
            cout<<"Enter attack number (1-10):";
            cin>>p_attack;
            if((10<p_attack)||(p_attack<0))
                    {
                        cout<<"Please enter a number between the given range"<<endl;
                        break;
                    }
            if(p_attack==z_attack)
            {
                p_health-=25;
                cout<<"THE ZOMBIE ATTACKED YOU, YOU JUST LOST 25 HP";
                if(p_health==0)
                {
                    cout<<endl<<"OOH YOU GOT INFECTED";
                    return 0;
                }
            }
            else
            {
                z_health-=A.damage;
                cout<<"GREAT JOB YOU'VE HIT THE ZOMBIE";
                // power=p_attack*A.points;
                // power=power+power;
            }
            A.incount();
            z_attack=z_attack+5;
            if(z_attack>10)
            {
                z_attack-=3;
            }
            else if(z_attack<0)
            {
                z_attack+=2;
            }
        break;
            case 4:
                 z_health=0.4*z_health;
            break;
            default:
                 cout<<"Invalid input!!!!";

            break;
        }

    }
    cout<<"YOU KILLED THE LEVEL 3 ZOMBIE"<<endl;
    cout<<"YOU SURVIVED!!!!"<<endl;

        
}
int practice()
{
    G.count=0;
    B.count=0;
    A.count=0;
    z_health=1000;
    z_attack=10 ;
    while(z_health>0)
    {
        // if(power==100)
        // {
        //     cout<<"You can use the powerup";
        //     status= true;
        //     cout<<"\nTo use the powerup press 4 when choosing weapon";
        // }
        if(p_health<0)
        {
            p_health=0;
            return 0;
        }
        if(z_health<0)
        {
            z_health=0;
            return 0;
        }
        cout<<"Health = "<<p_health<<"\t Zombie = "<<z_health<</*"\tPower = "<<power<<*/endl;
        cout<<"1)Gun(Damage=50 HP\tPoints=2x) \n2)Bat(Damage=25 HP \tpoints=5x) \n3)Axe(Damage=40 HP \tpoints=4x)"<<endl;
        cout<<"Enter weapon number:";
        cout<<"THIS INFORMATION STATION WILL BE SHOWN TO YOU AT ALL TIMES"<<endl;
        cout<<"You will ,for the purposes of this practice session be getting a gun.(with no upper usage limit)"<<endl;
        cout<<"\nEnter attack number(1-80):";
        cin>>p_attack;

        cout<<z_attack;
        cout<<endl<<"THIS IS A RANDOM COMPUTER GENERATED NUMBER WHICH WILL CHANGE AFTER EVERY SHOT\n";
        if((80<p_attack)||(p_attack<0))
        {
            cout<<"Please enter a number between the given range"<<endl;
        }
        else if(p_attack=='e')
        {
            break;
        }
        if(p_attack==z_attack)//reduce players health
        {
            p_health=p_health-5;
            cout<<"\nOOH THAT MUST'VE HURT HOPE YOU AREN'T INFECTED";
            z_attack=z_attack+5;
            if(z_attack>20)
            {
                z_attack-=12;
            }
            else if(z_attack<0)
            {
                z_attack+=9;
            }

            if(p_health==0)
            {
                cout<<endl<<"\nOOH YOU GOT INFECTED";
                        
                return 0;
            }
        }
        else
        {
            z_health-=G.damage;//reduce zombie health
            cout<<"\nGREAT JOB YOU'VE HIT THE ZOMBIE";
            // power=power + power;
            // power=p_attack*G.points;//increase power
            //make number randomer
            z_attack=z_attack+5;
            if(z_attack>20)
            {
                z_attack-=9;
            }
            else if(z_attack<0)
            {
                z_attack+=2;
            }
        }
        G.incount();
    }
	// power+=power;
    return 0; 
}