# InternetReadFile function

## Description

Reads data from a handle opened by the
[InternetOpenUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetopenurla),
[FtpOpenFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpopenfilea),
or
[HttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpopenrequesta) function.

## Parameters

### `hFile` [in]

Handle returned from a previous call to
[InternetOpenUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetopenurla),
[FtpOpenFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpopenfilea),
or
[HttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpopenrequesta).

### `lpBuffer` [out]

Pointer to a buffer that receives the data.

### `dwNumberOfBytesToRead` [in]

Number of bytes to be read.

### `lpdwNumberOfBytesRead` [out]

Pointer to a variable that receives the number of bytes read.
**InternetReadFile** sets this value to zero before doing any work or error checking.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). An application can also use
[InternetGetLastResponseInfo](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetlastresponseinfoa) when necessary.

## Remarks

**InternetReadFile** operates much like the base
[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) function, with a few exceptions. Typically,
**InternetReadFile** retrieves data from an
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinInet/appendix-a-hinternet-handles) handle as a sequential stream of bytes. The amount of data to be read for each call to
**InternetReadFile** is specified by the
*dwNumberOfBytesToRead* parameter and the data is returned in the
*lpBuffer* parameter. A normal read retrieves the specified
*dwNumberOfBytesToRead* for each call to
**InternetReadFile** until the end of the file is reached. To ensure all data is retrieved, an application must continue to call the
**InternetReadFile** function until the function returns **TRUE** and the
*lpdwNumberOfBytesRead* parameter equals zero. This is especially important if the requested data is written to the cache, because otherwise the cache will not be properly updated and the file downloaded will not be committed to the cache. Note that caching happens automatically unless the original request to open the data stream set the **INTERNET_FLAG_NO_CACHE_WRITE** flag.

When an application retrieves a handle using
[InternetOpenUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetopenurla), WinINet attempts to make all data look like a file download, in an effort to make reading from the Internet easier for the application. For some types of information, such as FTP file directory listings, it converts the data to be returned by
**InternetReadFile** to an HTML stream. It does this on a line-by-line basis. For example, it can convert an FTP directory listing to a line of HTML and return this HTML to the application.

WinINet attempts to write the HTML to the
*lpBuffer* buffer a line at a time. If the application's buffer is too small to fit at least one line of generated HTML, the error code
**ERROR_INSUFFICIENT_BUFFER** is returned as an indication to the application that it needs a larger buffer. Also, converted lines might not completely fill the buffer, so
**InternetReadFile** can return with less data in
*lpBuffer* than requested. Subsequent reads will retrieve all the converted HTML. The application must again check that all data is retrieved as described previously.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

When running asynchronously, if a call to **InternetReadFile** does not result in a completed transaction, it will return *FALSE* and a subsequent call to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return *ERROR_IO_PENDING*. When the transaction is completed the [InternetStatusCallback](https://learn.microsoft.com/windows/desktop/api/wininet/nc-wininet-internet_status_callback) specified in a previous call to [InternetSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetstatuscallback) will be called with *INTERNET_STATUS_REQUEST_COMPLETE*.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Common Functions](https://learn.microsoft.com/windows/desktop/WinInet/common-functions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)