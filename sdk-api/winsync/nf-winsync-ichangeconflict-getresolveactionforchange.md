# IChangeConflict::GetResolveActionForChange

## Description

Gets the conflict resolution action for the conflict.

## Parameters

### `pResolveAction` [out]

Returns the conflict resolution action for the conflict.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## See also

[IChangeConflict Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ichangeconflict)

[SYNC RESOLVE ACTION Enumeration](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-sync_resolve_action)