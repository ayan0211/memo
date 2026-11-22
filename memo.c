#include <stdio.h>

void firstfit(int blocks[],int process[],int nb , int np) {

    int allocation[20];
    int remaining[20];

    for (int i = 0; i < nb; i++) {
        remaining[i] = blocks[i];
        
    }

    for (int i = 0; i<np; i++) {

        allocation[i] = -1;

        for(int j =0; j < nb; j++){

            if(remaining[j] >= process[i]){
                allocation[i] = j;

                remaining[j] -= process[i];
                    break;
            }

            
        }

        
    }

    printf("First Fit : \n");

    for(int i = 0; i < np ; i++){

        if(allocation[i] != -1) {

        printf("P%d -> black%d\n",i+1,allocation[i]+1);

        }

        else{
            printf("P%d - > Remained Single\n",i+1);
        }
    }
    
}

void Bestfit(int blocks[],int process[],int nb,int np){
    int allocation[20];
    int remaining[20];
    int best = -1;

    for (int i = 0; i < nb ; i++){
        remaining[i] = blocks[i];
        
    }

    for(int i = 0; i < np ; i++){
        allocation[i] = -1;
        best = -1;

        for(int j = 0; j < nb ; j++){

            if(remaining[j] >= process[i]){

                if(best == -1 || remaining[j] < remaining[best]){

                    best = j;
                }

                
            }
        }

        if (best != -1){
            allocation[i] = best;
            remaining[best] -= process[i];
        }
    }

    printf("Best Fit\n");

    for(int i = 0; i < np; i++){
        if(allocation[i] != -1){
                    printf("P%d -> Block: %d\n",i+1,allocation[i]+1);
        }
        else{
            printf("P%d -> Single\n",i+1);
            
        }
    }
}

void worstfit(int blocks[],int process[],int nb,int np){
    int allocation[20];
    int remaining[20];
    int worst = -1;

    for (int i = 0; i < nb ; i++){
        remaining[i] = blocks[i];
        
    }

    for(int i = 0; i < np ; i++){
        allocation[i] = -1;
    worst = -1;

        for(int j = 0; j < nb ; j++){

            if(remaining[j] >= process[i]){

                if(worst == -1 || remaining[j] > remaining[worst]){

                    worst = j;
                }

                
            }
        }

        if (worst != -1){
            allocation[i] = worst;
            remaining[worst] -= process[i];
        }
    }

    printf("Worst Fit\n");

    for(int i = 0; i < np; i++){
        if(allocation[i] != -1){
                    printf("P%d -> Block: %d\n",i+1,allocation[i]+1);
        }
        else{
            printf("P%d -> Single\n",i+1);
            
        }
    }
}

int main(){
    
    int blocks[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    firstfit(blocks,process,5,4);
    Bestfit(blocks,process,5,4);
    worstfit(blocks,process,5,4);

    
}


