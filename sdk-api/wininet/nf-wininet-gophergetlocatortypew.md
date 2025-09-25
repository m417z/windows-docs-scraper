# GopherGetLocatorTypeW function

## Description

[The **GopherGetLocatorType** function is available for use in the operating systems specified in the Requirements section.]

Parses a Gopher locator and determines its attributes.

## Parameters

### `lpszLocator` [in]

Pointer to a null-terminated string that specifies the Gopher locator to be parsed.

### `lpdwGopherType` [out]

Pointer to a variable that receives the type of the locator. The type is a bitmask that consists of a combination of the
[gopher type values](https://learn.microsoft.com/windows/desktop/WinInet/gopher-type-values).

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**GopherGetLocatorType** returns information about the item referenced by a Gopher locator. Note that it is possible for multiple attributes to be set on a file. For example, both **GOPHER_TYPE_TEXT_FILE** and **GOPHER_TYPE_GOPHER_PLUS** are set for a text file stored on a Gopher+ server.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines GopherGetLocatorType as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)