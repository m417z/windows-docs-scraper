# GetCharWidth32W function

## Description

The **GetCharWidth32** function retrieves the widths, in logical coordinates, of consecutive characters in a specified range from the current font.

## Parameters

### `hdc` [in]

A handle to the device context.

### `iFirst` [in]

The first character in the group of consecutive characters.

### `iLast` [in]

The last character in the group of consecutive characters, which must not precede the specified first character.

### `lpBuffer` [out]

A pointer to a buffer that receives the character widths, in logical coordinates.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

**GetCharWidth32** cannot be used on TrueType fonts. To retrieve character widths for TrueType fonts, use [GetCharABCWidths](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharabcwidthsa).

The range is inclusive; that is, the returned widths include the widths of the characters specified by the *iFirstChar* and *iLastChar* parameters.

If a character does not exist in the current font, it is assigned the width of the default character.

#### Examples

For an example, see "Displaying Keyboard Input" in [Using Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/using-keyboard-input).

> [!NOTE]
> The wingdi.h header defines GetCharWidth32 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetCharABCWidths](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharabcwidthsa)

[GetCharABCWidthsFloat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharabcwidthsfloata)

[GetCharWidthFloat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharwidthfloata)