/* Name : Gizela Suzandra Amaro Manuel 
   Student Number: 226029069 */ 

#include <stdio.h>
#include <string.h>

struct Asset {
    int    assetID;
    char   assetName[50];
    char   assetType[40];
    double purchaseValue;
    char   department[40];
    char   condition[45];
};
//Global variable

struct Asset assets[100];
int assetCount = 0;

// Function Declaration
void addAsset(void);
void displayAsset(void);
void searchAsset(void);
void assetMenu(void);