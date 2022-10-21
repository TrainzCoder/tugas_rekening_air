#include <stdio.h>
#include <stdlib.h>
#define ADMINISTRASI 50
#define BPM_R 10 //rumah tangga
#define BPM_S 20 //usaha
#define BIAYA_METER_1 50
#define BIAYA_METER_N 10
#define DENDA_100_KEATAS 20
#define DENDA_LBH100_KRNG10 10

int main() 
{
    int menu;
    system("cls");
    printf("==============================\n");
    printf("   PEMBAYARAN REKENING AIR    \n");
    printf("==============================\n");
    printf("[1] Rumah Tangga\n");
    printf("[2] Usaha\n");
    printf("==============================\n");
    printf("Pilih golongan berdasarkan jenis penggunaan anda : ");
    scanf("%d", &menu);

    switch(menu)
    {
    case 1:
        rumah_tangga();
        break;
    case 2:
        usaha();
        break;
    }

    return 0;
}

void rumah_tangga()
{
    int menu;
    system("cls");
    printf("==============================\n");
    printf("     KONSUMEN RUMAH TANGGA    \n");
    printf("==============================\n");
    printf("[1] Rumah Tangga Biasa\n");
    printf("[2] Non Niaga Bersubsidi\n");
    printf("[3] Non Niaga Tanpa Bersubsidi\n");
    printf("==============================\n");
    printf("Pilih golongan berdasarkan jenis penggunaan anda : ");
    scanf("%d", &menu);

    switch(menu)
    {
        case 1:
            rumah_tangga_biasa();
            break;
        case 2:
            non_niaga_bersubsidi();
            break;
        case 3:
            non_niaga_tanpa_bersubsidi();
            break;
    }
}

void rumah_tangga_biasa()
{
    int menu, pemakaian_bulan_lalu, pemakaian_saat_ini, biaya_meter, biaya_lainnya, tagihan, denda;
    system("cls");
    printf("==============================\n");
    printf("      RUMAH TANGGA BIASA      \n");
    printf("==============================\n");
    printf("Masukan pemakaian air bulan lalu : ");
    scanf("%d", &pemakaian_bulan_lalu);
    printf("Masukan pemakaian air saat ini   : ");
    scanf("%d", &pemakaian_saat_ini);
    
    while (pemakaian_bulan_lalu > pemakaian_saat_ini) //yang ini sudah validasi
    {
        system("cls");
        printf("MASUKAN BESAR PEMAKAIAN AIR DENGAN BENAR !\n\n");
        printf("==============================\n");
        printf("      RUMAH TANGGA BIASA      \n");
        printf("==============================\n");
        printf("Masukan pemakaian air bulan lalu : ");
        scanf("%d", &pemakaian_bulan_lalu);
        printf("Masukan pemakaian air saat ini   : ");
        scanf("%d", &pemakaian_saat_ini);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    // selisih pemakaian
    int besar_pemakaian = pemakaian_saat_ini - pemakaian_bulan_lalu;

    //menentukan biaya meter
    if(besar_pemakaian > 0 && besar_pemakaian <= 10)
    {
        biaya_meter = BIAYA_METER_1;
    }
    else if(besar_pemakaian > 10)
    {
        besar_pemakaian -= 10;
        biaya_meter = besar_pemakaian * BIAYA_METER_N + BIAYA_METER_1;
    }
    else if(besar_pemakaian == 0)
    {
        biaya_meter = 0;
    }

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

    biaya_lainnya = denda + BPM_R + ADMINISTRASI;
    tagihan = biaya_meter + biaya_lainnya;

    printf("==============================");
    printf("\nBiaya meter : %d\n", biaya_meter);
    printf("Biaya lainnya : %d\n", biaya_lainnya);
    printf("Tagihan : %d\n", tagihan);
    printf("==============================\n");
}

void non_niaga_bersubsidi()
{
    int menu;
    system("cls");
    printf("==============================\n");
    printf("      NON NIAGA BERSUBSIDI    \n");
    printf("==============================\n");
    printf("[1] Rumah Tangga A1\n");
    printf("[2] Rumah Tangga A2\n");
    printf("[3] Rumah Tangga A3\n");
    printf("[4] Rumah Tangga A4\n");
    printf("==============================\n");
    printf("Pilih golongan berdasarkan jenis penggunaan anda : ");
    scanf("%d", &menu);
    
    switch(menu)
    {
        case 1:
            subsidi_a1();
            break;
        case 2:
            subsidi_a2();
            break;
        case 3:
            subsidi_a3();
            break;
        case 4:
            subsidi_a4();
            break;
    }
}

void hitung_rumah_tangga(int BIAYA_METER_0_SAMPAI_10, int BIAYA_METER_11_SAMPAI_20, int BIAYA_METER_LEBIH_20, int pemakaian_bulan_lalu, int pemakaian_saat_ini)
{
    int biaya_meter, biaya_lainnya, tagihan, denda;

    // selisih pemakaian
    int besar_pemakaian = pemakaian_saat_ini - pemakaian_bulan_lalu;

    //menentukan biaya meter
    if(besar_pemakaian > 0 && besar_pemakaian <= 10)
    {
        biaya_meter = BIAYA_METER_0_SAMPAI_10;
    }
    else if(besar_pemakaian > 10 && besar_pemakaian <= 20)
    {
        besar_pemakaian -= 10;
        biaya_meter = besar_pemakaian * BIAYA_METER_11_SAMPAI_20 + BIAYA_METER_0_SAMPAI_10;
    }
    else if(besar_pemakaian > 20)
    {
        besar_pemakaian -= 20;
        biaya_meter = besar_pemakaian * BIAYA_METER_LEBIH_20 + BIAYA_METER_0_SAMPAI_10 + BIAYA_METER_11_SAMPAI_20;
    }
    else if(besar_pemakaian == 0)
    {
        biaya_meter = 0;
    }

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

    biaya_lainnya = denda + BPM_R + ADMINISTRASI;
    tagihan = biaya_meter + biaya_lainnya;

    printf("==============================");
    printf("\nBiaya meter : %d\n", biaya_meter);
    printf("Biaya lainnya : %d\n", biaya_lainnya);
    printf("Tagihan : %d\n", tagihan);
    printf("==============================\n");
}

void subsidi_a1()
{
    const int BIAYA_METER_0_SAMPAI_10 = 1780;
    const int BIAYA_METER_11_SAMPAI_20 = 2060;
    const int BIAYA_METER_LEBIH_20 = 5880;
    int menu, pemakaian_bulan_lalu, pemakaian_saat_ini;
    system("cls");
    printf("==============================\n");
    printf("     NON NIAGA BERSUBSIDI     \n");
    printf("        Rumah Tangga A1       \n");
    printf("==============================\n");
    printf("Masukan pemakaian air bulan lalu : ");
    scanf("%d", &pemakaian_bulan_lalu);
    printf("Masukan pemakaian air saat ini   : ");
    scanf("%d", &pemakaian_saat_ini);
    
    while (pemakaian_bulan_lalu > pemakaian_saat_ini) //yang ini sudah validasi
    {
        system("cls");
        printf("MASUKAN BESAR PEMAKAIAN AIR DENGAN BENAR !\n\n");
        printf("==============================\n");
        printf("     NON NIAGA BERSUBSIDI     \n");
        printf("        Rumah Tangga A1       \n");
        printf("==============================\n");
        printf("Masukan pemakaian air bulan lalu : ");
        scanf("%d", &pemakaian_bulan_lalu);
        printf("Masukan pemakaian air saat ini   : ");
        scanf("%d", &pemakaian_saat_ini);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    hitung_rumah_tangga(BIAYA_METER_0_SAMPAI_10, BIAYA_METER_11_SAMPAI_20, BIAYA_METER_LEBIH_20, pemakaian_bulan_lalu, pemakaian_saat_ini);
}

void subsidi_a2()
{
    const int BIAYA_METER_0_SAMPAI_10 = 2060;
    const int BIAYA_METER_11_SAMPAI_20 = 2340;
    const int BIAYA_METER_LEBIH_20 = 5940;
    int menu, pemakaian_bulan_lalu, pemakaian_saat_ini;
    system("cls");
    printf("==============================\n");
    printf("     NON NIAGA BERSUBSIDI     \n");
    printf("        Rumah Tangga A2       \n");
    printf("==============================\n");
    printf("Masukan pemakaian air bulan lalu : ");
    scanf("%d", &pemakaian_bulan_lalu);
    printf("Masukan pemakaian air saat ini   : ");
    scanf("%d", &pemakaian_saat_ini);
    
    while (pemakaian_bulan_lalu > pemakaian_saat_ini) //yang ini sudah validasi
    {
        system("cls");
        printf("MASUKAN BESAR PEMAKAIAN AIR DENGAN BENAR !\n\n");
        printf("==============================\n");
        printf("     NON NIAGA BERSUBSIDI     \n");
        printf("        Rumah Tangga A2       \n");
        printf("==============================\n");
        printf("Masukan pemakaian air bulan lalu : ");
        scanf("%d", &pemakaian_bulan_lalu);
        printf("Masukan pemakaian air saat ini   : ");
        scanf("%d", &pemakaian_saat_ini);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    hitung_rumah_tangga(BIAYA_METER_0_SAMPAI_10, BIAYA_METER_11_SAMPAI_20, BIAYA_METER_LEBIH_20, pemakaian_bulan_lalu, pemakaian_saat_ini);
}

void subsidi_a3()
{
    const int BIAYA_METER_0_SAMPAI_10 = 2900;
    const int BIAYA_METER_11_SAMPAI_20 = 3180;
    const int BIAYA_METER_LEBIH_20 = 6120;
    int menu, pemakaian_bulan_lalu, pemakaian_saat_ini;
    system("cls");
    printf("==============================\n");
    printf("     NON NIAGA BERSUBSIDI     \n");
    printf("        Rumah Tangga A3       \n");
    printf("==============================\n");
    printf("Masukan pemakaian air bulan lalu : ");
    scanf("%d", &pemakaian_bulan_lalu);
    printf("Masukan pemakaian air saat ini   : ");
    scanf("%d", &pemakaian_saat_ini);
    
    while (pemakaian_bulan_lalu > pemakaian_saat_ini) //yang ini sudah validasi
    {
        system("cls");
        printf("MASUKAN BESAR PEMAKAIAN AIR DENGAN BENAR !\n\n");
        printf("==============================\n");
        printf("     NON NIAGA BERSUBSIDI     \n");
        printf("        Rumah Tangga A3       \n");
        printf("==============================\n");
        printf("Masukan pemakaian air bulan lalu : ");
        scanf("%d", &pemakaian_bulan_lalu);
        printf("Masukan pemakaian air saat ini   : ");
        scanf("%d", &pemakaian_saat_ini);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    hitung_rumah_tangga(BIAYA_METER_0_SAMPAI_10, BIAYA_METER_11_SAMPAI_20, BIAYA_METER_LEBIH_20, pemakaian_bulan_lalu, pemakaian_saat_ini);
}

void subsidi_a4()
{
    const int BIAYA_METER_0_SAMPAI_10 = 3460;
    const int BIAYA_METER_11_SAMPAI_20 = 3740;
    const int BIAYA_METER_LEBIH_20 = 6240;
    int menu, pemakaian_bulan_lalu, pemakaian_saat_ini;
    system("cls");
    printf("==============================\n");
    printf("     NON NIAGA BERSUBSIDI     \n");
    printf("        Rumah Tangga A4       \n");
    printf("==============================\n");
    printf("Masukan pemakaian air bulan lalu : ");
    scanf("%d", &pemakaian_bulan_lalu);
    printf("Masukan pemakaian air saat ini   : ");
    scanf("%d", &pemakaian_saat_ini);
    
    while (pemakaian_bulan_lalu > pemakaian_saat_ini) //yang ini sudah validasi
    {
        system("cls");
        printf("MASUKAN BESAR PEMAKAIAN AIR DENGAN BENAR !\n\n");
        printf("==============================\n");
        printf("     NON NIAGA BERSUBSIDI     \n");
        printf("        Rumah Tangga A4       \n");
        printf("==============================\n");
        printf("Masukan pemakaian air bulan lalu : ");
        scanf("%d", &pemakaian_bulan_lalu);
        printf("Masukan pemakaian air saat ini   : ");
        scanf("%d", &pemakaian_saat_ini);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    hitung_rumah_tangga(BIAYA_METER_0_SAMPAI_10, BIAYA_METER_11_SAMPAI_20, BIAYA_METER_LEBIH_20, pemakaian_bulan_lalu, pemakaian_saat_ini);
}

void non_niaga_tanpa_bersubsidi()
{
    int menu;
    system("cls");
    printf("==============================\n");
    printf("  NON NIAGA TANPA BERSUBSIDI  \n");
    printf("==============================\n");
    printf("[1] Rumah Tangga A1\n");
    printf("[2] Rumah Tangga A2\n");
    printf("[3] Rumah Tangga A3\n");
    printf("[4] Rumah Tangga A4\n");
    printf("[5] Rumah Tangga B\n");
    printf("==============================\n");
    printf("Pilih golongan berdasarkan jenis penggunaan anda : ");
    scanf("%d", &menu);
    
    switch(menu)
    {
        case 1:
            non_subsidi_a1();
            break;
        case 2:
            non_subsidi_a2();
            break;
        case 3:
            non_subsidi_a3();
            break;
        case 4:
            non_subsidi_a4();
            break;
        case 5:
            non_subsidi_b();
            break;
    }
}

void non_subsidi_a1()
{
    const int BIAYA_METER_0_SAMPAI_10 = 6340;
    const int BIAYA_METER_11_SAMPAI_20 = 9200;
    const int BIAYA_METER_LEBIH_20 = 9600;
    int menu, pemakaian_bulan_lalu, pemakaian_saat_ini;
    system("cls");
    printf("==============================\n");
    printf("  NON NIAGA TANPA BERSUBSIDI  \n");
    printf("         Rumah Tangga A2      \n");
    printf("==============================\n");
    printf("Masukan pemakaian air bulan lalu : ");
    scanf("%d", &pemakaian_bulan_lalu);
    printf("Masukan pemakaian air saat ini   : ");
    scanf("%d", &pemakaian_saat_ini);
    
    while (pemakaian_bulan_lalu > pemakaian_saat_ini) //yang ini sudah validasi
    {
        system("cls");
        printf("MASUKAN BESAR PEMAKAIAN AIR DENGAN BENAR !\n\n");
        printf("==============================\n");
        printf("  NON NIAGA TANPA BERSUBSIDI  \n");
        printf("         Rumah Tangga A1      \n");
        printf("==============================\n");
        printf("Masukan pemakaian air bulan lalu : ");
        scanf("%d", &pemakaian_bulan_lalu);
        printf("Masukan pemakaian air saat ini   : ");
        scanf("%d", &pemakaian_saat_ini);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    hitung_rumah_tangga(BIAYA_METER_0_SAMPAI_10, BIAYA_METER_11_SAMPAI_20, BIAYA_METER_LEBIH_20, pemakaian_bulan_lalu, pemakaian_saat_ini);
}

void non_subsidi_a2()
{
    const int BIAYA_METER_0_SAMPAI_10 = 6490;
    const int BIAYA_METER_11_SAMPAI_20 = 9500;
    const int BIAYA_METER_LEBIH_20 = 9800;
    int menu, pemakaian_bulan_lalu, pemakaian_saat_ini;
    system("cls");
    printf("==============================\n");
    printf("  NON NIAGA TANPA BERSUBSIDI  \n");
    printf("         Rumah Tangga A2      \n");
    printf("==============================\n");
    printf("Masukan pemakaian air bulan lalu : ");
    scanf("%d", &pemakaian_bulan_lalu);
    printf("Masukan pemakaian air saat ini   : ");
    scanf("%d", &pemakaian_saat_ini);
    
    while (pemakaian_bulan_lalu > pemakaian_saat_ini) //yang ini sudah validasi
    {
        system("cls");
        printf("MASUKAN BESAR PEMAKAIAN AIR DENGAN BENAR !\n\n");
        printf("==============================\n");
        printf("  NON NIAGA TANPA BERSUBSIDI  \n");
        printf("         Rumah Tangga A2      \n");
        printf("==============================\n");
        printf("Masukan pemakaian air bulan lalu : ");
        scanf("%d", &pemakaian_bulan_lalu);
        printf("Masukan pemakaian air saat ini   : ");
        scanf("%d", &pemakaian_saat_ini);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    hitung_rumah_tangga(BIAYA_METER_0_SAMPAI_10, BIAYA_METER_11_SAMPAI_20, BIAYA_METER_LEBIH_20, pemakaian_bulan_lalu, pemakaian_saat_ini);
}

void non_subsidi_a3()
{

    const int BIAYA_METER_0_SAMPAI_10 = 6640;
    const int BIAYA_METER_11_SAMPAI_20 = 9800;
    const int BIAYA_METER_LEBIH_20 = 10100;
    int menu, pemakaian_bulan_lalu, pemakaian_saat_ini;
    system("cls");
    printf("==============================\n");
    printf("  NON NIAGA TANPA BERSUBSIDI  \n");
    printf("         Rumah Tangga A3      \n");
    printf("==============================\n");
    printf("Masukan pemakaian air bulan lalu : ");
    scanf("%d", &pemakaian_bulan_lalu);
    printf("Masukan pemakaian air saat ini   : ");
    scanf("%d", &pemakaian_saat_ini);
    
    while (pemakaian_bulan_lalu > pemakaian_saat_ini) //yang ini sudah validasi
    {
        system("cls");
        printf("MASUKAN BESAR PEMAKAIAN AIR DENGAN BENAR !\n\n");
        printf("==============================\n");
        printf("  NON NIAGA TANPA BERSUBSIDI  \n");
        printf("         Rumah Tangga A3      \n");
        printf("==============================\n");
        printf("Masukan pemakaian air bulan lalu : ");
        scanf("%d", &pemakaian_bulan_lalu);
        printf("Masukan pemakaian air saat ini   : ");
        scanf("%d", &pemakaian_saat_ini);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    hitung_rumah_tangga(BIAYA_METER_0_SAMPAI_10, BIAYA_METER_11_SAMPAI_20, BIAYA_METER_LEBIH_20, pemakaian_bulan_lalu, pemakaian_saat_ini);
}

void non_subsidi_a4()
{
    const int BIAYA_METER_0_SAMPAI_10 = 6790;
    const int BIAYA_METER_11_SAMPAI_20 = 10100;
    const int BIAYA_METER_LEBIH_20 = 10400;
    int menu, pemakaian_bulan_lalu, pemakaian_saat_ini;
    system("cls");
    printf("==============================\n");
    printf("  NON NIAGA TANPA BERSUBSIDI  \n");
    printf("         Rumah Tangga A4      \n");
    printf("==============================\n");
    printf("Masukan pemakaian air bulan lalu : ");
    scanf("%d", &pemakaian_bulan_lalu);
    printf("Masukan pemakaian air saat ini   : ");
    scanf("%d", &pemakaian_saat_ini);
    
    while (pemakaian_bulan_lalu > pemakaian_saat_ini) //yang ini sudah validasi
    {
        system("cls");
        printf("MASUKAN BESAR PEMAKAIAN AIR DENGAN BENAR !\n\n");
        printf("==============================\n");
        printf("  NON NIAGA TANPA BERSUBSIDI  \n");
        printf("         Rumah Tangga A4      \n");
        printf("==============================\n");
        printf("Masukan pemakaian air bulan lalu : ");
        scanf("%d", &pemakaian_bulan_lalu);
        printf("Masukan pemakaian air saat ini   : ");
        scanf("%d", &pemakaian_saat_ini);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    hitung_rumah_tangga(BIAYA_METER_0_SAMPAI_10, BIAYA_METER_11_SAMPAI_20, BIAYA_METER_LEBIH_20, pemakaian_bulan_lalu, pemakaian_saat_ini);
}

void non_subsidi_b()
{
    const int BIAYA_METER_0_SAMPAI_10 = 6940;
    const int BIAYA_METER_11_SAMPAI_20 = 10400;
    const int BIAYA_METER_LEBIH_20 = 10700;
    int menu, pemakaian_bulan_lalu, pemakaian_saat_ini;
    system("cls");
    printf("==============================\n");
    printf("  NON NIAGA TANPA BERSUBSIDI  \n");
    printf("         Rumah Tangga B       \n");
    printf("==============================\n");
    printf("Masukan pemakaian air bulan lalu : ");
    scanf("%d", &pemakaian_bulan_lalu);
    printf("Masukan pemakaian air saat ini   : ");
    scanf("%d", &pemakaian_saat_ini);
    
    while (pemakaian_bulan_lalu > pemakaian_saat_ini) //yang ini sudah validasi
    {
        system("cls");
        printf("MASUKAN BESAR PEMAKAIAN AIR DENGAN BENAR !\n\n");
        printf("==============================\n");
        printf("  NON NIAGA TANPA BERSUBSIDI  \n");
        printf("         Rumah Tangga B       \n");
        printf("==============================\n");
        printf("Masukan pemakaian air bulan lalu : ");
        scanf("%d", &pemakaian_bulan_lalu);
        printf("Masukan pemakaian air saat ini   : ");
        scanf("%d", &pemakaian_saat_ini);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    hitung_rumah_tangga(BIAYA_METER_0_SAMPAI_10, BIAYA_METER_11_SAMPAI_20, BIAYA_METER_LEBIH_20, pemakaian_bulan_lalu, pemakaian_saat_ini);
}











void usaha()
{
    int menu;
    system("cls");
    printf("==============================\n");
    printf("         KONSUMEN USAHA       \n");
    printf("==============================\n");
    printf("[1] Usaha Biasa\n");
    printf("[2] Niaga Kecil\n");
    printf("[3] Niaga Sedang\n");
    printf("[4] Niaga Besar\n");
    printf("==============================\n");
    printf("Pilih golongan berdasarkan jenis penggunaan anda : ");
    scanf("%d", &menu);

    switch(menu)
    {
        case 1:
            usaha_biasa();
            break;
        case 2:
            niaga_kecil();
            break;
        case 3:
            niaga_sedang();
            break;
        case 4:
            niaga_besar();
            break;
    }
}

void usaha_biasa()
{
    int menu, pemakaian_bulan_lalu, pemakaian_saat_ini, biaya_meter, biaya_lainnya, tagihan, denda;
    system("cls");
    printf("==============================\n");
    printf("          USAHA BIASA         \n");
    printf("==============================\n");
    printf("Masukan pemakaian air bulan lalu : ");
    scanf("%d", &pemakaian_bulan_lalu);
    printf("Masukan pemakaian air saat ini   : ");
    scanf("%d", &pemakaian_saat_ini);
    
    while (pemakaian_bulan_lalu > pemakaian_saat_ini) //yang ini sudah validasi
    {
        system("cls");
        printf("MASUKAN BESAR PEMAKAIAN AIR DENGAN BENAR !\n\n");
        printf("==============================\n");
        printf("          USAHA BIASA         \n");
        printf("==============================\n");
        printf("Masukan pemakaian air bulan lalu : ");
        scanf("%d", &pemakaian_bulan_lalu);
        printf("Masukan pemakaian air saat ini   : ");
        scanf("%d", &pemakaian_saat_ini);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    // selisih pemakaian
    int besar_pemakaian = pemakaian_saat_ini - pemakaian_bulan_lalu;

    //menentukan biaya meter
    if(besar_pemakaian > 0 && besar_pemakaian <= 10)
    {
        biaya_meter = BIAYA_METER_1;
    }
    else if(besar_pemakaian > 10)
    {
        besar_pemakaian -= 10;
        biaya_meter = besar_pemakaian * BIAYA_METER_N + BIAYA_METER_1;
    }
    else if(besar_pemakaian == 0)
    {
        biaya_meter = 0;
    }

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

    biaya_lainnya = denda + BPM_S + ADMINISTRASI;
    tagihan = biaya_meter + biaya_lainnya;

    printf("==============================");
    printf("\nBiaya meter : %d\n", biaya_meter);
    printf("Biaya lainnya : %d\n", biaya_lainnya);
    printf("Tagihan : %d\n", tagihan);
    printf("==============================\n");
}

void hitung_usaha(int BIAYA_METER_0_SAMPAI_10, int BIAYA_METER_11_SAMPAI_20, int BIAYA_METER_LEBIH_20, int pemakaian_bulan_lalu, int pemakaian_saat_ini)
{
    int biaya_meter, biaya_lainnya, tagihan, denda;

    // selisih pemakaian
    int besar_pemakaian = pemakaian_saat_ini - pemakaian_bulan_lalu;

    //menentukan biaya meter
    if(besar_pemakaian > 0 && besar_pemakaian <= 10)
    {
        biaya_meter = BIAYA_METER_0_SAMPAI_10;
    }
    else if(besar_pemakaian > 10 && besar_pemakaian <= 20)
    {
        besar_pemakaian -= 10;
        biaya_meter = besar_pemakaian * BIAYA_METER_11_SAMPAI_20 + BIAYA_METER_0_SAMPAI_10;
    }
    else if(besar_pemakaian > 20)
    {
        besar_pemakaian -= 20;
        biaya_meter = besar_pemakaian * BIAYA_METER_LEBIH_20 + BIAYA_METER_0_SAMPAI_10 + BIAYA_METER_11_SAMPAI_20;
    }
    else if(besar_pemakaian == 0)
    {
        biaya_meter = 0;
    }

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

    biaya_lainnya = denda + BPM_S + ADMINISTRASI;
    tagihan = biaya_meter + biaya_lainnya;

    printf("==============================");
    printf("\nBiaya meter : %d\n", biaya_meter);
    printf("Biaya lainnya : %d\n", biaya_lainnya);
    printf("Tagihan : %d\n", tagihan);
    printf("==============================\n");
}

void niaga_kecil()
{
    const int BIAYA_METER_0_SAMPAI_10 = 9200;
    const int BIAYA_METER_11_SAMPAI_20 = 9850;
    const int BIAYA_METER_LEBIH_20 = 10950;
    int menu, pemakaian_bulan_lalu, pemakaian_saat_ini;
    system("cls");
    printf("==============================\n");
    printf("          NIAGA KECIL         \n");
    printf("==============================\n");
    printf("Masukan pemakaian air bulan lalu : ");
    scanf("%d", &pemakaian_bulan_lalu);
    printf("Masukan pemakaian air saat ini   : ");
    scanf("%d", &pemakaian_saat_ini);
    
    while (pemakaian_bulan_lalu > pemakaian_saat_ini) //yang ini sudah validasi
    {
        system("cls");
        printf("MASUKAN BESAR PEMAKAIAN AIR DENGAN BENAR !\n\n");
        printf("==============================\n");
        printf("          NIAGA KECIL         \n");
        printf("==============================\n");
        printf("Masukan pemakaian air bulan lalu : ");
        scanf("%d", &pemakaian_bulan_lalu);
        printf("Masukan pemakaian air saat ini   : ");
        scanf("%d", &pemakaian_saat_ini);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    hitung_usaha(BIAYA_METER_0_SAMPAI_10, BIAYA_METER_11_SAMPAI_20, BIAYA_METER_LEBIH_20, pemakaian_bulan_lalu, pemakaian_saat_ini);
}

void niaga_sedang()
{
    const int BIAYA_METER_0_SAMPAI_10 = 10400;
    const int BIAYA_METER_11_SAMPAI_20 = 11050;
    const int BIAYA_METER_LEBIH_20 = 12150;
    int menu, pemakaian_bulan_lalu, pemakaian_saat_ini;
    system("cls");
    printf("==============================\n");
    printf("          NIAGA SEDANG        \n");
    printf("==============================\n");
    printf("Masukan pemakaian air bulan lalu : ");
    scanf("%d", &pemakaian_bulan_lalu);
    printf("Masukan pemakaian air saat ini   : ");
    scanf("%d", &pemakaian_saat_ini);
    
    while (pemakaian_bulan_lalu > pemakaian_saat_ini) //yang ini sudah validasi
    {
        system("cls");
        printf("MASUKAN BESAR PEMAKAIAN AIR DENGAN BENAR !\n\n");
        printf("==============================\n");
        printf("          NIAGA SEDANG        \n");
        printf("==============================\n");
        printf("Masukan pemakaian air bulan lalu : ");
        scanf("%d", &pemakaian_bulan_lalu);
        printf("Masukan pemakaian air saat ini   : ");
        scanf("%d", &pemakaian_saat_ini);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    hitung_usaha(BIAYA_METER_0_SAMPAI_10, BIAYA_METER_11_SAMPAI_20, BIAYA_METER_LEBIH_20, pemakaian_bulan_lalu, pemakaian_saat_ini);
}

void niaga_besar()
{
    const int BIAYA_METER_0_SAMPAI_10 = 11600;
    const int BIAYA_METER_11_SAMPAI_20 = 12250;
    const int BIAYA_METER_LEBIH_20 = 14750;
    int menu, pemakaian_bulan_lalu, pemakaian_saat_ini;
    system("cls");
    printf("==============================\n");
    printf("          NIAGA BESAR         \n");
    printf("==============================\n");
    printf("Masukan pemakaian air bulan lalu : ");
    scanf("%d", &pemakaian_bulan_lalu);
    printf("Masukan pemakaian air saat ini   : ");
    scanf("%d", &pemakaian_saat_ini);
    
    while (pemakaian_bulan_lalu > pemakaian_saat_ini) //yang ini sudah validasi
    {
        system("cls");
        printf("MASUKAN BESAR PEMAKAIAN AIR DENGAN BENAR !\n\n");
        printf("==============================\n");
        printf("          NIAGA BESAR         \n");
        printf("==============================\n");
        printf("Masukan pemakaian air bulan lalu : ");
        scanf("%d", &pemakaian_bulan_lalu);
        printf("Masukan pemakaian air saat ini   : ");
        scanf("%d", &pemakaian_saat_ini);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    hitung_usaha(BIAYA_METER_0_SAMPAI_10, BIAYA_METER_11_SAMPAI_20, BIAYA_METER_LEBIH_20, pemakaian_bulan_lalu, pemakaian_saat_ini);
}
