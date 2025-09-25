# IAMExtDevice::Calibrate

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Calibrate` method calibrates an external device's transport mechanism.

This method is not implemented.

## Parameters

### `hEvent` [in]

Handle to an event. The event is signaled when the action is complete.

### `Mode` [in]

Specifies a value that activates or deactivates the calibration process:

| Value | Description |
| --- | --- |
| ED_ACTIVE | Activates the calibration process. |
| ED_INACTIVE | Deactivates the calibration process. |
| **NULL** | No action; return the calibration status in *pStatus*. |

### `pStatus` [out]

Pointer to a **long** integer that receives one of the following values:

| Value | Description |
| --- | --- |
| OATRUE | Calibration is active. |
| OAFALSE | Calibration is inactive. |

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

Use this method on certain external devices that require calibration; for example, rewinding a tape and resetting the counter, or computing the frame offset for a timecode reader.

Filters for various external devices can implement this method differently, depending on the calibration that the device needs. This method assumes the [IMediaEventSink](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediaeventsink) interface has already established an event sink, or that another event signaling method has been established.

### DV Implementation

The [MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) and UVC drivers do not support this method. The method returns E_NOTIMPL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtDevice Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamextdevice)