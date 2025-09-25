# IntersectClipRect function

## Description

The **IntersectClipRect** function creates a new clipping region from the intersection of the current clipping region and the specified rectangle.

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

The return value specifies the new clipping region's type and can be one of the following values.

| Return code | Description |
| --- | --- |
| **NULLREGION** | Region is empty. |
| **SIMPLEREGION** | Region is a single rectangle. |
| **COMPLEXREGION** | Region is more than one rectangle. |
| **ERROR** | An error occurred. (The current clipping region is unaffected.) |

## Remarks

The lower and right-most edges of the given rectangle are excluded from the clipping region.

If a clipping region does not already exist then the system may apply a default clipping region to the specified HDC. A clipping region is then created from the intersection of that default clipping region and the rectangle specified in the function parameters.

## See also

[Clipping Functions](https://learn.microsoft.com/windows/desktop/gdi/clipping-functions)

[Clipping Overview](https://learn.microsoft.com/windows/desktop/gdi/clipping)

[ExcludeClipRect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-excludecliprect)