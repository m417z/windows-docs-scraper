# ISingleItemException::GetItemId

## Description

Gets the ID of the item that is specified in the exception.

## Parameters

### `pbItemId` [in, out]

Returns the ID of the item that is specified in the exception.

### `pcbIdSize` [in, out]

Specifies the number of bytes in *pbItemId*. Returns the number of bytes required to retrieve the ID when *pbItemId* is too small, or returns the number of bytes written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** |  |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pbItemId* is too small. In this case, the required number of bytes is returned in *pcbIdSize*. |

## See also

[ISingleItemException Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isingleitemexception)