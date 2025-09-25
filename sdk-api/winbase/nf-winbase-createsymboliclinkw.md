# CreateSymbolicLinkW function

## Description

Creates a symbolic link.

To perform this operation as a transacted operation, use the
[CreateSymbolicLinkTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createsymboliclinktransacteda) function.

## Parameters

### `lpSymlinkFileName` [in]

The symbolic link to be created.

This parameter may include the path.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpTargetFileName` [in]

The name of the target for the symbolic link to be created.

 If *lpTargetFileName* has a device name associated with it, the link is treated as
an absolute link; otherwise, the link is treated as a relative link.

This parameter may include the path.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `dwFlags` [in]

Indicates whether the link target, *lpTargetFileName*, is a directory.

| Value | Meaning |
| --- | --- |
| 0x0 | The link target is a file. |
| **SYMBOLIC_LINK_FLAG_DIRECTORY**<br><br>0x1 | The link target is a directory. |
| **SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE**<br><br>0x2 | Specify this flag to allow creation of symbolic links when the process is not elevated. [Developer Mode](https://learn.microsoft.com/windows/uwp/get-started/enable-your-device-for-development) must first be enabled on the machine before this option will function. |

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

To remove a symbolic link, delete the file (using
[DeleteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-deletefilea) or similar APIs) or remove the directory (using
[RemoveDirectory](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-removedirectorya) or similar APIs) depending on what type
of symbolic link is used.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | Yes |

CsvFs does not support soft link or any other reparse points.

> [!NOTE]
> The winbase.h header defines CreateSymbolicLink as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateSymbolicLinkTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createsymboliclinktransacteda)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[Symbolic Links](https://learn.microsoft.com/windows/desktop/FileIO/symbolic-links)