#include<stdio.h>
char board[3][3];
int X[]={0,0,0,0,1,1,1,2,2,2};
int Y[]={0,0,1,2,0,1,2,0,1,2};
int match[][3]={ {1,2,3} , {4,5,6}, {7,8,9} , {1,4,7}, {2,5,8}, {3,6,9}, {1,5,9}, {3,5,7}};
int numberOfMove=0;
void display(){
	for(int i=0; i<7; i++){
		if(i&1){
			printf("\t\t\t| %c  | %c  |  %c |\n",board[i/2][0],board[i/2][1],board[i/2][2]);
		}
		else{
			printf("\t\t\t|----|----|----|\n");
		}
	}
}
void userMove(){
	numberOfMove++;
	int val;
	printf("\n\tPlayer %c choice your box number which is not already fill up: ",(numberOfMove&1)?'X':'O');
	scanf("%d",&val);

	if('1'<=board[X[val]][Y[val]] && board[X[val]][Y[val]]<='9'){
		board[X[val]][Y[val]]=(numberOfMove&1)?'X':'O'; //for odd number move it is 'X' and even number move 'O'
	}
	else{
		printf("\tIt is already filled please try again and another one\n");
		numberOfMove--;
		userMove();
	}
}
char gameOver(){
	if(numberOfMove==9)
		return 'N';// N for none
	for(int i=0; i<8; i++){
		int Win=1;
		for(int j=0; j<3; j++){
			if(board[ X[ match[i][j] ] ] [ Y[match[i][j] ] ]!=board[ X[ match[i][0] ] ] [ Y[ match[i][0] ] ] ){
				Win=0;break;
			}

		}
		if(Win)return board[ X[ match[i][0] ] ] [ Y[ match[i][0] ] ];//who win
	}
	return 'C';//C for continue
}
int main(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			board[i][j] = (char)(i*3+j+1+'0');
		}
	}
	display();
	char ch='C';
	while(ch=='C'){
		userMove();
		display();
		ch = gameOver();
	}
	if(ch=='N')printf("\n\t\tGame is tie\n");
	else printf("\n\t\tWow! **%c** is win\n",ch);

}