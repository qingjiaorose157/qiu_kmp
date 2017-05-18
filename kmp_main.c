#include<stdio.h>  
#include<string.h>  
typedef struct seqstring{  
    char string[100];  
    int length;  
}seqstring;  
  
void getnext(seqstring p,int next[]){  
    int i,j;  
    next[0]=-1;
    i=0;
    j=-1;  
    while(i<p.length){
        if(j==-1||p.string[i]==p.string[j])   {   i++;j++;next[i]=j;  }   
        else  j=next[j];  
    }  
}   
  
int kmp(seqstring t,seqstring p,int next[]){  
    int i,j;  
    i=j=0;  
    while(i<t.length&&j<p.length){  
        if(j==-1||t.string[i]==p.string[j]){  i++;j++;  }  
        else  j=next[j];  
    }  
    if(j==p.length) return i-p.length;  
    else return -1;  
}   
int main(){  
    seqstring t,p;  
    int next[50];  
    printf("please input string t:");  
    scanf("%s",t.string);  
      
    t.length=strlen(t.string);  
    printf("please input string p:");  
    scanf("%s",p.string);  
    p.length=strlen(p.string);  
      
    getnext(p,next);  
    printf("\n%d\n",kmp(t,p,next));  
}  
