#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"








//##################################
int
sys_getyear(void)
{
 return 1975;
}


int
sys_alarm(void)
{
/*
  int ticks;
  void (*handler)();

  if(argint(0, &ticks) < 0)
    return -1;
  if(argptr(1, (char**)&handler, 1))
    return -1;
  myproc()->alarmticks = ticks;
  myproc()->alarmleft = ticks; // as init
  myproc()->alarmhandler = handler;*/
 
  return 0;

}

int
sys_date(struct rtcdate *r)
{
  if (argptr(0, (void *)&r, sizeof(*r)) < 0)
    return -1;

  cmostime(r);
  return 0;
}

int
sys_listpid(void)
{
	showPid();
	return 0;
}

// shutdown syscall
int
sys_shutdown(void)
{
	char *p = "Shutdown";
	for (; *p; p++)
		/* ACPI power-off */
		outw(0xB004, 0x2000);
	return 0;
}

// find syscall
int
sys_find(void)
{
	int pid;
	if (argint(0, &pid) < 0)
		return -1;
	return findpid(pid);
}

// changePriority syscall
int
sys_cp(void)
{
	int pid, priority;
	if (argint(0, &pid) < 0)
		return -1;
	if (argint(1, &priority) < 0)
		return -1;

	return changePriority(pid, priority);
}


//##################################


int
sys_sd(void)
{
	char *str;
	if (argstr(0, &str) < 0)//################################
		return -1;
	else
	{
		sd_store(str);
		return 0;
	}
		
}

char
sys_rec(void)
{
	int num;
	if (argint(0, &num) < 0)
	{
		//cprintf("##>error\n");
		return 0;
	}
	//cprintf("##ok_num: %d\n",num);
	return rec_get(num);
}

int
sys_rec_num(void)
{
	return rec_get_num();
}
int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
