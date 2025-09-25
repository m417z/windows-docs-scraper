# CommandLineToArgvW function

## Description

Parses a Unicode command line string and returns an array of pointers to the command line arguments, along with a count of such arguments, in a way that is similar to the standard C run-time *argv* and *argc* values.

## Parameters

### `lpCmdLine` [in]

Type: **LPCWSTR**

Pointer to a **null**-terminated Unicode string that contains the full command line. If this parameter is an empty string the function returns the path to the current executable file.

### `pNumArgs` [out]

Type: **int***

Pointer to an **int** that receives the number of array elements returned, similar to *argc*.

## Return value

Type: **LPWSTR***

A pointer to an array of **LPWSTR** values, similar to *argv*.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The address returned by **CommandLineToArgvW** is the address of the first element in an array of **LPWSTR** values; the number of pointers in this array is indicated by *pNumArgs*. Each pointer to a **null**-terminated Unicode string represents an individual argument found on the command line.

**CommandLineToArgvW** allocates a block of contiguous memory for pointers to the argument strings, and for the argument strings themselves; the calling application must free the memory used by the argument list when it is no longer needed. To free the memory, use a single call to the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

For more information about the *argv* and *argc* argument convention, see [Argument Definitions](https://learn.microsoft.com/previous-versions/88w63h9k(v=vs.85)) and [Parsing C Command-Line Arguments](https://learn.microsoft.com/cpp/c-language/parsing-c-command-line-arguments).

The [GetCommandLineW](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-getcommandlinew) function can be used to get a command line string that is suitable for use as the *lpCmdLine* parameter.

This function accepts command lines that contain a program name; the program name can be enclosed in quotation marks or not.

**CommandLineToArgvW** has a special interpretation of backslash characters when they are followed by a quotation mark character ("). This interpretation assumes that any preceding argument is a valid file system path, or else it may behave unpredictably.

This special interpretation controls the "in quotes" mode tracked by the parser. When this mode is off, whitespace terminates the current argument. When on, whitespace is added to the argument like all other characters.

* 2*n* backslashes followed by a quotation mark produce *n* backslashes followed by begin/end quote. This does not become part of the parsed argument, but toggles the "in quotes" mode.
* (2*n*) + 1 backslashes followed by a quotation mark again produce *n* backslashes followed by a quotation mark literal ("). This does not toggle the "in quotes" mode.
* *n* backslashes not followed by a quotation mark simply produce *n* backslashes.

**Important**

**CommandLineToArgvW** treats whitespace outside of quotation marks as argument delimiters. However, if *lpCmdLine* starts with any amount of whitespace, **CommandLineToArgvW** will consider the first argument to be an empty string. Excess whitespace at the end of *lpCmdLine* is ignored.

#### Examples

The following example demonstrates how to parse a Unicode command-line string. The code frees the memory for the argument list at exit.

```cpp
#include <windows.h>
#include <stdio.h>
#include <shellapi.h>

int __cdecl main()
{
   LPWSTR *szArglist;
   int nArgs;
   int i;

   szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
   if( NULL == szArglist )
   {
      wprintf(L"CommandLineToArgvW failed\n");
      return 0;
   }
   else for( i=0; i<nArgs; i++) printf("%d: %ws\n", i, szArglist[i]);

// Free memory allocated for CommandLineToArgvW arguments.

   LocalFree(szArglist);

   return(1);
}
```