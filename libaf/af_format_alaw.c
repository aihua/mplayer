/*=============================================================================
//	
//  This software has been released under the terms of the GNU Public
//  license. See http://www.gnu.org/copyleft/gpl.html for details.
//
//  Copyright 2002 Anders Johansson ajh@watri.uwa.edu.au
//
//  This file is based on a part of libsndfile, the work of 
//    Erik de Castro Lopo <erikd@zip.com.au> 
//
//=============================================================================
*/

#ifndef __af_format_alaw_c
#define __af_format_alaw_c

#include <unistd.h>
#include <inttypes.h>

#include "af.h"

// Conversion tables (the function are below)
static short alaw_decode [128] =
{	 -5504,  -5248,  -6016,  -5760,  -4480,  -4224,  -4992,  -4736, 
	 -7552,  -7296,  -8064,  -7808,  -6528,  -6272,  -7040,  -6784, 
	 -2752,  -2624,  -3008,  -2880,  -2240,  -2112,  -2496,  -2368, 
	 -3776,  -3648,  -4032,  -3904,  -3264,  -3136,  -3520,  -3392, 
	-22016, -20992, -24064, -23040, -17920, -16896, -19968, -18944, 
	-30208, -29184, -32256, -31232, -26112, -25088, -28160, -27136, 
	-11008, -10496, -12032, -11520,  -8960,  -8448,  -9984,  -9472, 
	-15104, -14592, -16128, -15616, -13056, -12544, -14080, -13568, 
	  -344,   -328,   -376,   -360,   -280,   -264,   -312,   -296, 
	  -472,   -456,   -504,   -488,   -408,   -392,   -440,   -424, 
	   -88,    -72,   -120,   -104,    -24,     -8,    -56,    -40, 
	  -216,   -200,   -248,   -232,   -152,   -136,   -184,   -168, 
	 -1376,  -1312,  -1504,  -1440,  -1120,  -1056,  -1248,  -1184, 
	 -1888,  -1824,  -2016,  -1952,  -1632,  -1568,  -1760,  -1696, 
	  -688,   -656,   -752,   -720,   -560,   -528,   -624,   -592, 
	  -944,   -912,  -1008,   -976,   -816,   -784,   -880,   -848
} ; /* alaw_decode */

static unsigned char alaw_encode [2049] =
{	0xD5, 0xD4, 0xD7, 0xD6, 0xD1, 0xD0, 0xD3, 0xD2, 0xDD, 0xDC, 0xDF, 0xDE, 
	0xD9, 0xD8, 0xDB, 0xDA, 0xC5, 0xC4, 0xC7, 0xC6, 0xC1, 0xC0, 0xC3, 0xC2, 
	0xCD, 0xCC, 0xCF, 0xCE, 0xC9, 0xC8, 0xCB, 0xCA, 0xF5, 0xF5, 0xF4, 0xF4, 
	0xF7, 0xF7, 0xF6, 0xF6, 0xF1, 0xF1, 0xF0, 0xF0, 0xF3, 0xF3, 0xF2, 0xF2, 
	0xFD, 0xFD, 0xFC, 0xFC, 0xFF, 0xFF, 0xFE, 0xFE, 0xF9, 0xF9, 0xF8, 0xF8, 
	0xFB, 0xFB, 0xFA, 0xFA, 0xE5, 0xE5, 0xE5, 0xE5, 0xE4, 0xE4, 0xE4, 0xE4, 
	0xE7, 0xE7, 0xE7, 0xE7, 0xE6, 0xE6, 0xE6, 0xE6, 0xE1, 0xE1, 0xE1, 0xE1, 
	0xE0, 0xE0, 0xE0, 0xE0, 0xE3, 0xE3, 0xE3, 0xE3, 0xE2, 0xE2, 0xE2, 0xE2, 
	0xED, 0xED, 0xED, 0xED, 0xEC, 0xEC, 0xEC, 0xEC, 0xEF, 0xEF, 0xEF, 0xEF, 
	0xEE, 0xEE, 0xEE, 0xEE, 0xE9, 0xE9, 0xE9, 0xE9, 0xE8, 0xE8, 0xE8, 0xE8, 
	0xEB, 0xEB, 0xEB, 0xEB, 0xEA, 0xEA, 0xEA, 0xEA, 0x95, 0x95, 0x95, 0x95, 
	0x95, 0x95, 0x95, 0x95, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 
	0x97, 0x97, 0x97, 0x97, 0x97, 0x97, 0x97, 0x97, 0x96, 0x96, 0x96, 0x96, 
	0x96, 0x96, 0x96, 0x96, 0x91, 0x91, 0x91, 0x91, 0x91, 0x91, 0x91, 0x91, 
	0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x93, 0x93, 0x93, 0x93, 
	0x93, 0x93, 0x93, 0x93, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 
	0x9D, 0x9D, 0x9D, 0x9D, 0x9D, 0x9D, 0x9D, 0x9D, 0x9C, 0x9C, 0x9C, 0x9C, 
	0x9C, 0x9C, 0x9C, 0x9C, 0x9F, 0x9F, 0x9F, 0x9F, 0x9F, 0x9F, 0x9F, 0x9F, 
	0x9E, 0x9E, 0x9E, 0x9E, 0x9E, 0x9E, 0x9E, 0x9E, 0x99, 0x99, 0x99, 0x99, 
	0x99, 0x99, 0x99, 0x99, 0x98, 0x98, 0x98, 0x98, 0x98, 0x98, 0x98, 0x98, 
	0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9A, 0x9A, 0x9A, 0x9A, 
	0x9A, 0x9A, 0x9A, 0x9A, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 
	0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x84, 0x84, 0x84, 0x84, 
	0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 
	0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 
	0x87, 0x87, 0x87, 0x87, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 
	0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x81, 0x81, 0x81, 0x81, 
	0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 
	0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x82, 0x82, 0x82, 0x82, 
	0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 
	0x8D, 0x8D, 0x8D, 0x8D, 0x8D, 0x8D, 0x8D, 0x8D, 0x8D, 0x8D, 0x8D, 0x8D, 
	0x8D, 0x8D, 0x8D, 0x8D, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 
	0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8F, 0x8F, 0x8F, 0x8F, 
	0x8F, 0x8F, 0x8F, 0x8F, 0x8F, 0x8F, 0x8F, 0x8F, 0x8F, 0x8F, 0x8F, 0x8F, 
	0x8E, 0x8E, 0x8E, 0x8E, 0x8E, 0x8E, 0x8E, 0x8E, 0x8E, 0x8E, 0x8E, 0x8E, 
	0x8E, 0x8E, 0x8E, 0x8E, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 
	0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x88, 0x88, 0x88, 0x88, 
	0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
	0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 
	0x8B, 0x8B, 0x8B, 0x8B, 0x8A, 0x8A, 0x8A, 0x8A, 0x8A, 0x8A, 0x8A, 0x8A, 
	0x8A, 0x8A, 0x8A, 0x8A, 0x8A, 0x8A, 0x8A, 0x8A, 0xB5, 0xB5, 0xB5, 0xB5, 
	0xB5, 0xB5, 0xB5, 0xB5, 0xB5, 0xB5, 0xB5, 0xB5, 0xB5, 0xB5, 0xB5, 0xB5, 
	0xB5, 0xB5, 0xB5, 0xB5, 0xB5, 0xB5, 0xB5, 0xB5, 0xB5, 0xB5, 0xB5, 0xB5, 
	0xB5, 0xB5, 0xB5, 0xB5, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 
	0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 
	0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 
	0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 
	0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 
	0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB6, 0xB6, 0xB6, 0xB6, 
	0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 
	0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 
	0xB6, 0xB6, 0xB6, 0xB6, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 
	0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 
	0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 0xB1, 
	0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 
	0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 
	0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB3, 0xB3, 0xB3, 0xB3, 
	0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 
	0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 
	0xB3, 0xB3, 0xB3, 0xB3, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 
	0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 
	0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 0xB2, 
	0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 
	0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 
	0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBC, 0xBC, 0xBC, 0xBC, 
	0xBC, 0xBC, 0xBC, 0xBC, 0xBC, 0xBC, 0xBC, 0xBC, 0xBC, 0xBC, 0xBC, 0xBC, 
	0xBC, 0xBC, 0xBC, 0xBC, 0xBC, 0xBC, 0xBC, 0xBC, 0xBC, 0xBC, 0xBC, 0xBC, 
	0xBC, 0xBC, 0xBC, 0xBC, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 
	0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 
	0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 
	0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 
	0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 
	0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE, 0xB9, 0xB9, 0xB9, 0xB9, 
	0xB9, 0xB9, 0xB9, 0xB9, 0xB9, 0xB9, 0xB9, 0xB9, 0xB9, 0xB9, 0xB9, 0xB9, 
	0xB9, 0xB9, 0xB9, 0xB9, 0xB9, 0xB9, 0xB9, 0xB9, 0xB9, 0xB9, 0xB9, 0xB9, 
	0xB9, 0xB9, 0xB9, 0xB9, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 
	0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 
	0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 
	0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 
	0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 
	0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBA, 0xBA, 0xBA, 0xBA, 
	0xBA, 0xBA, 0xBA, 0xBA, 0xBA, 0xBA, 0xBA, 0xBA, 0xBA, 0xBA, 0xBA, 0xBA, 
	0xBA, 0xBA, 0xBA, 0xBA, 0xBA, 0xBA, 0xBA, 0xBA, 0xBA, 0xBA, 0xBA, 0xBA, 
	0xBA, 0xBA, 0xBA, 0xBA, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 
	0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 
	0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 
	0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 
	0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 
	0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA4, 0xA4, 0xA4, 0xA4, 
	0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 
	0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 
	0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 
	0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 
	0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 
	0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 
	0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 
	0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 
	0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 
	0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7, 
	0xA7, 0xA7, 0xA7, 0xA7, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 
	0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 
	0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 
	0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 
	0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 
	0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA1, 0xA1, 0xA1, 0xA1, 
	0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 
	0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 
	0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 
	0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 
	0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 
	0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 
	0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 
	0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 
	0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 
	0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 
	0xA0, 0xA0, 0xA0, 0xA0, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 
	0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 
	0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 
	0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 
	0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 
	0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA2, 0xA2, 0xA2, 0xA2, 
	0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 
	0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 
	0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 
	0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 
	0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 
	0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 
	0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 
	0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 
	0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 
	0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 0xAD, 
	0xAD, 0xAD, 0xAD, 0xAD, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 
	0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 
	0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 
	0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 
	0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 
	0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAC, 0xAF, 0xAF, 0xAF, 0xAF, 
	0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 
	0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 
	0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 
	0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 
	0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 
	0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 
	0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 
	0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 
	0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 
	0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 
	0xAE, 0xAE, 0xAE, 0xAE, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 
	0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 
	0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 
	0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 
	0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 
	0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA8, 0xA8, 0xA8, 0xA8, 
	0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 
	0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 
	0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 
	0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 
	0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 
	0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 
	0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 
	0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 
	0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 
	0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 
	0xAB, 0xAB, 0xAB, 0xAB, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
	0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
	0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
	0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
	0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
	0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x2A
} ; /* alaw_encode */

/* Convert from alaw to signd int8 to signed int32 or float */
static int from_alaw(void* in, void* out, int len, int bps, int format)
{
  register int i;
  // Make sure the input parametrs are OK
  if(format & (AF_FORMAT_SPECIAL_MASK | AF_FORMAT_US))
      return AF_ERROR;
    
  // Convert to int or to float
  if((format & AF_FORMAT_POINT_MASK) == AF_FORMAT_I){
    switch(bps){
    case(1): 
      for(i=0;i<len;i++){
	if(((int8_t*)in)[i] & 0x80)
	  ((int8_t*)out)[i] = (-1 * alaw_decode[(((int8_t*)in)[i]) & 0x7F]) >> 8;
	else
	  ((int8_t*)out)[i] = (alaw_decode[(((int8_t*)in)[i]) & 0x7F]) >> 8;
      } 
      break;
    case(2):
      for(i=0;i<len;i++){
	if(((int8_t*)in)[i] & 0x80)
	  ((int16_t*)out)[i] = -1 * alaw_decode[(((int8_t*)in)[i]) & 0x7F];
	else
	  ((int16_t*)out)[i] = alaw_decode[(((int8_t*)in)[i]) & 0x7F];
      } 
      break;
    case(4):
      for(i=0;i<len;i++){
	if(((int8_t*)in)[i] & 0x80)
	  ((int32_t*)out)[i] = (-1 * alaw_decode[(((int8_t*)in)[i]) & 0x7F]) << 16;
	else
	  ((int32_t*)out)[i] = (alaw_decode[(((int8_t*)in)[i]) & 0x7F]) << 16;
      } 
      break;
    default:
      return AF_ERROR;
    }
  }
  else{
    for(i=0;i<len;i++){
      if(((int8_t*)in)[i] & 0x80)
	((float*)out)[i] = -1.0/32768.0 * (float)alaw_decode[(((int8_t*)in)[i]) & 0x7F];
      else
	((float*)out)[i] = +1.0/32768.0 * (float)alaw_decode[(((int8_t*)in)[i]) & 0x7F];
    }
  }
  return AF_OK;
}

/* Convert from singed int8 to singned int32 or float to alaw */
static int to_alaw(void* in, void* out, int len, int bps, int format)
{
  register int i;
  // Make sure the input parametrs are OK
  if(format & (AF_FORMAT_SPECIAL_MASK | AF_FORMAT_US))
      return AF_ERROR;
    
  // Convert from int or to float
  if((format & AF_FORMAT_POINT_MASK) == AF_FORMAT_I){
    switch(bps){
    case(1): 
      for(i=0;i<len;i++){
	if(((int8_t*)in)[i] >= 0)
	  ((int8_t*)out)[i] = alaw_encode[((int8_t*)in)[i] << 4];
	else
	  ((int8_t*)out)[i] = 0x7F & alaw_encode[-((int8_t*)in)[i] << 4];
      }
      break;
    case(2): 
      for(i=0;i<len;i++){
	if(((int16_t*)in)[i] >= 0)
	  ((int8_t*)out)[i] = alaw_encode[((int16_t*)in)[i] / 16];
	else
	  ((int8_t*)out)[i] = 0x7F & alaw_encode[((int16_t*)in)[i] / -16];
      }
      break;
    case(4): 
      for(i=0;i<len;i++){
	if(((int32_t*)in)[i] >= 0)
	  ((int8_t*)out)[i] = alaw_encode[((int32_t*)in)[i] >> (16 + 4)];
	else
	  ((int8_t*)out)[i] = 0x7F & alaw_encode[-((int32_t*)in)[i] >> (16 + 4)];
      }
      break;
    default:
      return AF_ERROR;
    }
  }
  else{
    for(i=0;i<len;i++){
      if(((float*)in)[i] >= 0)
	((int8_t*)out)[i] = alaw_encode[(int)(32767.0/16.0 * ((float*)in)[i])];
      else
	((int8_t*)out)[i] = 0x7F & alaw_encode[(int)(-32767.0/16.0 * ((float*)in)[i])];
    }
  }
  return AF_OK;
}
#endif /* __af_format_alaw_c */
