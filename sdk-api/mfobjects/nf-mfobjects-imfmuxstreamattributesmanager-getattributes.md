# IMFMuxStreamAttributesManager::GetAttributes

## Description

Gets the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) for the substream with the specified index.

## Parameters

### `dwMuxStreamIndex` [in]

The index of the substream for which attributes are retrieved.

### `ppStreamAttributes` [in]

The attributes for the specified substream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |
| **MF_E_INVALIDSTREAMNUMBER** | The stream specified substream index is invalid. Call [GetStreamCount](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmuxstreamattributesmanager-getstreamcount) to get the number of substreams managed by the multiplexed media source. |

## See also

[IMFMuxStreamMediaTypeManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmuxstreammediatypemanager)