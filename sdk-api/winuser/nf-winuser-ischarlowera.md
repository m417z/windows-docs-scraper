# IsCharLowerA function

## Description

Determines whether a character is lowercase. This determination is based on the semantics of the language selected by the user during setup or through Control Panel.

## Parameters

### `ch` [in]

Type: **TCHAR**

The character to be tested.

## Return value

Type: **BOOL**

If the character is lowercase, the return value is nonzero.

If the character is not lowercase, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

**Conceptual**

[IsCharUpper](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-ischaruppera)

**Reference**

[Strings](https://learn.microsoft.com/windows/desktop/menurc/strings)

## Remarks

> [!NOTE]
> The winuser.h header defines IsCharLower as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).