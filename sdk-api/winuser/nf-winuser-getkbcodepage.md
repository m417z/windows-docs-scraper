# GetKBCodePage function

## Description

Retrieves the current code page.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should use the [GetOEMCP](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getoemcp) function to retrieve the OEM code-page identifier for the system.

## Return value

Type: **UINT**

The return value is an OEM code-page identifier, or it is the default identifier if the registry value is not readable. For a list of OEM code-page identifiers, see [Code Page Identifiers](https://learn.microsoft.com/windows/desktop/Intl/code-page-identifiers).

## See also

**Conceptual**

[GetACP](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getacp)

[GetOEMCP](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getoemcp)

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

**Reference**