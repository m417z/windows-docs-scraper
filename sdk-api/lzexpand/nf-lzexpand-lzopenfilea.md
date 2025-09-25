# LZOpenFileA function

## Description

Creates, opens, reopens, or deletes the specified file.

## Parameters

### `lpFileName` [in]

The name of the file.

### `lpReOpenBuf` [out]

A pointer to the [OFSTRUCT](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-ofstruct) structure that is to receive
information about the file when the file is first opened. The structure can be used in subsequent calls to the
**LZOpenFile** function to see the open file.

The **szPathName** member of this structure contains characters from the original
equipment manufacturer (OEM) character set.

### `wStyle` [in]

The action to be taken. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **OF_CANCEL**<br><br>0x0800 | Ignored. Provided only for compatibility with 16-bit Windows. Use the **OF_PROMPT** style to display a dialog box containing a **Cancel** button. |
| **OF_CREATE**<br><br>0x1000 | Directs **LZOpenFile** to create a new file. If the file already exists, it is truncated to zero length. |
| **OF_DELETE**<br><br>0x0200 | Deletes the file. |
| **OF_EXIST**<br><br>0x4000 | Opens the file and then closes it to test for a file's existence. |
| **OF_PARSE**<br><br>0x0100 | Fills the [OFSTRUCT](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-ofstruct) structure but carries out no other action. |
| **OF_PROMPT**<br><br>0x2000 | Displays a dialog box if the requested file does not exist. The dialog box informs the user that the system cannot find the file, and it contains **Retry** and **Cancel** buttons. Clicking the **Cancel** button directs **LZOpenFile** to return a file not found error message. |
| **OF_READ**<br><br>0x0000 | Opens the file for reading only. |
| **OF_READWRITE**<br><br>0x0002 | Opens the file for reading and writing. |
| **OF_REOPEN**<br><br>0x8000 | Opens the file using information in the reopen buffer. |
| **OF_SHARE_DENY_NONE**<br><br>0x0040 | Opens the file without denying other processes read or write access to the file. **LZOpenFile** fails if the file has been opened in compatibility mode by any other process. |
| **OF_SHARE_DENY_READ**<br><br>0x0030 | Opens the file and denies other processes read access to the file. **LZOpenFile** fails if the file has been opened in compatibility mode or has been opened for read access by any other process. |
| **OF_SHARE_DENY_WRITE**<br><br>0x0020 | Opens the file and denies other processes write access to the file. **LZOpenFile** fails if the file has been opened in compatibility mode or has been opened for write access by any other process. |
| **OF_SHARE_EXCLUSIVE**<br><br>0x0010 | Opens the file in exclusive mode, denying other processes both read and write access to the file. **LZOpenFile** fails if the file has been opened in any other mode for read or write access, even by the current process. |
| **OF_WRITE**<br><br>0x0001 | Opens the file for writing only. |

## Return value

If the function succeeds and the value specified by the *wStyle* parameter is not
**OF_READ**, the return value is a handle identifying the file. If the file is compressed
and opened with *wStyle* set to **OF_READ**, the return value is
a special file handle.

If the function fails, the return value is an **LZERROR_*** code. These codes have
values less than zero. There is no extended error information for this function; do not call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** **LZOpenFile** calls neither
[SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) nor
[SetLastErrorEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setlasterrorex); thus, its failure does not affect a
thread's last-error code.

The following is the list of the error codes that **LZOpenFile** can return upon
failure.

| Return code/value | Description |
| --- | --- |
| **LZERROR_BADINHANDLE**<br><br>-1 | The handle identifying the source file is not valid. The file cannot be read. |
| **LZERROR_GLOBALLOC**<br><br>-5 | The maximum number of open compressed files has been exceeded or local memory cannot be allocated. |

## Remarks

If the *wStyle* parameter is the **OF_READ** flag (or
**OF_READ** and any of the **OF_SHARE_*** flags) and the file is
compressed, **LZOpenFile** calls the
[LZInit](https://learn.microsoft.com/windows/desktop/api/lzexpand/nf-lzexpand-lzinit) function, which performs the required initialization for
the decompression operations.

The handle this function returns is compatible only with the functions in Lz32.dll; it should not be used
for other file operations.

If **LZOpenFile** is unable to open the file specified by
*lpFileName*, on some versions of Windows it attempts to open a file with almost the same
file name, except the last character is replaced with an underscore ("_"). Thus, if an attempt to
open "MyProgram.exe" fails, **LZOpenFile** tries to open
"MyProgram.ex_". Installation packages often substitute the underscore for the last letter of a
file name extension to indicate that the file is compressed. For example, "MyProgram.exe"
compressed might be named "MyProgram.ex_". To determine the name of the file opened (if any),
examine the **szPathName** member of the
[OFSTRUCT](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-ofstruct) structure in the
*lpReOpenBuf* parameter.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

CsvFs will do redirected IO for compressed files.

> [!NOTE]
> The lzexpand.h header defines LZOpenFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Compression and Decompression](https://learn.microsoft.com/windows/desktop/FileIO/file-compression-and-decompression)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[LZClose](https://learn.microsoft.com/windows/desktop/api/lzexpand/nf-lzexpand-lzclose)

[LZInit](https://learn.microsoft.com/windows/desktop/api/lzexpand/nf-lzexpand-lzinit)

[LZRead](https://learn.microsoft.com/windows/desktop/api/lzexpand/nf-lzexpand-lzread)

[OFSTRUCT](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-ofstruct)