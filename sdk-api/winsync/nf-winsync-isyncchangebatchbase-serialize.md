# ISyncChangeBatchBase::Serialize

## Description

Serializes the change batch to an array of bytes.

## Parameters

### `pbChangeBatch` [in, out]

The byte array that receives the change batch data.

### `pcbChangeBatch` [in, out]

Specifies the number of bytes in *pbChangeBatch*. Returns the number of bytes required for *pbChangeBatch* when *pbChangeBatch* is too small, or the number of bytes written to *pbChangeBatch* when data is written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** |  |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pbChangeBatch* is too small. In this case, the required number of bytes is stored in *pcbChangeBatch*. |
| **SYNC_E_INVALID_OPERATION** | The last group added to the batch was not ended. |

## See also

[ISyncChangeBatchBase Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchbase)

[SyncSerializationVersion Enumeration](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-sync_serialization_version)