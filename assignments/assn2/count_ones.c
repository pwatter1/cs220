 /*
 Complete the function below. Do NOT add main function or any include statement.
 */
unsigned int count_ones(int n) {  
    /* 1111111111111.... */
    int bit_position = 1<<32;
    int count = 0;
   
    /* move through bit by bit, using AND one to see if bit set */
    /* seperate by positive or negative int */
    if(n >= 0){
        while(n > 0){
            if((n & 1) == 1){count += 1;}
            n >>= 1;
        }
    }else{
        /* NOT n */
        n = ~n;
        while(n > 0){
            if((n & 1) == 1){count += 1;}
            n >>= 1;
        }
        /* account for two's complement */
        count = 32 - count;
    }
    return count; 
}
