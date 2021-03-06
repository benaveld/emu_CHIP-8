#include "io.hpp"
#include <stdio.h>
#include <stdexcept>

using namespace std;

unsigned char hex2byte(char input)
{
  if (input >= '0' && input <= '9')
    return input - '0';
  if (input >= 'A' && input <= 'F')
    return input - 'A' + 10;
  if (input >= 'a' && input <= 'f')
    return input - 'a' + 10;

  fprintf(stderr, "error char: %x\n", input);  
  throw std::invalid_argument("Invalid input string");
}

unsigned char *chip8::io::readProgram(const char *filename)
{
  unsigned char *memory = new unsigned char[chip8MemorySize];

  int address = INT32_MAX;
  char c;
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp)
  {
    while ((c = getc(fp)) != EOF)
    {
      if (address >= INT32_MAX)
      {
        address = hex2byte(c);
        for (int i = 1; i < 4; i++)
        {
          if((c = getc(fp)) == EOF){
            throw std::length_error("Unexpected end of file.");
          }
          address = address << 4 | hex2byte(c);
        }
      } else if(c == '\n'){
        address = INT32_MAX;
      } else {
        memory[address] = hex2byte(c) << 4 | hex2byte(getc(fp));
        address++;
      }

    }
    fclose(fp);
  }

  return memory;
}