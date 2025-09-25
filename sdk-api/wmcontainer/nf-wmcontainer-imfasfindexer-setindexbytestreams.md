# IMFASFIndexer::SetIndexByteStreams

## Description

Adds byte streams to be indexed.

## Parameters

### `ppIByteStreams` [in]

An array of [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface pointers. To get the byte stream, call [MFCreateASFIndexerByteStream](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-mfcreateasfindexerbytestream).

### `cByteStreams` [in]

The number of pointers in the *ppIByteStreams* array.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_ALREADY_INITIALIZED** | The indexer object has already been initialized and it has packets which have been indexed. |

## Remarks

For a reading scenario, only one byte stream should be used by the indexer object. For an index generating scenario, it depends how many index objects are needed to be generated.

## See also

[ASF Index Object](https://learn.microsoft.com/windows/desktop/medfound/asf-index-object)

[IMFASFIndexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfindexer)