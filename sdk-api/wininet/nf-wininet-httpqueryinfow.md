# HttpQueryInfoW function

## Description

Retrieves header information associated with an HTTP request.

## Parameters

### `hRequest` [in]

A handle returned by
a call to the [HttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpopenrequesta) or
[InternetOpenUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetopenurla) function.

### `dwInfoLevel` [in]

A combination of an attribute to be retrieved and flags that modify the request. For a list of possible attribute and modifier values, see
[Query Info Flags](https://learn.microsoft.com/windows/desktop/WinInet/query-info-flags).

### `lpBuffer` [in, out]

A pointer to a buffer to receive the requested information. This parameter must not be **NULL**.

### `lpdwBufferLength` [in, out]

A pointer to a variable that contains, on entry, the size in bytes of the buffer pointed to by *lpvBuffer*.

When the function returns successfully, this variable contains the number of bytes of information written to the buffer. In the case of a string, the byte count does not include the string's terminating **null** character.

When the function
fails with an extended error code of **ERROR_INSUFFICIENT_BUFFER**, the variable pointed to by *lpdwBufferLength* contains on exit the size, in bytes, of a buffer large enough to receive the requested information. The calling application can then allocate a buffer of this size or larger, and call the function again.

### `lpdwIndex` [in, out]

A pointer to a zero-based header index used to enumerate multiple headers with the same name. When calling the function, this parameter is the index of the specified header to return. When the function returns, this parameter is the index of the next header. If the next index cannot be found, **ERROR_HTTP_HEADER_NOT_FOUND** is returned.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

You can retrieve the following types of data from
**HttpQueryInfo**:

* Strings (default)
* [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) (for dates)
* **DWORD** (for **STATUS_CODE**, **CONTENT_LENGTH**, and so on, if **HTTP_QUERY_FLAG_NUMBER** has been used)

If your application requires that the data be returned as a data type other than a string, you must include the appropriate modifier with the attribute passed to
*dwInfoLevel*.

The **HttpQueryInfo** function is available in Microsoft Internet Explorer 3.0 for ISO-8859-1 characters (**HttpQueryInfoA** function) and in Internet Explorer 4.0 or later for ISO-8859-1 characters (**HttpQueryInfoA** function) and for ISO-8859-1 characters converted to UTF-16LE characters.(the **HttpQueryInfoW** function).

**Note** The **HttpQueryInfoA** function represents headers as ISO-8859-1 characters not ANSI characters. The **HttpQueryInfoW** function represents headers as ISO-8859-1 characters converted to UTF-16LE characters. As a result, it is never safe to use the **HttpQueryInfoW** function when the headers can contain non-ASCII characters.
Instead, an application can use the [MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) and [WideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-widechartomultibyte) functions with a *Codepage* parameter set to 28591 to map between ANSI characters and UTF-16LE characters.

See [Retrieving HTTP Headers](https://learn.microsoft.com/windows/desktop/WinInet/retrieving-http-headers) for an example code calling the **HttpQueryInfo** function.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines HttpQueryInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[HTTP Sessions](https://learn.microsoft.com/windows/desktop/WinInet/http-sessions)

[Retrieving HTTP Headers](https://learn.microsoft.com/windows/desktop/WinInet/retrieving-http-headers)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)