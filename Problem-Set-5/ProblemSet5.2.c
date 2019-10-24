#include <stdio.h>
/*The PS question did not specifically ask for user input so I did not implement that function because 
it would add another layer of complexity. This code is working just fine but you need to change the
parameters inside the int main() function. Hope that is okay.
*/
int RotateFunction(int, int, int*);

//input the parameters in the int main function
int main(){
    //how big do you want the array?
    int s = 6;
    //how many times and in what direction do you want to rotate? Negative rotates left. Positive rotates right. 
    int rotation = -1;
    //what do you want inside your array? Remember to change the array size to fit!
    int num[6] = {1, 2, 3, 4, 5, 6};
    //Run the Rotation function
    RotateFunction(s, rotation, num);
}

int RotateFunction(int size, int r, int *num)
{
   //initialize place holder
    int c;
    int rotation = r;
    int s = size;
    //the first one rotates to the left, the second one rotates to the right
    if(rotation < 0){
        int rotate;
        rotate = rotation * -1;
        for (int j = 0; j < rotate; j++){
            c = *(num + 0);
            for (int i = 1; i < 6; i ++){
                *(num + i - 1) = *(num + i);
            }
            *(num + s - 1) = c;
        }
    }
    else {
        for (int j = 0; j < rotation; j++){
            c = *(num + s - 1);
            for (int i = 0; i < s; i ++){
                *(num + s - i) = *(num + s - i - 1);
            }
            *(num + 0) = c;
        }    
    }
    
    //print the rotated array
    for (int i = 0; i < 6; i ++){
        printf("%d\n", num[i]);
    }
    return 0;
}