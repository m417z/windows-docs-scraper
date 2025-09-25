# IMFMediaSource::CreatePresentationDescriptor

## Description

Retrieves a copy of the media source's presentation descriptor. Applications use the presentation descriptor to select streams and to get information about the source content.

## Parameters

### `ppPresentationDescriptor` [out]

Receives a pointer to the presentation descriptor's [IMFPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationdescriptor) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The media source's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-shutdown) method has been called. |

## Remarks

The presentation descriptor contains the media source's default settings for the presentation. The application can change these settings by selecting or deselecting streams, or by changing the media type on a stream. Do not modify the presentation descriptor unless the source is stopped. The changes take affect when the source's [IMFMediaSource::Start](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-start) method is called.

## See also

[IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource)

[Media Sources](https://learn.microsoft.com/windows/desktop/medfound/media-sources)