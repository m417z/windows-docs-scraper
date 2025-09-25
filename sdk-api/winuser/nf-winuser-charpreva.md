# CharPrevA function

## Description

Retrieves a pointer to the preceding character in a string. This function can handle strings consisting of either single- or multi-byte characters.

## Parameters

### `lpszStart` [in]

Type: **LPCTSTR**

The beginning of the string.

### `lpszCurrent` [in]

Type: **LPCTSTR**

A character in a null-terminated string.

## Return value

Type: **LPTSTR**

The return value is a pointer to the preceding character in the string, or to the first character in the string if the
*lpszCurrent* parameter equals the
*lpszStart* parameter.

## Remarks

When called as an ANSI function, **CharPrev** uses the system default code-page, whereas [CharPrevExA](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-charprevexa) specifies a code-page to use.

This function works with default "user" expectations of characters when dealing with diacritics. For example:
A string that contains U+0061 U+030a "LATIN SMALL LETTER A" + COMBINING RING ABOVE" — which looks like "å", will advance two code points, not one.
A string that contains U+0061 U+0301 U+0302 U+0303 U+0304 — which looks like "a´^~¯", will advance five code points, not one,
and so on.

> [!NOTE]
> The winuser.h header defines CharPrev as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CharNext](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-charnexta)

[CharNextExA](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-charnextexa)

[CharPrevExA](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-charprevexa)

**Conceptual**

**Reference**

[Strings](https://learn.microsoft.com/windows/desktop/menurc/strings)