
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "nbtrees.h"

void Create_tree(Isi_Tree X, int Jml_Node) {
    Isi_Tree P = {
        {0},
        {'A', 2, 0, 0},
        {'B', 4, 3, 1},
        {'C', 6, 0, 1},
        {'D', 0, 5, 2},
        {'E', 9, 0, 2},
        {'F', 0, 7, 3},
        {'G', 0, 8, 3},
        {'H', 0, 0, 3},
        {'I', 0, 10, 5},
        {'J', 0, 0, 5}
    };

    memcpy(X, P, sizeof(Isi_Tree));
}


boolean IsEmpty (Isi_Tree P) {
    return (P[0].info == 0);
}

void PreOrder (Isi_Tree P) {
    int current = 1;
    boolean tampilkan = true;

    printf("%c ", P[current].info);

    do {
      if(P[current].ps_fs != 0 && tampilkan){
        current = P[current].ps_fs;
        printf("%c ", P[current].info);
      } else {
        if(P[current].ps_nb != 0){
          current = P[current].ps_nb;
          printf("%c ", P[current].info);
          tampilkan = true;
        }else{
            current = P[current].ps_pr;
            tampilkan = false;
        }
      }
    } while (P[current].ps_pr != 0);
}

void InOrder(Isi_Tree P) {    
    int queue[jml_maks + 1];
    int rear = 0;
    boolean printed[jml_maks + 1] = {false};

    int current = 1;
    boolean kunjungan = true;
    boolean toBrother = false;
    address addressOfSibling = 0;

    while (current != 0) {
        if (P[current].ps_fs != 0 && kunjungan && !toBrother) {
            queue[rear] = current;
            rear++;

            current = P[current].ps_fs;
        } else {
            if (!printed[current]) {
                printf("%c ", P[current].info);
                printed[current] = true;
            }
            
            if (toBrother) {
                current = P[addressOfSibling].ps_nb;
                toBrother = false;
                continue;
            }

            if (P[current].ps_nb != 0) {
                addressOfSibling = current;
                current = P[current].ps_pr;
                toBrother = true;
                kunjungan = true;
            } else {
                current = P[current].ps_pr;
                kunjungan = false;
                rear--;
            }
        }
    }
}

void PostOrder (Isi_Tree P) {
    int current = 1;
    boolean tampilkan = true;

    while (current != 0) {
        if (P[current].ps_fs != 0 && tampilkan) {
            current = P[current].ps_fs;
        } else {
            printf("%c ", P[current].info);
            if (P[current].ps_nb != 0) {
                current = P[current].ps_nb;
                tampilkan = true;
            } else {
                current = P[current].ps_pr;
                tampilkan = false;
            }
        }
    }
}


void Level_order(Isi_Tree P, int Jml_Node) {
    int queue[jml_maks + 1];
    int front = 0, rear = 0;

    queue[rear++] = 1;

    while (front < rear) {
        int current = queue[front++];
        printf("%c ", P[current].info);

        int child = P[current].ps_fs;
        while (child != 0) {
            queue[rear++] = child;
            child = P[child].ps_nb;
        }
    }

    printf("\n");
}

void PrintTree (Isi_Tree P) {
    int totalElements = nbElmt(P);
    int i;
    for (i = 1; i < totalElements; i++) {
        printf("--> Index ke-%d\n", i);
        printf("--------------------------------------\n");
        printf("info array ke-%d         : %c\n", i, P[i].info);
        printf("first son array ke-%d    : %d\n", i, P[i].ps_fs);
        printf("next brother array ke-%d : %d\n", i, P[i].ps_nb);
        printf("parent array ke-%d       : %d\n", i, P[i].ps_pr);
        printf("--------------------------------------\n");
    }
}

boolean Search (Isi_Tree P, infotype X) {
    int current = 1;
    boolean tampilkan = true;

    boolean found = false;
    while (current != 0 && !found) {
        if (P[current].info == X) {
            found = true;
        } else {
            if (P[current].ps_fs != 0 && tampilkan) {
                current = P[current].ps_fs;
            } else {
                if (P[current].ps_nb != 0) {
                    current = P[current].ps_nb;
                    tampilkan = true;
                } else {
                    current = P[current].ps_pr;
                    tampilkan = false;
                }
            }
        }
    }

    return found;
}

int nbElmt (Isi_Tree P) {
    int current = 1;
    boolean tampilkan = true;

    int count = 1;

    while (current != 0) {
        if (P[current].ps_fs != 0 && tampilkan) {
            current = P[current].ps_fs;
            count++;
        } else {
            if (P[current].ps_nb != 0) {
                count++;
                current = P[current].ps_nb;
                tampilkan = true;
            } else {
                current = P[current].ps_pr;
                tampilkan = false;
            }
        }
    }

    return count;
}

int nbDaun(Isi_Tree P) {
    int current = 1;
    boolean tampilkan = true;
    int count = 0;

    while (current != 0) {
        if (P[current].ps_fs == 0) {
            count++; // node daun
        }

        if (P[current].ps_fs != 0 && tampilkan) {
            current = P[current].ps_fs;
        } else {
            if (P[current].ps_nb != 0) {
                current = P[current].ps_nb;
                tampilkan = true;
            } else {
                current = P[current].ps_pr;
                tampilkan = false;
            }
        }
    }

    return count;
}


int Level (Isi_Tree P, infotype X) {
    int current = 1;
    boolean tampilkan = true;

    int level = 0;
    boolean found = false;

    while (current != 0 && !found) {
        if (P[current].info == X) {
            found = true;
        } else {
            if (P[current].ps_fs != 0 && tampilkan) {
                current = P[current].ps_fs;
                level++;
            } else {
                if (P[current].ps_nb != 0) {
                    current = P[current].ps_nb;
                    tampilkan = true;
                } else {
                    current = P[current].ps_pr;
                    tampilkan = false;
                }
            }
        }
    }

    return level;
}

int Depth (Isi_Tree P) {
    int current = 1;
    boolean tampilkan = true;

    int depth = 0;

    while (current != 0) {
        if (P[current].ps_fs != 0 && tampilkan) {
            current = P[current].ps_fs;
            depth++;
        } else {
            if (P[current].ps_nb != 0) {
                current = P[current].ps_nb;
                tampilkan = true;
            } else {
                current = P[current].ps_pr;
                tampilkan = false;
            }
        }
    }

    return depth;
}

int Max (infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}
