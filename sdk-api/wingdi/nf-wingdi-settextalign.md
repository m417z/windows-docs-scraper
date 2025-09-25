# SetTextAlign function

## Description

The **SetTextAlign** function sets the text-alignment flags for the specified device context.

## Parameters

### `hdc` [in]

A handle to the device context.

### `align` [in]

The text alignment by using a mask of the values in the following list. Only one flag can be chosen from those that affect horizontal and vertical alignment. In addition, only one of the two flags that alter the current position can be chosen.

| Value | Meaning |
| --- | --- |
| **TA_BASELINE** | The reference point will be on the base line of the text. |
| **TA_BOTTOM** | The reference point will be on the bottom edge of the bounding rectangle. |
| **TA_TOP** | The reference point will be on the top edge of the bounding rectangle. |
| **TA_CENTER** | The reference point will be aligned horizontally with the center of the bounding rectangle. |
| **TA_LEFT** | The reference point will be on the left edge of the bounding rectangle. |
| **TA_RIGHT** | The reference point will be on the right edge of the bounding rectangle. |
| **TA_NOUPDATECP** | The current position is not updated after each text output call. The reference point is passed to the text output function. |
| **TA_RTLREADING** | **Middle East language edition of Windows:** The text is laid out in right to left reading order, as opposed to the default left to right order. This applies only when the font selected into the device context is either Hebrew or Arabic. |
| **TA_UPDATECP** | The current position is updated after each text output call. The current position is used as the reference point. |

When the current font has a vertical default base line, as with Kanji, the following values must be used instead of TA_BASELINE and TA_CENTER.

| Value | Meaning |
| --- | --- |
| **VTA_BASELINE** | The reference point will be on the base line of the text. |
| **VTA_CENTER** | The reference point will be aligned vertically with the center of the bounding rectangle. |

The default values are TA_LEFT, TA_TOP, and TA_NOUPDATECP.

## Return value

If the function succeeds, the return value is the previous text-alignment setting.

If the function fails, the return value is GDI_ERROR.

## Remarks

The [TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta) and [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) functions use the text-alignment flags to position a string of text on a display or other device. The flags specify the relationship between a reference point and a rectangle that bounds the text. The reference point is either the current position or a point passed to a text output function.

The rectangle that bounds the text is formed by the character cells in the text string.

The best way to get left-aligned text is to use either

```cpp

SetTextAlign (hdc, GetTextAlign(hdc) & (~TA_CENTER))

```

or

```cpp

SetTextAlign (hdc,TA_LEFT | <other flags>)

```

You can also use **SetTextAlign** (hdc, TA_LEFT) for this purpose, but this loses any vertical or right-to-left settings.

**Note** You should not use **SetTextAlign** with TA_UPDATECP when you are using [ScriptStringOut](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringout), because selected text is not rendered correctly. If you must use this flag, you can unset and reset it as necessary to avoid the problem.

#### Examples

For an example, see [Setting the Text Alignment](https://learn.microsoft.com/windows/desktop/gdi/setting-the-text-alignment).

## See also

[ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextalign)

[ScriptStringOut](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringout)

[TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta)