# ISyncCallback2::OnChangeApplied

## Description

Occurs after a change is successfully applied.

## Parameters

### `dwChangesApplied` [in]

The number of changes that have been successfully applied during the synchronization session. This value is the sum of item changes plus change unit changes.

### `dwChangesFailed` [in]

The number of changes that have failed to apply during the synchronization session. This value is the sum of item changes plus change unit changes.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Application-determined error codes** |  |

## See also

[ISyncCallback Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynccallback)

[ISyncCallback2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynccallback2)