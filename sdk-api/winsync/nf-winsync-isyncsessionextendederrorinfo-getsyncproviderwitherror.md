# ISyncSessionExtendedErrorInfo::GetSyncProviderWithError

## Description

Gets the [ISyncProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncprovider) interface of the provider that caused synchronization to fail.

## Parameters

### `ppProviderWithError` [out]

The [ISyncProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncprovider) interface of the provider that caused synchronization to fail.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_INVALID_OPERATION** | A synchronization session was not started. |

## Remarks

The destination provider indicates which provider caused synchronization to fail during processing of the [IKnowledgeSyncProvider::ProcessChangeBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-iknowledgesyncprovider-processchangebatch) method by using [ISyncSessionState2::SetProviderWithError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncsessionstate2-setproviderwitherror). **ISyncSessionExtendedErrorInfo::GetSyncProviderWithError** is used by an application to obtain the [ISyncProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncprovider) interface of the provider that caused the failure. The application can then query for other interfaces that are implemented by the provider, and call methods to handle the error.

## See also

[IKnowledgeSyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iknowledgesyncprovider)

[ISyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncprovider)

[ISyncSessionExtendedErrorInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncsessionextendederrorinfo)

[ISyncSessionState2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncsessionstate2)