# GetThemeIntList function

## Description

Retrieves a list of **int** data from a visual style.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part that contains the list of data to return. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Value of type **int** that specifies the state of the part. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iPropId` [in]

Type: **int**

Value of type **int** that specifies the property to retrieve. See [Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs).

### `pIntList` [out]

Type: **[INTLIST](https://learn.microsoft.com/windows/desktop/api/uxtheme/ns-uxtheme-intlist)***

Pointer to an [INTLIST](https://learn.microsoft.com/windows/desktop/api/uxtheme/ns-uxtheme-intlist) structure that receives the **int** data.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful, otherwise an error code.

## See also

[INTLIST](https://learn.microsoft.com/windows/desktop/api/uxtheme/ns-uxtheme-intlist)