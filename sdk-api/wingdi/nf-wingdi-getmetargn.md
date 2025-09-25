# GetMetaRgn function

## Description

The **GetMetaRgn** function retrieves the current metaregion for the specified device context.

## Parameters

### `hdc` [in]

A handle to the device context.

### `hrgn` [in]

A handle to an existing region before the function is called. After the function returns, this parameter is a handle to a copy of the current metaregion.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

If the function succeeds, *hrgn* is a handle to a copy of the current metaregion. Subsequent changes to this copy will not affect the current metaregion.

The current clipping region of a device context is defined by the intersection of its clipping region and its metaregion.

## See also

[Clipping Functions](https://learn.microsoft.com/windows/desktop/gdi/clipping-functions)

[Clipping Overview](https://learn.microsoft.com/windows/desktop/gdi/clipping)

[SetMetaRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setmetargn)