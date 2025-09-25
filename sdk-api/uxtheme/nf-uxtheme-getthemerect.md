# GetThemeRect function

## Description

Retrieves the value of a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) property.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part containing the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) property. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Value of type **int** that specifies the state of the part. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iPropId` [in]

Type: **int**

Value of type **int** that specifies the property to retrieve. For a list of possible values, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs).

### `pRect` [out]

Type: **LPRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives a rectangle.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs)