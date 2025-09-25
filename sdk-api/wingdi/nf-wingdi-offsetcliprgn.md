# OffsetClipRgn function

## Description

The **OffsetClipRgn** function moves the clipping region of a device context by the specified offsets.

## Parameters

### `hdc` [in]

A handle to the device context.

### `x` [in]

The number of logical units to move left or right.

### `y` [in]

The number of logical units to move up or down.

## Return value

The return value specifies the new region's complexity and can be one of the following values.

| Return code | Description |
| --- | --- |
| **NULLREGION** | Region is empty. |
| **SIMPLEREGION** | Region is a single rectangle. |
| **COMPLEXREGION** | Region is more than one rectangle. |
| **ERROR** | An error occurred. (The current clipping region is unaffected.) |

## See also

[Clipping Functions](https://learn.microsoft.com/windows/desktop/gdi/clipping-functions)

[Clipping Overview](https://learn.microsoft.com/windows/desktop/gdi/clipping)

[SelectClipRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectcliprgn)