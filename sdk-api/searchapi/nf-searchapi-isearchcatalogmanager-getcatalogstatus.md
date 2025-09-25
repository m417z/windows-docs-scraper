# ISearchCatalogManager::GetCatalogStatus

## Description

Gets the status of the catalog.

## Parameters

### `pStatus` [out]

Type: **[CatalogStatus](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-catalogstatus)***

Receives a pointer to a value from the [CatalogStatus](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-catalogstatus) enumeration. If *pStatus* is *CATALOG_STATUS_PAUSED*, further information can be obtained from the *pPausedReason* parameter.

### `pPausedReason` [out]

Type: **[CatalogPausedReason](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-catalogpausedreason)***

Receives a pointer to a value from the [CatalogPausedReason](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-catalogpausedreason) enumeration describing why the catalog is paused. If the catalog status is not *CATALOG_STATUS_PAUSED*, this parameter receives the value *CATALOG_PAUSED_REASON_NONE*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.