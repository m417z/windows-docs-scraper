# ExtTextOutA function

## Description

The **ExtTextOut** function draws text using the currently selected font, background color, and text color. You can optionally provide dimensions to be used for clipping, opaquing, or both.

## Parameters

### `hdc` [in]

A handle to the device context.

### `x` [in]

The x-coordinate, in logical coordinates, of the reference point used to position the string.

### `y` [in]

The y-coordinate, in logical coordinates, of the reference point used to position the string.

### `options` [in]

Specifies how to use the application-defined rectangle. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **ETO_CLIPPED** | The text will be clipped to the rectangle. |
| **ETO_GLYPH_INDEX** | The *lpString* array refers to an array returned from [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa) and should be parsed directly by GDI as no further language-specific processing is required. Glyph indexing only applies to TrueType fonts, but the flag can be used for bitmap and vector fonts to indicate that no further language processing is necessary and GDI should process the string directly. Note that all glyph indexes are 16-bit values even though the string is assumed to be an array of 8-bit values for raster fonts.<br><br>For ExtTextOutW, the glyph indexes are saved to a metafile. However, to display the correct characters the metafile must be played back using the same font. For ExtTextOutA, the glyph indexes are not saved. |
| **ETO_IGNORELANGUAGE** | Reserved for system use. If an application sets this flag, it loses international scripting support and in some cases it may display no text at all. |
| **ETO_NUMERICSLATIN** | To display numbers, use European digits. |
| **ETO_NUMERICSLOCAL** | To display numbers, use digits appropriate to the locale. |
| **ETO_OPAQUE** | The current background color should be used to fill the rectangle. |
| **ETO_PDY** | When this is set, the array pointed to by *lpDx* contains pairs of values. The first value of each pair is, as usual, the distance between origins of adjacent character cells, but the second value is the displacement along the vertical direction of the font. |
| **ETO_RTLREADING** | **Middle East language edition of Windows:** If this value is specified and a Hebrew or Arabic font is selected into the device context, the string is output using right-to-left reading order. If this value is not specified, the string is output in left-to-right order. The same effect can be achieved by setting the TA_RTLREADING value in [SetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextalign). This value is preserved for backward compatibility. |

The ETO_GLYPH_INDEX and ETO_RTLREADING values cannot be used together. Because ETO_GLYPH_INDEX implies that all language processing has been completed, the function ignores the ETO_RTLREADING flag if also specified.

### `lprect` [in]

A pointer to an optional [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the dimensions, in logical coordinates, of a rectangle that is used for clipping, opaquing, or both.

### `lpString` [in]

A pointer to a string that specifies the text to be drawn. The string does not need to be zero-terminated, since *cbCount* specifies the length of the string.

### `c` [in]

The [length of the string](https://learn.microsoft.com/windows/desktop/gdi/specifying-length-of-text-output-string) pointed to by *lpString*.

This value may not exceed 8192.

### `lpDx` [in]

A pointer to an optional array of values that indicate the distance between origins of adjacent character cells. For example, lpDx[*i*] logical units separate the origins of character cell *i* and character cell *i* + 1.

## Return value

If the string is drawn, the return value is nonzero. However, if the ANSI version of **ExtTextOut** is called with ETO_GLYPH_INDEX, the function returns **TRUE** even though the function does nothing.

If the function fails, the return value is zero.

## Remarks

The current text-alignment settings for the specified device context determine how the reference point is used to position the text. The text-alignment settings are retrieved by calling the [GetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextalign) function. The text-alignment settings are altered by calling the [SetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextalign) function. You can use the following values for text alignment. Only one flag can be chosen from those that affect horizontal and vertical alignment. In addition, only one of the two flags that alter the current position can be chosen.

| Term | Description |
| --- | --- |
| TA_BASELINE | The reference point will be on the base line of the text. |
| TA_BOTTOM | The reference point will be on the bottom edge of the bounding rectangle. |
| TA_TOP | The reference point will be on the top edge of the bounding rectangle. |
| TA_CENTER | The reference point will be aligned horizontally with the center of the bounding rectangle. |
| TA_LEFT | The reference point will be on the left edge of the bounding rectangle. |
| TA_RIGHT | The reference point will be on the right edge of the bounding rectangle. |
| TA_NOUPDATECP | The current position is not updated after each text output call. The reference point is passed to the text output function. |
| TA_RTLREADING | **Middle East language edition of Windows:** The text is laid out in right to left reading order, as opposed to the default left to right order. This applies only when the font selected into the device context is either Hebrew or Arabic. |
| TA_UPDATECP | The current position is updated after each text output call. The current position is used as the reference point. |

If the *lpDx* parameter is **NULL**, the **ExtTextOut** function uses the default spacing between characters. The character-cell origins and the contents of the array pointed to by the *lpDx* parameter are specified in logical units. A character-cell origin is defined as the upper-left corner of the character cell.

By default, the current position is not used or updated by this function. However, an application can call the [SetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextalign) function with the *fMode* parameter set to TA_UPDATECP to permit the system to use and update the current position each time the application calls **ExtTextOut** for a specified device context. When this flag is set, the system ignores the *X* and *Y* parameters on subsequent **ExtTextOut** calls.

For the ANSI version of **ExtTextOut**, the *lpDx* array has the same number of INT values as there are bytes in *lpString*. For DBCS characters, you can apportion the dx in the *lpDx* entries between the lead byte and the trail byte, as long as the sum of the two bytes adds up to the desired dx. For DBCS characters with the Unicode version of **ExtTextOut**, each Unicode glyph gets a single *pdx* entry.

Note, the *alpDx* values from [GetTextExtentExPoint](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentexpointa) are not the same as the *lpDx* values for **ExtTextOut**. To use the *alpDx* values in *lpDx*, you must first process them.

**ExtTextOut** will use [Uniscribe](https://learn.microsoft.com/windows/win32/intl/uniscribe) when necessary resulting in font fallback. The ETO_IGNORELANGUAGE flag will inhibit this behavior and should not be passed.

Additionally, **ExtTextOut** will perform internal batching of calls before transitioning to kernel mode, mitigating some of the performance concerns when weighing usage of **PolyTextOut** versus **ExtTextOut**.

> [!TIP]
>  **ExtTextOut** is strongly recommended over **PolyTextOut** for modern development due to its ability to handle display of different languages.

#### Examples

For an example, see "Setting Fonts for Menu-Item Text Strings" in [Using Menus](https://learn.microsoft.com/windows/desktop/menurc/using-menus).

> [!NOTE]
> The wingdi.h header defines ExtTextOut as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextalign)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)

[SetBkColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkcolor)

[SetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextalign)

[SetTextColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextcolor)