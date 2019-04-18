#include <stdio.h>
#include <string.h>

// character bank from ghidra hex
char output[35] = {
      0xD6, 0xF0, 0xBA, 0x04, 0x40, 0x90, 0x32, 0x30, 0x18, 0x18, 0xC3, 0x80,
      0x80, 0xE0, 0xD8, 0x20, 0x2C, 0x02, 0xA0, 0x20, 0x2C, 0x7C, 0x49, 0xB8,
      0xD0, 0xE0, 0x7C, 0x98, 0x6C, 0x56, 0x84, 0x00, 0x00, 0x00, 0x80 };

// Flag Characters
char character[20] = { 'a', 'b', 'c', 'd', 'e', 'f', 'l', 'g', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '{', '}'};


void obfuscate(char* param_1, unsigned int size)
{
  unsigned int local_c = 523190095; // x1f2f3f4f;

    for (int i = 0; i < size; i++) {
      local_c = param_1[i] * (local_c >> 3) * (i + 1);
      param_1[i] = local_c;
    }

}

int main(int argc, char const *argv[]) 
{
  // Initialize variables
  int back_trace = 0;
  int position = 0;
  int current_position = 0;
  char key[35];
  char temp_key[35];
  char visited[35][20] = { 0 };

  while (position < 35) {
    current_position = position;
    for (int i = 0; i < 20; i++) {

      // Check if character was already visited
      if (visited[position][i] == 1 ) {
        continue;
      }

      // Set temp_key to key
      memset(temp_key, 0, 35);
      strncpy(temp_key, key, position + 1);

      // Add possible character
      temp_key[position] = character[i];

      obfuscate(temp_key, position + 1);

      // Check if matches output
      if (temp_key[position] == output[position]) {
        // add to key
        key[position] = character[i];

        // Mark position x character as visited
        visited[position][i] = 1;

        // Move to next position
        position +=1;
        break;
      }
    }

    // Check if position didn't advance
    if (position == current_position) {

      // Back Trace
      position = position - 1;

      // Reset visited matrix
      for (int i = position + 1; i < 35; i++) {
        for (int j = 0; j < 20; j++) {
          visited[i][j] = 0;
        }
      }
    }
  }

  // Add '}' to end of key when length hit.... still works without final bracket though if string >=35 characters
  char final_key[36];
  memset(final_key, 0x00, 35);
  strncpy(final_key, key, 35);
  final_key[35] = '}';

  printf("Key: %s\n", final_key );
  return 1;
}