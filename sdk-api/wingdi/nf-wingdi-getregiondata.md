## Description

The **GetRegionData** function fills the specified buffer with data describing a region. This data includes the dimensions of the rectangles that make up the region.

## Parameters

### `hrgn` [in]

A handle to the region.

### `nCount` [in]

The size, in bytes, of the *lpRgnData* buffer.

### `lpRgnData` [out]

A pointer to a [RGNDATA](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-rgndata) structure that receives the information. The dimensions of the region are in logical units. If this parameter is **NULL**, then the return value contains the number of bytes needed for the region data.

## Return value

If the function succeeds and *nCount* specifies an adequate number of bytes, then the return value equals the actual number of bytes used (less than or equal to *nCount*).

If *lpRgnData* is **NULL**, then the return value is the required number of bytes.

If the function fails, then the return value is zero.

If the failure is due to *hrgn* being invalid, then **GetLastError** returns **ERROR_INVALID_HANDLE**. Otherwise, **GetLastError** returns **ERROR_INVALID_PARAMETER** .

If *nCount* is too small, then the function fails.

## Remarks

The **GetRegionData** function is used in conjunction with the [ExtCreateRegion](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreateregion) function.

## See also

[CreatePolyPolygonRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpolypolygonrgn)

[CreatePolygonRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpolygonrgn)

[CreateRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgn)

[CreateRectRgnIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgnindirect)

[CreateRoundRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createroundrectrgn)

[ExtCreateRegion](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreateregion)

[RGNDATA](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndata)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)