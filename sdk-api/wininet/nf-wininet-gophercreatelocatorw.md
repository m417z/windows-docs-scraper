# GopherCreateLocatorW function

## Description

[The **GopherCreateLocator** function is available for use in the operating systems specified in the Requirements section.]

Creates a Gopher or Gopher+ locator string from the selector string's component parts.

## Parameters

### `lpszHost` [in]

Pointer to a **null**-terminated string that contains the name of the host, or a dotted-decimal IP address (such as 198.105.232.1).

### `nServerPort` [in]

Port number on which the Gopher server at
*lpszHost* lives, in host byte order. If
*nServerPort* is **INTERNET_INVALID_PORT_NUMBER**, the default Gopher port is used.

### `lpszDisplayString` [in]

Pointer to a **null**-terminated string that contains the Gopher document or directory to be displayed. If this parameter is **NULL**, the function returns the default directory for the Gopher server.

### `lpszSelectorString` [in]

Pointer to the selector string to send to the Gopher server in order to retrieve information. This parameter can be **NULL**.

### `dwGopherType` [in]

Determines whether
*lpszSelectorString* refers to a directory or document, and whether the request is Gopher+ or Gopher. The default value, GOPHER_TYPE_DIRECTORY, is used if the value of
*dwGopherType* is zero. This can be one of the
[gopher type values](https://learn.microsoft.com/windows/desktop/WinInet/gopher-type-values).

### `lpszLocator` [out]

Pointer to a buffer that receives the locator string. If
*lpszLocator* is **NULL**,
*lpdwBufferLength* receives the necessary buffer length, but the function performs no other processing.

### `lpdwBufferLength` [in, out]

Pointer to a variable that contains the length of the
*lpszLocator* buffer, in characters. When the function returns, this parameter receives the number of characters written to the
buffer. If
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_INSUFFICIENT_BUFFER**, this parameter receives the number of characters required.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) or
[InternetGetLastResponseInfo](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetlastresponseinfoa).

## Remarks

To retrieve information from a Gopher server, an application must first get a Gopher "locator" from the Gopher server.

The locator, which the application should treat as an opaque token, is normally used for calls to the
[GopherFindFirstFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-gopherfindfirstfilea) function to retrieve a specific piece of information.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines GopherCreateLocator as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

 [WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)