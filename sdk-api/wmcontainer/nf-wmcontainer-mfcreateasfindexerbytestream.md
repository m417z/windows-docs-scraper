# MFCreateASFIndexerByteStream function

## Description

Creates a byte stream to access the index in an ASF stream.

## Parameters

### `pIContentByteStream` [in]

Pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of a byte stream that contains the ASF stream.

### `cbIndexStartOffset` [in]

Byte offset of the index within the ASF stream. To get this value, call [IMFASFIndexer::GetIndexPosition](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-getindexposition).

### `pIIndexByteStream` [out]

Receives a pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface. Use this interface to read from the index or write to the index. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table:

| Return code | Description |
| --- | --- |
| **S_OK** | The call succeeded. |
| **MF_E_UNEXPECTED** | The offset specified in *cbIndexStartOffset* is invalid. |

## See also

[ASF Index Object](https://learn.microsoft.com/windows/desktop/medfound/asf-index-object)

[IMFASFIndexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfindexer)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)