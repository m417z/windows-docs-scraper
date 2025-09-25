# GopherGetAttributeA function

## Description

[The **GopherGetAttribute** function is available for use in the operating systems specified in the Requirements section.]

Retrieves the specific attribute information from the server.

## Parameters

### `hConnect` [in]

Handle to a Gopher session returned by
[InternetConnect](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetconnecta).

### `lpszLocator` [in]

Pointer to a **null**-terminated string that identifies the item at the Gopher server on which to return attribute information.

### `lpszAttributeName` [in]

Pointer to a space-delimited string specifying the names of attributes to return. If
*lpszAttributeName* is **NULL**,
**GopherGetAttribute** returns information about all attributes.

### `lpBuffer` [out]

Pointer to an application-defined buffer from which attribute information is retrieved.

### `dwBufferLength` [in]

Size of the
*lpBuffer* buffer, in **TCHARs**.

### `lpdwCharactersReturned` [out]

Pointer to a variable that contains the number of characters read into the
*lpBuffer* buffer.

### `lpfnEnumerator` [in]

Pointer to a [GopherAttributeEnumerator](https://learn.microsoft.com/windows/desktop/api/wininet/nc-wininet-gopher_attribute_enumerator) callback function that enumerates each attribute of the locator. This parameter is optional. If it is **NULL**, all Gopher attribute information is placed into
*lpBuffer*. If
*lpfnEnumerator* is specified, the callback function is called once for each attribute of the object.

The callback function receives the address of a single
[GOPHER_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-gopher_attribute_type) structure with each call. The enumeration callback function allows the application to avoid having to parse the Gopher attribute information.

### `dwContext` [in]

Application-defined value that associates this operation with any application data.

## Return value

Returns **TRUE** if the request is satisfied, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) or
[InternetGetLastResponseInfo](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetlastresponseinfoa).

## Remarks

Generally, applications call this function after calling
[GopherFindFirstFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-gopherfindfirstfilea) or
[InternetFindNextFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetfindnextfilea).

The size of the
*lpBuffer* parameter must be equal to or greater than the value of **MIN_GOPHER_ATTRIBUTE_LENGTH**.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines GopherGetAttribute as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)