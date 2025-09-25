# GetOEMCP function

## Description

Returns the current original equipment manufacturer (OEM) code page identifier for the operating system.

**Note** The ANSI code pages can be different on different computers, or can be changed for a single computer, leading to data corruption. For the most consistent results, applications should use Unicode, such as UTF-8 or UTF-16, instead of a specific code page.

## Return value

Returns the current OEM code page identifier for the operating system.

## Remarks

See [Code Page Identifiers](https://learn.microsoft.com/windows/desktop/Intl/code-page-identifiers) for a list of OEM and other code pages.

## See also

[GetACP](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getacp)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)