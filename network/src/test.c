// Licensed to Pioneers in Engineering under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  Pioneers in Engineering licenses
// this file to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
//  with the License.  You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License

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
  NDL3_setopt(target, 1, NDL3_PORT_ORDERED);
  NDL3_setopt(host, 1, NDL3_PORT_ORDERED);
  int good = 0;
  int total = 128;
  srand(time(NULL));
  for (int i = 0; i < total; i++) {
    printf ("sending\n");
    for (int j = 0; j < 3; j++) {
      char * in_msg = malloc(20);
      sprintf(in_msg, "%d, %d", i, j);
      NDL3_send(host, 1, in_msg, 1 + strlen(in_msg));
      printf("%d, %d\n", i, j);
    }
    printf ("recving\n");

    for (int j = 0; j < 3; j++) {

      uint8_t buffer[256];
      char * out_msg = NULL;
      while (out_msg == NULL) {
        NDL3_error e = NDL3_pop_error(target);
        if (e) {
          /*printf("error = %d\n", e);*/
          /*exit(0);*/
          /*break;*/
          if (e == 5) {
            break;
          }
        }
        /*printf("error = %d\n", e);*/
        /*if (e == NDL3_ERROR_PACKET_LOST) {*/
          /*break;*/
        /*} else if (e == 7) {*/
          /*goto start;*/
        /*} else if (e != 0 && e != 1 && e != 2 && e != 5) {*/
          /*printf("error = %d\n", e);*/
        /*}*/
        NDL3_recv(target, 1, (void **) &out_msg, NULL);
        NDL3_L2_pop(host, buffer, sizeof(buffer), NULL);
        /*if ((rand() >> 16) & 0x3) {  [> NOLINT(runtime/threadsafe_fn) <]*/
          /*memset(buffer, 0, sizeof(buffer));*/
        /*}*/
        NDL3_elapse_time(host, 5);
        NDL3_elapse_time(target, 5);
        NDL3_L2_push(target, buffer, sizeof(buffer));
        memset(buffer, 0, sizeof(buffer));
        NDL3_L2_pop(target, buffer, sizeof(buffer), NULL);
        /*if ((rand() >> 16) & 0x3) {  [> NOLINT(runtime/threadsafe_fn) <]*/
          /*memset(buffer, 0, sizeof(buffer));*/
        /*}*/
        NDL3_L2_push(host, buffer, sizeof(buffer));
        memset(buffer, 0, sizeof(buffer));
        NDL3_elapse_time(host, 5);
        NDL3_elapse_time(target, 5);
      }
      if (out_msg) {
        printf("%s\n", out_msg);
      }

    }

    /*for (int j = 0; j < 16; j++) {*/
      /*char * out_msg = NULL;*/
      /*NDL3_recv(target, 1, (void **) &out_msg, NULL);*/
      /*if (out_msg != NULL) {*/
        /*++good;*/
        /*printf("Got message:\n");*/
        /*printf("%s\n", out_msg);*/
      /*}*/
      /*free(out_msg);*/
    /*}*/
  }
  /*for (int i = 0; i < total; i++) {*/
  /*start:*/
    /*printf("loop start\n");*/
    /*char * in_msg = strdup(test_msg);*/
    /*NDL3_send(host, 1, in_msg, 1 + strlen(in_msg));*/
    /*[>sprintf(in_msg, "%d", i);<]*/
    /*[>in_msg = strdup(test_msg);<]*/
    /*[>sprintf(in_msg, "second %d", i);<]*/
    /*[>NDL3_send(host, 1, in_msg, 1 + strlen(in_msg));<]*/
    /*char * out_msg = NULL;*/

    /*uint8_t buffer[256];*/
    /*while (out_msg == NULL) {*/
      /*NDL3_error e = NDL3_pop_error(target);*/
      /*if (e == NDL3_ERROR_PACKET_LOST) {*/
        /*break;*/
      /*} else if (e == 7) {*/
        /*goto start;*/
      /*} else if (e != 0 && e != 1 && e != 2 && e != 5) {*/
        /*printf("error = %d\n", e);*/
      /*}*/
      /*NDL3_recv(target, 1, (void **) &out_msg, NULL);*/
      /*NDL3_L2_pop(host, buffer, sizeof(buffer), NULL);*/
      /*if ((rand() >> 16) & 0x3) {  [> NOLINT(runtime/threadsafe_fn) <]*/
        /*memset(buffer, 0, sizeof(buffer));*/
      /*}*/
      /*NDL3_elapse_time(host, 5);*/
      /*NDL3_elapse_time(target, 5);*/
      /*NDL3_L2_push(target, buffer, sizeof(buffer));*/
      /*memset(buffer, 0, sizeof(buffer));*/
      /*NDL3_L2_pop(target, buffer, sizeof(buffer), NULL);*/
      /*if ((rand() >> 16) & 0x3) {  [> NOLINT(runtime/threadsafe_fn) <]*/
        /*memset(buffer, 0, sizeof(buffer));*/
      /*}*/
      /*NDL3_L2_push(host, buffer, sizeof(buffer));*/
      /*memset(buffer, 0, sizeof(buffer));*/

      /*NDL3_elapse_time(host, 5);*/
      /*NDL3_elapse_time(target, 5);*/
    /*}*/
    /*if (out_msg != NULL) {*/
      /*++good;*/
      /*printf("Got message:\n");*/
      /*printf("%s\n", out_msg);*/
    /*}*/
    /*free(out_msg);*/
    /*for (int i = 0; i < 8; i++) {*/
      /*memset(buffer, 0, sizeof(buffer));*/
      /*NDL3_L2_pop(host, buffer, sizeof(buffer), NULL);*/
      /*NDL3_L2_push(target, buffer, sizeof(buffer));*/

      /*memset(buffer, 0, sizeof(buffer));*/
      /*NDL3_L2_pop(target, buffer, sizeof(buffer), NULL);*/
      /*NDL3_L2_push(host, buffer, sizeof(buffer));*/
    /*}*/
  /*}*/
  /*for (int i = 0; i < 16; i++) {*/
    /*char * out_msg = NULL;*/
    /*NDL3_recv(target, 1, (void **) &out_msg, NULL);*/
    /*if (out_msg != NULL) {*/
      /*++good;*/
      /*printf("Got message:\n");*/
      /*printf("%s\n", out_msg);*/
    /*}*/
    /*free(out_msg);*/
  /*}*/
  /*printf("Received %d/%d (%02f%%) packets\n",*/
         /*good, total, 100 * (float) good / total);*/
  return 0;
}
