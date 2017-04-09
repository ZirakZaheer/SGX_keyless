#include <stdarg.h>
#include <stdio.h>      /* vsnprintf */

#include "key_operations.h"
#include "key_operations_t.h"  /* print_string */

/* 
 * printf: 
 *   Invokes OCALL to display the enclave buffer to the terminal.
 */
void printf(const char *fmt, ...)
{
    char buf[BUFSIZ] = {'\0'};
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, BUFSIZ, fmt, ap);
    va_end(ap);
    ocall_key_operations_sample(buf);
}

int ecall_key_operations_sample()
{
  printf("IN KEY_OPERATIONS\n");
  return 0;
}

