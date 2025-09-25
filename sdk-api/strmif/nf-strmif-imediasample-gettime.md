# IMediaSample::GetTime

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetTime` method retrieves the stream times at which this sample should begin and finish.

## Parameters

### `pTimeStart` [out]

Pointer to a variable that receives the start time.

### `pTimeEnd` [out]

Pointer to a variable that receives the stop time. If the sample has no stop time, the value is set to the start time plus one.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. The sample has valid start and stop times. |
| **VFW_S_NO_STOP_TIME** | The sample has a valid start time, but no stop time. |
| **VFW_E_SAMPLE_TIME_NOT_SET** | The sample is not time-stamped. |

## Remarks

Both time values are relative to the stream time. For more information, see [Time and Clocks in DirectShow](https://learn.microsoft.com/windows/desktop/DirectShow/time-and-clocks-in-directshow).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSample Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample)