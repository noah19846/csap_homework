#include <string.h>
#include <stdlib.h>

void *calloc(size_t nmemb, size_t size)
{
   if (nmemb == 0 || size == 0)
      return NULL;

   size_t total = nmemb * size;

   if (total / nmemb != size)
      return NULL; // overflow

   void *ptr = malloc(total);

   if (ptr != NULL)
   {
      memset(ptr, 0, total);
   }

   return ptr;
}
