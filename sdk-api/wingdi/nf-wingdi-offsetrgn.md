# OffsetRgn function

## Description

The **OffsetRgn** function moves a region by the specified offsets.

## Parameters

### `hrgn` [in]

Handle to the region to be moved.

### `x` [in]

Specifies the number of logical units to move left or right.

### `y` [in]

Specifies the number of logical units to move up or down.

## Return value

The return value specifies the new region's complexity. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| NULLREGION | Region is empty. |
| SIMPLEREGION | Region is a single rectangle. |
| COMPLEXREGION | Region is more than one rectangle. |
| ERROR | An error occurred; region is unaffected. |

## See also

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)