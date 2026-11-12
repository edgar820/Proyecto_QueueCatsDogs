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
    CatAndDogQueue CDQ = malloc(sizeof(struct strCatAndDogQueue));
    CDQ->first = NULL;
    CDQ->last = NULL;
    CDQ->firstDog = NULL;
    CDQ->lastDog = NULL;
    CDQ->firstCat = NULL;
    CDQ->lastCat = NULL;
    CDQ->size = 0;

    return CDQ;
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
    if(q == NULL || q->first == NULL){
        return NULL;
    }

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
    if (q->firstCat == NULL)
    {
        return NULL;
    }
    
    Pet gatoFuera = q->firstCat;
    q->firstCat = gatoFuera->nextSame;

    if (q->firstCat == NULL)
    {
        q->lastCat = NULL;
    }

    if (gatoFuera->prior != NULL)
    {
        gatoFuera->prior->next = gatoFuera->next;
    }
    else{
        q->first = gatoFuera->next;
    }

    if (gatoFuera->next != NULL)
    {
        gatoFuera->next->prior = gatoFuera->prior;
    }
    else{
        q->last = gatoFuera->prior;
    }
    
    gatoFuera->next = NULL;
    gatoFuera->prior = NULL;
    gatoFuera->nextSame = NULL;
    q->size--;
    
    return gatoFuera;
}

Pet catAndDogQueue_dequeueDog(CatAndDogQueue q){
    if (q->firstDog == NULL)
    {
        return NULL;
    }
    
    Pet perroFuera = q->firstDog;
    q->firstDog = perroFuera->nextSame;

    if (q->firstDog == NULL)
    {
        q->lastDog = NULL;
    }

    if (perroFuera->prior != NULL)
    {
        perroFuera->prior->next = perroFuera->next;
    }
    else{
        q->first = perroFuera->next;
    }

    if (perroFuera->next != NULL)
    {
        perroFuera->next->prior = perroFuera->prior;
    }
    else{
        q->last = perroFuera->prior;
    }
    
    perroFuera->next = NULL;
    perroFuera->prior = NULL;
    perroFuera->nextSame = NULL;
    q->size--;
    
    return perroFuera;

}