#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

int main(int argc, char **argv) {
  uint8_t hex[4096];
  int foo_value = 0;

  printf("You submit your code as a hex encoded string of max 4096 characters (2048 bytes)\n");
  read(0, hex, sizeof(hex));
  uint8_t shellcode[2048] = {0};
  uint8_t *cur_char = hex;
  for (int i = 0; i < sizeof(shellcode); ++i) {
      sscanf(cur_char, "%2hhx", &shellcode[i]);
      cur_char += 2;
  }

  int (*foo)() = (int(*)())shellcode;
  foo_value = foo();

  printf("%d\n", foo_value);
}
