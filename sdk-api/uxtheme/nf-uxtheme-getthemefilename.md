# GetThemeFilename function

## Description

Retrieves the value of a filename property.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part that contains the filename property. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Value of type **int** that specifies the state of the part. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iPropId` [in]

Type: **int**

Value of type **int** that specifies the property to retrieve. For a list of possible values, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs).

### `pszThemeFileName` [out]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a buffer that receives the retrieved file name.

### `cchMaxBuffChars` [in]

Type: **int**

Value of type **int** that receives the maximum number of characters in the file name

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs)