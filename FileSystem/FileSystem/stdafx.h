// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
int getOperation(char *token);
int checkTxt(char *ch);
int checkComparison(char *ch, char *fileName);
void list(FILE *fp);
void decodeInput(FILE *fp, char *cmd);
int getSeek(FILE *fp, int seek, char *fileName);
void copyFrom(FILE *fp, int iter, char *cmd);
int findText(FILE *fp, char *fileName);
void copyTo(FILE *fp, int iter, char *cmd);


// TODO: reference additional headers your program requires here
