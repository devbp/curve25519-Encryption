// curve25519.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <time.h>
#include <stdint.h>
#include<cstdlib>
#include<iostream>
typedef uint8_t u8;
#include "curve64.h"
//extern void curve25519_donna(u8 *output, const u8 *secret, const u8 *bp);


int main() {
	static const unsigned char basepoint[32] = { 9 };
	unsigned char mysecret[32], mypublic[32];
	unsigned i;
	uint64_t start, end;

	//memset(mysecret, 42, 32);
	//memset(mysecret, 30, 32);
	mysecret[0] &= 248;
	//mysecret[1] &= 240;
	mysecret[31] &= 127;
	mysecret[31] |= 64;

	// Load the caches
	//for (i = 0; i < 1000; ++i) 
	{
		curve25519_donna(mypublic, mysecret, basepoint);
	}

	for (int i = 0; i < 32; i++)
		std::cout <<std::hex<< (unsigned int)mysecret[i];

	std::cout << std::endl;
	for (int i = 0; i < 32; i++)
		std::cout <<std::hex<<(unsigned int) mypublic[i];
	
	//for (i = 0; i < 30000; ++i)
	{
		curve25519_donna(mypublic, mysecret, basepoint);
	}

	system("pause");

	return 0;
}