# ISyncChange::GetChangeUnits

## Description

Gets an object that can enumerate change units that are contained in this change.

## Parameters

### `ppEnum` [out]

Returns a change unit enumerator. Returns **NULL** when this change does not contain change units.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** |  |
| **SYNC_E_ITEM_HAS_NO_CHANGE_UNITS** | The change contains no change units. |

## See also

[ISyncChange Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchange)