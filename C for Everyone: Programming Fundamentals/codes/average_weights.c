/* This program reads the weights of elephant seals from a file and calculates the average weight.
   The weights are stored in an array and the number of weights is tracked using a pointer.
   The average weight is calculated and printed to the console.
*/


# include <stdio.h>

// This function reads the weights from a file and stores them in an array
// It also keeps track of the number of weights read
void read_weights(float *weights,int *n){

    // Open the file in read mode
    FILE *fptr = fopen("./data/elephant_seal_data.txt", "r");
    
    // Check if the file was opened successfully
    if (fptr == NULL){
        printf("Error opening file\n");
        return;
    }

    // Read the weights from the file until EOF
    while (fscanf(fptr, "%f", &weights[*n]) != EOF){
        (*n)++;
    }
    // Close the file
    fclose(fptr);
}

// This function calculates the average of the weights in the array
// It takes a pointer to the array and the number of weights as arguments
double average_weights(float *weights, int *n){
    double sum = 0;
    for (int i = 0; i < *n; i++){
        sum += weights[i];
    }
    return sum / *n;
}

void print_weights(float *weights, int n){
    for (int i = 0; i < n; i++){
        printf("%f\t", weights[i]);
    }
}

// The main function calls the read_weights and average_weights functions
// It also prints the average weight of the elephant seals
int main(){

    const int N = 1000;
    float weights[N];
    int n = 0;

    read_weights(weights, &n);
    double avg = average_weights(weights, &n);
    printf("The average weight of the elephant seals is: %.2f\n", avg);
    return 0;
    
}