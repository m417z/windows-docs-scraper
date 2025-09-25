# IKnowledgeSyncProvider::BeginSession

## Description

Notifies the provider that it is joining a synchronization session.

## Parameters

### `role` [in]

The role of this provider, relative to the other provider in the session.

### `pSessionState` [in]

The current status of the corresponding session.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Provider-determined error codes** |  |

## Remarks

The provider must return an error if it cannot begin a session. This can occur when the provider has not been initialized, has an invalid configuration, or is already enlisted in an active session.

## See also

[IKnowledgeSyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iknowledgesyncprovider)