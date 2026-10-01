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


struct Asset assets[100];
int assetCount = 0;

void addAsset(void);
void displayAsset(void);
void searchAsset(void);
void assetMenu(void);

int main(void) {
    assetMenu();
    return 0;
}

void addAsset(void) {
   
    if (assetCount >= 100) {
        printf("Registo cheio.\n");
        return;
    }
    
    printf("Enter Asset ID: ");
    scanf("%d", &assets[assetCount].assetID);

    while (assets[assetCount].assetID <=0)
    {
        printf("Negative values are not allowed!\n");
        printf("Enter Asset ID: ");
        scanf("%d", &assets[assetCount].assetID);
    
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

   

    printf("Enter Asset Name: ");
    fgets(assets[assetCount].assetName,50,stdin);
    assets[assetCount].assetName[strcspn(assets[assetCount].assetName, "\n")] = '\0';
    

    printf("Enter Asset Type: ");
    fgets(assets[assetCount].assetType,40,stdin);
    assets[assetCount].assetType[strcspn(assets[assetCount].assetType, "\n")] = '\0';
    
    

    printf("Enter Asset Purchase Value: ");
    scanf("%lf", &assets[assetCount].purchaseValue);

    while (assets[assetCount].purchaseValue < 0)
    {
        printf("Negative values are not allowed!\n");
        printf("Enter Asset Purchase Value: ");
        scanf("%lf", &assets[assetCount].purchaseValue);
    
    }
    
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Enter Asset Department: ");
    fgets(assets[assetCount].department,40,stdin);
    assets[assetCount].department[strcspn(assets[assetCount].department, "\n")] = '\0';
    
    

    printf("Enter Asset Condition: ");
    fgets(assets[assetCount].condition,45,stdin);
    assets[assetCount].condition[strcspn(assets[assetCount].condition, "\n")] = '\0';
    

    printf("Asset added!\n");
    assetCount++;
}

void displayAsset(void) {
    if (assetCount == 0) {
        printf("No assets.\n");
        return;
    }

    for (int i = 0; i < assetCount; i++) {
        printf("Asset ID: %d\n",   assets[i].assetID);
        printf("Asset Name: %s\n", assets[i].assetName);
        printf("Asset Type: %s\n", assets[i].assetType);
        printf("Purchase Value: %.2f\n", assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
      
      
    }
}

void searchAsset(void) {
    int c;
    int option;
    int found = 0;
    int id;
    char termo[50];

    if (assetCount == 0) {
        printf("No assets available.\n");
        return;
    }

    printf("\n1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("3. Search by Type\n");
    printf("4. Search by Department\n");
    printf("Choose your option: ");
    scanf("%d", &option);

    while ((c = getchar()) != '\n' && c != EOF);

    if (option == 1) {
        printf("Enter ID: ");
        scanf("%d", &id);
    }
    else if (option == 2) {
        printf("Enter Name: ");
        fgets(termo, sizeof(termo), stdin);
        termo[strcspn(termo, "\n")] = '\0';
    }
    else if (option == 3) {
        printf("Enter Type: ");
        fgets(termo, sizeof(termo), stdin);
        termo[strcspn(termo, "\n")] = '\0';
    }
    else if (option == 4) {
        printf("Enter Department: ");
        fgets(termo, sizeof(termo), stdin);
        termo[strcspn(termo, "\n")] = '\0';
    }
    else {
        printf("Invalid option.\n");
        return;
    }

    for (int i = 0; i < assetCount; i++) {

        if ((option == 1 && assets[i].assetID == id) ||
            (option == 2 && strcmp(assets[i].assetName, termo) == 0) ||
            (option == 3 && strcmp(assets[i].assetType, termo) == 0) ||
            (option == 4 && strcmp(assets[i].department, termo) == 0)) {

            printf("\n--- Asset Found ---\n");
            printf("Asset ID: %d\n", assets[i].assetID);
            printf("Asset Name: %s\n", assets[i].assetName);
            printf("Asset Type: %s\n", assets[i].assetType);
            printf("Purchase Value: %.2f\n", assets[i].purchaseValue);
            printf("Department: %s\n", assets[i].department);
            printf("Condition: %s\n", assets[i].condition);

            found = 1;
        }
    }

    if (found == 0) {
        printf("\nAsset not found!\n");
    }
}
void assetMenu(){
    int choice;
    int c;
    do
    {
        
    printf("-----------------------Asset Management Menu----------------------\n");
    printf("1.Add Asset\n");
    printf("2.Display Asset\n");
    printf("3.Search Asset\n");
    printf("4.Back to main Menu\n");

    printf("Choose your option: ");
    
    
    if (scanf("%d", &choice) != 1) {
    printf("Entrada invalida.\n");
    choice = 0;  
        
    }

    while ((c = getchar()) != '\n' && c != EOF);


      switch (choice)
    {
    case 1:
        addAsset();
        break;
    case 2:
        displayAsset();
        break;
    case 3:
        searchAsset();
        break;
    case 4:
        printf("Back to main menu!");
        break;
    
    default:
        printf("Error...!\n");
        break;
    }

        
    } while (choice!=4);
    
      




    


}