#include <stdio.h>
int ifOut(); /* It's a function to understand if the inputs are in board */
int ifHit(); /* It's a function to understand if user hit the target */
/* Down here Coordinates of the marked region and sizes of the m. region,detector and board */
float rsidex,lsidex,usidey,dsidey,rdetsidex,ldetsidex,udetsidey,ddetsidey;
float inputx,inputy; /* coordinates of the center of detector */
float mrsizex = 18.0,mrsizey = 20.0,mrcrdx = 120.0,mrcrdy = 10.0,detsizex = 40.0,detsizey = 40,boardsizex = 300.0,boardsizey = 400.0;
int attremain = 10; /* Attemps remaining to end the game with lose */

int main(){
printf("Board = %.2lf %.2lf,Marked Region = %.2lf %.2lf,Detector = %.2lf %.2lf, Attemps Remaining = %d\n",boardsizex,boardsizey,mrsizex,mrsizey,detsizex,detsizey,attremain);
while(attremain>0){
    printf("Enter the x coordinate");             /* We Take detector coordinates as input */
    scanf("%f",&inputx);                        
    printf("Enter the y coordinate"); 
    scanf("%f",&inputy);
    rsidex = mrcrdx + (mrsizex/2);
    lsidex = mrcrdx - (mrsizex/2);
    usidey = mrcrdy + (mrsizey/2);
    dsidey = mrcrdy - (mrsizey/2);                 /* Calculating sides of the marked region and detector */
    rdetsidex = inputx + (detsizex/2);
    ldetsidex = inputx - (detsizex/2);
    udetsidey = inputy + (detsizey/2);
    ddetsidey = inputy - (detsizey/2);
    if(ifOut()== 1){
        printf("It's not a valid coordinate.Try Again!\n");
        }
    if (ifHit() == 0 && ifOut()== 0){
		attremain = attremain -1;
        printf("You missed the target! Try Again! Board = %.2lf %.2lf,Marked Region = %.2lf %.2lf,Detector = %.2lf %.2lf, Attemps Remaining = %d\n",boardsizex,boardsizey,mrsizex,mrsizey,detsizex,detsizey,attremain);
        
        }
    if (ifHit() == 1){
		attremain = attremain -1;
        detsizex = detsizex / 2;                    
        detsizey = detsizey / 2;

        if(rdetsidex < rsidex && rdetsidex > lsidex){
            mrsizex = rdetsidex - lsidex;
            mrcrdx = (rdetsidex + lsidex)/2;                        /* If user hits the target,the operators determine where the detector hits */
        
            }
        if(udetsidey < usidey && udetsidey > dsidey){
            mrsizey = udetsidey - dsidey;
            mrcrdy = (udetsidey + dsidey)/2;
            }
        if(rdetsidex > rsidex){
            mrsizex = rsidex - ldetsidex;
            mrcrdx = (rsidex + ldetsidex)/2;

            }
        if(udetsidey > usidey){
            mrsizey = usidey - ddetsidey;
            mrcrdy = (usidey + ddetsidey)/2;
    
            }
        
        
    	if(rdetsidex > rsidex && ldetsidex < lsidex && udetsidey > usidey && ddetsidey < dsidey){
        	printf("You won the game!");
            return 1;
        }
		printf("Partial Hit! Board = %lf %lf,Marked Region = %lf %lf,Detector = %lf %lf, Attemps Remaining = %d\n",boardsizex,boardsizey,mrsizex,mrsizey,detsizex,detsizey,attremain);
}
    }

if(attremain==0){
    printf("You lose the game!\n");  /* If user has no longer right to continue,lose the game */
    return 1;
    }
}
int ifHit(){
if(inputx + (detsizex/2) > lsidex && inputx - (detsizex/2) < rsidex && inputy + (detsizey/2) > dsidey && inputy - (detsizey/2) < usidey){
    return 1;}
else 
    return 0;
}
int ifOut(){
if (inputx > boardsizex || inputy > boardsizey || inputx < 0 || inputy < 0 ){
    return 1;
    }
else 
    return 0 ;
    
}


