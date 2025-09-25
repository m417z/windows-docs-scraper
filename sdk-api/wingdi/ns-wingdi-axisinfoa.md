# AXISINFOA structure

## Description

The **AXISINFO** structure contains information about an axis of a multiple master font.

## Members

### `axMinValue`

The minimum value for this axis.

### `axMaxValue`

The maximum value for this axis.

### `axAxisName`

The name of the axis, specified as an array of characters.

## Remarks

The **AXISINFO** structure contains the name of an axis in a multiple master font and also the minimum and maximum possible values for the axis. The length of the name is MM_MAX_AXES_NAMELEN, which equals 16. An application queries these values before setting its desired values in the [DESIGNVECTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-designvector) array.

The PostScript Open Type Font does not support multiple master functionality.

For the ANSI version of this structure, **axAxisName** must be an array of bytes.

> [!NOTE]
> The wingdi.h header defines AXISINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AXESLIST](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-axeslista)

[DESIGNVECTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-designvector)

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)