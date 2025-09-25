# GetRgnBox function

## Description

The **GetRgnBox** function retrieves the bounding rectangle of the specified region.

## Parameters

### `hrgn` [in]

A handle to the region.

### `lprc` [out]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the bounding rectangle in logical units.

## Return value

The return value specifies the region's complexity. It can be one of the following values:

| Value | Meaning |
| --- | --- |
| NULLREGION | Region is empty. |
| SIMPLEREGION | Region is a single rectangle. |
| COMPLEXREGION | Region is more than a single rectangle. |

If the *hrgn* parameter does not identify a valid region, the return value is zero.

## See also

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)