# FtpGetFileSize function

## Description

Retrieves the file size of the requested FTP resource.

## Parameters

### `hFile` [in]

Handle returned from a call to
[FtpOpenFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpopenfilea).

### `lpdwFileSizeHigh` [out]

Pointer to the high-order unsigned long integer of the file size of the requested FTP resource.

## Return value

Returns the low-order unsigned long integer of the file size of the requested FTP resource.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[FTP Sessions](https://learn.microsoft.com/windows/desktop/WinInet/ftp-sessions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)