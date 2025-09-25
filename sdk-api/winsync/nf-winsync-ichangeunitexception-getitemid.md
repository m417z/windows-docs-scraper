# IChangeUnitException::GetItemId

## Description

Gets the item ID for the item that contains the change unit that is associated with the exception.

## Parameters

### `pbItemId` [in, out]

Returns the item ID that contains the change unit that is associated with the exception.

### `pcbIdSize` [in, out]

Specifies the number of bytes in *pbItemId*. Returns the number of bytes required to retrieve the ID when *pbItemId* is too small, or the number of bytes written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** |  |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pbItemId* is too small. In this case, the required number of bytes is returned in *pcbIdSize*. |

## See also

[IChangeUnitException Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ichangeunitexception)