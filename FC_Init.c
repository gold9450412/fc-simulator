#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"FC_Code.h"
#include"FC_ROM.h"

int
Read_ROM(ROM_Info* Info)
{
    FILE * file = fopen("nestest.nes","rb");
    if(!file) return FAILED_ROM_READ;
    ROM_Header NES_Header;
    if(fread(&NES_Header, sizeof(NES_Header), 1, file))
    {
        union  
        { 
        uint32_t Identification_String;
        uint8_t Set_Identification_String[4];
        } Identification_String_Union;
        Identification_String_Union.Set_Identification_String[0] = 'N';
        Identification_String_Union.Set_Identification_String[1] = 'E';
        Identification_String_Union.Set_Identification_String[2] = 'S';
        Identification_String_Union.Set_Identification_String[3] = '\x1A';
        if(Identification_String_Union.Identification_String == NES_Header.Identification_String)
        {
            int NES_PRG_ROM_Size = NES_Header.PRG_ROM_Size * RPG_ROM_UNITS_16KB;
            int NES_CHR_ROM_Size = NES_Header.PRG_ROM_Size * CHR_ROM_UNITS_8KB;
            int NES_Mapper_Number;
            NES_Mapper_Number = (NES_Header.Flag6 >> MAPPER_NUM_HIGH_BYTE_SHIFT) | (NES_Header.Flag7 & HIGH_BYTE_MASK);
            Info->PRG_ROM_Size = NES_Header.PRG_ROM_Size;
            Info->CHR_ROM_Size = NES_Header.PRG_ROM_Size;
            Info->Mapper_Num = NES_Mapper_Number;
        }
        else
        {
            return FAILED_ID_READ;
        }

    }
    return OK;
}