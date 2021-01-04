//--------------------------------------------------------------------------------------------
/* CS 211 Programming Practicum
 * Instructor Name: Nasim Mobasheri
 * Author: Bhavana Laxmi Radharapu
 * UIN:661326091
 * Netid: bradha5
 * Project-1
*/
//--------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
// library to use malloc

// check for the sum of two number in the stored array
int TwoSumFunction(int* arr, int searchSum,int count,int *index1,int *index2){
    
        int frontIndex = 0;
      int backIndex = count-1;
      // setting our iterator to the first and last position in the stored array
        int iter1 = arr[frontIndex]; // setting the iterator to the beginning of the array
      int iter2 = arr[backIndex];  // setting the iterator to the end of the array
        
    // loops through the stored array
        for(int k=0;k < count ;k++){
            // To check if the index are same which means we don't have a set of numbers which can sum up to required number
            if(backIndex == frontIndex){
                *index1 = -1;
                *index2 = -1;
                break;
            }
            // to move the back iterator if the sum is greater than given number
            if((iter1+iter2) > searchSum){
                backIndex--;
                iter2 = arr[backIndex];
            }
            // to move the front iterator if the sum is lesser than given number
            else if((iter2 + iter1) < searchSum){
                frontIndex++;
                iter1 = arr[frontIndex];
            }
            
            // if the sum is found then return the positions of the number in our sorted array
            else if((iter1 + iter2) == searchSum){
                //Index + 1 is the position of the number in the integer
                *index1 = frontIndex + 1;
                *index2 = backIndex + 1;
                break;
            }
        }
    }
// }

//--------------------------------------------------------------------------------------------
// swaps the elements
void swap(int *x, int *y){
        int temp = *x;
      *x = *y;
      *y = temp;
}

//--------------------------------------------------------------------------------------------
// sorts the values in the array in increasing manner
void myFavouriteSort(int* arr, int n){
        int i,j,minIndex;
    for(int i = 0;i<n-1;i++){
        minIndex = i;
        for(int j = i+1; j<n ; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
     swap(&arr[minIndex],&arr[i]);
    }
}
//--------------------------------------------------------------------------------------------
//print the arrays
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
//--------------------------------------------------------------------------------------------
int main (int argc, char** argv)
{
    int val;
  int count = 0; // This vartable calculates the number of elements
    int* arr1; // stored the array of numbers
    int size = 5;
    arr1 = (int*)malloc(sizeof(int)*size); // allocation of memory
 
 /* prompt the user for input */
 printf ("Enter in a list of numbers to be stored in a dynamic array.\n");
 printf ("End the list with the terminal value of -999\n");
 
 scanf ("%d", &val);
    /* loop until the user enters -999 */
    while (val != -999)
    {
        // to check if the memory allocated is occupied and tone allocating more memory
        if(count >= size){
            int* temp;
            temp = arr1;
            arr1 = (int*)malloc(sizeof(int)*size*2);
            
            // copying the values from old array to dynamically grown new array
            for(int j=0;j<size;j++){
                arr1[j] = temp [j];
            }
            
            free(temp); // free the memory allocated
            size = size*2; // modifies the size
            
        }
        /* store the value into an array */
        arr1[count] = val; // setting val to the position count
        count++; // incrementing count


    /* get next value */
    scanf("%d", &val);
   }
    
    //making a copy of the array
    int* arr2;
    //allocating memory of the size of Original array
    arr2 = (int*)malloc(size * sizeof(int));
    // setting values of Original array to the copy array
    for(int k=0;k<count;k++){
        arr2[k] = arr1[k];
    }
    
//     print the Original Array
    printf("Original Array: ");
    printArray(arr2,count);
    
    /* call function to sort one of the arrays */
    myFavouriteSort(arr1, count);
    printf("Sorted array: ");// prints the sorted array
    printArray(arr1,count);
    
//--------------------------------------------------------------------------------------------

 printf ("Enter in a list of numbers to use for searching.  \n");
 printf ("End the list with a terminal value of -999\n");
 scanf ("%d", &val);

    /* loop until the user enters -999 */
    while (val != -999)
   {
        //
        int index1 = -1;
        int index2 = -1;
        
        //function call to check for the sum of numbers
        TwoSumFunction(arr1,val,count,&index1,&index2);
        
        // if the sum is not found or if the numbers in the same index are being added twice it
        if(index1 == -1 || index2 == -1){
            printf("Targeted sum could not be achieved by the sorted array.\n");
        }
        // if the sum of numbers is found and respective output
        else{
            printf("Targeted sum achieved!!\n");
            printf("The elements in the sorted array are in positions ");
            printf("%d",index1);
            printf(" and ");
            printf("%d",index2);
            printf("\n");
        }

    /* get next value */
    scanf("%d", &val);
   }
    
// program ends
 printf ("Good bye\n");
 return 0;
} 
