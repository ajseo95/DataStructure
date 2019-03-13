#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <string.h>

#define ERROR_PROB 0.01

typedef struct _Bit{
	unsigned int bit : 1;
}Bit;

typedef unsigned int(*hashfunc_t)(const char*);

typedef struct _BloomFilters{
	int FILTER_SIZE;
	int NUM_HASHFUNC;
	Bit *FilterArray;
	hashfunc_t *fucs;
}BloomFilters;


void insert(BloomFilters* B, char *Key);
int lookup(BloomFilters* B, char *Key);
int Hash(BloomFilters* B, unsigned int Key);
BloomFilters* CreateBloomFilter(int s, int b, int k);
void removeWhiteSpace(char *str);


unsigned int Hash1(const char *Key){
	int HashVal = 0;
	for (; *Key != '\0'; Key++)
		HashVal += *Key + 31;
	return HashVal;
}
unsigned int Hash2(const char *Key){
	int HashVal = 0;
	for (; *Key != '\0'; Key++)
		HashVal += *Key * 31;
	return HashVal;
}
unsigned int Hash3(const char *Key){
	int HashVal = 0;
	for (; *Key != '\0'; Key++)
		HashVal += (*Key + 31) * 11;
	return HashVal;
}
unsigned int Hash4(const char *Key){
	int HashVal = 0;
	for (; *Key != '\0'; Key++)
		HashVal = (HashVal >> 5) + *Key++;
	return HashVal;
}
unsigned int Hash5(const char *Key){
	int HashVal = 0;
	for (; *Key != '\0'; Key++)
		HashVal = (HashVal << 5) + *Key++;
	return HashVal;
}
unsigned int Hash6(const char *Key){
	int HashVal = 0;
	for (; *Key != '\0'; Key++)
		HashVal = (HashVal << 5) + (HashVal >> 5) + *Key++;
	return HashVal;
}
unsigned int Hash7(const char *Key){
	int HashVal = 0;
	for (; *Key != '\0'; Key++)
		HashVal += (*Key * 11) + 31;
	return HashVal;
}
unsigned int Hash8(const char *Key){
	int HashVal = 0;
	for (; *Key != '\0'; Key++)
		HashVal = ((HashVal << 5) + (HashVal >> 5)) * 11 + *Key++;
	return HashVal;
}
unsigned int Hash9(const char *Key){
	int HashVal = 0;
	for (; *Key != '\0'; Key++)
		HashVal = (HashVal >> 5) * 11 + *Key++;
	return HashVal;
}
unsigned int Hash10(const char *Key){
	int HashVal = 0;
	for (; *Key != '\0'; Key++)
		HashVal = (HashVal << 5) * 11 + *Key++;
	return HashVal;
}


int main(int argc, char* argv[]){

	FILE* txt;
	BloomFilters *B;
	int b, k, S, i;
	char buf[BUFSIZ + 1];

	txt = fopen(argv[1], "r");

	// Error probability : 1%
	b = 1.44 * log10(1 / ERROR_PROB) / log10(2.0);
	k = 0.693 * b;
	// Read counter S
	fgets(buf, 255, txt);
	S = atoi(buf);

	B = CreateBloomFilter(S, b, k);

	printf("b = %d \t k = %d\n", b, k);

	for (i = 0; i < S; i++) {
		fgets(buf, BUFSIZ, txt);
		removeWhiteSpace(buf);
		insert(B, buf);
	}
	while (true) {
		fgets(buf, BUFSIZ, txt);
		removeWhiteSpace(buf);
		printf("%s = %s\n", buf, (lookup(B, buf)) ? "true" : "false");
		if (feof(txt)) break;
	}
	for (i = 0; i < B->FILTER_SIZE; i++) {
		printf("%u", B->FilterArray[i].bit);
	}

}

void insert(BloomFilters* B, char *Key){
	for (int i = 0; i < B->NUM_HASHFUNC; i++){
		int hashVal = Hash(B, B->fucs[i](Key));
		B->FilterArray[hashVal].bit = 1;
	}
}
int lookup(BloomFilters* B, char *Key){
	for (int i = 0; i < B->NUM_HASHFUNC; i++){
		int hashVal = Hash(B, B->fucs[i](Key));
		if (B->FilterArray[hashVal].bit != 1){
			return 0;
		}
	}

	return 1;
}
int Hash(BloomFilters* B, unsigned int Key){
	return Key % B->FILTER_SIZE;
}
BloomFilters* CreateBloomFilter(int s, int b, int k){
	BloomFilters* B;
	int i;

	B = (BloomFilters*)malloc(sizeof(BloomFilters));

	B->FILTER_SIZE = b*s;
	B->NUM_HASHFUNC = k;
	B->FilterArray = (Bit*)malloc(sizeof(unsigned int)*b*s);
	for (i = 0; i < B->FILTER_SIZE; i++)
		B->FilterArray[i].bit = 0;
	B->fucs = (hashfunc_t*)malloc(sizeof(hashfunc_t) * 10);
	B->fucs[0] = Hash1;
	B->fucs[1] = Hash2;
	B->fucs[2] = Hash3;
	B->fucs[3] = Hash4;
	B->fucs[4] = Hash5;
	B->fucs[5] = Hash6;
	B->fucs[6] = Hash7;
	B->fucs[7] = Hash8;
	B->fucs[8] = Hash9;
	B->fucs[9] = Hash10;

	return B;
}
void removeWhiteSpace(char *str) {
	int i;
	for (i = 0; i < BUFSIZ; i++, str++) {
		if (*str == '\0') return;
		if (*str == '\n') *str = '\0';
	}
}
