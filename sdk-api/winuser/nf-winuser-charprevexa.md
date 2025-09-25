# CharPrevExA function

## Description

Retrieves the pointer to the preceding character in a string. This function can handle strings consisting of either single- or multi-byte characters.

## Parameters

### `CodePage` [in]

Type: **WORD**

The identifier of the code page to use to check lead-byte ranges. Can be one of the code-page values provided in [Code Page Identifiers](https://learn.microsoft.com/windows/desktop/Intl/code-page-identifiers), or one of the following predefined values.

| Value | Meaning |
| --- | --- |
| **CP_ACP**<br><br>0 | Use system default ANSI code page. |
| **CP_MACCP**<br><br>2 | Use the system default Macintosh code page. |
| **CP_OEMCP**<br><br>1 | Use system default OEM code page. |

### `lpStart` [in]

Type: **LPCSTR**

The beginning of the string.

### `lpCurrentChar` [in]

Type: **LPCSTR**

A character in a null-terminated string.

### `dwFlags` [in]

Type: **DWORD**

This parameter is reserved and must be zero.

## Return value

Type: **LPSTR**

The return value is a pointer to the preceding character in the string, or to the first character in the string if the
*lpCurrentChar* parameter equals the
*lpStart* parameter.

## Remarks

**CharPrevExA** specifies a code-page to use, whereas [CharPrev](https://learn.microsoft.com/windows/desktop/menurc/v) (if called as an ANSI function) uses the system default code-page.

## See also

[CharNextExA](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-charnextexa)

[CharPrev](https://learn.microsoft.com/windows/desktop/menurc/v)

**Conceptual**

**Reference**

[Strings](https://learn.microsoft.com/windows/desktop/menurc/strings)