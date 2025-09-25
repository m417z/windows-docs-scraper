# ISupportLastWriteTime::GetChangeUnitChangeTime

## Description

Gets the date and time when the specified change unit was last changed.

## Parameters

### `pbItemId` [in]

The ID of the item that contains the change unit to look up.

### `pbChangeUnitId` [in]

The ID of the change unit to look up.

### `pullTimestamp` [out]

The date and time when the specified change unit was last changed.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Provider-determined error codes** |  |

## See also

[ISupportLastWriteTime Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isupportlastwritetime)