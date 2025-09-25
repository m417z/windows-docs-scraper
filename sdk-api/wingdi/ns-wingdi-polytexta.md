# POLYTEXTA structure

## Description

The **POLYTEXT** structure describes how the [PolyTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polytextouta) function should draw a string of text.

## Members

### `x`

The horizontal reference point for the string. The string is aligned to this point using the current text-alignment mode.

### `y`

The vertical reference point for the string. The string is aligned to this point using the current text-alignment mode.

### `n`

The [length of the string](https://learn.microsoft.com/windows/desktop/gdi/specifying-length-of-text-output-string) pointed to by **lpstr**.

### `lpstr`

Pointer to a string of text to be drawn by the [PolyTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polytextouta) function. This string need not be null-terminated, since **n** specifies the length of the string.

### `uiFlags`

Specifies whether the string is to be opaque or clipped and whether the string is accompanied by an array of character-width values. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| ETO_OPAQUE | The rectangle for each string is to be opaqued with the current background color. |
| ETO_CLIPPED | Each string is to be clipped to its specified rectangle. |

### `rcl`

A rectangle structure that contains the dimensions of the opaquing or clipping rectangle. This member is ignored if neither of the ETO_OPAQUE nor the ETO_CLIPPED value is specified for the **uiFlags** member.

### `pdx`

Pointer to an array containing the width value for each character in the string.

## See also

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[PolyTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polytextouta)

## Remarks

> [!NOTE]
> The wingdi.h header defines POLYTEXT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).