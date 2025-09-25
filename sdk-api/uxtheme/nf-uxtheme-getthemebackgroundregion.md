# GetThemeBackgroundRegion function

## Description

Computes the region for a regular or partially transparent background that is bounded by a specified rectangle.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `hdc` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HDC to draw into. The DC uses dots per inch (DPI) scaling. This parameter may be set to **NULL**.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part that contains the region. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Value of type **int** that specifies the state of the part. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `pRect` [in]

Type: **LPCRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains, in logical coordinates, the specified rectangle used to compute the region.

### `pRegion` [out]

Type: **[HRGN](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to the handle to the computed [region](https://learn.microsoft.com/windows/desktop/gdi/regions).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The region handle that is returned by this function should be released when it is no longer needed, using [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject).

## See also

**Other Resources**

[Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs)

**Reference**

[Regions](https://learn.microsoft.com/windows/desktop/gdi/regions)