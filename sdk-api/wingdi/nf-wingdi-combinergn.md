# CombineRgn function

## Description

The **CombineRgn** function combines two regions and stores the result in a third region. The two regions are combined according to the specified mode.

## Parameters

### `hrgnDst` [in]

A handle to a new region with dimensions defined by combining two other regions. (This region must exist before **CombineRgn** is called.)

### `hrgnSrc1` [in]

A handle to the first of two regions to be combined.

### `hrgnSrc2` [in]

A handle to the second of two regions to be combined.

### `iMode` [in]

A mode indicating how the two regions will be combined. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **RGN_AND** | Creates the intersection of the two combined regions. |
| **RGN_COPY** | Creates a copy of the region identified by *hrgnSrc1*. |
| **RGN_DIFF** | Combines the parts of *hrgnSrc1* that are not part of *hrgnSrc2*. |
| **RGN_OR** | Creates the union of two combined regions. |
| **RGN_XOR** | Creates the union of two combined regions except for any overlapping areas. |

## Return value

The return value specifies the type of the resulting region. It can be one of the following values.

| Return code | Description |
| --- | --- |
| **NULLREGION** | The region is empty. |
| **SIMPLEREGION** | The region is a single rectangle. |
| **COMPLEXREGION** | The region is more than a single rectangle. |
| **ERROR** | No region is created. |

## Remarks

The three regions need not be distinct. For example, the *hrgnSrc1* parameter can equal the *hrgnDest* parameter.

## See also

[CreateEllipticRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createellipticrgn)

[CreateEllipticRgnIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createellipticrgnindirect)

[CreatePolyPolygonRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpolypolygonrgn)

[CreatePolygonRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpolygonrgn)

[CreateRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgn)

[CreateRectRgnIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgnindirect)

[CreateRoundRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createroundrectrgn)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)