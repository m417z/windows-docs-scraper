# GetFullPathNameA function

## Description

Retrieves the full path and file name of the specified file.

To perform this operation as a transacted operation, use the
[GetFullPathNameTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfullpathnametransacteda) function.

For more information about file and path names, see
[File Names, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

**Note** See the Remarks section for discussion of
the use of relative paths with the **GetFullPathName** function
in multithreaded applications or shared library code.

## Parameters

### `lpFileName` [in]

The name of the file.

This parameter can be a short (the 8.3 form) or long file name. This string can also be a share or volume
name.

### `nBufferLength` [in]

The size of the buffer to receive the null-terminated string for the drive and path, in
**TCHARs**.

### `lpBuffer` [out]

A pointer to a buffer that receives the null-terminated string for the drive and path.

### `lpFilePart` [out]

A pointer to a buffer that receives the address (within *lpBuffer*) of the final
file name component in the path.

This parameter can be **NULL**.

If *lpBuffer*
refers to a directory and not a file, *lpFilePart* receives zero.

## Return value

If the function succeeds, the return value is the length, in **TCHARs**, of the
string copied to *lpBuffer*, not including the terminating null character.

If the *lpBuffer* buffer is too small to contain the path, the return value is the
size, in **TCHARs**, of the buffer that is required to hold the path and the
terminating null character.

If the function fails for any other reason, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**GetFullPathName** merges the name of the current drive
and directory with a specified file name to determine the full path and file name of a specified file. It also
calculates the address of the file name portion of the full path and file name.

This function does not verify that the resulting path and file name are valid, or that they see an existing
file on the associated volume.

Note that the *lpFilePart* parameter does not
require string buffer space, but only enough for a single address. This is because it simply returns an address
within the buffer that already exists for *lpBuffer*.

Share and volume names are
valid input for *lpFileName*. For example, the following list identities the returned path
and file names if test-2 is a remote computer and U: is a network mapped drive whose current directory is the root of the volume:

* If you specify "\\test-2\q$\lh" the path returned is
  "\\test-2\q$\lh"
* If you specify "\\?\UNC\test-2\q$\lh" the path returned is
  "\\?\UNC\test-2\q$\lh"
* If you specify "U:" the path returned is the current directory on the
  "U:\" drive

**GetFullPathName** does not convert the specified file
name, *lpFileName*. If the specified file name exists, you can use
[GetLongPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getlongpathnamea) or
[GetShortPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getshortpathnamew) to convert to long or short path
names, respectively.

If the return value is greater than or equal to the value specified in
*nBufferLength*, you can call the function again with a buffer that is large enough to
hold the path. For an example of this case in addition to using zero-length buffer for dynamic allocation, see the
Example Code section.

**Note** Although the return value in this case is a length that includes the terminating null character, the return
value on success does not include the terminating null character in the count.

Relative paths passed to the **GetFullPathName** function are
interpreted as relative to the process's current directory.
The current directory state written by the
[SetCurrentDirectory](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcurrentdirectory)
function is global to the process and can be changed by any thread at any time.
Applications should be aware that
consecutive calls to the **GetFullPathName** function with a relative path
may produce different results if the current directory changes between the two calls.

To avoid problems caused by inconsistent results,
multithreaded applications and shared library code should avoid using relative paths.
If a relative path is received, it should be consumed exactly once,
either by passing the relative path directly to a function like **CreateFile**,
or by converting it to an absolute path and using the absolute path
from that point forward.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

#### Examples

The following C++ example shows a basic use of
**GetFullPathName**,
[GetLongPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getlongpathnamea), and
[GetShortPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getshortpathnamew). For another example using dynamic
allocation, see [GetShortPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getshortpathnamew).

```cpp
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#define BUFSIZE 4096
#define LONG_DIR_NAME TEXT("c:\\longdirectoryname")

void _tmain(int argc, TCHAR *argv[])
{
    DWORD  retval=0;
    BOOL   success;
    TCHAR  buffer[BUFSIZE]=TEXT("");
    TCHAR  buf[BUFSIZE]=TEXT("");
    TCHAR** lppPart={NULL};

   if( argc != 2 )
   {
      _tprintf(TEXT("Usage: %s [file]\n"), argv[0]);
      return;
   }

// Retrieve the full path name for a file.
// The file does not need to exist.

    retval = GetFullPathName(argv[1],
                 BUFSIZE,
                 buffer,
                 lppPart);

    if (retval == 0)
    {
        // Handle an error condition.
        printf ("GetFullPathName failed (%d)\n", GetLastError());
        return;
    }
    else
    {
        _tprintf(TEXT("The full path name is:  %s\n"), buffer);
        if (lppPart != NULL && *lppPart != 0)
        {
            _tprintf(TEXT("The final component in the path name is:  %s\n"), *lppPart);
        }
    }

// Create a long directory name for use with the next two examples.

    success = CreateDirectory(LONG_DIR_NAME,
                              NULL);

    if (!success)
    {
        // Handle an error condition.
        printf ("CreateDirectory failed (%d)\n", GetLastError());
        return;
    }

// Retrieve the short path name.

    retval = GetShortPathName(LONG_DIR_NAME,
                  buf,
                  BUFSIZE);

    if (retval == 0)
    {
        // Handle an error condition.
         printf ("GetShortPathName failed (%d)\n", GetLastError());
         return;
    }
    else _tprintf(TEXT("The short name for %s is %s\n"),
                  LONG_DIR_NAME, buf);

// Retrieve the long path name.

    retval = GetLongPathName(buf,
              buffer,
              BUFSIZE);

    if (retval == 0)
    {
        // Handle an error condition.
         printf ("GetLongPathName failed (%d)\n", GetLastError());
         return;
    }
    else _tprintf(TEXT("The long name for %s is %s\n"), buf, buffer);

// Clean up the directory.

    success = RemoveDirectory(LONG_DIR_NAME);
    if (!success)
    {
        // Handle an error condition.
        printf ("RemoveDirectory failed (%d)\n", GetLastError());
        return;
    }
}

```

> [!NOTE]
> The fileapi.h header defines GetFullPathName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[GetFullPathNameTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfullpathnametransacteda)

[GetLongPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getlongpathnamea)

[GetShortPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getshortpathnamew)

[GetTempPath](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-gettemppatha)

[SearchPath](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-searchpathw)