# ISyncSessionState2::SetProviderWithError

## Description

Indicates which provider caused synchronization to fail.

## Parameters

### `fSelf` [in]

**TRUE** when the provider that calls this method is the provider that caused the error. Otherwise, **FALSE**.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **SYNC_E_INVALID_OPERATION** | A synchronization session does not exist. |

## Remarks

The destination provider indicates which provider caused synchronization to fail during processing of the [IKnowledgeSyncProvider::ProcessChangeBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-iknowledgesyncprovider-processchangebatch) method, by using **ISyncSessionState2::SetProviderWithError**. **ISyncSessionState2::SetProviderWithError** is used by an application to obtain the [ISyncProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncprovider) interface of the provider that caused the failure. The synchronization session can then query for other interfaces that are implemented by the provider, and call methods to handle the error.

## See also

[IKnowledgeSyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iknowledgesyncprovider)

[ISyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncprovider)

[ISyncSessionState Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncsessionstate)

[ISyncSessionState2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncsessionstate2)