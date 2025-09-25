# IKnowledgeSyncProvider::EndSession

## Description

Notifies the provider that a synchronization session to which it was enlisted has finished.

## Parameters

### `pSessionState` [in]

The current status of the corresponding session.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Provider-determined error codes** |  |

## Remarks

*pSessionState* will be equal to the **ISyncSessionState** object that was provided to the previous corresponding call to [IKnowledgeSyncProvider::BeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-iknowledgesyncprovider-beginsession).

**Note** This method must return an error, typically [SYNC_E_INVALIDOPERATION](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-error-codes), if the provider did not receive a previous call to [BeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-iknowledgesyncprovider-beginsession) for the specified session.

When this method is called, the provider must release any references it has to the **ISyncSessionState** object that is specified by *pSessionState*.

## See also

[IKnowledgeSyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iknowledgesyncprovider)