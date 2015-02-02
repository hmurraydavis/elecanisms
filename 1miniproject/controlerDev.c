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
    float readings[TIME_READING_WINDOW]; //allocate array for sensor readings
    
    float sensorReading = 5; //pseudo sensor reading
    
    for(int i=1; i<TIME_READING_WINDOW-1; ++i){
        if(readings[i]>0.0000){
            readings[i-1] = readings[i]; //Shift out the oldest sensor reading
        }
        else{
            readings[i-1] = sensorReading;
        }
    }
    
    readings[TIME_READING_WINDOW-1] = sensorReading;
    printf("Time reading window: %3d\n",TIME_READING_WINDOW);
    printf("Written value to array is: %3.3f \n", readings[TIME_READING_WINDOW-1]);
    
    for(int i=0; i<=TIME_READING_WINDOW-1; i++){
        printf("Array value at %2d is: %f \n",i,readings[i]);
    }
    
    float sum_sensor_readings = sum_array(readings, 30);
    float current_position = sum_sensor_readings/TIME_READING_WINDOW; 
    float motor_command = K*(SET_POINT - current_position);
    printf("The sum of the sensor readings is: %6.1f \n", sum_sensor_readings);

    return 0;
}
