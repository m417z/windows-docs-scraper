# ISearchCatalogManager::RegisterViewForNotification

## Description

Not implemented.

## Parameters

### `pszView` [in]

Type: **LPCWSTR**

A pointer to the name of the view.

### `pViewChangedSink` [in]

Type: **[ISearchViewChangedSink](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchviewchangedsink)***

Pointer to the [ISearchViewChangedSink](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchviewchangedsink) object to receive notifications.

### `pdwCookie` [out]

Type: **DWORD***

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.