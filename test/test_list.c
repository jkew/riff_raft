#include <../src/include/list.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

list_ref *list = NULL;

void test_clear() {
  int *val = malloc(sizeof(int));
  *val = 999;
  list = new_list();
  pushv(list, val);
  assert(1 == sizel(list));
  assert(*val == 999);
  clearl(list);
}


void test_push_pop() {
  int *val = malloc(sizeof(int));
  *val = 999;
  list = new_list();
  pushv(list, val);
  pushv(list, val);
  pushv(list, val);
  assert(3 == sizel(list));
  assert(*val == 999);
  assert(val == popv(list));
  assert(2 == sizel(list));
  assert(val == popv(list));
  assert(1 == sizel(list));
  assert(val == popv(list));
  assert(0 == sizel(list));
  clearl(list);
  free(val);
}


void test_itr() {
  int input[] = { 0, 1, 2, 999, 3 };
  int i;
  list = new_list();
  listi itr = list_itr(list);
  for (i = 0; i < 5; i++) {
    itr = add_itr(list, itr, &input[i]);
    assert((i + 1) == sizel(list));
    assert(input[i] == *((int *)value_itr(itr)));
  }
  assert(5 == sizel(list));
  itr = list_itr(list);
  i = 0;
  while(there(itr)) {
    assert(input[i] == *((int *)value_itr(itr)));
    i++;
    itr = next_itr(itr);
  }
  
  itr = prev_itr(itr); // back to the end of the list

  i = 4;
  while(there(itr)) {
    assert(input[i] == *((int *)value_itr(itr)));
    i--;
    itr = prev_itr(itr);  
  }

  itr = list_itr(list);
  int *val;
  while(there(itr = remove_itr(list, itr, &val))) {
    // no need to free val
  }
  assert(0 == sizel(list));
  clearl(list);
}

void test_get() {
  list = new_list();
  int MAX_SIZE = 10;
  for (int i = 0; i < MAX_SIZE; i++) {
      int *val = malloc(sizeof(int));
      *val = i;
      pushv(list, val);
      assert(list->tail != 0);
      assert(*((int *) list->tail->value) == 0);
      assert(*((int *) list->head->value) == i);
      // We are pushing; so get the values in reverse
      for (int check = i; check >= 0; check--) {
        int *got = list_get(list, check);
        assert((*got) == (i - check));
      }
  }
  // out of bounds => return null
  assert(list_get(list, MAX_SIZE) == NULL);
  void *val = 0;
  while ((val = popv(list))) free(val);
  clearl(list);
}

int main() {
 test_clear();
 test_itr();
 test_get();
 return 0;
}
