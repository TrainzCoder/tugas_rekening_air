#include <stdio.h>
#include <stdlib.h>
#define ADMINISTRASI 50
#define BPM_R 10 //rumah tangga
#define BPM_S 20 //usaha
#define BIAYA_METER_1 50
#define BIAYA_METER_N 10
#define DENDA_100_KEATAS 20
#define DENDA_LBH100_KRNG10 10

void rumah_tangga();
void usaha();
void instruksi();
void keluar();

int main() 
{
    char kelas_konsumen;
    system("cls");
    printf("==============================\n");
    printf("   PEMBAYARAN REKENING AIR    \n");
    printf("==============================\n");
    printf("[R] Rumah Tangga\n");
    printf("[S] Usaha\n");
    printf("==============================\n");
    printf("Pilih golongan berdasarkan jenis penggunaan anda : ");
    scanf("%c", &kelas_konsumen);

    if(kelas_konsumen == 'r' || kelas_konsumen == 'R')
    {
        rumah_tangga();
    } 
    else if(kelas_konsumen == 's' || kelas_konsumen == 'S')
    {
        usaha();
    }
    return 0;
}

void rumah_tangga()
{
    int pemakaian_bulan_lalu, pemakaian_saat_ini, biaya_meter, biaya_lainnya, tagihan, denda; //masih int semua
    system("cls");
    printf("==============================\n");
    printf("     KONSUMEN RUMAH TANGGA    \n");
    printf("==============================\n");
    printf("Masukan pemakaian air bulan lalu : ");
    scanf("%d", &pemakaian_bulan_lalu);
    printf("Masukan pemakaian air saat ini   : ");
    scanf("%d", &pemakaian_saat_ini);

    //selisih
    int besar_pemakaian = pemakaian_saat_ini - pemakaian_bulan_lalu;
    //printf("\nbesar pemakaian = %d\n\n", besar_pemakaian); //test

    //kalo minus
    if(besar_pemakaian < 0)
    {
        besar_pemakaian = -1 * (besar_pemakaian);
    }

    //menentukan biayanya meter
    if(besar_pemakaian > 0 && besar_pemakaian <= 10)
    {
        biaya_meter = BIAYA_METER_1;
    }
    else if(besar_pemakaian > 10)
    {
        biaya_meter = besar_pemakaian - 10;
        biaya_meter = besar_pemakaian * 10 + 50;
    }
    else if(besar_pemakaian == 0)
    {
        biaya_meter = 0;
    }
    // printf("biaya meter = %d\n", biaya_meter); //test

    //menentukan denda
    if(besar_pemakaian >= 0 && besar_pemakaian <= 10)
    {
        denda = 0;
    }
    else if(besar_pemakaian > 10 && besar_pemakaian <= 100)
    {
        denda = DENDA_LBH100_KRNG10;
    }
    else if(besar_pemakaian > 100)
    {
        denda = DENDA_100_KEATAS;
    }
    //printf("denda = %d\n", denda); //test
    //printf("+ 50 + 10\n"); //test

    biaya_lainnya = denda + BPM_R + ADMINISTRASI;
    tagihan = biaya_meter + biaya_lainnya;

    printf("\nBiaya meter : %d\n", biaya_meter);
    printf("Biaya lainnya : %d\n", biaya_lainnya);
    printf("Tagihan : %d\n", tagihan);
    printf("==============================\n");
}

void usaha()
{
    int pemakaian_bulan_lalu, pemakaian_saat_ini, biaya_meter, biaya_lainnya, tagihan, denda; //masih int semua
    system("cls");
    printf("==============================\n");
    printf("         KONSUMEN USAHA       \n");
    printf("==============================\n");
    printf("Masukan pemakaian air bulan lalu : ");
    scanf("%d", &pemakaian_bulan_lalu);
    printf("Masukan pemakaian air saat ini   : ");
    scanf("%d", &pemakaian_saat_ini);

    //selisih
    int besar_pemakaian = pemakaian_saat_ini - pemakaian_bulan_lalu;
    //printf("\nbesar pemakaian = %d\n\n", besar_pemakaian); //test

        //kalo minus
    if(besar_pemakaian < 0)
    {
        besar_pemakaian = -1 * (besar_pemakaian);
    }

    //menentukan biayanya meter
    if(besar_pemakaian > 0 && besar_pemakaian <= 10)
    {
        biaya_meter = BIAYA_METER_1;
    }
    else if(besar_pemakaian > 10)
    {
        biaya_meter = besar_pemakaian - 10;
        biaya_meter = besar_pemakaian * 10 + 50;
    }
    else if(besar_pemakaian == 0)
    {
        biaya_meter = 0;
    }
    else if(besar_pemakaian < 0)
    {
        printf("MINUS");
    }
    // printf("biaya meter = %d\n", biaya_meter); //test

    //menentukan denda
    if(besar_pemakaian >= 0 && besar_pemakaian <= 10)
    {
        denda = 0;
    }
    else if(besar_pemakaian > 10 && besar_pemakaian <= 100)
    {
        denda = DENDA_LBH100_KRNG10;
    }
    else if(besar_pemakaian > 100)
    {
        denda = DENDA_100_KEATAS;
    }
    //printf("denda = %d\n", denda); //test
    //printf("+ 50 + 10\n"); //test

    biaya_lainnya = denda + BPM_S + ADMINISTRASI;
    tagihan = biaya_meter + biaya_lainnya;

    printf("\nBiaya meter : %d\n", biaya_meter);
    printf("Biaya lainnya : %d\n", biaya_lainnya);
    printf("Tagihan : %d\n", tagihan);
    printf("==============================\n");
}
