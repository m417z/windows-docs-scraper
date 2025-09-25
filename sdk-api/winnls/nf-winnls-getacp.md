# GetACP function

## Description

Retrieves the current Windows ANSI code page identifier for the operating system.

**Caution** The ANSI API functions, for example, the ANSI version of [TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta), implicitly use **GetACP** to translate text to or from Unicode. For the Multilingual User Interface (MUI) edition of Windows, the system ACP might not cover all code points in the user's selected logon language identifier. For compatibility with this edition, your application should avoid calls that depend on **GetACP** either implicitly or explicitly, as this function can cause some locales to display text as question marks. Instead, the application should use the Unicode API functions directly, for example, the Unicode version of [TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta).

## Return value

Returns the current Windows ANSI code page (ACP) identifier for the operating system. See [Code Page Identifiers](https://learn.microsoft.com/windows/desktop/Intl/code-page-identifiers) for a list of identifiers for Windows ANSI code pages and other code pages.

## Remarks

The ANSI code pages can be different on different computers, or can be changed for a single computer, leading to data corruption. For the most consistent results, applications should use UTF-8 or UTF-16 when possible.

## See also

[Code Page Identifiers](https://learn.microsoft.com/windows/desktop/Intl/code-page-identifiers)

[GetCPInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcpinfo)

[GetOEMCP](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getoemcp)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)