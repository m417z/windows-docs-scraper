# ISyncFilterInfo::Serialize

## Description

Serializes the filter data to an array of bytes.

## Parameters

### `pbBuffer` [in, out]

Returns the serialized filter information. Set this value to **NULL** to request the required size of the buffer.

### `pcbBuffer` [in, out]

Specifies the number of bytes in *pbBuffer*. Returns the number of bytes required to serialize the filter when *pcbBuffer* is too small, or the number of bytes written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** |  |
| **0x800700EA (HRESULT_FROM_WIN32(ERROR_MORE_DATA))** | *pbBuffer* is **NULL** or *pcbBuffer* is too small. In this case, the number of bytes required to serialize the filter is returned in *pcbBuffer*. |

## See also

[ISyncFilterInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncfilterinfo)