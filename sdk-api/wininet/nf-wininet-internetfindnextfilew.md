# InternetFindNextFileW function

## Description

Continues a file search started as a result of a previous call to
[FtpFindFirstFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpfindfirstfilea).

**Windows XP and Windows Server 2003 R2 and earlier:** Or continues a file search as a result of a previous call to [GopherFindFirstFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-gopherfindfirstfilea).

## Parameters

### `hFind` [in]

Handle returned from either
[FtpFindFirstFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpfindfirstfilea) or
[InternetOpenUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetopenurla) (directories only).

**Windows XP and Windows Server 2003 R2 and earlier:** Also a handle returned from [GopherFindFirstFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-gopherfindfirstfilea).

### `lpvFindData` [out]

Pointer to the buffer that receives information about the file or directory. The format of the information placed in the buffer depends on the protocol in use. The FTP protocol returns a
[WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure.

**Windows XP and Windows Server 2003 R2 and earlier:** The Gopher protocol returns a
[GOPHER_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-gopher_find_dataa) structure.

## Return value

Returns **TRUE** if the function succeeds, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If the function finds no matching files,
**GetLastError** returns **ERROR_NO_MORE_FILES**.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetFindNextFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Enabling Internet Functionality](https://learn.microsoft.com/windows/desktop/WinInet/enabling-internet-functionality)

 [WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)