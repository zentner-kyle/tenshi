#include <ndl3.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char * test_msg = "test msg"
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test "
      " test ";

int main() {
  NDL3Net * target = NDL3_new(NULL, NULL, NULL);
  NDL3Net * host = NDL3_new(NULL, NULL, NULL);
  NDL3_open(target, 1);
  NDL3_open(host, 1);
  char * in_msg = strdup(test_msg);
  srand(time(NULL));
  NDL3_send(host, 1, in_msg, 1 + strlen(in_msg));
  char * out_msg = NULL;

  uint8_t buffer[256];
  while (out_msg == NULL) {
    NDL3_recv(target, 1, (void **) &out_msg, NULL);
    NDL3_L2_pop(host, buffer, sizeof(buffer), NULL);
    if (rand() & 0xff) {  /* NOLINT(runtime/threadsafe_fn) */
      memset(buffer, 0, sizeof(buffer));
    }
    /*if (rand() & 0xff) {*/
      /*int r = rand() & 0xff;*/
      /*memset(buffer + r, 0, sizeof(buffer) - r);*/
    /*}*/
    NDL3_L2_push(target, buffer, sizeof(buffer));
    NDL3_L2_pop(target, buffer, sizeof(buffer), NULL);
    if (rand() & 0xff) {  /* NOLINT(runtime/threadsafe_fn) */
      memset(buffer, 0, sizeof(buffer));
    }
    /*if (rand() & 0xff) {*/
      /*int r = rand() & 0xff;*/
      /*memset(buffer + r, 0, sizeof(buffer) - r);*/
    /*}*/
    NDL3_L2_push(host, buffer, sizeof(buffer));

    NDL3_elapse_time(host, 100);
    NDL3_elapse_time(target, 100);
  }
  printf("%s\n", out_msg);
  return 0;
}
