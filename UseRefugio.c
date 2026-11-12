#include <stdio.h>
#include <stdlib.h>
#include "Refugio.h"

int main(){

    Pet myDogs[10];
    Pet myCats[10];
    for (int i = 0; i < 10; i ++) {
        myDogs[i] = pet_create(i + 1, DOG);
    }
    for (int i = 0; i < 10; i ++) {
        myCats[i] = pet_create(i + 1, CAT);
    }
    CatAndDogQueue animalShelter = catAndDogQueue_create();
    Pet currentPet;
    catAndDogQueue_enqueue(animalShelter, myDogs[0]);
    for (int i = 0; i < 10; i ++) {
        catAndDogQueue_enqueue(animalShelter, myCats[i]);
    }
    catAndDogQueue_enqueue(animalShelter, myDogs[1]);
    for (int i = 0; i < 3; i ++) {
        currentPet = catAndDogQueue_dequeueDog(animalShelter);
        if (currentPet != NULL) {
            printf("Dog #%03d has been adopted. Woof!\n", pet_getId(currentPet));
        } else {
            printf("All dogs have been adopted!\n");
        }
    }
    for (int i = 0; i < 10; i ++) {
        currentPet = catAndDogQueue_dequeueCat(animalShelter);
        printf("Cat #%03d has been adopted. Meow!\n", pet_getId(currentPet));
    }
    return 0;
    
}