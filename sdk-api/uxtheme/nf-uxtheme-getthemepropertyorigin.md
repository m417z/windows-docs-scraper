# GetThemePropertyOrigin function

## Description

Retrieves the location of the theme property definition for a property.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part that contains the theme. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Value of type **int** that specifies the state of the part. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iPropId` [in]

Type: **int**

Value of type **int** that specifies the property to retrieve. You may use any of the property values from Vssym32.h. These values are described in the reference pages for the functions that use them. For instance, the [GetThemeInt](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-getthemeint) function uses the TMT_BORDERSIZE value. See the [Visual Styles Reference](https://learn.microsoft.com/windows/desktop/Controls/uxctl-ref) for a list of functions.

### `pOrigin` [out]

Type: **[PROPERTYORIGIN](https://learn.microsoft.com/windows/desktop/api/uxtheme/ne-uxtheme-propertyorigin)***

Pointer to a [PROPERTYORIGIN](https://learn.microsoft.com/windows/desktop/api/uxtheme/ne-uxtheme-propertyorigin) enumerated type that indicates where the property was or was not found.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs)