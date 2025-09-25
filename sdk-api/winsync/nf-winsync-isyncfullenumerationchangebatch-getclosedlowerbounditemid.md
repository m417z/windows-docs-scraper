# ISyncFullEnumerationChangeBatch::GetClosedLowerBoundItemId

## Description

Gets the closed lower bound on item IDs that require destination versions.

## Parameters

### `pbClosedLowerBoundItemId` [in, out]

Returns the closed lower bound on item IDs that require destination versions.

### `pcbIdSize` [in, out]

Specifies the number of bytes in *pbClosedLowerBoundItemId*. Returns the number of bytes required for the size of *pbClosedLowerBoundItemId* when *pcbIdSize* is too small, or the number of bytes written to *pbClosedLowerBoundItemId*.

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