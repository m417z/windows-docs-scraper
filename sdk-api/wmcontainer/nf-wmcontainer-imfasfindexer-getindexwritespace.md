# IMFASFIndexer::GetIndexWriteSpace

## Description

Retrieves the size, in bytes, of the buffer required to store the completed index.

## Parameters

### `pcbIndexWriteSpace` [out]

Receives the size of the index, in bytes

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INDEX_NOT_COMMITTED** | The index has not been committed. For more information; see Remarks. |

## Remarks

Use this method to get the size of the index and then allocate a buffer big enough to hold it.

The index must be committed with a call to[IMFASFIndexer::CommitIndex](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-commitindex) before calling **IMFASFIndexer::GetIndexWriteSpace**. If the index is not committed before **GetIndexWriteSpace** is called, then MF_E_INDEX_NOT_COMMITTED will be returned as a result.

Call [IMFASFIndexer::GetCompletedIndex](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-getcompletedindex) to write the completed index into a media buffer.

You cannot use this method in a reading scenario. You can only use this method when writing indexes.

## See also

[ASF Index Object](https://learn.microsoft.com/windows/desktop/medfound/asf-index-object)

[IMFASFIndexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfindexer)