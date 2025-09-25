# InternetWriteFile function

## Description

Writes data to an open Internet file.

## Parameters

### `hFile` [in]

Handle returned from a previous call to
[FtpOpenFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpopenfilea) or an
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinInet/appendix-a-hinternet-handles) handle sent by
[HttpSendRequestEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpsendrequestexa).

### `lpBuffer` [in]

Pointer to a buffer that contains the data to be written to the file.

### `dwNumberOfBytesToWrite` [in]

Number of bytes to be written to the file.

### `lpdwNumberOfBytesWritten` [out]

Pointer to a variable that receives the number of bytes written to the file.
**InternetWriteFile** sets this value to zero before doing any work or error checking.

## Return value

Returns TRUE if the function succeeds, or FALSE otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). An application can also use
[InternetGetLastResponseInfo](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetlastresponseinfoa) when necessary.

## Remarks

When the application is sending data, it must call
[InternetCloseHandle](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetclosehandle) to end the data transfer.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Common Functions](https://learn.microsoft.com/windows/desktop/WinInet/common-functions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)