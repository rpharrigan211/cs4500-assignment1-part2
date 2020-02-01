//lang::Cpp

#include <stdlib.h>
#include "object.h"
#include "queue.h"
#include "string.h"
#include "stringqueue.h"
#include <stdio.h>
#include <iostream>

// Using test functions from warmup 3
void FAIL() {
    printf("Some tests failed");
    exit(1);
}
void OK(const char* m) { printf(m); }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }


int main(int argc, char** argv) {
    Object* a = new Object();
    Object* b = new Object();
    String* str1 = new String("a");
    String* str2 = new String("b");
    String* str3 = new String("a");
    String* str4 = new String("ab");
    
    
    t_true(str1->equals(str3)); //str1 and str3 are equal
    t_false(str1->equals(a)); //str1 and a are not equal
    t_false(str1->equals(str2)); //str1 and str2 are not equal
    
    t_true(str1->size() == 1); //str1 is size 1, not counting null terminator
    
    t_true(str1->concat(str2)->equals(str4)); //str2 added to str1 equals str4
    
    Queue* queue1 = new Queue();
    t_true(queue1->size() == 0); //nothing in queue1

    queue1->add(a); //add a to queue1
    t_true(queue1->size() == 1); //1 item (a)

    queue1->add(b); //add b to queue1
    t_true(queue1->size() == 2); //2 items (a, b)
    t_true(queue1->head()->equals(a)); //a is head of queue1
    queue1->remove(); //removes the head from queue1 (a)
    t_true(queue1->size() == 1); //1 item (b)
    t_false(queue1->head()->equals(a)); //a is no longer the head
    t_true(queue1->head()->equals(b)); //b is head of queue1

    StringQueue* queue2 = new StringQueue();
    StringQueue* queue3 = new StringQueue();
    queue2->add(str1); //add str1 to queue2
    queue3->add(str1); //add str1 to queue3
    
    t_true(queue2->size() == 1); //1 item (str1)
    t_true(queue2->size() == queue3->size()); //sizes of both queues are equal
    
    t_false(queue1->equals(queue2)); //Object Queue and String Queue are not
    //equal despite equal size
    t_true(queue2->equals(queue3)); //both String Queues are equal
    t_true(queue2->hashCode() == queue3->hashCode()); //equal hash codes

    queue2->add(str2); //adds str2 to queue2
    queue2->remove(); //removes the head from queue2 (str1)
    
    t_false(queue2->equals(queue3)); //String Queues are no longer equal
    
    Queue* queue4 = new Queue();
    
    queue4->add(b); //add b to queue4
    t_true(queue4->equals(queue1)); //queue4 is equal to queue1
    t_true(queue4->hashCode() == queue1->hashCode()); //equal hash codes
    
    queue4->remove(); //removes remaining element from queue4
    queue3->remove(); //removes remaining element from queue3
    t_true( queue4->size() == 0);
    t_true( queue4->size() == 0);

    delete a;
    delete b;
    delete str1;
    delete str2;
    delete str3;
    delete str4;
    delete queue1;
    delete queue2;
    delete queue3;
    delete queue4;
    
    OK("All tests passed!");
}