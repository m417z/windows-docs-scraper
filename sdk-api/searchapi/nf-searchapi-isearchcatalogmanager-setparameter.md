# ISearchCatalogManager::SetParameter

## Description

Sets a name/value parameter for the catalog.

## Parameters

### `pszName` [in]

Type: **LPCWSTR**

The name of the parameter to change.

### `pValue` [in]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

A pointer to the new value for the parameter.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.