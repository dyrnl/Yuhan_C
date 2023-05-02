#include <stdio.h>

int print_title_screen()
{
	printf("###############################\n");
	printf("##                           ##\n");    
	printf("##          Dino Rush        ##\n");  
	printf("##            V.0.1          ##\n");  
	printf("##                           ##\n");  
	printf("##       1. Start Game       ##\n");  
	printf("##       2. How to Play      ##\n");  
	printf("##       3. Exit             ##\n");  
	printf("##                           ##\n");
	printf("###############################\n");
	
	return 0;
}

int print_how_to_play_screen()
{
	printf("###############################\n");
	printf("##                           ##\n");  
	printf("##                           ##\n");  
	printf("##      To Avoid Enemy       ##\n");  
	printf("##                           ##\n");  
	printf("##                           ##\n");  
	printf("##  Press Space Bar to Jump  ##\n");  
	printf("##                           ##\n");  
	printf("##                           ##\n");  
	printf("###############################\n");
	
	return 0;
}

int main()
{
	int ans = 0;
	int menu = 1;
	int re = 1;
	while(menu){
		print_title_screen();
		printf("input>");
		scanf("%d", &menu);
		if(menu==2){
			while(re){
				print_how_to_play_screen();
				printf("Return to menu? (1. yes 2. no)>");
				scanf("%d", &ans);
				if(ans==1){
					break;
				}
				else if(ans==2){
					continue;
				}
				else{
					continue;
				}
				}
			}
					else if(menu==3){
						break;
					}
					else{
						continue;
					}
			}
		return 0;
}

