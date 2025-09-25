# CharNextA function

## Description

Retrieves a pointer to the next character in a string. This function can handle strings consisting of either single- or multi-byte characters.

## Parameters

### `lpsz` [in]

Type: **LPCTSTR**

A character in a null-terminated string.

## Return value

Type: **LPTSTR**

The return value is a pointer to the next character in the string, or to the terminating null character if at the end of the string.

If
*lpsz* points to the terminating null character, the return value is equal to
*lpsz*.

## Remarks

When called as an ANSI function, **CharNext** uses the system default code-page, whereas [CharNextExA](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-charnextexa) specifies a code-page to use.

This function works with default "user" expectations of characters when dealing with diacritics. For example:
A string that contains U+0061 U+030a "LATIN SMALL LETTER A" + COMBINING RING ABOVE" — which looks like "å", will advance two code points, not one.
A string that contains U+0061 U+0301 U+0302 U+0303 U+0304 — which looks like "a´^~¯", will advance five code points, not one,
and so on.

> [!NOTE]
> The winuser.h header defines CharNext as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CharNextExA](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-charnextexa)

[CharPrev](https://learn.microsoft.com/windows/desktop/menurc/v)

**Conceptual**

**Reference**

[Strings](https://learn.microsoft.com/windows/desktop/menurc/strings)