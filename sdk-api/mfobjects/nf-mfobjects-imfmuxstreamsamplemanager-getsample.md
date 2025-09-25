# IMFMuxStreamSampleManager::GetSample

## Description

Gets the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) associated with the substream with the specified index.

## Parameters

### `dwMuxStreamIndex` [in]

The index of the substream for which a sample is retrieved.

### `ppSample` [out]

The retrieved sample.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDSTREAMNUMBER** | The specified substream index is invalid. |
| **MF_E_INVALIDSTREAMDATA** | The stream data for the sample is invalid. |

## See also

[IMFMuxStreamSampleManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmuxstreamsamplemanager)