# GetTextMetricsA function

## Description

The **GetTextMetrics** function fills the specified buffer with the metrics for the currently selected font.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lptm` [out]

A pointer to the [TEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-textmetrica) structure that receives the text metrics.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

To determine whether a font is a TrueType font, first select it into a DC, then call **GetTextMetrics**, and then check for TMPF_TRUETYPE in TEXTMETRIC.tmPitchAndFamily. Note that [GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc) returns an uninitialized DC, which has "System" (a bitmap font) as the default font; thus the need to select a font into the DC.

#### Examples

For an example, see "Displaying Keyboard Input" in [Using Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/using-keyboard-input) or [Drawing Text from Different Fonts on the Same Line](https://learn.microsoft.com/windows/desktop/gdi/drawing-text-from-different-fonts-on-the-same-line).

> [!NOTE]
> The wingdi.h header defines GetTextMetrics as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextalign)

[GetTextExtentPoint32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpoint32a)

[GetTextFace](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextfacea)

[SetTextJustification](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextjustification)

[TEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-textmetrica)