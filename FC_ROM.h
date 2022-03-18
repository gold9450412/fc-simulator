#include<stdint.h>
#include<stdio.h>

#pragma once

#define RPG_ROM_UNITS_16KB 1024 * 16
#define CHR_ROM_UNITS_8KB  1024 * 8

#define MAPPER_NUM_HIGH_BYTE_SHIFT 4
#define HIGH_BYTE_MASK 0xF0
#define LOW_BYTE_MASK 0x0F

typedef struct 
{
    uint32_t Identification_String;
    uint8_t PRG_ROM_Size; //unit 16KB
    uint8_t CHR_ROM_Size; //unit  8KB
    uint8_t Flag6;
    uint8_t Flag7;
    uint8_t Mapper_MSB_Submapper;
} ROM_Header;

typedef struct 
{
    uint8_t PRG_ROM_Size; //unit 16KB
    uint8_t CHR_ROM_Size; //unit  8KB
    uint8_t Mapper_Num; 
} ROM_Info;
