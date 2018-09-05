#include <stdio.h>
#include <string.h>
//숫자를 문자열로 받아서 자릿수 표현 
char a[10002];
char b[10002];
//결과 자리수 대로 숫자 배열에 저장 
int c[10010]; 

//문자열 포인터로 연산 피연산 숫자 지정 
char *ptr_num1;
char *ptr_num2;

int stop1=0,stop2=0;

int main(){
	
	int aPm=1,bPm=1; // a,b의 양수 음수 여부 저장 (0 음수 1 양수) 
	int aRealn=0, bRealn=0; //음수면 1로 부호를 뺀 본 숫자 길이 확인 
	
	scanf("%s" ,a);
	scanf("%s" ,b);
	
	
	if (a[0]=='-') {aPm=0; aRealn=1;} //- 부호 시에 aPm 음수, 시작지점 1번방  
	if (b[0]=='-') {bPm=0; bRealn=1;} //- 부호 시에 bPm 음수, 시작지점 1번방
	
	int i,j;
	int zeroCnt=0;
	int cnt=0;
	
	
	
	//printf("%s: %d %d %s : %d %d\n\n",a,aPm,aRealn,b,bPm,bRealn);
	
	//길이가 a 가 더 길면 a를 연산 숫자로 
	if (strlen(a)-aRealn > strlen(b)-bRealn){
		ptr_num1=a;
		ptr_num2=b;
		stop1=aRealn;
		stop2=bRealn;
		//printf("a win\n");
	}
	
	//길이가 b 가 더 길면 b를 연산 숫자로 
	else if (strlen(a)-aRealn < strlen(b)-bRealn){
		ptr_num1=b;
		ptr_num2=a;
		stop1=bRealn;
		stop2=aRealn;
		//printf("b win\n");
	}
	
	//길이가 같으면 숫자를 자리수 비교로 더 큰 숫자 지정 
	else{
		int i,j;
		int sameCnt=0;
		int sw=0;
		
		for (i=aRealn,j=bRealn; i<strlen(a),j<strlen(b); i++,j++){
	//		printf("%c %c\n",a[i],b[j]);
			if (a[i]>b[j]) { //a의 지정 자릿수가 크면 a를 연산 숫자로 
				ptr_num1=a;
				ptr_num2=b;
				stop1=aRealn;
				stop2=bRealn;
				sw=1;
				break;  
			}
			else if (a[i]<b[j]) { //b의 지정 자릿수가 크면 b를 연산 숫자로
				ptr_num1=b;
				ptr_num2=a;
				stop1=bRealn;
				stop2=aRealn;
				sw=1;
				break;
			}
			else sameCnt++;
						
		} 
		 
		if (sw==0 && sameCnt==strlen(a)-aRealn && sameCnt==strlen(b)-bRealn && aPm!=bPm){
			printf("0\n");
			return 0;
		}
		
		else if (sw==0 && aPm==bPm){
			ptr_num1=a;
			ptr_num2=b;
			stop1=aRealn;
			stop2=bRealn;
		}
	}
	
	
	
//	printf("!%s %d %s %d \n\n",ptr_num1,stop1,ptr_num2,stop2);
	
	
	int num1Int, num2Int;
	int im,nam=0;
	int p=0;

	
	j=strlen(ptr_num2)-1;
	for (i=strlen(ptr_num1)-1; i>=stop1; i--){
		num2Int=0;
		
		num1Int=(*(ptr_num1+i)-48);
		if (j>=stop2) num2Int=(*(ptr_num2+j)-48);
//		printf("%d %d -> ",i,j);
//		printf("%d %d : ",num1Int,num2Int);
		if (aPm!=bPm){
			if (num1Int<num2Int){
				int k;
				for (k=i-1; k>=stop1; k--){
					if (*(ptr_num1+k) == '0') *(ptr_num1+k) = '9';
					else { *(ptr_num1+k)-=1; break;}
				}
				num1Int+=10;
			}
			im=num1Int-num2Int;
//			printf("%d\n",im);
			c[p++]=im;
			
		}
		
		else{
			im=num1Int+num2Int+nam;
			nam=im/10;
			c[p++]=im%10;
			
//			printf("%d\n",im);
		}
		
		j--;
	}
	
	c[p++]=nam;
	
	int sw=1;
	if (*(ptr_num1)=='-' && *(ptr_num2)!='-' || (*(ptr_num1)=='-' && *(ptr_num2)=='-')) printf("-");
	for (i=p-1; i>=0; i--) {
		if (sw==1 && c[i]==0) continue;
		else {sw=0; printf("%d",c[i]);}	
		
	}
	
	return 0;
	
}

