# SetMetaRgn function

## Description

The **SetMetaRgn** function intersects the current clipping region for the specified device context with the current metaregion and saves the combined region as the new metaregion for the specified device context. The clipping region is reset to a null region.

## Parameters

### `hdc` [in]

A handle to the device context.

## Return value

The return value specifies the new clipping region's complexity and can be one of the following values.

| Return code | Description |
| --- | --- |
| **NULLREGION** | Region is empty. |
| **SIMPLEREGION** | Region is a single rectangle. |
| **COMPLEXREGION** | Region is more than one rectangle. |
| **ERROR** | An error occurred. (The previous clipping region is unaffected.) |

## Remarks

The current clipping region of a device context is defined by the intersection of its clipping region and its metaregion.

The **SetMetaRgn** function should only be called after an application's original device context was saved by calling the [SaveDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-savedc) function.

## See also

[Clipping Functions](https://learn.microsoft.com/windows/desktop/gdi/clipping-functions)

[Clipping Overview](https://learn.microsoft.com/windows/desktop/gdi/clipping)

[GetMetaRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getmetargn)

[SaveDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-savedc)