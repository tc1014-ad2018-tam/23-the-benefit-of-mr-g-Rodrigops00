//Rodrigo Perez Solis
//A01411278
//This program will help the user to buy tickets for the benefits of mr G




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Prints the Main Menu.
void menu(){
    printf("Welcome.\nplease choose an option.\n0. Buy.\n1. Save sells data.\n2. Reports.\n3. Exit.\n");
}

// reports menu
void menureports(){
    printf("Choose an option:\n1. Total tickets sold.\2. Total tickets sold per zone.\n3. Total income.\n4. Total income per zone.\n5. Occupation rate.\n6. Occupation rate per zone.\n");
}

// tell the user the paying methods
void payingmeth(){
    printf("Select a Payment Method:\n1. Visa\n2. MasterCard\n3. American Express\n");
}

//  zones
void zones(){
    printf("Zones:\n1. VIP: $100\n2. Platinum: $85\n3. Gold: $70\n4. Silver: $55\n5. Green: $45\n6. Yellow: $40\n7. Red: $30\n8. Sky Blue: $50\n9. Navy Blue: $35\n10. Deep Blue: $20\n");
}

// This struct will save his information
struct seats{
    char name[30];
    int ticket;
    bool seat;
    int payment;
}

        seats[400][200];


void Openfile(FILE *fp) {
    // Opens file or creates it (if necessary).
    fp = fopen("MrG.txt", "wb");

    // values are initialized
    for (int i = 0; i < 400; i++) {
        for (int j = 0; j < 200; j++) {
            strcpy(seats[i][j].name, "");
            seats[i][j].payment = 0;
            seats[i][j].seat = false;

            // The prices depend on each section.

            if (j < 50 || j > 149) {

                if (i < 100) {
                    seats[i][j].ticket = 50;
                } else if (i < 300) {
                    seats[i][j].ticket = 35;
                } else {
                    seats[i][j].ticket = 20;
                }

            } else {

                if (i < 5) {
                    seats[i][j].ticket = 100;
                } else if (i < 10) {
                    seats[i][j].ticket = 85;
                } else if (i < 50) {
                    seats[i][j].ticket = 70;
                } else if (i < 100) {
                    seats[i][j].ticket = 55;
                } else if (i < 250) {
                    seats[i][j].ticket = 45;
                } else if (i < 350) {
                    seats[i][j].ticket = 40;
                } else {
                    seats[i][j].ticket = 30;
                }

            }
        }
    }

    fwrite(&seats, sizeof(seats), 1, fp);
}

// Function to buy.
void buy() {
    // Declaration of variables.
    char name[30];
    char option;
    int row;
    int first;
    int last;
    int seat;
    int payment;

    zones();
    printf("Select the zone where you would like to sit:\n");
    scanf("%d", &option);

    // Zones with it's respective rows.
    switch (option) {
        case 1:
            first = 1;
            last = 5;
            break;
        case 2:
            first = 6;
            last = 10;
            break;
        case 3:
            first = 11;
            last = 50;
            break;
        case 4:
            first = 51;
            last = 100;
            break;
        case 5:
            first = 101;
            last = 250;
            break;
        case 6:
            first = 251;
            last = 350;
            break;
        case 7:
            first = 351;
            last = 400;
            break;
        case 8:
            first = 1;
            last = 100;
            break;
        case 9:
            first = 101;
            last = 300;
            break;
        case 10:
            first = 301;
            last = 400;
            break;
        default:
            printf("Back.\n");
            return;
    }

    do {
        printf("Choose a row between %d-%d", first, last);
        scanf("%d", &row);
    } while (row < first || row > last);

    if (option > 7) {
        do {
            printf("Choose a seat between 1-50 or 151-200");
            scanf("%d", &seat);
        } while ((seat < 1 || seat > 50) && (seat < 151 || seat > 200));

    } else {
        do {
            printf("Choose a seat between 51-150");
            scanf("%d", &seat);
        } while (seat < 51 || seat > 150);
    }

    payingmeth();
    printf("Select one payment method, or cancel with other number.\n");
    scanf("%d", &payment);

    if (payment < 1 || payment > 3) {
        printf("Back.\n");
        return;
    }

    printf("What's your name?:");
    fflush(stdin);
    fgets(name, sizeof(name), stdin);

    printf("Enter O to accept, anything else to cancel.\n");
    scanf("%c", &option);

    if (!option) {

        if (seats[row - 1][seat - 1].seat) {
            printf("This seat is taken.\n");
        } else {
            seats[row - 1][seat - 1].seat = true;
            seats[row - 1][seat - 1].payment = payment;
            strcpy(seats[row - 1][seat - 1].name, name);
            printf("Transaction confirmed.\n");
        }

    } else{
        printf("Back.");
    }
}

// Function to count the total sales or total income.
int income(int first, int last, int firstseat, int lastseat, int sold) {
    int count = 0;
    int sales = 0;
    for (int i = first - 1; i < last; i++) {
        for (int j = firstseat - 1; j < lastseat; j++) {
            if (seats[i][j].seat) {
                count++;
                sales += seats[i][j].ticket;
            }
        }
    }
    if (sold) { // If sold = 1, this statement returns the total sales.
        return count;
    }
    return sales; // Or it returns the total income.
}

// Function to sum the income of all zones.
int ZoneSold(int zone, int sold) {
    int count = 0;
    int first;
    int last;

    switch (zone) {
        case 1:
            first = 1;
            last = 5;
            break;
        case 2:
            first = 6;
            last = 10;
            break;
        case 3:
            first = 11;
            last = 50;
            break;
        case 4:
            first = 51;
            last = 100;
            break;
        case 5:
            first = 101;
            last = 250;
            break;
        case 6:
            first = 251;
            last = 350;
            break;
        case 7:
            first = 351;
            last = 400;
            break;
        case 8:
            first = 1;
            last = 100;
            break;
        case 9:
            first = 101;
            last = 300;
            break;
        case 10:
            first = 301;
            last = 400;
            break;
        default:
            first = 1;
            last = 200;
            break;
    }

    if (zone > 7) {
        count += income(first, last, 1, 50, sold);
        count += income(first, last, 151, 200, sold);
    } else {
        count += income(first, last, 51, 150, sold);
    }

    return count;
}

// Reports menu.
void Reports() {
    int option;
    int zone = 0;
    int count = 0;
    float rowsize;

    // Reports menu.
    menureports();
    printf("Choose an option, or any other number to return:\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            count = ZoneSold(zone, 1);
            printf("Total tickets sold: %d", count);
            break;
        case 2:
            do {
                zones();
                printf("Enter a zone:");
                scanf("%d", &zone);
            } while (zone < 1 || zone > 10);

            count = ZoneSold(zone, 1);
            printf("Total tickets sold in this zone: %d", count);
            break;
        case 3:
            count = ZoneSold(zone, 0);
            printf("Total income: $%d", count);
            break;
        case 4:
            do {
                zones();
                printf("Enter a zone:\n");
                scanf("%d", &zone);
            } while (zone < 1 || zone > 10);

            count = ZoneSold(zone, 0);
            printf("Total income in this zone: $%d", count);
            break;
        case 5:
            count = ZoneSold(zone, 1);
            printf("Occupation rate: %f%%", count * 100.0 / 80000);
            break;
        case 6:
            do {
                zones();
                printf("Enter a zone:");
                scanf("%d", &zone);
            } while (zone < 1 || zone > 10);
            count = ZoneSold(zone, 1);

            // The rows have different sizes depending on the zone.
            switch (zone) {
                case 1:
                case 2:
                    rowsize = 5;
                    break;
                case 3:
                    rowsize = 40;
                    break;
                case 4:
                case 6:
                case 7:
                    rowsize = 50;
                    break;
                case 8:
                case 10:
                    rowsize = 100;
                    break;
                case 5:
                    rowsize = 150;
                    break;
                case 9:
                default:
                    rowsize = 200;
                    break;
            }
            printf("Occupation rate in this zone: %f%%", count / rowsize);
            break;
        default:
            printf("Back");
            return;
    }

}

// This function modifies the file with the entered data.
void wFile(FILE *fp) {
    fp = fopen("MrG.txt", "wb");
    fwrite(&seats, sizeof(seats), 1, fp);
    fclose(fp);
}

int main() {

    FILE *fp;
    int option;

    fp = fopen("mrg.txt", "rb");

    if (fp == NULL) {
        Openfile(fp);
    } else {
        // if the file exists the data will be stored in the array
        while (fread(&seats, sizeof(seats), 1, fp));
    }
    // close the file
    fclose(fp);


    do {
        //Prints the menu.
        menu();
        scanf("%d", &option);
        fflush(stdin);

        switch (option) {
            case 0:
                buy();
                break;
            case 1:
                wFile(fp);
                printf("Data saved.\n");
                break;
            case 2:
                Reports();
                break;
            case 3:
                wFile(fp);
                printf("\nBYE.\n");
                break;
            default:
                printf("\nNot valid.\n");
                break;
        }

    } while (option != '0');

    return 0;
}
