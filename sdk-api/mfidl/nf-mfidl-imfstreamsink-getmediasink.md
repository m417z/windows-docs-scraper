# IMFStreamSink::GetMediaSink

## Description

Retrieves the media sink that owns this stream sink.

## Parameters

### `ppMediaSink` [out]

Receives a pointer to the media sink's [IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The media sink's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-shutdown) method has been called. |
| **MF_E_STREAMSINK_REMOVED** | This stream was removed from the media sink and is no longer valid. |

## See also

[IMFStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamsink)

[Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/media-sinks)