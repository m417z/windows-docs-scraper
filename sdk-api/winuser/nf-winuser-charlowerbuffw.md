# CharLowerBuffW function

## Description

Converts uppercase characters in a buffer to lowercase characters. The function converts the characters in place.

## Parameters

### `lpsz` [in, out]

Type: **LPTSTR**

A buffer containing one or more characters to be processed.

### `cchLength` [in]

Type: **DWORD**

The size, in
characters, of the buffer pointed to by
*lpsz*. The function examines each character, and converts uppercase characters to lowercase characters. The function examines the number of
characters indicated by
*cchLength*, even if one or more characters are null characters.

## Return value

Type: **DWORD**

The return value is the number of
characters processed. For example, if **CharLowerBuff**("Acme of Operating Systems", 10) succeeds, the return value is 10.

## Remarks

Note that **CharLowerBuff** always maps uppercase I to lowercase I ("i"), even when the current language is Turkish or Azerbaijani. If you need a function that is linguistically sensitive in this respect, call [LCMapSting](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcmapstringa).

Conversion to Unicode in the ANSI version of the function is done with the system default locale in all cases.

#### Examples

For an example, see "Creating a Spell Dialog Box" in [Using Combo Boxes](https://learn.microsoft.com/windows/desktop/Controls/using-combo-boxes).

> [!NOTE]
> The winuser.h header defines CharLowerBuff as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CharLower](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-charlowera)

[CharUpper](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-charuppera)

[CharUpperBuff](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-charupperbuffa)

**Conceptual**

**Reference**

[Strings](https://learn.microsoft.com/windows/desktop/menurc/strings)