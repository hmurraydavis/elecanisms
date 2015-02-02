#include <stdio.h>

#define TIME_READING_WINDOW 30
#define SET_POINT 45
#define K 2

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
    //allocate array for sensor readings:
    float readings[TIME_READING_WINDOW]; 
    
    float sensorReading = 5; //pseudo sensor reading, TODO: REPLACE WITH REAL VALUE
    
    for(int i=1; i<TIME_READING_WINDOW-1; ++i){
        //Shift out the oldest sensor reading:
        if(readings[i]>0.1000){
            readings[i-1] = readings[i]; 
        }
        else{
            readings[i-1] = sensorReading;
        }
    }
    //Write the current sensor reading to end of array:
    readings[TIME_READING_WINDOW-1] = sensorReading;
    
    for(int i=0; i<=TIME_READING_WINDOW-1; i++){
        printf("Array value at %2d is: %f \n",i,readings[i]);
    }
    
    float sum_sensor_readings = sum_array(readings, 30);
    float current_position = sum_sensor_readings/TIME_READING_WINDOW; 
    float motor_command = K*(SET_POINT - current_position);
    printf("The sum of the sensor readings is: %6.1f \n", sum_sensor_readings);

    return 0;
}
