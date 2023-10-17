/*
============================================================================
Name : 31b.c
Author : Ankita Agrawal
Description : Write a program to create a semaphore and initialize value to the semaphore.
 a. create a binary semaphore
 b. create a counting semaphore
Date: 17 0ct, 2023
============================================================================
*/
#include <stdio.h>
#include <semaphore.h>

int main() {
    sem_t mySemaphore; // Declare the semaphore object

    // Initialize the counting semaphore with an initial value of, for example, 3
    if (sem_init(&mySemaphore, 0, 3) == 0) {
        printf("Counting semaphore created and initialized with a value of 3.\n");

        // You can use the semaphore here for synchronization or other purposes.

        // Don't forget to destroy the semaphore when you're done with it.
        if (sem_destroy(&mySemaphore) == 0) {
            printf("Semaphore destroyed.\n");
        } else {
            perror("sem_destroy");
        }
    } else {
        perror("sem_init");
      }

    return 0;
}

