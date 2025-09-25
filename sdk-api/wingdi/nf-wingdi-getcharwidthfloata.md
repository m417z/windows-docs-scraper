# GetCharWidthFloatA function

## Description

The **GetCharWidthFloat** function retrieves the fractional widths of consecutive characters in a specified range from the current font.

## Parameters

### `hdc` [in]

A handle to the device context.

### `iFirst` [in]

The code point of the first character in the group of consecutive characters.

### `iLast` [in]

The code point of the last character in the group of consecutive characters.

### `lpBuffer` [out]

A pointer to a buffer that receives the character widths, in logical units.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The returned widths are in the 32-bit IEEE floating-point format. (The widths are measured along the base line of the characters.)

If the *iFirstChar* parameter specifies the letter a and the *iLastChar* parameter specifies the letter z, **GetCharWidthFloat** retrieves the widths of all lowercase characters.

If a character does not exist in the current font, it is assigned the width of the default character.

> [!NOTE]
> The wingdi.h header defines GetCharWidthFloat as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetCharABCWidths](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharabcwidthsa)

[GetCharABCWidthsFloat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharabcwidthsfloata)

[GetCharWidth32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharwidth32a)