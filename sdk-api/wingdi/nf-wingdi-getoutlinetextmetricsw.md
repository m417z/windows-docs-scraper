# GetOutlineTextMetricsW function

## Description

The **GetOutlineTextMetrics** function retrieves text metrics for TrueType fonts.

## Parameters

### `hdc` [in]

A handle to the device context.

### `cjCopy` [in]

The size, in bytes, of the array that receives the text metrics.

### `potm` [out, optional]

A pointer to an [OUTLINETEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-outlinetextmetrica) structure. If this parameter is **NULL**, the function returns the size of the buffer required for the retrieved metric data.

## Return value

If the function succeeds, the return value is nonzero or the size of the required buffer.

If the function fails, the return value is zero.

## Remarks

The [OUTLINETEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-outlinetextmetrica) structure contains most of the text metric information provided for TrueType fonts (including a [TEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-textmetrica) structure). The sizes returned in **OUTLINETEXTMETRIC** are in logical units; they depend on the current mapping mode.

> [!NOTE]
> The wingdi.h header defines GetOutlineTextMetrics as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextMetrics](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextmetrics)

[OUTLINETEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-outlinetextmetrica)

[TEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-textmetrica)