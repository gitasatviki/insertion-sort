#include <stdio.h>//library
#include <stdlib.h>//library
#include <time.h>//library

void menu()//sub program menghasilkan menu
{
    printf("PROGRAM INSERTION SORT\n");
    printf("======================\n");
    printf("Menu :\n");
    printf("1. Urutan Menaik\n");
    printf("2. Urutan Menurun\n");
    printf("3. Keluar\n");
    printf("======================\n");
}

void sort_naik(int arr[], int bil)//sub program mengurutkan menaik
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);//waktu running time mulai
    int i, j, k, key;
    for (i=1; i<bil; i++)//looping mengurutkan
    {
        key=arr[i];
        j=i-1;
        while (j>=0&&arr[j]>key)//mengurutkan naik
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;

        printf("Langkah %d :", i);
        for (k=0; k<bil; k++)
        {
            printf("%d ", arr[k]);//output langkah-langkah mengurutkan
        }
        printf("\n\n");
    }
    clock_gettime(CLOCK_MONOTONIC, &end);//running time akhir
    double waktu = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1e9;//hasil running time
    printf("Waktu yang diperlukan: %.5f second\n", waktu);//output running time
}

void sort_turun(int arr2[], int bil2)//sub program mengurutkan menurun
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    int i, j, k, key2;
    for (i=1; i<bil2; i++)
    {
        key2=arr2[i];
        j=i-1;
        while (j>=0&&arr2[j]<key2)//urutan menurun
        {
            arr2[j+1]=arr2[j];
            j=j-1;
        }
        arr2[j+1]=key2;

        printf("Langkah %d :", i);
        for (k =0; k<bil2; k++)
        {
            printf("%d ", arr2[k]);//ouput langkah-langkah mengurutkan
        }
        printf("\n\n");
    }
    clock_gettime(CLOCK_MONOTONIC, &end);//running time berakhir
    double waktu = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1e9;//running time keseluruhan
    printf("\nWaktu yang diperlukan: %.5f second\n", waktu);//output running time
}

void menaik()//sub program menu menaik
{
    int bil, k;

    printf("Jumlah Bilangan Array : ");//masukkan inputan jumlah array
    scanf("%d", &bil);
    int *arr=(int*)malloc(bil*sizeof(int));
    if (arr==NULL)
    {
        printf("Alokasi memori gagal!");
        exit(1);
    }

    printf("\n");

    for (k=0; k<bil; k++)
    {
        printf("Masukkan Bilangan Array ke-%d : ", k+1);//masukkan inputan bilangan
        scanf("%d", &arr[k]);
    }

    printf("\nLangkah-Langkah Sorting\n");
    sort_naik(arr, bil);//mengurutkan

    printf("\nArray yang telah diurutkan : ");
    for (int i=0; i<bil; i++)
    {
        printf("%d ", arr[i]);//output mengurutkan
    }
    printf("\n\n");
}

void menurun()//sub program menu menurun
{
    int bil2, k;

    printf("Jumlah Bilangan Array : ");
    scanf("%d", &bil2);//inputan jumlah array
    int *arr2=(int *)malloc(bil2*sizeof(int));
    if (arr2==NULL)
    {
        printf("Alokasi memori gagal!");
        exit(1);
    }

    printf("\n");

    for (k=0; k<bil2; k++)
    {
        printf("Masukkan Bilangan Array ke-%d : ", k+1);
        scanf("%d", &arr2[k]);//inputan bilangan
    }

    printf("\nLangkah-Langkah Sorting\n");
    sort_turun(arr2, bil2);//mengurutkan

    printf("\nArray yang telah diurutkan : ");
    for (int i=0; i<bil2; i++)
    {
        printf("%d ", arr2[i]);//ouput hasil urutan
    }
    printf("\n\n");
}

int main()//menu utama
{
    int pil;

    do
    {
        menu();
        printf("Pilihan : ");
        scanf("%d", &pil);//input pilihan menu
        printf("\n\n");

        switch (pil)
        {
        case 1:
            system("cls");
            menaik();//menu 1
            break;
        case 2:
            system("cls");
            menurun();//menu 2
            break;
        case 3:
            system("cls");
            printf("Keluar dari Program!");//menu 3
            break;
        default:
            printf("Pilihan Tidak Valid");// menu bila memasukkan angka selain 1-3
            break;
        }
    } while (pil != 3);

    return 0;
}
