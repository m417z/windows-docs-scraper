# HitTestThemeBackground function

## Description

Retrieves a hit test code for a point in the background specified by a visual style.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `hdc` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HDC to use when drawing. This parameter may be set to **NULL**.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Value of type **int** that specifies the state of the part. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `dwOptions` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**DWORD** that specifies the hit test options. See [Hit Test Options](https://learn.microsoft.com/windows/desktop/Controls/theme-hit-test-options) for a list of options.

### `pRect` [in]

Type: **LPCRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains, in logical coordinates, the rectangle that bounds the background.

### `hrgn` [in]

Type: **[HRGN](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a region that can be used to specify the bounds of a hit test area. This parameter may be set to **NULL**.

### `ptTest` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that contains the coordinates of the point.

### `pwHitTestCode` [out]

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

**WORD** that receives the hit test code that indicates whether the point in *ptTest* is in the background area bounded by *pRect* or *hrgn*. See [Hit Test Return Values](https://learn.microsoft.com/windows/desktop/Controls/theme-hit-test-retval) for a list of values returned.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The values in *ptTest* and *pRect* should be in the same coordinate system, such as client or screen. If the *hrgn* parameter is used, it must be specified in the same coordinates as *pRect* and *ptTest*.

## See also

[Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs)