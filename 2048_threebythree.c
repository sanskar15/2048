#include <stdio.h>
#include <stdlib.h>

int a[3][3];								// this array is used to keep previous state of the grid
int arr[3][3] = {							//3*3 array
					{0,0,0},			
					{0,0,0},
					{0,0,0}
					};




int random(void){						// this function generate 90% times 2 and 10% times 4
	
	int i = rand()%3;
	int	j = rand()%3;
	float r = rand()%11;
	while(arr[i][j]!=0){
		i = rand()%3;
		j = rand()%3;
		}
	if(arr[i][j]==0){
			if(r<9){
				arr[i][j]=2;
			}else{
				arr[i][j]=4;
			}
			
	}
}


int validMove(){								// This function checks if the move is valid or not
	int i,j;									// i.e. It checks if there has been any changes in grid after a
  	int x = 0;									// move hase been done.												  	
	for(i =0;i<3;i++){
		for( j =0;j<3;j++){
			if(arr[i][j]!=a[i][j]){
				x =1;	
			}
		}
}
return x;
}

int move(int input){				//This function executes the move 
	
	int i,j,a;
	int merge[3] = {0,0,0};             // This array stops this condition--> 2 2 4 -->0 0 8
	if(input==2){							//Down move
	  for(a=0;a<2;a++){
		for( i =2;i>0;i--){
			for( j = 0;j<3;j++){
				if(arr[i][j]==0){
					arr[i][j]=arr[i-1][j];
					arr[i-1][j]=0;
				}
				if(arr[i][j]==arr[i-1][j]&&merge[j]==0){
					arr[i][j] = 2*arr[i-1][j];
					arr[i-1][j]=0;
					merge[j] = 1;
				}
	
			}
		}
	}
		
		if(validMove()==1){
			random();
		}
	}
	
	if(input==6){											//Right move
	 for(a=0;a<2;a++){
		for( j =2;j>0;j--){
			for(i = 0;i<3;i++){
				if(arr[i][j]==0){
					arr[i][j]=arr[i][j-1];
					arr[i][j-1]=0;
				}
				if(arr[i][j]==arr[i][j-1]&&merge[i]==0){
					arr[i][j] = 2*arr[i][j-1];
					arr[i][j-1]=0;
					merge[i]=1;
				
				}
			}
		}
	}
		if(validMove()==1){
			random();
		}
		
	}
	
	if(input==8){										//Up move
	 for(a=0;a<2;a++){	
		for( j =0;j<3;j++){
			for(i = 0;i<2;i++){
				if(arr[i][j]==0){
					arr[i][j]=arr[i+1][j];
					arr[i+1][j]=0;
				}
				if(arr[i+1][j]==arr[i][j]&&merge[j]==0){
					arr[i][j]=2*arr[i+1][j];
					arr[i+1][j]=0;
					merge[j] = 1;
				}
			}
		
		}
	
	}
		
	if(validMove()==1){
			random();
		}
	}
	
	if(input==4){											// Left Move
	for(a=0;a<2;a++){	
		for( i =0;i<3;i++){
			for( j = 0;j<2;j++){
				if(arr[i][j]==0){
					arr[i][j]=arr[i][j+1];
					arr[i][j+1]=0;
				}
				if(arr[i][j]==arr[i][j+1]&&merge[i]==0){
					arr[i][j] = 2*arr[i][j+1];
					arr[i][j+1]=0;
					merge[i] = 1;
				}
			}
		}
		
	}
	if(validMove()==1){
			random();
		}
	}
	
}


int gameOver(){						// This function compares each element with its adjacent elements and 
	int i,j;						// if all elements are different it will give sum of x and y equal to 12.
	int x,y=0;
	for(i=0;i<=2;i++){
		for( j =0;j<=2;j++){
		 if((i==2)&&(j!=2)){
		 	if(arr[i][j]!=arr[i][j+1]&&arr[i][j]!=0){
		 		x++;
			 }
		 }if((j==2)&&(i!=2)){
		 	if(arr[i][j]!=arr[i+1][j]&&arr[i][j]!=0){
		 		y++;
			 }
		 }if((i<2)&&(j<2)){
		 
			if(arr[i][j]!=arr[i][j+1]&&arr[i][j]!=0){
				x++;				}
			}
			if((i<2)&&(j<2)){
			if(arr[i][j]!=arr[i+1][j]&&arr[i][j]!=0){
				y++;}
			}
			if((i==2)&&(j==2)){
		 	if(arr[i][j]==0){
		 		x--;
		 		y--;
			 }
			}
		}
	}
	return x+y;
}

int main(void){
	srand(time(NULL));
	int input,i,j;
	int x =0;
	
	printf("press--> 8 for up\n"				// movement instructions
		   "         6 for right\n"
		   "         2 for down\n"
		   "         4 for left\n");
	
	
	for(i=0;i<2;i++){         			// Put two numbers randomly at starting of the game. 
		random();
	}	
	
	
	for(i =0;i<3;i++){						// print starting grid
		for( j =0;j<3;j++){
			printf("\t\t%i  ",arr[i][j]);
		}
		printf("\n\n");
	}
	
	while(1){								// this loop keep on taking input till game over
	scanf("\t\t%i",&input);
	if(input==2||input==4||input==6||input==8){		// If correct key is pressed
	
	for(i =0;i<3;i++){						// Stores the previous state of grid
		for( j =0;j<3;j++){					
			a[i][j]=arr[i][j];				
			}
		}	
		
	move(input);
	
	for(i =0;i<3;i++){						// prints the grid after the move
		for( j =0;j<3;j++){
			printf("\t\t%i  ",arr[i][j]);
			if(a[i][j]==2048){
				printf("You Win");
			}
		}
		printf("\n\n");
	}
	
	
	if(gameOver()==12){						// Game over condition
		printf("Game Over");
		break;
		}
		
	for(i =0;i<5;i++){						// Winning Condition
		for( j =0;j<5;j++){	
			if(arr[i][j]==2048){
				printf("You Win");
				x = 1;
				break;
			}}}
			if(x==1){
				break;
			}	
}
	
}

}
	


