# ISearchCatalogManager::GetItemsChangedSink

## Description

Gets the change notification sink interface.

## Parameters

### `pISearchNotifyInlineSite` [in]

Type: **[ISearchNotifyInlineSite](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchnotifyinlinesite)***

A pointer to your [ISearchNotifyInlineSite](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchnotifyinlinesite) interface.

### `riid` [in]

Type: **REFIID**

The UUID of the [ISearchItemsChangedSink](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchitemschangedsink) interface.

### `ppv` [out]

Type: **void***

Receives a pointer to the [ISearchItemsChangedSink](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchitemschangedsink) interface.

### `pGUIDCatalogResetSignature` [out]

Type: **GUID***

Receives a pointer to the GUID representing the catalog reset. If this GUID changes, all notifications must be resent.

### `pGUIDCheckPointSignature` [out]

Type: **GUID***

Receives a pointer to the GUID representing a checkpoint.

### `pdwLastCheckPointNumber` [out]

Type: **DWORD***

Receives a pointer to the number indicating the last checkpoint to be saved.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.