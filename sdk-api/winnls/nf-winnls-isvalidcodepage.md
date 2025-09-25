# IsValidCodePage function

## Description

Determines if a specified code page is valid.

## Parameters

### `CodePage` [in]

[Code page identifier](https://learn.microsoft.com/windows/desktop/Intl/code-page-identifiers) for the code page to check.

## Return value

Returns a nonzero value if the code page is valid, or 0 if the code page is invalid.

## Remarks

A code page is considered valid only if it is installed on the operating system. Unicode is preferred.

Starting with Windows Vista, all code pages that can be installed are loaded by default.

## See also

[GetACP](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getacp)

[GetCPInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcpinfo)

[GetOEMCP](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getoemcp)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)