# NetApiBufferAllocate function

## Description

The
**NetApiBufferAllocate** function allocates memory from the heap. Use this function only when compatibility with the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function is required. Otherwise, use the
[memory management functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions).

## Parameters

### `ByteCount` [in]

Number of bytes to be allocated.

### `Buffer` [out]

Receives a pointer to the allocated buffer.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

No special group membership is required to successfully execute the ApiBuffer functions.

For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

#### Examples

The following code sample demonstrates how to use the network management
[ApiBuffer functions](https://learn.microsoft.com/windows/desktop/NetMgmt/apibuffer-functions).

The sample first calls the
**NetApiBufferAllocate** function to allocate memory and then the
[NetApiBufferSize](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibuffersize) function to retrieve the size of the allocated memory. Following this, the sample calls
[NetApiBufferReallocate](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferreallocate) to change the size of the memory allocation. Finally, the sample calls
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) to free the memory. In each case, the sample prints a message indicating success or failure.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <lm.h>
#include <stdio.h>

#pragma comment(lib, "netapi32.lib")

void PrintError(LPSTR lpszApi, DWORD res);

int main()
{
   PUSER_INFO_10 p;
   DWORD res, dwSize;

   // Call the NetApiBufferAllocate function
   //   to allocate the memory. If successful,
   //   print a message.
   //
   res = NetApiBufferAllocate(1024, (LPVOID *) &p);
   if(res == NERR_Success)
   {
      printf("NetApiBufferAllocate:   Allocated 1024 bytes.\n");

      // Call the NetApiBufferSize function
      //   to retrieve the size of the allocated buffer.
      //   If successful, print the size.
      //
      res = NetApiBufferSize(p, &dwSize);
      if(res == NERR_Success)
      {
         printf("NetApiBufferSize:       Buffer has %u bytes.\n", dwSize);

         // Call the NetApiBufferReallocate function
         //   to change the size of the allocated memory.
         //   If successful, print the new size of the buffer.
         //
         res = NetApiBufferReallocate(p, dwSize * 2, (LPVOID *) &p);
         if(res == NERR_Success)
            printf("NetApiBufferReallocate: Re-Allocated %u bytes.\n", dwSize * 2);
         else
            PrintError("NetApiBufferReallocate", res);

         // Call the NetApiBufferFree function
         //    to free the allocated memory.
         //    If successful, print a message.
         //
         res = NetApiBufferFree(p);
         if(res == NERR_Success)
            printf("Freed Buffer\n");

         else
            PrintError("NetApiBufferFree", res);
      }
      else
         PrintError("NetApiBufferSize", res);
   }
   else
      PrintError("NetApiBufferAllocate", res);
   return 0;
}

void PrintError(LPSTR lpszApi, DWORD res)
{
   printf("%s: Error %u\n", lpszApi, res);
   return;
}

```

## See also

[Api Buffer
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/apibuffer-functions)

[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree)

[NetApiBufferReallocate](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferreallocate)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)