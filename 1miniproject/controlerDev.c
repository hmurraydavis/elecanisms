#include <stdio.h>

#define TIME_READING_WINDOW 30

int sum_array(float a[], int num_elements){
    /*Written by:
    Peter H. Anderson, MSU, Feb 21, '97
    http://www.phanderson.com/C/arraysum.html
    
    Modified for floating point addition by Halie Murray-Davis, Feb 1, '15'*/
    int i;
    float sum=0;
    for (i=0; i<num_elements; i++)
    {
     sum = sum + a[i];
    }
    return(sum);
}

int main(){
    float readings[TIME_READING_WINDOW]; //allocate array for sensor readings
    
    float sensorReading = 5; //pseudo sensor reading
    
    for(int i=1; i<TIME_READING_WINDOW-1; ++i){
        readings[i-1] = readings[1]; //Shift out the oldest sensor reading
        readings[TIME_READING_WINDOW-1] = sensorReading;
        
        //Togel sensor reading value: TODO: DELETE & REPLACE.
        if(sensorReading == 5){
            sensorReading = 6; 
        }
        else{
            sensorReading = 5;
        }
    }
    
    for(int i=0; i<TIME_READING_WINDOW-1; ++i){
        printf("Array value at %2d is: %f \n",i,readings[1]);
    }
    float sum_sensor_readings = sum_array(readings, 30);
    printf("The sum of the sensor readings is: %6.1f \n", sum_sensor_readings);
    printf("Hi!\n");
    return 0;
}
