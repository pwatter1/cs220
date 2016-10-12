 /*
 Complete the function below. Do NOT add main function or any include statement.
 */

int swap_bytes(int n) {
    /* maintain individual byte and clear rest */   
    /* assuming 32 bits */
        
    n = ((n & 0x00FF0000) << 8) | ((n & 0xFF000000) >> 8) |
        ((n & 0x000000FF) << 8) | ((n & 0x0000FF00) >> 8) ;
        
    return n;
}
