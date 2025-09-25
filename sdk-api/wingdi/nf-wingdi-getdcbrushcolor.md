# GetDCBrushColor function

## Description

The **GetDCBrushColor** function retrieves the current brush color for the specified device context (DC).

## Parameters

### `hdc` [in]

A handle to the DC whose brush color is to be returned.

## Return value

If the function succeeds, the return value is the [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value for the current DC brush color.

If the function fails, the return value is CLR_INVALID.

## Remarks

For information on setting the brush color, see [SetDCBrushColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdcbrushcolor).

**ICM:** Color management is performed if ICM is enabled.

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[SetDCBrushColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdcbrushcolor)