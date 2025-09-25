# GetLongPathNameTransactedW function

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Converts the specified path to its long form as a transacted operation.

To perform this operation without a transaction, use the
[GetLongPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getlongpathnamea) function.

For more information about file and path names, see
[Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

## Parameters

### `lpszShortPath` [in]

The path to be converted.

The path must reside on the local computer; otherwise, the function fails and the last error code is set to
**ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE**.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpszLongPath` [out]

A pointer to the buffer to receive the long path.

You can use the same buffer you used for the *lpszShortPath* parameter.

### `cchBuffer` [in]

The size of the buffer *lpszLongPath* points to, in
**TCHAR**s.

### `hTransaction` [in]

A handle to the transaction. This handle is returned by the
[CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction) function.

## Return value

If the function succeeds, the return value is the length, in **TCHAR**s, of the
string copied to *lpszLongPath*, not including the terminating null character.

If the *lpBuffer* buffer is too small to contain the path, the return value is the
size, in **TCHAR**s, of the buffer that is required to hold the path and the
terminating null character.

If the function fails for any other reason, such as if the file does not exist, the return value is zero. To
get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

On many file systems, a short file name contains a tilde (~) character. However, not all file systems follow
this convention. Therefore, do not assume that you can skip calling
**GetLongPathNameTransacted** if the path does not
contain a tilde (~) character.

If a long path is not found, this function returns the name specified in the
*lpszShortPath* parameter in the *lpszLongPath* parameter.

If the return value is greater than the value specified in *cchBuffer*, you can call
the function again with a buffer that is large enough to hold the path. For an example of this case, see the
Example Code section for [GetFullPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfullpathnamea).

**Note** Although the return value in this case is a length that includes the terminating null character, the return
value on success does not include the terminating null character in the count.

It is possible to have access to a file or directory but not have access to some of the parent directories of
that file or directory. As a result,
**GetLongPathNameTransacted** may fail when it is
unable to query the parent directory of a path component to determine the long name for that component. This check
can be skipped for directory components that have file extensions longer than 3 characters, or total lengths
longer than 12 characters. For more information, see the
[Short vs. Long Names](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file) section of
[Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

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
> The winbase.h header defines GetLongPathNameTransacted as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[GetFullPathNameTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfullpathnametransacteda)

[GetShortPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getshortpathnamew)

[Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file)

[Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal)