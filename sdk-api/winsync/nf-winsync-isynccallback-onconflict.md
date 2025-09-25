# ISyncCallback::OnConflict

## Description

Occurs when a conflict is detected when the concurrency conflict resolution policy is set to [CRP_NONE](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-conflict_resolution_policy).

## Parameters

### `pConflict` [in]

Information about the conflict. This includes metadata and item data for the two changes that are in conflict.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Application-determined error codes.** |  |

## Remarks

This notification can be used by an application to perform custom conflict resolution for concurrency conflicts. To accomplish this, the application inspects and processes the contents of *pConflict*, and then sets the resolution action for the conflict by calling [IChangeConflict::SetResolveActionForChange](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ichangeconflict) before it returns from this method.

## See also

[IChangeConflict Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ichangeconflict)

[ISyncCallback Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynccallback)

[SYNC_FULL_ENUMERATION_ACTION Enumeration](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-sync_full_enumeration_action)