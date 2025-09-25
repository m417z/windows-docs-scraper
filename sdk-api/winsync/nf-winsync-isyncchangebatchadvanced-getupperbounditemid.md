# ISyncChangeBatchAdvanced::GetUpperBoundItemId

## Description

Gets the highest item ID that is represented in the knowledge of any group in the change batch.

## Parameters

### `pbItemId` [in, out]

Returns the highest item ID that is represented in the knowledge of any group in the change batch.

### `pcbIdSize` [in, out]

Specifies the number of bytes in *pbItemId*. Returns the number of bytes that are necessary to retrieve the ID when *pbItemId* is too small, or returns the number of bytes written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | When *pbItemId* is too small. In this situation, the required number of bytes is returned in *pcbIdSize*. |

## See also

[ISyncChangeBatchAdvanced Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchadvanced)