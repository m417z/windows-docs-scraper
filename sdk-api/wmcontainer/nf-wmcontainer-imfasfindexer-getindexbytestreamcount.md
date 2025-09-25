# IMFASFIndexer::GetIndexByteStreamCount

## Description

Retrieves the number of byte streams that are in use by the indexer object.

## Parameters

### `pcByteStreams` [out]

Receives the number of byte streams that are in use by the indexer object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pcByteStreams* is **NULL**. |

## See also

[ASF Index Object](https://learn.microsoft.com/windows/desktop/medfound/asf-index-object)

[IMFASFIndexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfindexer)