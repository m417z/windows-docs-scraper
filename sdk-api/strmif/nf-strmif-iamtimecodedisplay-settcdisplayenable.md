# IAMTimecodeDisplay::SetTCDisplayEnable

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetTCDisplayEnable` method enables or disables an external device's timecode character output generator.

## Parameters

### `State` [in]

Value specifying whether to enable or disable the timecode character output generator. Specify OATRUE to enable or OAFALSE to disable.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

This method is not intended for rendering characters inside a filter graph, it is purely intended for hardware displays. Ensure that your external timecode reader or generator has display capability before trying to use this method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTimecodeDisplay Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtimecodedisplay)

[IAMTimecodeDisplay::GetTCDisplayEnable](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtimecodedisplay-gettcdisplayenable)