# AreFileApisANSI function

## Description

Determines whether the file I/O functions are using the ANSI or OEM character set code
page. This function is useful for 8-bit console input and output operations.

## Return value

If the set of file I/O functions is using the ANSI code page, the return value is nonzero.

If the set of file I/O functions is using the OEM code page, the return value is zero.

## Remarks

The [SetFileApisToOEM](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileapistooem) function causes a set of file
I/O functions to use the OEM code page. The
[SetFileApisToANSI](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileapistoansi) function causes the same set of file
I/O functions to use the ANSI code page. Use the **AreFileApisANSI** function to
determine which code page the set of file I/O functions is currently using. For a discussion of these functions'
usage, please see the Remarks sections of
**SetFileApisToOEM** and
**SetFileApisToANSI**.

The file I/O functions whose code page is ascertained by **AreFileApisANSI** are
those functions exported by KERNEL32.DLL that accept or return a file name.

The functions [SetFileApisToOEM](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileapistooem) and
[SetFileApisToANSI](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileapistoansi) set the code page for a process, so
**AreFileApisANSI** returns a value indicating the code page of an entire
process.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[SetFileApisToANSI](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileapistoansi)

[SetFileApisToOEM](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileapistooem)