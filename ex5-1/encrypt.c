#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// this function takes a message in binary form (i.e., a message that only includes
// 0s and 1s) as a string and returns decimal equivalent of it as an integer.
// Example: string message "111101" return 61 as an int, since 61 is decimal
// equivalent of "111101".  
int str_to_int(char msg[], int len) {
  int num = 0;
  for(int n = 0; n < len; n++) {
    int temp = 1;
    int temp_num = msg[n] - '0';
    for(int k = len - n - 1; 0 < k; k--) {
      temp = 2*temp_num*temp;
    }
    if( n == len - 1) {
      temp = temp_num*1;
    }
    num = num + temp;
  }
  return num;

}


// this function takes a decimal value as an integer and creates a string
// including 0s and 1s that is the binary representation of the integer number.
// Example: number 61 (as an int) results in "111101", since "111101" is
// binary representation of the decimal value 61.  
void int_to_str(int num_encrypted, char msg_encrypted[], int len) {
  int num = num_encrypted;
  for(int n = len - 1; n >= 0; n--) {
    msg_encrypted[n] = num % 2 + '0';
    num = num / 2;
  }

}


int main() {

  int num_msg = 0; // the binary message as an int
  char msg[33] = {'\0'}; // this will hold the binary message as a string
  int n = -1; // n used in encryption

  printf ("Enter the message to be encrypted in binary format (max 32 bit): ");
  if (scanf(" %s", msg) != 1) { // read the binary message as a string
    printf("Could not read the message!\n");
    return 1;
  }  

  int len = strlen(msg); // length of the binary message
  
  // convert the string binary message to an integer
  num_msg = str_to_int(msg, len);
  
  // read n
  printf ("Enter n: ");
  if (scanf("%d", &n) != 1) {
    printf("Could not read n!\n");
    return 1;
  }

  int num_encrypted = num_msg;


  num_encrypted =  num_encrypted << (n-1);

  char msg_encrypted[33] = {'\0'};
  int encrypted_len = len + n - 1;

  // convert the encrypted message back to a string
  int_to_str(num_encrypted, msg_encrypted, encrypted_len);

  // print out the original and encrypted messages as strings
  printf("Plain binary message is %s and encrypted message is %s \n", msg, msg_encrypted);
  return 0;

}
