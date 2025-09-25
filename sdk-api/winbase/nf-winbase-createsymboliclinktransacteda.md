# CreateSymbolicLinkTransactedA function

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Creates a symbolic link as a transacted operation.

## Parameters

### `lpSymlinkFileName` [in]

The symbolic link to be created.

### `lpTargetFileName` [in]

The name of the target for the symbolic link to be created.

If *lpTargetFileName* has a device name associated with it, the link is treated as an
absolute link; otherwise, the link is treated as a relative link.

### `dwFlags` [in]

Indicates whether the link target, *lpTargetFileName*, is a directory.

| Value | Meaning |
| --- | --- |
| 0x0 | The link target is a file. |
| **SYMBOLIC_LINK_FLAG_DIRECTORY**<br><br>0x1 | The link target is a directory. |

### `hTransaction` [in]

A handle to the transaction. This handle is returned by the
[CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Symbolic links can either be absolute or relative links. Absolute links are links that specify each portion of
the path name; relative links are determined relative to where relative–link specifiers are
in a specified path. Relative links are specified using the following conventions:

* Dot (. and ..) conventions—for example,
  "..\" resolves the path relative to the parent directory.
* Names with no slashes (\\)—for example, "tmp" resolves
  the path relative to the current directory.
* Root relative—for example, "\Windows\System32" resolves
  to "*current drive*:\Windows\System32".
* Current working directory–relative—for example, if the current
  working directory is C:\Windows\System32, "C:File.txt" resolves to
  "C:\Windows\System32\File.txt".

  **Note** If you specify a current working directory–relative link, it is created as an
  absolute link, due to the way the current working directory is processed based on the user and the
  thread.

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
> The winbase.h header defines CreateSymbolicLinkTransacted as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[Symbolic Links](https://learn.microsoft.com/windows/desktop/FileIO/symbolic-links)

[Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal)