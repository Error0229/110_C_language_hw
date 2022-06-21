 #include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reverse(char* s,int size){
	char temp[200];
	memset(temp,0,sizeof(temp));
	for(int i=0;i<size;i++){
		temp[i]=s[size-i-1];
	}
	for(int i=0;i<size;i++){
		s[i]=temp[i];
	}
	return;
}
int judge_less(char *a, char *b){
	if (~strlen(a)&strlen(b))return strlen(a)<strlen(b);
	for(int i = strlen(a)-1; i>=0;i--){
		if (~a[i]&b[i])return a[i] < b[i];
	}
	return 0;
}
int main(){
    char num_a[200],num_b[200],ans[200];
    memset(ans,0,sizeof(ans));
    memset(num_a,0,sizeof(num_a));
    memset(num_b,0,sizeof(num_b));
    int k,max_len,digit_a,digit_b,len_a,len_b;
    scanf("%d",&k);
    scanf("%s%s",num_a,num_b);
    len_a = strlen(num_a);
    len_b = strlen(num_b);
    reverse(num_a,len_a);
    reverse(num_b,len_b);
    max_len = len_a > len_b? len_a : len_b; 
    if(k == 1){
    	for (int i = 0; i < max_len; i++){
    		digit_a = i < len_a ? num_a[i] : '0';
    		digit_b = i < len_b ? num_b[i] : '0';
    		ans[i] += digit_a + digit_b -'0';
    		if (ans[i] > '9'){
    			ans[i+1]+=1;
    			ans[i]-=10;
			}
		}
		if (ans[max_len]){
			ans[max_len++]='1';
		}
		reverse(ans,max_len);
		puts(strlen(ans) ? ans : "0");	
	}
	else if (k == 2){
		int flag=0;
		if (judge_less(num_a,num_b)){
			char *str_t = (char *)malloc((strlen(num_a) + 1) * sizeof(char));
  			strcpy(str_t, num_a);
			strcpy(num_a, num_b);
			strcpy(num_b, str_t);
  			free(str_t);
			len_a = strlen(num_a);
			len_b = strlen(num_b);
			flag = 1;
		}

    	for (int i = 0; i < max_len; i++){
    		digit_a = i < len_a ? num_a[i] : '0';
    		digit_b = i < len_b ? num_b[i] : '0';
    		ans[i] += (digit_a - digit_b)+'0';	
			if (ans[i] < '0'){
    			ans[i+1]-=1;
    			ans[i]+=10;
			}   
		}
		for(int i = max_len-1;i>=0;i--){
			if (ans[i]=='0'){
				ans[i]=0;
				max_len--;
			}
			else break;
		}
		if (flag){
			ans[max_len++]='-';
		}
		reverse(ans,max_len);
		puts(strlen(ans) ? ans : "0");	
	}
	else{
		for(int i=0;i<199;i++)ans[i]='0';
//		puts(ans);
		for(int i = 0; i < len_a; i++){
			for(int j = 0; j <len_b; j++){
				int tp=(num_a[i]-'0')*(num_b[j]-'0');
				ans[i+j]+=tp%10;
				ans[i+j+1]+=tp/10;
				
				while(ans[i+j] > '9'){
					ans[i+j+1]+=1;
					ans[i+j]-=10;
				}
			}
		}
		int id=0;
		while(id < 199){
			while(ans[id]>'9'){
				ans[id+1]+=1;
				ans[id]-=10;
			}
			id++;
		}
		for(int i = strlen(ans)-1;i>=0;i--){
			if (ans[i]=='0'){
				ans[i]=0;
				max_len--;
			}
			else break;
		}
		reverse(ans,strlen(ans));
		puts(strlen(ans) ? ans : "0");	
	}
    
}
