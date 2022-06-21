#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#define bigint_len 1000
typedef struct bigint bigint;

struct bigint{
	int seq[bigint_len+5];
};
bigint bigint_new(char* str){
	int dtc=0,negc=0,alc=0;
	for(int i=0;i<strlen(str);i++){
		if(str[i]=='.')dtc++;
		else if(str[i]=='-')negc++;
		else if(isdigit(str[i]))alc++;
	}
	if(dtc>1 || negc >1 || (negc && str[0]!='-') || (negc+dtc+alc != strlen(str))){
		puts("Error input mf");
		exit(0);
	}
	bigint k;
	memset(k.seq,0,sizeof(k.seq));
	k.seq[0] = (str[0] == '-') ? 0 : 1; // 0 is neg
	int __intlen = 0, offset=0, slen = strlen(str);	
	for(int i = 0;i < slen;i++){
		if (str[i]=='-') continue;
		if (isdigit(str[i]))__intlen++;
		else{
			break;
		}
	}
	int id = bigint_len/2-__intlen;
	for(int i = 0; i < slen;i++){
		if (str[i]=='-'){
			continue;
		} 
		if (str[i] == '.')offset++,slen--;
		k.seq[id++] = str[offset+i]-'0';
	}
	return k;
}
bigint bigintf(int a) { //no float ==
	char st[bigint_len+5];
	memset(st,0,sizeof(st));
	int i=0;
	if(a<0)i+=1,st[0]='-',a*=-1;
	if (a==0) st[0]='0';
	for(;a>0;i++){
		st[i] = a%10+'0';
		a/=10;
	}
	puts(st);
	return bigint_new(st);
}
bigint bigint_input(){
	bigint k;
	char st[bigint_len+5];
	memset(st,0,sizeof(st));
	scanf("%s",st);
	k = bigint_new(st);
	return k;
}
void bigint_print (bigint k){
	int __front=bigint_len/2-1,__end=bigint_len/2-1;
	for(int i=1;i < bigint_len/2;i++){
		if(k.seq[i]!=0){
			__front = i;
			break;
		}
	}
	for(int i=bigint_len-1;i >= bigint_len/2;i--){
		if(k.seq[i]!=0){
			__end = i;
			break;
		}
	}
	if(!k.seq[0])printf("-");
	for(int i = __front; i <= __end;i++){
		if(i == bigint_len/2){
			printf(".");
		}
		printf("%d",k.seq[i]);
	}
	puts("");
}
bigint bigint_abs(bigint a){
	a.seq[0]=0;
	return a;
}
int compare (bigint a,bigint b){  // (abs) if a less than b return true
	for(int i = 1; i < bigint_len; i++){
		if (a.seq[i] != b.seq[i]){
			if(a.seq[i]<b.seq[i]) return 1; //less
			else return 0; //greater
		}
	}
	return -1; // equal
}
bigint bigint_plus(bigint a,bigint b){
	if ((a.seq[0] == 0) ^ (b.seq[0] == 0)){ //actually subtract
		if (compare(a,b)==1){//swap
			bigint k;
			k = b;
			b = a;
			a = k;
		}
		for(int i = bigint_len-1 ; i>=1; i--){
			a.seq[i]-=b.seq[i];
			if(a.seq[i]<0){
				a.seq[i-1]--;
				a.seq[i]+=10;
			}
		}
		return a;
	}
	for (int i = bigint_len-1; i>=1;i--){
		a.seq[i] += b.seq[i];
		if (a.seq[i]>9){
			a.seq[i-1]++;
			a.seq[i]-=10;
		}
	}
	return a;
}
bigint bigint_sub(bigint a, bigint b){
	b.seq[0]=(!b.seq[0]);
	return bigint_plus(a,b);
}
bigint bigint_mul (bigint a,bigint b){
	bigint sum = bigintf(0);
	int fla=0,flb=0,la=bigint_len/2-1,lb=bigint_len/2-1;
	for(int i=bigint_len-1;i >= bigint_len/2;i--){// find last digit of float point
		if(a.seq[i]!=0 && !fla){
			la = i;
			fla = 1;
		}
		if(b.seq[i]!=0 && !flb){
			lb = i;
			flb = 1;
		}
		if (fla && flb)break;
	}
	
	int offset = lb-bigint_len/2+1;
	for(int i=la;i >= 10;i--){
		for(int j = lb,id = i+offset; j>=10 && id>=1;j--,id--){
			int tmp = a.seq[i]*b.seq[j];
			sum.seq[id] += tmp;
			sum.seq[id-1] += sum.seq[id]/10;
			sum.seq[id] %=10;
		}
	}
	return sum;
}
void bigint_shiftleft_dec(bigint* a,int k){
	for(int i=k;i<bigint_len;i++){
		a->seq[i-k] = a->seq[i]; 
	}
}
bigint bigint_div(bigint a,bigint b){
	bigint quot = bigintf(0), k = bigintf(0), bk = bigintf(0);
	if(compare(b,k)){
		puts("can not divide zero");
		exit(0);
	}
	int judge=0,offset=0,neg=0;
	int fla=0,flb=0,la=bigint_len/2-1,lb=bigint_len/2-1;
	neg =(a.seq[0] == 0) ^ (b.seq[0] == 0)
	for(int i=bigint_len-1;i >= 1;i--){// find last digit of float point
		if(b.seq[i]!=0){
			lb = i;
			break;
		}
	}
	bigint_shiftleft_dec(&a ,lb-bigint_len/2+1);
	judge=compare(a,k);
	while(judge !=-1){
		bigint dying = bigintf(0);
		while(compare(a,b)==1){ //after this a>=b
			bigint_shiftleft_dec(&a ,1);
			offset++; 	
		}
		int fr = 0;
		for(int i=1;i<bigint_len;i++){ //find first digit of a
			if (a.seq[i]!=0){
				fr=i;
				break;
			}
		}
		dying.seq[bigint_len/2-1] = a.seq[fr]; 
		while(compare(dying,b)==1){
			bigint_shiftleft_dec(&b,1);
			dying[bigint_len/2-1] = a.seq[--fr];
		}
		for(int i=9;i>=1;i--){
			bigint well = bigint_mul(b,bigint(i));
			bigint_shiftleft_dec(well,fr-bigint_len/2-1);
			if(compare(a,b)<1){
				bigint_shiftleft_dec(quot,1);
				quot.seq[bigint_len/2-1] = i; 
				
			}
		}
	}
}
bigint mod (bigint a,bigint b);
int main(){
	bigint kt,stfu;
	kt = bigint_input();
	stfu = bigint_input();
	bigint_print(bigint_mul(kt,stfu));
}
