# GopherFindFirstFileA function

## Description

[The **GopherFindFirstFile** function is available for use in the operating systems specified in the Requirements section.]

Uses a Gopher locator and search criteria to create a session with the server and locate the requested documents, binary files, index servers, or directory trees.

## Parameters

### `hConnect` [in]

Handle to a Gopher session returned by
[InternetConnect](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetconnecta).

### `lpszLocator` [in]

Pointer to a **null**-terminated string that contains the name of the item to locate. This can be one of the following:

* Gopher locator returned by a previous call to this function or the
  [InternetFindNextFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetfindnextfilea) function.
* **NULL** pointer or empty string indicating that the topmost information from a Gopher server is being returned.
* Locator created by the
  [GopherCreateLocator](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-gophercreatelocatora) function.

### `lpszSearchString` [in]

Pointer to a buffer that contains the strings to search, if this request is to an index server. Otherwise, this parameter should be **NULL**.

### `lpFindData` [out]

Pointer to a
[GOPHER_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-gopher_find_dataa) structure that receives the information retrieved by this function.

### `dwFlags` [in]

Controls the function behavior. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| INTERNET_FLAG_HYPERLINK | Forces a reload if there was no Expires time and no LastModified time returned from the server when determining whether to reload the item from the network. |
| INTERNET_FLAG_NEED_FILE | Causes a temporary file to be created if the file cannot be cached. |
| INTERNET_FLAG_NO_CACHE_WRITE | Does not add the returned entity to the cache. |
| INTERNET_FLAG_RELOAD | Forces a download of the requested file, object, or directory listing from the origin server, not from the cache. |
| INTERNET_FLAG_RESYNCHRONIZE | Reloads HTTP resources if the resource has been modified since the last time it was downloaded. All FTP and Gopher resources are reloaded. |

### `dwContext` [in]

Pointer to a variable that contains the application-defined value that associates this search with any application data.

## Return value

Returns a valid search handle if successful, or **NULL** otherwise. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) or
[InternetGetLastResponseInfo](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetlastresponseinfoa).

## Remarks

**GopherFindFirstFile** closely resembles the [FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea) function. It creates a connection with a Gopher server, and then returns a single structure containing information about the first Gopher object referenced by the locator string.

After calling
**GopherFindFirstFile** to retrieve the first Gopher object in an enumeration, an application can use the
[InternetFindNextFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetfindnextfilea) function to retrieve subsequent Gopher objects.

After the calling application has finished using the
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinInet/appendix-a-hinternet-handles) handle returned by
**GopherFindFirstFile**, it must be closed using the
[InternetCloseHandle](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetclosehandle) function.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines GopherFindFirstFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)