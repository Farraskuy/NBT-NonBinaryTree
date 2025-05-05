#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "nbtrees.h"

int main(int argc, char *argv[]) {
    Isi_Tree T;
    int Jml_Node = 10;
    int i = 0;
    char X;

    boolean finished = false;
    int choice = 0;

    Create_tree(T, Jml_Node);


    do {
        system("cls||clear");
        
        if (choice == 0) {
            printf(" (1) Traversal PreOrder \n");
            printf(" (2) Traversal InOrder \n");
            printf(" (3) Traversal PostOrder \n");
            printf(" (4) Traversal LevelOrder \n");
            printf(" (5) Print Tree \n");
            printf(" (6) Search node Tree \n");
            printf(" (7) Jumlah Daun/Leaf \n");
            printf(" (8) Mencari level node Tree \n");
            printf(" (9) Kedalaman Tree \n");
            printf(" (10) Membandingkan 2 node Tree \n");
            printf(" (11) Exit \n");
        }

        if (choice == 1) {
            printf("Traversal PreOrder: \n");
            PreOrder(T);
            printf("\n\n");

            printf("Klik apapun untuk melanjutkan \n");

            getchar();
            choice = 0;
            continue;
        }

        if (choice == 2) {
            printf("Traversal InOrder\n");
            InOrder(T);
            printf("\n\n");

            printf("Klik apapun untuk melanjutkan \n");

            getchar();
            choice = 0;
            continue;
        }

        if (choice == 3) {
            printf("Traversal PostOrder\n");
            PostOrder(T);
            printf("\n\n");

            printf("Klik apapun untuk melanjutkan \n");

            getchar();
            choice = 0;
            continue;
        }

        if (choice == 4) {
            printf("Traversal LevelOrder\n");
            Level_order(T, Jml_Node);
            printf("\n\n");

            printf("Klik apapun untuk melanjutkan \n");

            getchar();
            choice = 0;
            continue;
        }

        if (choice == 5) {
            printf("Print Tree: \n");
            PrintTree(T);
            printf("\n\n");

            printf("Klik apapun untuk melanjutkan \n");

            getchar();
            choice = 0;
            continue;
        }

        if (choice == 6) {
            printf("Search node Tree\n");
            printf("Masukkan node yang dicari: ");
            scanf("%c", &X);
            getchar();
            if (Search(T, X)) {
                printf("Node %c ditemukan\n", X);
            } else {
                printf("Node %c tidak ditemukan\n", X);
            }
            printf("\n\n");

            printf("Klik apapun untuk melanjutkan \n");

            getchar();
            choice = 0;
            continue;
        }

        if (choice == 7) {
            printf("Jumlah Daun/Leaf\n");
            printf("Jumlah daun : %d\n", nbDaun(T));
            printf("\n\n");

            printf("Klik apapun untuk melanjutkan \n");

            getchar();
            choice = 0;
            continue;
        }

        if (choice == 8) {
            printf("Mencari level node Tree\n");
            printf("Masukkan node yang dicari: ");
            scanf("%c", &X);
            getchar();
            printf("Jumlah level : %d\n", Level(T, X));
            printf("\n\n");

            printf("Klik apapun untuk melanjutkan \n");

            getchar();
            choice = 0;
            continue;
        }

        if (choice == 9) {
            printf("Kedalaman Tree\n");
            printf("Kedalaman : %d\n", Depth(T));
            printf("\n\n");

            printf("Klik apapun untuk melanjutkan \n");

            getchar();
            choice = 0;
            continue;
        }

        if (choice == 10) {
            char Z;
            printf("Search node Tree\n");
            printf("Masukkan node yang dicari: ");
            scanf("%c", &X);
            getchar();
            if (Search(T, X)) {
                printf("Node %c ditemukan\n", X);
            } else {
                printf("Node %c tidak ditemukan\n", X);
            }
            
            printf("Masukkan node yang dicari: ");
            scanf("%c", &Z);
            getchar();
            if (Search(T, Z)) {
                printf("Node %c ditemukan\n", Z);
            } else {
                printf("Node %c tidak ditemukan\n", Z);
            }

            int a = Max(X, Z);

            printf("Node terbesar: %c\n", a);

            printf("Klik apapun untuk melanjutkan \n");

            getchar();
            choice = 0;
            continue;
        }

        if (choice == 11) {
            printf("Exit \n");
            finished = true;
            break;
        }
        
        printf(" Select Menu (Input With Keyboard): ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 11) {
            choice = 0;
            continue;
        }
        

        printf("======================================================\n");
    } while (1);
}