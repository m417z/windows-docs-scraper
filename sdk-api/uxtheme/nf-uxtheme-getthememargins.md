# GetThemeMargins function

## Description

Retrieves the value of a [MARGINS](https://learn.microsoft.com/windows/desktop/api/uxtheme/ns-uxtheme-margins) property.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `hdc` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HDC to select fonts into. This parameter may be set to **NULL**.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part that contains the [MARGINS](https://learn.microsoft.com/windows/desktop/api/uxtheme/ns-uxtheme-margins) property. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Value of type **int** that specifies the state of the part. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iPropId` [in]

Type: **int**

Value of type **int** that specifies the property to retrieve. For a list of possible values, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs).

### `prc` [in]

Type: **LPRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the rectangle that specifies the area to be drawn into. This parameter may be set to **NULL**.

### `pMargins` [out]

Type: **[MARGINS](https://learn.microsoft.com/windows/desktop/api/uxtheme/ns-uxtheme-margins)***

Pointer to a [MARGINS](https://learn.microsoft.com/windows/desktop/api/uxtheme/ns-uxtheme-margins) structure that receives the retrieved value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs)