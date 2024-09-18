#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *string_reverse(const char *str);
char *concat(const char *str_1, const char *str_2);
void string_contains(const char *str, const char *substr, int *substr_exists, int *substr_index);

char *string_reverse(const char *str) {
  int length = strlen(str);
  char *reversed_str = malloc((length + 1) * sizeof(char));

  for (int i = 0; i < length; i++) {
    reversed_str[i] = str[length - i - 1];
  }
  reversed_str[length] = '\0';

  return reversed_str;
}

char *concat(const char *str_1, const char *str_2) {
  int str1_len = strlen(str_1);
  int str2_len = strlen(str_2);
  char *result_str = malloc((str1_len + str2_len + 1) * sizeof(char));
  for (int i = 0; i < str1_len; i++) {
    result_str[i] = str_1[i];
  }
  for (int i = 0; i < str2_len; i++) {
    result_str[i + str1_len + 1] = str_2[i];
  }
  result_str[str1_len + str2_len + 2] = '\0';
  return result_str;
}

void string_contains(const char *str, const char *substr, int *substr_exists, int *substr_index) {
  int str_len = strlen(str);
  int substr_len = strlen(substr);
  
  char *temp_str = malloc((substr_len + 1) * sizeof(char));
  int temp_len = substr_len;
  temp_str[temp_len + 1] = '\0';

  for (int i = 0; i < str_len; i++) {
    if (i + substr_len > str_len) {
      break;
    }
    int count = 0;
    for (int j = i; j < i + substr_len; j++) {
      temp_str[count] = str[j];
      count++;
    }
    for (int k = 0; k < temp_len; k++) {
      if (temp_str[k] == substr[k]) {
        *substr_exists = 1;
      } else {
        *substr_exists = 0;
        break;
      }
    }

    if (*substr_exists == 1) {
      *substr_index = i;
      return;
    }
  }
  *substr_index = -1; // does not exist
}

#endif //STRING_UTILS_H