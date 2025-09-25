# GetClipBox function

## Description

The **GetClipBox** function retrieves the dimensions of the tightest bounding rectangle that can be drawn around the current visible area on the device. The visible area is defined by the current clipping region or clip path, as well as any overlapping windows.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lprect` [out]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that is to receive the rectangle dimensions, in logical units.

## Return value

If the function succeeds, the return value specifies the clipping box's complexity and can be one of the following values.

| Return code | Description |
| --- | --- |
| **NULLREGION** | Region is empty. |
| **SIMPLEREGION** | Region is a single rectangle. |
| **COMPLEXREGION** | Region is more than one rectangle. |
| **ERROR** | An error occurred. |

**GetClipBox** returns logical coordinates based on the given device context.

## See also

[Clipping Functions](https://learn.microsoft.com/windows/desktop/gdi/clipping-functions)

[Clipping Overview](https://learn.microsoft.com/windows/desktop/gdi/clipping)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)