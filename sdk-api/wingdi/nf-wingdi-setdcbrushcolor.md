# SetDCBrushColor function

## Description

**SetDCBrushColor** function sets the current device context (DC) brush color to the specified color value. If the device cannot represent the specified color value, the color is set to the nearest physical color.

## Parameters

### `hdc` [in]

A handle to the DC.

### `color` [in]

The new brush color.

## Return value

If the function succeeds, the return value specifies the previous DC brush color as a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value.

If the function fails, the return value is CLR_INVALID.

## Remarks

When the stock DC_BRUSH is selected in a DC, all the subsequent drawings will be done using the DC brush color until the stock brush is deselected. The default DC_BRUSH color is WHITE.

The function returns the previous DC_BRUSH color, even if the stock brush DC_BRUSH is not selected in the DC: however, this will not be used in drawing operations until the stock DC_BRUSH is selected in the DC.

The [GetStockObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getstockobject) function with an argument of DC_BRUSH or DC_PEN can be used interchangeably with the [SetDCPenColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdcpencolor) and **SetDCBrushColor** functions.

**ICM:** Color management is performed if ICM is enabled.

#### Examples

For an example of setting colors, see [Setting the Pen or Brush Color](https://learn.microsoft.com/windows/desktop/gdi/setting-the-pen-or-brush-color).

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[GetDCBrushColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdcbrushcolor)