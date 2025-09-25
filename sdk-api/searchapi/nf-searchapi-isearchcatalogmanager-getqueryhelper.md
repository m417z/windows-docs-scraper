# ISearchCatalogManager::GetQueryHelper

## Description

Gets the [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper) interface for the current catalog.

## Parameters

### `ppSearchQueryHelper` [out, retval]

Type: **[ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper)****

Receives the address of a pointer to a new instance of the [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper) interface with default settings.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

After the [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper) interface is created, use the put... methods for this interface to change settings. Settings for the **ISearchQueryHelper** object are relevant only until the settings are changed again or the item is released. When the item is next created, settings are set to default values.