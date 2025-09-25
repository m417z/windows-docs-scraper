# GetTextAlign function

## Description

The **GetTextAlign** function retrieves the text-alignment setting for the specified device context.

## Parameters

### `hdc` [in]

A handle to the device context.

## Return value

If the function succeeds, the return value is the status of the text-alignment flags. For more information about the return value, see the Remarks section. The return value is a combination of the following values.

| Value | Meaning |
| --- | --- |
| TA_BASELINE | The reference point is on the base line of the text. |
| TA_BOTTOM | The reference point is on the bottom edge of the bounding rectangle. |
| TA_TOP | The reference point is on the top edge of the bounding rectangle. |
| TA_CENTER | The reference point is aligned horizontally with the center of the bounding rectangle. |
| TA_LEFT | The reference point is on the left edge of the bounding rectangle. |
| TA_RIGHT | The reference point is on the right edge of the bounding rectangle. |
| TA_RTLREADING | **Middle East language edition of Windows:** The text is laid out in right to left reading order, as opposed to the default left to right order. This only applies when the font selected into the device context is either Hebrew or Arabic. |
| TA_NOUPDATECP | The current position is not updated after each text output call. |
| TA_UPDATECP | The current position is updated after each text output call. |

When the current font has a vertical default base line (as with Kanji), the following values are used instead of TA_BASELINE and TA_CENTER.

| Value | Meaning |
| --- | --- |
| VTA_BASELINE | The reference point is on the base line of the text. |
| VTA_CENTER | The reference point is aligned vertically with the center of the bounding rectangle. |

If the function fails, the return value is GDI_ERROR.

## Remarks

The bounding rectangle is a rectangle bounding all of the character cells in a string of text. Its dimensions can be obtained by calling the [GetTextExtentPoint32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpoint32a) function.

The text-alignment flags determine how the [TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta) and [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) functions align a string of text in relation to the string's reference point provided to **TextOut** or **ExtTextOut**.

The text-alignment flags are not necessarily single bit flags and may be equal to zero. The flags must be examined in groups of related flags, as shown in the following list.

* TA_LEFT, TA_RIGHT, and TA_CENTER
* TA_BOTTOM, TA_TOP, and TA_BASELINE
* TA_NOUPDATECP and TA_UPDATECP

If the current font has a vertical default base line, the related flags are as shown in the following list.

* TA_LEFT, TA_RIGHT, and VTA_BASELINE
* TA_BOTTOM, TA_TOP, and VTA_CENTER
* TA_NOUPDATECP and TA_UPDATECP

**To verify that a particular flag is set in the return value of this function:**

1. Apply the bitwise OR operator to the flag and its related flags.
2. Apply the bitwise AND operator to the result and the return value.
3. Test for the equality of this result and the flag.

#### Examples

For an example, see [Setting the Text Alignment](https://learn.microsoft.com/windows/desktop/gdi/setting-the-text-alignment).

## See also

[ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextExtentPoint32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpoint32a)

[SetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextalign)

[TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta)