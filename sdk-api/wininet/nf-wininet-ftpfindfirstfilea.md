# FtpFindFirstFileA function

## Description

Searches the specified directory of the given FTP session. File and directory entries are returned to the application in the
[WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure.

## Parameters

### `hConnect` [in]

Handle to an FTP session returned from
[InternetConnect](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetconnecta).

### `lpszSearchFile` [in]

Pointer to a **null**-terminated string that specifies a valid directory path or file name for the FTP server's file system. The string can contain wildcards, but no blank spaces are allowed. If the value of
*lpszSearchFile* is **NULL** or if it is an empty string, the function finds the first file in the current directory on the server.

### `lpFindFileData` [out]

Pointer to a
[WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure that receives information about the found file or directory.

### `dwFlags` [in]

Controls the behavior of this function. This parameter can be a combination of the following values.

INTERNET_FLAG_HYPERLINK

INTERNET_FLAG_NEED_FILE

INTERNET_FLAG_NO_CACHE_WRITE

INTERNET_FLAG_RELOAD

INTERNET_FLAG_RESYNCHRONIZE

### `dwContext` [in]

Pointer to a variable that specifies the application-defined value that associates this search with any application data. This parameter is used only if the application has already called
[InternetSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetstatuscallback) to set up a status callback function.

## Return value

Returns a valid handle for the request if the directory enumeration was started successfully, or returns **NULL** otherwise. To get a specific error message, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If **GetLastError** returns ERROR_INTERNET_EXTENDED_ERROR, as in the case where the function finds no matching files, call the
[InternetGetLastResponseInfo](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetlastresponseinfoa) function to retrieve the extended error text, as documented in [Handling Errors](https://learn.microsoft.com/windows/desktop/WinInet/appendix-c-handling-errors).

## Remarks

For
**FtpFindFirstFile**, file times returned in the
[WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure are in the local time zone, not in a coordinated universal time (UTC) format.

**FtpFindFirstFile** is similar to the [FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea) function. Note, however, that only one
**FtpFindFirstFile** can occur at a time within a given FTP session. The enumerations, therefore, are correlated with the FTP session handle. This is because the FTP protocol allows only a single directory enumeration per session.

After calling
**FtpFindFirstFile** and until calling
[InternetCloseHandle](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetclosehandle), the application cannot call
**FtpFindFirstFile** again on the given FTP session handle. If a call is made to
**FtpFindFirstFile** on that handle, the function fails with
[ERROR_FTP_TRANSFER_IN_PROGRESS](https://learn.microsoft.com/windows/desktop/WinInet/wininet-errors). After the calling application has finished using the
**HINTERNET** handle returned by
**FtpFindFirstFile**, it must be closed using the
[InternetCloseHandle](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetclosehandle) function.

After beginning a directory enumeration with
**FtpFindFirstFile**, the
[InternetFindNextFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetfindnextfilea) function can be used to continue the enumeration.

Because the FTP protocol provides no standard means of enumerating, some of the common information about files, such as file creation date and time, is not always available or correct. When this happens,
**FtpFindFirstFile** and
[InternetFindNextFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetfindnextfilea) fill in unavailable information with a best guess based on available information. For example, creation and last access dates are often the same as the file's modification date.

The application cannot call
**FtpFindFirstFile** between calls to
[FtpOpenFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpopenfilea) and
[InternetCloseHandle](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetclosehandle).

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines FtpFindFirstFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FTP Sessions](https://learn.microsoft.com/windows/desktop/WinInet/ftp-sessions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)