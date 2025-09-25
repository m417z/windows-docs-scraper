# ICONMETRICSW structure

## Description

Contains the scalable metrics associated with icons. This structure is used with the [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function when the **SPI_GETICONMETRICS** or **SPI_SETICONMETRICS** action is specified.

## Members

### `cbSize`

Type: **UINT**

The size of the structure, in bytes.

### `iHorzSpacing`

Type: **int**

The horizontal space, in pixels, for each arranged icon.

### `iVertSpacing`

Type: **int**

The vertical space, in pixels, for each arranged icon.

### `iTitleWrap`

Type: **int**

If this member is nonzero, icon titles wrap to a new line. If this member is zero, titles do not wrap.

### `lfFont`

Type: **[LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta)**

The font to use for icon titles.

## See also

**Conceptual**

[Icons](https://learn.microsoft.com/windows/desktop/menurc/icons)

**Other Resources**

[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)

## Remarks

> [!NOTE]
> The winuser.h header defines ICONMETRICS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).