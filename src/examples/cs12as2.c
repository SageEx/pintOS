#include <stdio.h>
#include <stdlib.h>
#include "../threads/synch.h"
#include "../threads/thread.h"

struct semaphore Tobacco,Paper,Matches,Smoking;
int curr=0;
int no=40;

void
agent(){
    while(no--){
        /* printf("Agent Running\n"); */
        sema_down(&Smoking);
        if(curr==0){
            curr++;
            curr%=3;
            sema_up(&Tobacco);
        }
        else if(curr==1){
            curr++;
            curr%=3;
            sema_up(&Paper);
        }
        else if(curr==2){
            curr++;
            curr%=3;
            sema_up(&Matches);
        }
    }
}

void
tob(){
    while(no--){
        /* if(smoking==1 && curr==0){ */
        /*     printf("Tobacco Man Got Paper & Matches - He is smoking "); */
        /*     smoking=0; */
        /*     /1* sem *1/ */
        /* } */
        printf("Tobacco Man Got Paper & Matches - He is smoking\n ");
        sema_up(&Smoking);
        sema_down(&Tobacco);

    }
}
void
pap(){
    while(no--){
        /* if(smoking==1 && curr==1){ */
        /*     printf("Paper Man Got Tobacco & Matches - He is smoking "); */
        /*     smoking=0; */
        /*     /1* sem *1/ */
        /* } */
        printf("Paper Man Got Tobacco & Matches - He is smoking \n");
        sema_up(&Smoking);
        sema_down(&Paper);
    }
}
void
mat(){
    while(no--){
        /* if(smoking==1 && curr==2){ */
        /*     printf("Matches Man Got Paper & Tobacco - He is smoking "); */
        /*     smoking=0; */
        /*     /1* sem *1/ */
        /* } */
        printf("Matches Man Got Paper & Tobacco - He is smoking \n");
        sema_up(&Smoking);
        sema_down(&Matches);
    }
}

void
as1301CS12(void)
{
    printf("\nHello Arindam - 1301CS12\n");
    sema_init(&Smoking,0);
    sema_init(&Tobacco,0);
    sema_init(&Paper,0);
    sema_init(&Matches,0);
    thread_create("agent",5,&agent,"");
    thread_create("Tobacco",5,&tob,"");
    thread_create("Paper",5,&pap,"");
    thread_create("Matches",5,&mat,"");

}
