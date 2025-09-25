# StrDupW function

## Description

Duplicates a string.

## Parameters

### `pszSrch`

Type: **PCTSTR**

A pointer to a constant **null**-terminated character string.

## Return value

Type: **PTSTR**

Returns the address of the string that was copied, or **NULL** if the string cannot be copied.

## Remarks

**StrDup** will allocate storage the size of the original string. If storage allocation is successful, the original string is copied to the duplicate string.

This function uses [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) to allocate storage space for the copy of the string. The calling application must free this memory by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function on the pointer returned by the call to **StrDup**.

#### Examples

This simple console application illustrates the use of **StrDup**.

```cpp
#include <windows.h>
#include <shlwapi.h>
#include <stdio.h>

void main(void)
{
   char buffer[] = "This is the buffer text";
   char *newstring;

   // Note: Never use an unbounded %s format specifier in printf.
   printf("Original: %25s\n", buffer);

   newstring = StrDup(buffer);
   if (newstring != NULL)
   {
       printf("Copy:     %25s\n", newstring);
       LocalFree(newstring);
   }
}

OUTPUT:
- - - - - -
Original: This is the buffer text
Copy:     This is the buffer text
```

> [!NOTE]
> The shlwapi.h header defines StrDup as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).