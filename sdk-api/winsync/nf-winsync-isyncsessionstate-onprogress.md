# ISyncSessionState::OnProgress

## Description

Reports synchronization progress to the application.

## Parameters

### `provider` [in]

The role of the provider that is sending this event.

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
| **E_INVALIDARG** | *provider* or *syncStage* is not a valid value. |

## Remarks

This method can be used to report custom progress to the application. When a provider calls this method, the [ISyncCallback::OnProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isynccallback-onprogress) event is raised.

## See also

[ISyncCallback Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynccallback)

[ISyncSessionState Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncsessionstate)

[SYNC_PROGRESS STAGE Enumeration](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-sync_progress_stage)

[SYNC_PROVIDER ROLE Enumeration](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-sync_provider_role)