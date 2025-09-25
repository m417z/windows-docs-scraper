# GetThemeFont function

## Description

Retrieves the value of a font property.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `hdc` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HDC. This parameter may be set to **NULL**.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part that contains the font property. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Value of type **int** that specifies the state of the part. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iPropId` [in]

Type: **int**

Value of type **int** that specifies the property to retrieve. For a list of possible values, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs).

### `pFont` [out]

Type: **LOGFONTW***

Pointer to a [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure that receives the font property value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The font is scaled in dots per inch (DPI) for the current logical screen.

If the property is not supported for the specified part and state, E_PROP_ID_UNSUPPORTED may be returned.

## See also

[Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs)