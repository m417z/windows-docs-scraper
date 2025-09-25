# IMFMediaStream::GetMediaSource

## Description

Retrieves a pointer to the media source that created this media stream.

## Parameters

### `ppMediaSource` [out]

Receives a pointer to the [IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource) interface of the media source. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The media source's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-shutdown) method has been called. |

## See also

[IMFMediaStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediastream)

[Media Sources](https://learn.microsoft.com/windows/desktop/medfound/media-sources)