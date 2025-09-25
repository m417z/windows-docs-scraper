# ISyncChange::GetFlags

## Description

Gets flags that are associated with this change.

## Parameters

### `pdwFlags` [out]

Returns the flags that are associated with this change. This will be a combination of **SYNC_CHANGE_FLAG** values (See Remarks).

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## Remarks

The following table describes the values that the source and destination provider can use for this property.

| SYNC_CHANGE_FLAG value | Provider | Indicates |
| --- | --- | --- |
| **SYNC_CHANGE_FLAG_DELETED** | Source or destination | The item previously existed in the replica but has been deleted. |
| **SYNC_CHANGE_FLAG_DOES_NOT_EXIST** | Destination only | The item does not exist in the destination replica. |

## See also

[ISyncChange Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchange)