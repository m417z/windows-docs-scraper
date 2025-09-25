# ISearchNotifyInlineSite::OnCatalogStatusChange

## Description

Called by the search service to notify a client when the status of the catalog changes.

## Parameters

### `guidCatalogResetSignature` [in]

Type: **REFGUID**

A GUID representing the catalog reset. If this GUID changes, all notifications must be resent.

### `guidCheckPointSignature` [in]

Type: **REFGUID**

A GUID representing the last checkpoint restored. If this GUID changes, all notifications accumulated since the last saved checkpoint must be resent.

### `dwLastCheckPointNumber` [in]

Type: **DWORD**

A number indicating the last checkpoint saved.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When a catalog checkpoint occurs, the search service updates the *dwLastCheckPointNumber*, and all notifications sent prior to that checkpoint are safe and recoverable in the event of a service failure. Notification providers need to track only those notifications sent between checkpoints and must resend them if the catalog is restored or reset.

If a catalog restore occurs, the search service rolls back the catalog to the last saved checkpoint and updates the *guidCheckPointSignature*. In this situation, notification providers must resend all notifications accumulated since the most recent saved checkpoint, as identified by the *dwLastCheckPointNumber* parameter.

If a catalog reset occurs, the search service resets the entire catalog and updates the *guidCatalogResetSignature*. The notification provider must resend its entire crawl scope.

## See also

[ISearchNotifyInlineSite](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchnotifyinlinesite)

[Notifying the Index of Changes](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-notifyingofchanges)