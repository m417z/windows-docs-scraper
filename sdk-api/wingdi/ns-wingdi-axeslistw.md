# AXESLISTW structure

## Description

The **AXESLIST** structure contains information on all the axes of a multiple master font.

## Members

### `axlReserved`

Reserved. Must be STAMP_AXESLIST.

### `axlNumAxes`

Number of axes for a specified multiple master font.

### `axlAxisInfo`

An array of [AXISINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-axisinfoa) structures. Each **AXISINFO** structure contains information on an axis of a specified multiple master font. This corresponds to the **dvValues** array in the [DESIGNVECTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-designvector) structure.

## Remarks

The PostScript Open Type Font does not support multiple master functionality.

The information on the axes of a multiple master font are specified by the [AXISINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-axisinfoa) structures. The **axlNumAxes** member specifies the actual size of **axlAxisInfo**, while MM_MAX_NUMAXES, which equals 16, is the maximum allowed size of **axlAxisInfo**.

> [!NOTE]
> The wingdi.h header defines AXESLIST as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AXISINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-axisinfoa)

[DESIGNVECTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-designvector)

[ENUMTEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enumtextmetrica)

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)