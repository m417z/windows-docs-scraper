# IChangeConflict::SetResolveActionForChange

## Description

Sets a conflict resolution action for the conflict.

## Parameters

### `resolveAction` [in]

The conflict resolution action for the conflict.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_INTERNAL_ERROR** | An internal error has occurred. |

## Remarks

By setting this action in an event handler for [ISyncCallback::OnConflict](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isynccallback-onconflict), the event handler specifies how a change applier should handle the conflict.

## See also

[IChangeConflict Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ichangeconflict)

[ISyncCallback::OnConflict Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isynccallback-onconflict)

[SYNC RESOLVE ACTION Enumeration](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-sync_resolve_action)