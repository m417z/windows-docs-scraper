# GetFullPathNameTransactedW function

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Retrieves the full path and file name of the specified file as a transacted operation.

To perform this operation without transactions, use the
[GetFullPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfullpathnamea) function.

For more information about file and path names, see
[File Names, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

## Parameters

### `lpFileName` [in]

The name of the file.

This string can use short (the 8.3 form) or long file names. This string can be a share or volume name.

The file must reside on the local computer; otherwise, the function fails and the last error code is set to
**ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE**.

### `nBufferLength` [in]

The size of the buffer to receive the null-terminated string for the drive and path, in
**TCHARs**.

### `lpBuffer` [out]

A pointer to a buffer that receives the null-terminated string for the drive and path.

### `lpFilePart` [out]

A pointer to a buffer that receives the address (in *lpBuffer*) of the final file
name component in the path. Specify **NULL** if you do not need to receive this
information.

If *lpBuffer* points to a directory and not a file,
*lpFilePart* receives 0 (zero).

### `hTransaction` [in]

A handle to the transaction. This handle is returned by the
[CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction) function.

## Return value

If the function succeeds, the return value is the length, in **TCHARs**, of the
string copied to *lpBuffer*, not including the terminating null character.

If the *lpBuffer* buffer is too small to contain the path, the return value is the
size, in **TCHARs**, of the buffer that is required to hold the path and the
terminating null character.

If the function fails for any other reason, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**GetFullPathNameTransacted** merges the name
of the current drive and directory with a specified file name to determine the full path and file name of a
specified file. It also calculates the address of the file name portion of the full path and file name. This
function does not verify that the resulting path and file name are valid, or that they see an existing file on the
associated volume.

Share and volume names are valid input for *lpFileName*. For example, the following
list identities the returned path and file names if test-2 is a remote computer and U: is a network mapped drive:

* If you specify "\\test-2\q$\lh" the path returned is
  "\\test-2\q$\lh"
* If you specify "\\?\UNC\test-2\q$\lh" the path returned is
  "\\?\UNC\test-2\q$\lh"
* If you specify "U:" the path returned is "U:\"

**GetFullPathNameTransacted** does not convert
the specified file name, *lpFileName*. If the specified file name exists, you can use
[GetLongPathNameTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getlongpathnametransacteda),
[GetLongPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getlongpathnamea), or
[GetShortPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getshortpathnamew) to convert to long or short path
names, respectively.

If the return value is greater than the value specified in *nBufferLength*, you can
call the function again with a buffer that is large enough to hold the path. For an example of this case as well
as using zero length buffer for dynamic allocation, see the Example Code section.

**Note** Although the return value in this case is a length that includes the terminating null character, the return
value on success does not include the terminating null character in the count.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB 3.0 does not support TxF.

> [!NOTE]
> The winbase.h header defines GetFullPathNameTransacted as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[GetFullPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfullpathnamea)

[GetLongPathNameTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getlongpathnametransacteda)

[GetShortPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getshortpathnamew)

[GetTempPath](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-gettemppatha)

[SearchPath](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-searchpathw)

[Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal)