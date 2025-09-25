# ExcludeClipRect function

## Description

The **ExcludeClipRect** function creates a new clipping region that consists of the existing clipping region minus the specified rectangle.

## Parameters

### `hdc` [in]

A handle to the device context.

### `left` [in]

The x-coordinate, in logical units, of the upper-left corner of the rectangle.

### `top` [in]

The y-coordinate, in logical units, of the upper-left corner of the rectangle.

### `right` [in]

The x-coordinate, in logical units, of the lower-right corner of the rectangle.

### `bottom` [in]

The y-coordinate, in logical units, of the lower-right corner of the rectangle.

## Return value

The return value specifies the new clipping region's complexity; it can be one of the following values.

| Return code | Description |
| --- | --- |
| **NULLREGION** | Region is empty. |
| **SIMPLEREGION** | Region is a single rectangle. |
| **COMPLEXREGION** | Region is more than one rectangle. |
| **ERROR** | No region was created. |

## Remarks

The lower and right edges of the specified rectangle are not excluded from the clipping region.

## See also

[Clipping Functions](https://learn.microsoft.com/windows/desktop/gdi/clipping-functions)

[Clipping Overview](https://learn.microsoft.com/windows/desktop/gdi/clipping)

[IntersectClipRect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-intersectcliprect)