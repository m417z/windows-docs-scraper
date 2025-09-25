# SelectClipRgn function

## Description

The **SelectClipRgn** function selects a region as the current clipping region for the specified device context.

## Parameters

### `hdc` [in]

A handle to the device context.

### `hrgn` [in]

A handle to the region to be selected.

## Return value

The return value specifies the region's complexity and can be one of the following values.

| Return code | Description |
| --- | --- |
| **NULLREGION** | Region is empty. |
| **SIMPLEREGION** | Region is a single rectangle. |
| **COMPLEXREGION** | Region is more than one rectangle. |
| **ERROR** | An error occurred. (The previous clipping region is unaffected.) |

## Remarks

Only a copy of the selected region is used. The region itself can be selected for any number of other device contexts or it can be deleted.

The **SelectClipRgn** function assumes that the coordinates for a region are specified in device units.

To remove a device-context's clipping region, specify a **NULL** region handle.

#### Examples

For an example, see [Clipping Output](https://learn.microsoft.com/windows/desktop/gdi/clipping-output).

## See also

[Clipping Functions](https://learn.microsoft.com/windows/desktop/gdi/clipping-functions)

[Clipping Overview](https://learn.microsoft.com/windows/desktop/gdi/clipping)

[ExtSelectClipRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extselectcliprgn)