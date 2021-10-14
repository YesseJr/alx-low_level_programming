/*
 * File: 100-get_endianness.c
 * Author: Waython Yesse
 * Year: 2021 October 14 (Nyerere Day!)
 */

#include "main.h"

/**
 * get_endianness - checks if multibyte data is stored as little or big endian
 * Return: first value stored, 0 if big endian, 1 if little
 */

int get_endianness(void)
{
	/* have a 4 byte int hold some hex number 0x00000001 */
	/* test if first byte stored is 00 or 01 */
	/* big endian would store 00, little would store 01 */

	int n = 0x00000001;
	char *c = (char *)&n;

	return (c[0]);
}
