# CharUpperA function

## Description

Converts a character string or a single character to uppercase. If the operand is a character string, the function converts the characters in place.

## Parameters

### `lpsz` [in, out]

Type: **LPTSTR**

A null-terminated string, or a single character. If the high-order word of this parameter is zero, the low-order word must contain a single character to be converted.

## Return value

Type: **LPTSTR**

If the operand is a character string, the function returns a pointer to the converted string. Because the string is converted in place, the return value is equal to
*lpsz*.

If the operand is a single character, the return value is a 32-bit value whose high-order word is zero, and low-order word contains the converted character.

There is no indication of success or failure. Failure is rare. There is no extended error information for this function; do not call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Note that **CharUpper** always maps lowercase I ("i") to uppercase I, even when the current language is Turkish or Azerbaijani. If you need a function that is linguistically sensitive in this respect, call [LCMapString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcmapstringa).

Conversion to Unicode in the ANSI version of the function is done with the system default locale in all cases.

> [!NOTE]
> The winuser.h header defines CharUpper as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CharLower](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-charlowera)

[CharLowerBuff](https://learn.microsoft.com/windows/desktop/menurc/f)

[CharUpperBuff](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-charupperbuffa)

**Conceptual**

**Reference**

[Strings](https://learn.microsoft.com/windows/desktop/menurc/strings)