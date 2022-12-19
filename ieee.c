#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float ieee754_to_float(char* ieee754) {
  int i;
  float mantissa = 0.0;
  int exponent = 0;
  int sign = (ieee754[0] == '1') ? -1 : 1;
  for (i = 1; i <= 8; i++) 
  {
    exponent = exponent * 2 + (ieee754[i] - '0');
  }
  exponent -= 127;
  for (i = 9; i <= 31; i++) 
  {
    mantissa = mantissa / 2.0 + (ieee754[i] - '0');
  }
  mantissa /= (float) (1 << 23);
  return sign * ldexp(mantissa, exponent);
}

int main() {
  char* ieee754 = "01000000  10001011  01010101  00010010";
  float f = ieee754_to_float(ieee754);
  printf("Konversi IEEE 754 %s ke float adalah: %f\n", ieee754, f);
  return 0;
}
