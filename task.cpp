#include <bits/stdc++.h>
#include <iostream>
#define FINAL 0
#define RUNNING 1
#define READY 2
#define BLOCK 3
using namespace std;

const int maxn=20;
int N;
struct PCB{
    int id;
    int priority;
    int cputime;
    int alltime; 
    int startblock,startblocktmp; 
    int blocktime,blocktimetmp;
    int state;
}p1,p2;

struct PCB P[maxn];

void show(int i){
    cout<<"RUNNING PROG "<<i<<endl;
    printf("READY_QUEUE:");
    for(int i=0; i<N; i++){
        if(P[i].state==READY) cout<<"->id"<<i;
    }
    cout<<endl;
    printf("BLOCK_QUEUE:");
    for(int i=0; i<N; i++){
        if(P[i].state==BLOCK) cout<<"->id"<<i;
    }
    cout<<endl;
    printf("===================================================\n");
    printf("ID PRIORITY CPUTIME ALLTIME ");
    printf("STARTBLOCK BLOCKTIME STATE \n");

    for(int i=0; i<N; i++){
        printf("%d\t%d\t%d\t",P[i].id,P[i].priority,P[i].cputime);
        printf("%d\t%d\t%d\t",P[i].alltime,P[i].startblock,P[i].blocktime);
        if(P[i].state==FINAL) cout<<"FINAL"<<endl;
        else if(P[i].state==RUNNING) cout<<"RUNNING"<<endl;
        else if(P[i].state==READY) cout<<"READY"<<endl;
        else if(P[i].state==BLOCK) cout<<"BLOCK"<<endl;
    }
}
void process_management(){
    int n=0;
    int j=0;

    show(j);
    int running=0;
    while(n!=N){

        priority_queue<pair<int,int> > que;

        for(int i=0; i<N; i++){
            if(P[i].state==READY) {
                P[i].priority+=1;
                que.push(make_pair(P[i].priority,i));
            }
            else if(P[i].state==RUNNING) {
                P[i].priority-=3;
                P[i].cputime+=1;
                P[i].alltime-=1;
                P[i].startblocktmp--;
                if(P[i].alltime==0) {
                    P[i].state=FINAL;

                    running=0;
                    n++;
                }
                else if(P[i].startblocktmp<=0&&P[i].startblock>0) {
                    P[i].state=BLOCK;
                    P[i].blocktimetmp=P[i].blocktime;
                    running=0;
                }
            }
            else if(P[i].state==BLOCK){
                P[i].blocktimetmp-=1;
                if(P[i].blocktimetmp<=0) P[i].state=READY;
            }
        }


        if(( (!running))&&(!que.empty()) ){
            pair<int,int> k=que.top();
            int tmp=k.second;
            P[tmp].state=1;
            P[tmp].startblocktmp=P[tmp].startblock;
            running=1;
        }
        show(++j);
    }
}
int main()
{
    printf("Please enter the number of processes:\n");
    cin>>N;
    printf("Please enter the initial value of% d in order (process from 0 ~% d):\n",N,N-1);
    printf("(0- FINNAL,1-RUNNING,2-READY,3-BLOCK)\n");
    printf("ID PRIORITY CPUTIME ALLTIME ");
    printf("STARTBLOCK BLOCKTIME STATE \n");

    for(int i=0; i<N; i++){
        cin>>P[i].id>>P[i].priority>>P[i].cputime>>P[i].alltime;
        cin>>P[i].startblock>>P[i].blocktime>>P[i].state;
    }

    printf("The status of timeslice while processes are running\n");
    process_management();
    return 0;
}
