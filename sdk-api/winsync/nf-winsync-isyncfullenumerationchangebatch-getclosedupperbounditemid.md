# ISyncFullEnumerationChangeBatch::GetClosedUpperBoundItemId

## Description

Gets the closed upper bound on item IDs that require destination versions.

## Parameters

### `pbClosedUpperBoundItemId` [in, out]

Returns the closed upper bound on item IDs that require destination versions.

### `pcbIdSize` [in, out]

Specifies the number of bytes in *pbClosedUpperBoundItemId*. Returns the number of bytes required for the size of *pbClosedUpperBoundItemId* when *pcbIdSize* is too small, or the number of bytes written to *pbClosedUpperBoundItemId*.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pbClosedLowerBoundItemId* is too small. In this case, the required number of bytes is stored in *pcbIdSize*. |
| **SYNC_E_INVALID_OPERATION** | No group was added to the batch, or a group was opened but not ended. |

## Remarks

When the destination provider processes this change batch, it must provide version information for all its items that have item IDs that fall between the specified closed lower bound and closed upper bound, inclusive.

## See also

[ISyncFullEnumerationChangeBatch Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncfullenumerationchangebatch)