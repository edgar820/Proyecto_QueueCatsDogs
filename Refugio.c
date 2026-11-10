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
    pet->next = NULL;
    pet->nextSame = NULL;
    pet->prior = NULL;
    return pet;
}

CatAndDogQueue catAndDogQueue_create(){

}

int catAndDogQueue_size(CatAndDogQueue q){
    return q->size;
}

Bool catAndDogQueue_isEmpty(CatAndDogQueue q){
    if(q->size == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

/*void catAndDogQueue_enqueue(CatAndDogQueue q, Pet p){
    if(catAndDogQueue_isEmpty(q)){
        q->first = p;
        q->last = p;
        if(pet_isDog(p)){
            if(q->firstDog == NULL){
                q->firstDog = p;
                q->lastDog = p;
            }else{
                q->lastDog->nextSame = p;
                q->lastDog = p;
            }
        }else if(pet_isCat(p)){
            if(q->firstCat == NULL){
                q->firstCat = p;
                q->lastCat = p;
            }else{
                q->lastCat->nextSame = p;
                q->lastCat = p;
            }
        }
    }else{
        q->last->next = p;
        p->prior = q->last;
        q->last = p;
        if(pet_isDog(p)){
            if(q->firstDog == NULL){
                q->firstDog = p;
                q->lastDog = p;
            }else{
                q->lastDog->nextSame = p;
                q->lastDog = p;
            }
        }else if(pet_isCat(p)){
            if(q->firstCat == NULL){
                q->firstCat = p;
                q->lastCat = p;
            }else{
                q->lastCat->nextSame = p;
                q->lastCat = p;
            }
        }
    }
    q->size++;
}*/

void catAndDogQueue_enqueue(CatAndDogQueue q, Pet p){
    if(catAndDogQueue_isEmpty(q)){
        q->first = p;
        q->last = p;
    }else{
        q->last->next = p;
        p->prior = q->last;
        q->last = p;
    }
    if(pet_isDog(p)){
            if(q->firstDog == NULL){
                q->firstDog = p;
                q->lastDog = p;
            }else{
                q->lastDog->nextSame = p;
                q->lastDog = p;
            }
        }else if(pet_isCat(p)){
            if(q->firstCat == NULL){
                q->firstCat = p;
                q->lastCat = p;
            }else{
                q->lastCat->nextSame = p;
                q->lastCat = p;
            }
        }
    q->size++;
}

Pet catAndDogQueue_dequeue(CatAndDogQueue q){
    Pet animalFuera = q->first;
    if(pet_isCat(q->first)){
        if(q->firstCat->nextSame != NULL){
            q->firstCat = q->firstCat->nextSame;
        }else{
            q->firstCat = q->firstCat->nextSame;
            q->lastCat = NULL;
        }
    }else if(pet_isDog(q->first)){
        if(q->firstDog->nextSame != NULL){
            q->firstDog = q->firstDog->nextSame;
        }else{
            q->firstDog = q->firstDog->nextSame;
            q->lastDog = NULL;
        }
    }
    if(q->first->next != NULL){
        q->first = q->first->next;
        q->first->prior = NULL;
    }else{
        q->last = NULL;
        q->first = NULL;
    }
    q->size--;
    return animalFuera;
}

Pet catAndDogQueue_dequeueCat(CatAndDogQueue q){

}

Pet catAndDogQueue_dequeueDog(CatAndDogQueue q){
    
}