# ISyncCallback::OnProgress

## Description

Occurs periodically during the synchronization session to report progress.

## Parameters

### `provider` [in]

The role of the provider that is associated with this event.

### `syncStage` [in]

The current stage of the synchronization session.

### `dwCompletedWork` [in]

The amount of work that is currently completed in the session. This value is interpreted as being a part of *dwTotalWork*.

### `dwTotalWork` [in]

The total work for the session.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Application-determined error codes.** |  |

## Remarks

Exactly when **OnProgress** is sent and with what values depends on the providers.

## See also

[ISyncCallback Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynccallback)