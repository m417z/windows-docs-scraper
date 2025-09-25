# GetCPInfo function

## Description

Retrieves information about any valid installed or available code page.

**Note** To obtain additional information about valid installed or available code pages, the application should use [GetCPInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcpinfoexa).

## Parameters

### `CodePage` [in]

Identifier for the code page for which to retrieve information. For details, see the *CodePage* parameter of [GetCPInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcpinfoexa).

### `lpCPInfo` [out]

Pointer to a [CPINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-cpinfo) structure that receives information about the code page. See the Remarks section.

## Return value

Returns 1 if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

See Remarks for [GetCPInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcpinfoexa).

## See also

[CPINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-cpinfo)

[Code Page Identifiers](https://learn.microsoft.com/windows/desktop/Intl/code-page-identifiers)

[GetACP](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getacp)

[GetCPInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcpinfoexa)

[GetOEMCP](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getoemcp)

[MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[WideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-widechartomultibyte)