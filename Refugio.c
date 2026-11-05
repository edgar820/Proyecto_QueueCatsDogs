#include <stdio.h>
#include <stdlib.h>
#include "Refugio.h"

struct strPet {
    int id;
    struct strPet *next;
    struct strPet *prior;
    struct strPet *nextSame;
    Type type;
};


struct strCatAndDogQueue{
    int size;
    Pet first, last, firstDog, lastDog, firstCat, lastCat;
};

Bool pet_isDog(Pet p) {
    return p->type == DOG;
}

Bool pet_isCat(Pet p) {
    return p->type == CAT;
}

int pet_getId(Pet p) {
    return p->id;
}

Pet pet_create(int id, Type t) {
    Pet pet = (Pet) malloc(sizeof(struct strPet));
    pet->id = id;
    pet->type = t;
    return pet;
}