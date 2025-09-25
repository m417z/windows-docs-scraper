# GetThemePartSize function

## Description

Calculates the original size of the part defined by a visual style.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `hdc` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HDC to select fonts into.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part to calculate the size of. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Value of type **int** that specifies the state of the part. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `prc` [in]

Type: **LPCRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the rectangle used for the part drawing destination. This parameter may be set to **NULL**.

### `eSize` [in]

Type: **THEMESIZE**

Enumerated type that specifies the type of size to retrieve. See [THEMESIZE](https://learn.microsoft.com/windows/desktop/api/uxtheme/ne-uxtheme-themesize) for a list of type values.

### `psz` [out]

Type: **[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)***

Pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that receives the dimensions of the specified part.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs)