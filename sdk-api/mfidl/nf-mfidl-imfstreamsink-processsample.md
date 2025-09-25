# IMFStreamSink::ProcessSample

## Description

Delivers a sample to the stream. The media sink processes the sample.

## Parameters

### `pSample` [in]

Pointer to the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface of a sample that contains valid data for the stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALID_STATE_TRANSITION** | The media sink is in the wrong state to receive a sample. For example, preroll is complete but the presentation clock has not started yet. |
| **MF_E_INVALID_TIMESTAMP** | The sample has an invalid time stamp. See Remarks. |
| **MF_E_INVALIDREQUEST** | The media sink is paused or stopped and cannot process the sample. |
| **MF_E_NO_CLOCK** | The presentation clock was not set. Call [IMFMediaSink::SetPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-setpresentationclock). |
| **MF_E_NO_SAMPLE_TIMESTAMP** | The sample does not have a time stamp. |
| **MF_E_NOT_INITIALIZED** | The stream sink has not been initialized. |
| **MF_E_SHUTDOWN** | The media sink's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-shutdown) method has been called. |
| **MF_E_STREAMSINK_REMOVED** | This stream was removed from the media sink and is no longer valid. |

## Remarks

Call this method when the stream sink sends an [MEStreamSinkRequestSample](https://learn.microsoft.com/windows/desktop/medfound/mestreamsinkrequestsample) event.

This method can return MF_E_INVALID_TIMESTAMP for various reasons, depending on the implementation of the media sink:

* Negative time stamps.
* Time stamps that jump backward (within the same stream).
* The time stamps for one stream have drifted too far from the time stamps on another stream within the same media sink (for example, an archive sink that multiplexes the streams).

Not every media sink returns an error code in these situations.

## See also

[IMFStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamsink)

[Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/media-sinks)