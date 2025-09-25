# IMFMediaSink::GetStreamSinkCount

## Description

Gets the number of stream sinks on this media sink.

## Parameters

### `pcStreamSinkCount` [out]

Receives the number of stream sinks.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The media sink's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-shutdown) method has been called. |

## See also

[IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink)

[Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/media-sinks)