# ISyncChange::GetRootItemId

## Description

Gets the ID of the changed item.

## Parameters

### `pbRootItemId` [in, out]

Returns the ID of the item.

### `pcbIdSize` [in, out]

Specifies the number of bytes in *pbRootItemId*. Returns the number of bytes required to retrieve the ID when *pbRootItemId* is too small, or returns the number of bytes written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pbRootItemId* is too small. In this case, the required number of bytes is returned in *pcbIdSize*. |

## See also

[ISyncChange Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchange)