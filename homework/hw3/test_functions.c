//Chris Wilhelm
//cwilhel8
#include <assert.h>
#include <stdio.h>

#include "functions.h"

#define TEST_RESTRICTION_1 10
#define TEST_RESTRICTION_2 2
#define TEST_RESTRICTION_3 5
#define TEST_RESTRICTION_4 30

void test_read_files() {
  FILE* fptr = fopen("test_file_1.txt", "w");
  fprintf(fptr, "4\n \nthis\nshould\nfail\n");
  char words[4][MAX_WORD_SIZE + 1];
  assert(read_file(fptr, words, 4) == 1);
  fclose(fptr);
  FILE* fptr2 = fopen("test_file_2.txt", "w");
  fprintf(fptr2, "\n");
  char words2[1][MAX_WORD_SIZE + 1];
  assert(read_file(fptr2, words2, 1) == 1);
  fclose(fptr2);
}

void test_match_regex() {
    assert(match("abc", "abc", TEST_RESTRICTION_1) == 1);
    assert(match("abcd", "abc", TEST_RESTRICTION_1) == 0);
    assert(match("", "", TEST_RESTRICTION_1) == 1);
    assert(match("abc_d", "abcd", TEST_RESTRICTION_1) == 0);
    assert(match("\n", "\n", TEST_RESTRICTION_1) == 1);
    assert(match("", "abc", TEST_RESTRICTION_1) == 0);
    assert(match("     ", "     ", TEST_RESTRICTION_1) == 1);
    assert(match(" ab ab ", " ab ab ", TEST_RESTRICTION_1) == 1);
    assert(match("12#4", "12#4", TEST_RESTRICTION_1) == 1);
}

void test_match_regex_star() {
    assert(match("abcd*", "abc", TEST_RESTRICTION_1) == 1);
    assert(match("abc*d", "abcccccccd", TEST_RESTRICTION_1) == 1);
    assert(match("abc*de", "abcccccccd", TEST_RESTRICTION_1) == 0);
    assert(match("1*2", "11112", TEST_RESTRICTION_1) == 1);
    assert(match("1*", "", TEST_RESTRICTION_1) == 1);
    assert(match("1*23", "11223", TEST_RESTRICTION_1) == 0);
    assert(match("1a*2*b", "1aa22b", TEST_RESTRICTION_1) == 1);
    assert(match("*", "", TEST_RESTRICTION_1) == 0);
}

void test_match_regex_question() {
    assert(match("a?", "", TEST_RESTRICTION_1) == 1);
    assert(match("a?", "b", TEST_RESTRICTION_1) == 0);
    assert(match("a?", "a", TEST_RESTRICTION_1) == 1);
    assert(match("?", "", TEST_RESTRICTION_1) == 0);
    assert(match("1?2?", "", TEST_RESTRICTION_1) == 1);
}

void test_match_regex_tilde() {
    assert(match("~", "aaaa", TEST_RESTRICTION_1) == 1);
    assert(match("~", "", TEST_RESTRICTION_1) == 1);
    assert(match("~", "a", TEST_RESTRICTION_1) == 1);
    assert(match("a~", "ab", TEST_RESTRICTION_1) == 1);
    assert(match("~~", "ab", TEST_RESTRICTION_1) == 1);
    assert(match("b~", "a", TEST_RESTRICTION_1) == 0);
}

void test_match_regex_multiple() {
  assert(match("!2*keK?ee?rCC?C*aP?E*eR*T*", "!2222keKerCCCaeRRRT",
               TEST_RESTRICTION_1) == 1);
  assert(match("!~2*keK?ee?rCC?C*aP?E*eR*T*", "!2222keKerCCCaeRRRT",
              TEST_RESTRICTION_1) == 1);
  assert(match("~abc", "sda12!$2", TEST_RESTRICTION_1) == 0);
  assert(match("a*~", "aaabbb", TEST_RESTRICTION_1) == 1);
  assert(match("a*~c?", "aaabbbc", TEST_RESTRICTION_1) == 1);
  assert(match(",* ?", ",,,,", TEST_RESTRICTION_1) == 1);
  assert(match(",*~", ",,,aa", TEST_RESTRICTION_1) == 1);
  assert(match("a?y*m~,,,", "m,,,", TEST_RESTRICTION_1) == 1);
}

void test_match_regex_tilde_restriction() {
  assert(match("~", "aaaa", 3) == 0);
  assert(match("~", "", 1) == 1);
  assert(match("~", "a", 1) == 1);
  assert(match("a~", "ab", 1) == 1);
  assert(match("~~", "ab", 1) == 1);
  assert(match("b~", "a", 1) == 0);
  assert(match("!~2*keK?ee?rCC?C*aP?E*eR*T*", "!2222keKerCCCaeRRRT",
              TEST_RESTRICTION_1) == 1);
  assert(match("~abc", "sda12!$2", TEST_RESTRICTION_1) == 0);
  assert(match("a*~", "aaabbb", 2) == 0);
  assert(match("a*~c?", "aaabbbc", 2) == 0);
  assert(match("C?chris*~", "chris wilhelm", 10) == 1);
  assert(match("~", "aaa", 2) == 0);
  assert(match("~~", "aaa", 2) == 1);
  assert(match("~~", "chriswilhelm", 5) == 0);
}

int main() {
    printf("Starting Tests...\n");
    test_read_files();
    test_match_regex();
    test_match_regex_star();
    test_match_regex_question();
    test_match_regex_tilde();
    test_match_regex_multiple();
    test_match_regex_tilde_restriction();
    printf("All tests passed!!!\n");
}
