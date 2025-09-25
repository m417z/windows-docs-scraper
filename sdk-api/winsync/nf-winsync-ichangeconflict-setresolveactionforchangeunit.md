# IChangeConflict::SetResolveActionForChangeUnit

## Description

Sets a conflict resolution action for the conflicting change unit change.

## Parameters

### `pChangeUnit` [in]

The change unit for which to set the conflict resolution action.

### `resolveAction` [in]

The conflict resolution action to set for *pChangeUnit*.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_INTERNAL_ERROR** | When the conflict is an update-delete conflict, or when no conflict exists. |

## Remarks

Be aware that setting the conflict resolution action for a change unit on an update-delete conflict is not valid, because this type of conflict must be resolved at the item level.

By setting this action in an event handler for [ISyncCallback::OnConflict](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isynccallback-onconflict), the event handler specifies how the change applier should handle the conflict.

## See also

[IChangeConflict Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ichangeconflict)

[ISyncCallback::OnConflict Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isynccallback-onconflict)

[SYNC RESOLVE ACTION Enumeration](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-sync_resolve_action)