# DestroyPropertySheetPage function

## Description

Destroys a property sheet page. An application must call this function for pages that have not been passed to the [PropertySheet](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propertysheeta) function.

## Parameters

### `unnamedParam1`

Type: **HPROPSHEETPAGE**

Handle to the property sheet page to delete.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.