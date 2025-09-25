# GetDCPenColor function

## Description

The **GetDCPenColor** function retrieves the current pen color for the specified device context (DC).

## Parameters

### `hdc` [in]

A handle to the DC whose brush color is to be returned.

## Return value

If the function succeeds, the return value is a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value for the current DC pen color.

If the function fails, the return value is CLR_INVALID.

## Remarks

For information on setting the pen color, see [SetDCPenColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdcbrushcolor).

**ICM:** Color management is performed if ICM is enabled.

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[SetDCPenColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdcpencolor)