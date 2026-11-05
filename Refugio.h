#ifndef REFUGIO_H_
#define REFUGIO_H_

typedef struct strPet* Pet;
typedef struct strCatAndDogQueue* CatAndDogQueue;
typedef enum { FALSE, TRUE } Bool;
typedef enum { CAT, DOG } Type;

Bool pet_isDog(Pet p);
Bool pet_isCat(Pet p);
int pet_getId(Pet p);
Pet pet_create(int id, Type t);
CatAndDogQueue catAndDogQueue_create();
int catAndDogQueue_size(CatAndDogQueue q);
Bool catAndDogQueue_isEmpty(CatAndDogQueue q);
void catAndDogQueue_enqueue(CatAndDogQueue q, Pet p);
Pet catAndDogQueue_dequeue(CatAndDogQueue q);
Pet catAndDogQueue_dequeueCat(CatAndDogQueue q);
Pet catAndDogQueue_dequeueDog(CatAndDogQueue q);

#endif /*REFUGIO_H_*/