# InternetCrackUrlW function

## Description

Cracks a URL into its component parts.

## Parameters

### `lpszUrl` [in]

Pointer to a string that contains the canonical URL to be cracked.

### `dwUrlLength` [in]

Size of the
*lpszUrl* string, in **TCHARs**, or zero if
*lpszUrl* is an ASCIIZ string.

### `dwFlags` [in]

Controls the operation. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ICU_DECODE** | Converts encoded characters back to their normal form. This can be used only if the user provides buffers in the [URL_COMPONENTS](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-url_componentsa) structure to copy the components into. |
| **ICU_ESCAPE** | Converts all escape sequences (%xx) to their corresponding characters. This can be used only if the user provides buffers in the [URL_COMPONENTS](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-url_componentsa) structure to copy the components into. |

### `lpUrlComponents` [in, out]

Pointer to a
[URL_COMPONENTS](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-url_componentsa) structure that receives the URL components.

## Return value

Returns **TRUE** if the function succeeds, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The required components are indicated by members of the
[URL_COMPONENTS](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-url_componentsa) structure. Each component has a pointer to the value and has a member that stores the length of the stored value. If both the value and the length for a component are equal to zero, that component is not returned. **Windows Vista and later.:** If the pointer to the value of the component is **NULL** and the value of its corresponding length member is nonzero, the address of the first character of the corresponding component in the
*lpszUrl* string is stored in the pointer, and the length of the component is stored in the length member.

If the pointer contains the address of the user-supplied buffer, the length member must contain the size of the buffer.
**InternetCrackUrl** copies the component into the buffer, and the length member is set to the length of the copied component, minus 1 for the trailing string terminator.

For
**InternetCrackUrl** to work properly, the size of the
[URL_COMPONENTS](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-url_componentsa) structure, in bytes, must be stored in the
**dwStructSize** member.

**Note** Do not use **InternetCrackUrl** on "file://" URLs that contain spaces, because the value returned in the **dwUrlPathLength** member of the [URL_COMPONENTS](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-url_componentsa) structure pointed to by *lpUrlComponents* is too large. This is only the case, however, with "file://" URLs that contain space characters.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetCrackUrl as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FtpOpenFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpopenfilea)

[Handling Uniform Resource Locators](https://learn.microsoft.com/windows/desktop/WinInet/handling-uniform-resource-locators)

[InternetCloseHandle](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetclosehandle)

[InternetFindNextFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetfindnextfilea)

[InternetSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetstatuscallback)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)