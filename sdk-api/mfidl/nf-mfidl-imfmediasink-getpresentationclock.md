# IMFMediaSink::GetPresentationClock

## Description

Gets the presentation clock that was set on the media sink.

## Parameters

### `ppPresentationClock` [out]

Receives a pointer to the presentation clock's [IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NO_CLOCK** | No clock has been set. To set the presentation clock, call [IMFMediaSink::SetPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-setpresentationclock). |
| **MF_E_SHUTDOWN** | The media sink's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-shutdown) method has been called. |

## See also

[IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink)

[Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/media-sinks)