/* 
 * File:   stringqueue.h
 * Authors: ryanharrigan and nishanthduraiarasu
 *
 * Created on January 29, 2020, 10:11 PM
 */

//lang::CwC

#pragma once
#include <stdlib.h>

/*
 * StringQueue - Stores strings and returns them in FIFO order
*/
class StringQueue : public Queue {
    public:

        StringQueue() : Queue() {}

        virtual ~StringQueue() {}

        /*
         * Adds string to end of queue
         * @param str String to be added to queue
        */
        void add(String* str) {}

        /*
         * Removes the string at the head of the queue
        */
        void remove() {}

        /*
         * Returns pointer to string at the head of the queue
         * Exits if queue is empty
        */
        String* head() {}

        /*
         * Returns size of queue
        */
        size_t size() {}

        /**
		 * Is this Queue equal to the given Object?
         * Equality based on calling equals() on each queue element
         * Overrides equals() from Object
		 * @param otherQ Object pointer
		*/
        bool equals(Object *otherQ) {}

        /**
		 * Returns the hash code for this Queue
         * Overrides hashCode() from Object 
        */
        size_t hashCode() {}
};


