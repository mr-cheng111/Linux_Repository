#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct PCB {
    char name[10];
    int round;
    int cputime;
    int needtime;
    int count;
    char state;
    PCB *next;
};

PCB *finish, *ready, *tail, *run, *finish_tail;

const int N = 5;

PCB *createProcess(char *name, int needtime) 
{
    PCB *process = new PCB;
    strcpy(process->name, name);
    process->needtime = needtime;
    process->cputime = 0;
    process->round = 2;
    process->state = 'W';
    process->count = 0;
    process->next = NULL;
    return process;
}

void insert(PCB *process) 
{
    if (ready == NULL) 
	{
        ready = process;
        tail = process;
    } else {
        tail->next = process;
        tail = process;
    }
}

PCB* getReady() {
    PCB *p = ready;
    if (ready == NULL) 
	{
        return NULL;
    } else {
        ready = p->next;
        p->next = NULL;
    }
    return p;   
}

void insertFinish(PCB *process) 
{
    if (finish == NULL) 
	{
        finish = process;
        finish_tail = process;
    } 
	else 
	{
        finish_tail->next = process;
        finish_tail = process;
    }
    process->state = 'F';
}

void printPCB(PCB *process) 
{
    printf("%-15s%-15d%-15d%-15d%-15d%-15c\n", process->name, process->cputime, process->needtime, process->count, process->round, process->state);
}

void printHeader() 
{
    printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "process_name", "cputime", "needtime", "count" ,"round", "state");
}

void printList() 
{
    printHeader();
    printPCB(run);
    PCB *p = ready;
    while (p != NULL) 
	{
        printPCB(p);
        p = p->next;
    }
}

void roundrun(PCB *process[]) 
{
    finish = NULL;
    ready = NULL;
    tail = NULL;
    run = NULL;
    
    for (int i = 0; i < N; i++) 
	{
        insert(process[i]);
    }
    run = getReady();

    while (run != NULL) 
	{
        run->state = 'R';
        printList();
        run->cputime += 1;
        run->needtime -= 1;
        run->count += 1;
        
        if (run->needtime == 0) 
		{
            insertFinish(run);
            run = getReady();
        } 
		else if (run->count == run->round) 
		{
            run->count = 0;
            run->state = 'W';
            insert(run);
            run = getReady();
        }
    }
}

int main() {
    int time;
    char name[10];
    PCB *process[N];
	int count = N;
    cout << "Enter name and time of round process" << endl;

    while(count > 0) 
	{
        cin >> name;
        cin >> time;
		if(time <= 0)
		{
			cout<<"Please input a positive value!"<<endl;
		}
		else
		{
			process[count - 1] = createProcess(name, time);
			memset(name,0,sizeof(name));
			time = 0;
			count --;
		}
        
    }

    cout << "                  output of round                  " << endl;
    cout << "***************************************************" << endl;

    roundrun(process);

    return 0;
}