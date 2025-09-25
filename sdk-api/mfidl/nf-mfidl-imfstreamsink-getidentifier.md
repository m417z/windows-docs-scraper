# IMFStreamSink::GetIdentifier

## Description

Retrieves the stream identifier for this stream sink.

## Parameters

### `pdwIdentifier` [out]

Receives the stream identifier. If this stream sink was added by calling [IMFMediaSink::AddStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-addstreamsink), the stream identifier is in the *dwStreamSinkIdentifier* parameter of that method. Otherwise, the media sink defines the identifier.

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