#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
int lexicographic_sort(const char* a, const char* b) {
return strcmp(a,b);
} 

int lexicographic_sort_reverse(const char* a, const char* b) {
return strcmp(b, a);
}
 
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
char UniqueNo[34];
int k=0;
int unique=0;
int t=0;
bool ound=false;
while(a[k]!='\0'){
    t=0;
    ound=false;
    while(t<unique){
        if(UniqueNo[t]==a[k]){
            ound=true;
            break;
            
        }
        
        t++;
    }
    if(ound==true){
        k++;
        continue;
    }
    else{
        UniqueNo[unique]=a[k];
        unique++;
        
    }
    k++;
    }
    char UniqueNoB[34];
int kB=0;
int uniqueB=0;
int tB=0;
bool foundB=false;

while(b[kB]!='\0'){
    tB=0;
    foundB=false;

    while(tB<uniqueB){
        if(UniqueNoB[tB]==b[kB]){
            foundB=true;
            break;
        }

        tB++;
    }

    if(foundB==true){
        kB++;
        continue;
    }
    else{
        UniqueNoB[uniqueB]=b[kB];
        uniqueB++;
    }

    kB++;
}
if(unique>uniqueB){
    return 1;
}
else if(unique<uniqueB){
    return -1;
    
}
else{
    return strcmp(a,b);
}
    
}

int sort_by_length(const char* a, const char* b) {
 if(strlen(a)>strlen(b)){
    return 1;
 }
 else if(strlen(a)<strlen(b)){
    return -1;
 }
 else{
    return strcmp(a,b);
 }
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
int j=0;
int i=0;
while(i<len){
    while(j<len-1){
        if(cmp_func(arr[j],arr[j+1])>0){
           char *temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp; 
        }
        
        j++;
    }
   i++;
   j=0; 
}
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}