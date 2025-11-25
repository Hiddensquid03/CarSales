#include <stdio.h>
#include <string.h>
#include <time.h>



//  to do list
//ADD MORE VALIDATION
//add the clear buffer after every scan f
// add functions
// add more vehicles
// add date and time stamp to sales record
// add file handling to save sales data in seperate files
// add ability to read previous sales data from file on program start
// Add the ability for customer to leave feedback
// sort the car quanity highest up top lowest at bottom

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    printf("Hello, World!\n");
    // variable declaration
    int carsSold = 0;
    char NUSCARDVALID[50];
    char userInput[50];
    int quantityNeeded;
    int totalPrice;
    int userAge;
    float discountPrice;
    char nameHolder[200];
    int salesCount = 0;
    char TimeStamp[50];
    //Constant
#define MAXSALES 10


    //main structs
    struct Vehicle {
        char StockName[50];
        int Quantity;
        int Price;
    };

    //data tracking struct
    struct SalesData {
        char customerName[200];
        int customerAge;
        float salesAmount;
    };
    //instances of structs
    struct Vehicle vehicle1;
    strcpy(vehicle1.StockName, "Ford Raptor");
    vehicle1.Quantity = 5;
    vehicle1.Price = 50000;

    struct SalesData salesData[MAXSALES] = {0};
    do {
        //main loop


        printf("Hello welcome to the dealership\n");
        printf("What is your name\n");
        scanf(" %[^\n]", nameHolder);
        clearInputBuffer();
        printf("A) See our car list\n");
        printf("B See sales statistics\n");
        printf("C Exit\n");
        scanf("%s", userInput);
        clearInputBuffer();
        while (getchar() != '\n');
        switch (userInput[0]) {
            case 'a':
            case 'A':

                printf("Our current car is ");
                printf("%s \n we have  %d \n they cost %d \n ", vehicle1.StockName, vehicle1.Quantity, vehicle1.Price);
                printf("Would you like to buy %s Y,N", vehicle1.StockName);
                scanf("%s", userInput);
                clearInputBuffer();
                if (userInput[0] != 'Y' && userInput[0] != 'y') {
                    printf("Sorry we couldnt help you today");
                    break;
                }
                printf("Great How many would you like");
                scanf("%d", &quantityNeeded);
                clearInputBuffer();
                if (quantityNeeded > vehicle1.Quantity) {
                    printf("sorry we dont have that many in stock we have %d", vehicle1.Quantity);
                    break;
                }
                if (quantityNeeded < 1) {
                    printf("sorry that is an invalid number");
                    break;
                }
                totalPrice = vehicle1.Price * quantityNeeded;

                printf("How old are you ");
                scanf("%d", &userAge);
                clearInputBuffer();

                printf("do you have an nus card Y/N");
                scanf(" %s", NUSCARDVALID);
                clearInputBuffer();
                // prevents double discount
                if (userAge >= 18 && userAge <= 25 || NUSCARDVALID[0] == 'Y' || NUSCARDVALID[0] == 'y') {
                    discountPrice = totalPrice * 0.85;
                    //printf("your discount price is %.2f \n", discountPrice);
                } else {
                    discountPrice = totalPrice;
                }


                printf("Congratulations you bought %d Costing %f \n", quantityNeeded, discountPrice);
                printf("Press enter to continue \n");
                getchar();
                vehicle1.Quantity -= quantityNeeded;
                carsSold = carsSold + quantityNeeded;


                salesData[salesCount].customerAge = userAge;
                salesData[salesCount].salesAmount = discountPrice;
                strcpy(salesData[salesCount].customerName, nameHolder);

                salesCount++;
                break;

            // sales statistics
            case 'b':
            case 'B':
                printf("we have currently sold %d cars \n", carsSold);

                for (int i = 0; i < carsSold; i++) {
                    printf("we have made %f The purchase was made by %s They were %d\n", salesData[i].salesAmount,
                           salesData[i].customerName, salesData[i].customerAge);
                }
                break;

            case 'c':
            case 'C':
                printf("Thank you for visiting the dealership goodbye");
                return 0;


            // error handling
            default:
                printf("sorry this isnt a valid Option Please try again");
        }

        printf("Press enter to continue \n");
        while (getchar() != '\n');
    } while (vehicle1.Quantity > 0);
}
