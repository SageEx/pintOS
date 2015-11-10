#include <stdio.h>
#include <stdlib.h>
#include "../threads/synch.h"
#include "../threads/thread.h"

struct semaphore milk,water,tea,sugar;
int curr=0;
int no=400;

void
mother(){
    while(no--){
        /* printf("Agent Running\n"); */
        if(curr==0){
            curr++;
            curr%=4;
            sema_up(&milk);
            sema_up(&water);
            sema_up(&sugar);
        }
        else if(curr==1){
            curr++;
            curr%=4;
            sema_up(&tea);
            sema_up(&water);
            sema_up(&sugar);
        }
        else if(curr==2){
            curr++;
            curr%=4;
            sema_up(&tea);
            sema_up(&sugar);
            sema_up(&milk);
        }
        else if(curr==3){
            curr++;
            curr%=4;
            sema_up(&tea);
            sema_up(&water);
            sema_up(&milk);
        }
    }
}

void
child1(){
    while(no--){
        bool a1 = sema_try_down(&tea);
        bool a2 = sema_try_down(&sugar);
        if(a1 && a2){
            printf("Child 1 got tea & sugar.\n");
            sema_try_down(&tea);
            sema_try_down(&sugar);
            sema_try_down(&water);
            sema_try_down(&milk);
            int j = thread_get_priority();
            j--;
            thread_set_priority(j);
        }else if( a2 ){
            sema_up(&tea);
        } else if(a2){
            sema_up(&sugar);
        }

    }
}

void
child2(){
    while(no--){

        bool a1 = sema_try_down(&milk);
        bool a2 = sema_try_down(&tea);
        if(a1 && a2){
            printf("Child 2 got tea & milk.\n");
            sema_try_down(&tea);
            sema_try_down(&sugar);
            sema_try_down(&water);
            sema_try_down(&milk);
            int j = thread_get_priority();
            j--;
            thread_set_priority(j);
        }else if( a2 ){
            sema_up(&milk);
        } else if(a2){
            sema_up(&tea);
        }
    }
}

void
child3(){
    while(no--){

        bool a1 = sema_try_down(&water);
        bool a2 = sema_try_down(&sugar);
        if(a1 && a2){
            printf("Child 3 got water & sugar.\n");
            sema_try_down(&tea);
            sema_try_down(&sugar);
            sema_try_down(&water);
            sema_try_down(&milk);
            int j = thread_get_priority();
            j--;
            thread_set_priority(j);
        }else if( a2 ){
            sema_up(&water);
        } else if(a2){
            sema_up(&sugar);
        }
    }
}

void
child4(){
    while(no--){

        bool a1 = sema_try_down(&water);
        bool a2 = sema_try_down(&milk);
        if(a1 && a2){
            printf("Child 4 got water & milk.\n");
            sema_try_down(&tea);
            sema_try_down(&sugar);
            sema_try_down(&water);
            sema_try_down(&milk);
            int j = thread_get_priority();
            j--;
            thread_set_priority(j);
        }else if( a2 ){
            sema_up(&water);
        } else if(a2){
            sema_up(&milk);
        }
    }
}

void
as1301CS12(void)
{
    printf("\nHello Arindam - 1301CS12\n");
    sema_init(&milk,0);
    sema_init(&water,0);
    sema_init(&tea,0);
    sema_init(&sugar,0);
    thread_create("Mother",33,&mother,"");
    thread_create("child2",30,&child2,"");
    thread_create("child1",31,&child1,"");
    thread_create("child3",29,&child3,"");
    thread_create("child4",28,&child4,"");

}
