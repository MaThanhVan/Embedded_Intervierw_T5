/*
* File: Tinh_gia_cuoc_TAXI
* Author: MA THANH VAN
* Date: 5/06/2023
* Description: This is a file for caculate taxi fare
*/

 #include <TAXI.h>

/*
* Function: caculate_TAXI_Fare
* Description: This function use for caculate TAXI Fare
* Input:
*   travel_Distance - input uint8_t
* Output:
*   return: none
*/
void caculate_TAXI_Fare(uint8_t travel_Distance)
{
    uint8_t Fare;
    if(travel_Distance <= 1){
        Fare = 1 * 14;
    }
    if (travel_Distance <= 30)
    {
        Fare = ((1 * 14) + ((travel_Distance - 1) * 10)); 
    }
    if(travel_Distance > 30)
    {
        Fare = ((1 * 14) + (29 * 10) + ((travel_Distance - 30) * 8));
    }
    printf("So tien %d", Fare);
    
}