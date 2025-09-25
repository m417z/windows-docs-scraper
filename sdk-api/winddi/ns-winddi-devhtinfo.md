# DEVHTINFO structure

## Description

The DEVHTINFO structure is used as input to the [HTUI_DeviceColorAdjustment](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-htui_devicecoloradjustment) function.

## Members

### `HTFlags`

Is a set of caller-supplied flags indicating halftone attributes. See the **flHTFlags** member of the [GDIINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-gdiinfo) structure for a complete list of possible values.

### `HTPatternSize`

Is a caller-supplied value that must be one of the HTPAT_SIZE-prefixed constants defined in *winddi.h*.

### `DevPelsDPI`

For printers, specifies the number of dots per inch. See the description of the **ulDevicePelsDPI** member of the [GDIINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-gdiinfo) structure for more information.

For displays, this member should be set to zero.

### `ColorInfo`

Is a caller-supplied pointer to a [COLORINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-colorinfo) structure containing halftoning color information.

## See also

[COLORINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-colorinfo)

[GDIINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-gdiinfo)

[HTUI_DeviceColorAdjustment](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-htui_devicecoloradjustment)