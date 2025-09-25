# IMFMediaStream::GetStreamDescriptor

## Description

Retrieves a stream descriptor for this media stream.

## Parameters

### `ppStreamDescriptor` [out]

Receives a pointer to the [IMFStreamDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamdescriptor) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The media source's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-shutdown) method has been called. |

## Remarks

Do not modify the stream descriptor. To change the presentation, call [IMFMediaSource::CreatePresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-createpresentationdescriptor) and modify the presentation descriptor.

## See also

[IMFMediaStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediastream)

[Media Sources](https://learn.microsoft.com/windows/desktop/medfound/media-sources)