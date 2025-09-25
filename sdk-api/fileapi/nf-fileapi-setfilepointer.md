# SetFilePointer function

## Description

Moves the file pointer of the specified file.

This function stores the file pointer in two **LONG** values. To work with file pointers
that are larger than a single **LONG** value, it is easier to use the
[SetFilePointerEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfilepointerex) function.

## Parameters

### `hFile` [in]

A handle to the file.

The file handle must be created with the **GENERIC_READ** or
**GENERIC_WRITE** access right. For more information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

### `lDistanceToMove` [in]

The low order 32-bits of a signed value that specifies the number of bytes to move the file pointer.

If *lpDistanceToMoveHigh* is not **NULL**,
*lpDistanceToMoveHigh* and *lDistanceToMove* form a single
64-bit signed value that specifies the distance to move.

If *lpDistanceToMoveHigh* is **NULL**,
*lDistanceToMove* is a 32-bit signed value. A positive value for
*lDistanceToMove* moves the file pointer forward in the file, and a negative value
moves the file pointer back.

### `lpDistanceToMoveHigh` [in, out, optional]

A pointer to the high order 32-bits of the signed 64-bit distance to move.

If you do not need the high order 32-bits, this pointer must be set to **NULL**.

When not **NULL**, this parameter also receives the high order
**DWORD** of the new value of the file pointer. For more information, see the Remarks
section in this topic.

### `dwMoveMethod` [in]

The starting point for the file pointer move.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **FILE_BEGIN**<br><br>0 | The starting point is zero or the beginning of the file. |
| **FILE_CURRENT**<br><br>1 | The starting point is the current value of the file pointer. |
| **FILE_END**<br><br>2 | The starting point is the current end-of-file position. |

## Return value

If the function succeeds and *lpDistanceToMoveHigh* is
**NULL**, the return value is the low-order **DWORD** of the new
file pointer.
**Note** If the function returns a value other than **INVALID_SET_FILE_POINTER**, the call
to **SetFilePointer** has succeeded. You do not need to
call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If function succeeds and *lpDistanceToMoveHigh* is not
**NULL**, the return value is the low-order **DWORD** of the new
file pointer and *lpDistanceToMoveHigh* contains the high order
**DWORD** of the new file pointer.

If the function fails, the return value is **INVALID_SET_FILE_POINTER**. To get
extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If a new file pointer is a negative value, the function fails, the file pointer is not moved, and the code
returned by [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) is
**ERROR_NEGATIVE_SEEK**.

If *lpDistanceToMoveHigh* is **NULL** and the new file position
does not fit in a 32-bit value, the function fails and returns
**INVALID_SET_FILE_POINTER**.

**Note** Because **INVALID_SET_FILE_POINTER** is a valid value for the
low-order **DWORD** of the new file pointer, you must check both the return value of
the function and the error code returned by
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to determine whether or not an error has
occurred. If an error has occurred, the return value of
**SetFilePointer** is
**INVALID_SET_FILE_POINTER** and
**GetLastError** returns a value other than
**NO_ERROR**. For a code example that demonstrates how to check for failure, see the
Remarks section in this topic.

## Remarks

The file pointer that is identified by the value of the *hFile* parameter is not used
for overlapped read and write operations.

The *hFile* parameter must refer to a file stored on a seeking device; for example, a disk volume. Calling the
**SetFilePointer** function with a handle to a non-seeking
device such as a pipe or a communications device is not supported, even though the
**SetFilePointer** function may not return an error. The behavior of the
**SetFilePointer** function in this case is undefined.

**To specify the offset for overlapped operations**

* Use the **Offset** and **OffsetHigh** members of the
  [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure.

**To determine the file type for *hFile***

* Use the [GetFileType](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfiletype) function.

For information about how to determine the position of a file pointer, see
[Positioning a File Pointer](https://learn.microsoft.com/windows/desktop/FileIO/positioning-a-file-pointer).

Be careful when you set a file pointer in a multithreaded application. You must synchronize access to shared
resources. For example, an application with threads that share a file handle, update the file pointer, and read
from the file must protect this sequence by using a critical section object or mutex object. For more information,
see [Critical Section Objects](https://learn.microsoft.com/windows/desktop/Sync/critical-section-objects) and
[Mutex Objects](https://learn.microsoft.com/windows/desktop/Sync/mutex-objects).

If the *hFile* handle is opened with the
**FILE_FLAG_NO_BUFFERING** flag set, an application can move the file pointer only to
sector-aligned positions. A sector-aligned position is a position that is a whole number multiple of the volume
sector size. An application can obtain a volume sector size by calling the
[GetDiskFreeSpace](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespacea) function.

If an application calls **SetFilePointer** with distance
to move values that result in a position not sector-aligned and a handle that is opened with
**FILE_FLAG_NO_BUFFERING**, the function fails, and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_INVALID_PARAMETER**.

It is not an error to set a file pointer to a position beyond the end of the file. The size of the file does
not increase until you call the [SetEndOfFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setendoffile),
[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile), or
[WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex) function. A write operation increases the size
of the file to the file pointer position plus the size of the buffer written, which results in the intervening
bytes being zero initialized.

If the return value is **INVALID_SET_FILE_POINTER** and if
*lpDistanceToMoveHigh* is non-**NULL**, an application must call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to determine whether or not the function has
succeeded or failed. The following code example shows you that scenario.

```cpp
  // Case One: calling the function with lpDistanceToMoveHigh == NULL

  // Try to move hFile file pointer some distance
  DWORD dwPtr = SetFilePointer( hFile,
                                lDistance,
                                NULL,
                                FILE_BEGIN );

  if (dwPtr == INVALID_SET_FILE_POINTER) // Test for failure
   {
    // Obtain the error code.
    DWORD dwError = GetLastError() ;

    // Deal with failure
    // . . .

   } // End of error handler

  //
  // Case Two: calling the function with lpDistanceToMoveHigh != NULL

  // Try to move hFile file pointer a huge distance
  DWORD dwPtrLow = SetFilePointer( hFile,
                                   lDistLow,
                                   &lDistHigh,
                                   FILE_BEGIN );

  // Test for failure
  if ( dwPtrLow == INVALID_SET_FILE_POINTER &&
       GetLastError() != NO_ERROR )
   {
    // Deal with failure
    // . . .

   } // End of error handler

```

Although the parameter *lpDistanceToMoveHigh* is used to manipulate huge files, the
value of the parameter should be set when moving files of any size. If it is set to
**NULL**, then *lDistanceToMove* has a maximum value of
2^31–2, or 2 gigabytes less 2, because all file pointer values are signed values. Therefore,
if there is even a small chance for the file to increase to that size, it is best to treat the file as a huge file
and work with 64-bit file pointers. With
[file compression](https://learn.microsoft.com/windows/desktop/FileIO/file-compression-and-decompression) on the NTFS file
system, and [sparse files](https://learn.microsoft.com/windows/desktop/FileIO/sparse-files), it is possible to have files that
are large even if the underlying volume is not very large.

If *lpDistanceToMoveHigh* is not **NULL**, then
*lpDistanceToMoveHigh* and *lDistanceToMove* form a single 64-bit
signed value. The *lDistanceToMove* parameter is treated as the low-order 32 bits of the
value, and *lpDistanceToMoveHigh* as the high-order 32 bits, which means that
*lpDistanceToMoveHigh* is a sign extension of
*lDistanceToMove*.

To move the file pointer from zero to 2 gigabytes, *lpDistanceToMoveHigh* must be
set to either **NULL** or a sign extension of *lDistanceToMove*. To
move the pointer more than 2 gigabytes, use *lpDistanceToMoveHigh* and
*lDistanceToMove* as a single 64-bit quantity. For example, to move in the range from 2
gigabytes to 4 gigabytes set the contents of *lpDistanceToMoveHigh* to zero, or to
–1 for a negative sign extension of *lDistanceToMove*.

To work with 64-bit file pointers, you can declare a **LONG**, treat it as the upper
half of the 64-bit file pointer, and pass its address in *lpDistanceToMoveHigh*. This
means that you have to treat two different variables as a logical unit, which can cause an error. It is best to
use the **LARGE_INTEGER** structure to create a 64-bit value and pass the two 32-bit
values by using the appropriate elements of the union.

Also, it is best to use a function to hide the interface to
**SetFilePointer**. The following code example shows you that
scenario.

```cpp
__int64 myFileSeek (HANDLE hf, __int64 distance, DWORD MoveMethod)
{
   LARGE_INTEGER li;

   li.QuadPart = distance;

   li.LowPart = SetFilePointer (hf,
                                li.LowPart,
                                &li.HighPart,
                                MoveMethod);

   if (li.LowPart == INVALID_SET_FILE_POINTER && GetLastError()
       != NO_ERROR)
   {
      li.QuadPart = -1;
   }

   return li.QuadPart;
}

```

You can use **SetFilePointer** to determine the length of
a file. To do this, use **FILE_END** for *dwMoveMethod* and seek to
location zero. The file offset returned is the length of the file. However, this practice can have unintended
side effects, for example, failure to save the current file pointer so that the program can return to that
location. It is best to use [GetFileSize](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfilesize) instead.

You can also use the **SetFilePointer** function to query
the current file pointer position. To do this, specify a move method of **FILE_CURRENT** and
a distance of zero.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

#### Examples

For a code example of appending files, see
[Appending One File to Another File](https://learn.microsoft.com/windows/desktop/FileIO/appending-one-file-to-another-file).

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[GetDiskFreeSpace](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespacea)

[GetFileSize](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfilesize)

[GetFileType](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfiletype)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)

[ReadFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfileex)

[SetEndOfFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setendoffile)

[SetFilePointerEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfilepointerex)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)

[WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex)