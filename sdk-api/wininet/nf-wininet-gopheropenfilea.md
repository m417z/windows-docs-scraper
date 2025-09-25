# GopherOpenFileA function

## Description

[The **GopherOpenFile** function is available for use in the operating systems specified in the Requirements section.]

Begins reading a Gopher data file from a Gopher server.

## Parameters

### `hConnect` [in]

Handle to a Gopher session returned by
[InternetConnect](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetconnecta).

### `lpszLocator` [in]

Pointer to a **null**-terminated string that specifies the file to be opened. Generally, this locator is returned from a call to
[GopherFindFirstFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-gopherfindfirstfilea) or
[InternetFindNextFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetfindnextfilea). Because the Gopher protocol has no concept of a current directory, the locator is always fully qualified.

### `lpszView` [in]

Pointer to a **null**-terminated string that describes the view to open if several views of the file exist on the server. If
*lpszView* is **NULL**, the function uses the default file view.

### `dwFlags` [in]

Conditions under which subsequent transfers occur. This parameter can be any of the following values.

| Value | Meaning |
| --- | --- |
| INTERNET_FLAG_HYPERLINK | Forces a reload if there was no Expires time and no LastModified time returned from the server when determining whether to reload the item from the network. |
| INTERNET_FLAG_NEED_FILE | Causes a temporary file to be created if the file cannot be cached. |
| INTERNET_FLAG_NO_CACHE_WRITE | Does not add the returned entity to the cache. |
| INTERNET_FLAG_RELOAD | Forces a download of the requested file, object, or directory listing from the origin server, not from the cache. |
| INTERNET_FLAG_RESYNCHRONIZE | Reloads HTTP resources if the resource has been modified since the last time it was downloaded. All FTP and Gopher resources are reloaded. |

### `dwContext` [in]

Pointer to a variable that contains an application-defined value that associates this operation with any application data.

## Return value

Returns a handle if successful, or **NULL** if the file cannot be opened. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) or
[InternetGetLastResponseInfo](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetlastresponseinfoa).

## Remarks

**GopherOpenFile** opens a file at a Gopher server. Because a file cannot actually be opened or locked at a server, this function simply associates location information with a handle that an application can use for file-based operations such as
[InternetReadFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetreadfile) or
[GopherGetAttribute](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-gophergetattributea).

After the calling application has finished using the
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinInet/appendix-a-hinternet-handles) handle returned by
**GopherOpenFile**, it must be closed using the
[InternetCloseHandle](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetclosehandle) function.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines GopherOpenFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

 [WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)