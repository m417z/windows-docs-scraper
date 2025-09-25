# FindFirstFileTransactedA function

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Searches a directory for a file or subdirectory with a name that matches a specific name as a
transacted operation.

This function is the transacted form of the [FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa) function.

For the most basic version of this function, see [FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea).

## Parameters

### `lpFileName` [in]

The directory or path, and the file name. The file name can include wildcard characters, for example, an asterisk
(*) or a question mark (?).

This parameter should not be **NULL**, an invalid string (for example, an empty string or a string that is missing the terminating null character), or end in a trailing backslash (\\).

If the string ends with a wildcard, period (.), or directory name, the user must have access to the root and
all subdirectories on the path.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

The file must reside on the local computer; otherwise, the function fails and the last error code is set to **ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE**.

### `fInfoLevelId` [in]

The information level of the returned data.

This parameter is one of the
[FINDEX_INFO_LEVELS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-findex_info_levels) enumeration values.

### `lpFindFileData` [out]

A pointer to the [WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure that
receives information about a found file or subdirectory.

### `fSearchOp` [in]

The type of filtering to perform that is different from wildcard matching.

This parameter is one of the [FINDEX_SEARCH_OPS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-findex_search_ops)
enumeration values.

### `lpSearchFilter`

A pointer to the search criteria if the specified *fSearchOp* needs structured search
information.

At this time, none of the supported *fSearchOp* values require extended search
information. Therefore, this pointer must be **NULL**.

### `dwAdditionalFlags` [in]

Specifies additional flags that control the search.

| Value | Meaning |
| --- | --- |
| **FIND_FIRST_EX_CASE_SENSITIVE**<br><br>1 | Searches are case-sensitive. |

### `hTransaction` [in]

A handle to the transaction. This handle is returned by the [CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction) function.

## Return value

If the function succeeds, the return value is a search handle used in a subsequent call to
[FindNextFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilea) or
[FindClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findclose), and the *lpFindFileData* parameter contains information about the first file or directory found.

If the function fails or fails to locate files from the search string in the *lpFileName* parameter, the return value is **INVALID_HANDLE_VALUE** and the contents of *lpFindFileData* are indeterminate. To get extended
error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

The **FindFirstFileTransacted** function opens a search handle and
returns information about the first file that the file system finds with a name that matches the specified pattern. This may or may not be the first file or directory that appears in a directory-listing application (such as the dir command) when given the same file name string pattern. This is because **FindFirstFileTransacted** does no sorting of the search results. For additional information, see [FindNextFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilea).

The following list
identifies some other search characteristics:

* The search is performed strictly on the name of the file, not on any attributes such as a date or a file
  type.
* The search includes the long and short file names.
* An attempt to open
  a search with a trailing backslash always fails.
* Passing an invalid string, **NULL**, or empty string for the *lpFileName* parameter is not a valid use of this function. Results in this case are undefined.

**Note** In rare cases, file information on NTFS file systems may not be current at the time you call this
function. To be assured of getting the current file information, call the
[GetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileinformationbyhandle) function.

If the underlying file system does not support the specified type of filtering, other than directory
filtering, **FindFirstFileTransacted** fails with the error
**ERROR_NOT_SUPPORTED**. The application must use
[FINDEX_SEARCH_OPS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-findex_search_ops) type
**FileExSearchNameMatch** and perform its own filtering.

After the search handle is established, use it in the
[FindNextFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilea) function to search for other
files that match the same pattern with the same filtering that is being performed. When the search handle is not
needed, it should be closed by using the
[FindClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findclose) function.

As stated previously, you cannot use a trailing backslash (\\) in the *lpFileName* input string for
**FindFirstFileTransacted**, therefore it may not be obvious how to search root directories. If you want to see files or get the attributes of a root directory, the following options would apply:

* To examine files in a root directory, you can use "C:\*" and step through the directory by
  using [FindNextFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilea).
* To get the attributes of a root directory, use
  the [GetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesa) function.

**Note** Prepending the string "\\?\" does not allow access to the root directory.

On network shares, you can use an *lpFileName* in the form of the following:
"\\\\server\\service\*". However, you cannot use an *lpFileName* that points to
the share itself; for example, "\\\\server\\service" is not valid.

To examine a directory that is not a root directory, use the path to that directory, without a trailing
backslash. For example, an argument of "C:\\Windows" returns information about the directory
"C:\\Windows", not about a directory or file in "C:\\Windows". To examine the files and directories in "C:\\Windows", use an *lpFileName* of "C:\\Windows\\*".

Be aware that some other thread or process could create or delete a file with this name between the time you query for the result
and the time you act on the information. If this is a potential concern for your application, one possible solution is to use the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function with
**CREATE_NEW** (which fails if the file exists) or **OPEN_EXISTING** (which fails
if the file does not exist).

If you are writing a 32-bit application to list all the files in a directory and the application may be run on
a 64-bit computer, you should call
[Wow64DisableWow64FsRedirection](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-wow64disablewow64fsredirection) before
calling **FindFirstFileTransacted** and call [Wow64RevertWow64FsRedirection](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-wow64revertwow64fsredirection) after the last call to [FindNextFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilea). For more information, see [File System Redirector](https://learn.microsoft.com/windows/desktop/WinProg64/file-system-redirector).

If the path points to a symbolic link, the
[WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) buffer contains information about
the symbolic link, not the target.

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
> The winbase.h header defines FindFirstFileTransacted as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[FindClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findclose)

[FindNextFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilea)

[GetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesa)

[SetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileattributesa)

[Symbolic Links](https://learn.microsoft.com/windows/desktop/FileIO/symbolic-links)

[Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal)

[WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa)