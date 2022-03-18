#include <stdio.h>
#include "FC_Init.h"
#include "FC_ROM.h"
#include <fstream>
#include<iostream>
using namespace std;
int main()
{
    ROM_Info NES_ROM_Info;
    int ret;
    ret = Read_ROM(&NES_ROM_Info);

    if(ret == OK)
    {
        printf("ROM: RPG-ROM: %d x 16KB , CHR-ROM: %d x 8KB , Mapper: %03d\n", 
        NES_ROM_Info.PRG_ROM_Size,
        NES_ROM_Info.CHR_ROM_Size,
        NES_ROM_Info.Mapper_Num
        );
    }

    return 0;
}