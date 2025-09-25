# GetCPInfoExA function

## Description

Retrieves information about any valid installed or available code page.

## Parameters

### `CodePage` [in]

Identifier for the code page for which to retrieve information. The application can specify the code page identifier for any installed or available code page, or one of the following predefined values. See [Code Page Identifiers](https://learn.microsoft.com/windows/desktop/Intl/code-page-identifiers) for a list of identifiers for ANSI and other code pages.

| Value | Meaning |
| --- | --- |
| **CP_ACP** | Use the system default Windows ANSI code page. |
| **CP_MACCP** | Use the system default Macintosh code page. |
| **CP_OEMCP** | Use the system default OEM code page. |
| **CP_THREAD_ACP** | Use the current thread's ANSI code page. |

### `dwFlags` [in]

Reserved; must be 0.

### `lpCPInfoEx` [out]

Pointer to a [CPINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-cpinfoexa) structure that receives information about the code page.

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

The information retrieved in the [CPINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-cpinfoexa) structure is not always useful for all code pages. To determine buffer sizes, for example, the application should call [MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) or [WideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-widechartomultibyte) to request an accurate buffer size. If **CPINFOEX** settings indicate that a lead byte exists, the conversion function does not necessarily handle lead bytes differently, for example, in the case of a missing or illegal trail byte.

> [!NOTE]
> The winnls.h header defines GetCPInfoEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CPINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-cpinfoexa)

[GetACP](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getacp)

[GetCPInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcpinfo)

[GetOEMCP](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getoemcp)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)