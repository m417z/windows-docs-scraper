# SetFileApisToOEM function

## Description

Causes the file I/O functions for the process to use the OEM character set code page. This
function is useful for 8-bit console input and output operations.

## Remarks

The file I/O functions whose code page is set by **SetFileApisToOEM** are those
functions exported by KERNEL32.DLL that accept or return a file name.
**SetFileApisToOEM** sets the code page per process, rather than per thread or per
computer.

The **SetFileApisToOEM** function is complemented by the
[SetFileApisToANSI](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileapistoansi) function, which causes the same
set of file I/O functions to use the ANSI character set code page.

The 8-bit console functions use the OEM code page by default. All other functions use the ANSI code page by
default. This means that strings returned by the console functions may not be processed correctly by other
functions, and vice versa. For example, if the
[FindFirstFileA](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea) function returns a string that contains
certain extended ANSI characters, and the 8-bit console functions are set to use the OEM code page, then the
[WriteConsoleA](https://learn.microsoft.com/windows/console/writeconsole) function will not display the string
properly.

Use the [AreFileApisANSI](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-arefileapisansi) function to determine
which code page the set of file I/O functions is currently using. Use the
[SetConsoleCP](https://learn.microsoft.com/windows/console/setconsolecp) and
[SetConsoleOutputCP](https://learn.microsoft.com/windows/console/setconsoleoutputcp) functions to set the code page
for the 8-bit console functions.

To solve the problem of code page incompatibility, it is best to use Unicode for console applications. Console
applications that use Unicode are much more versatile than those that use 8-bit console functions. Barring that
solution, a console application can call the **SetFileApisToOEM** function to cause
the set of file I/O functions to use OEM character set strings rather than ANSI character set strings. Use the
[SetFileApisToANSI](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileapistoansi) function to set those functions
back to the ANSI code page.

When dealing with command lines, a console application should obtain the command line in Unicode form and then
convert it to OEM form using the relevant character-to-OEM functions. Note also that the array in the
*argv* parameter of the command-line **main** function
contains ANSI character set strings in this case.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[AreFileApisANSI](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-arefileapisansi)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[FindFirstFileA](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea)

[SetConsoleCP](https://learn.microsoft.com/windows/console/setconsolecp)

[SetConsoleOutputCP](https://learn.microsoft.com/windows/console/setconsoleoutputcp)

[SetFileApisToANSI](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileapistoansi)

[WriteConsoleA](https://learn.microsoft.com/windows/console/writeconsole)