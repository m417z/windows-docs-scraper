# IAMTimecodeGenerator::GetTimecode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetTimecode` method retrieves the most recent timecode and/or userbit value available in the stream.

## Parameters

### `pTimecodeSample` [out]

Pointer to a [TIMECODE_SAMPLE](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-timecode_sample) structure.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

Use this method to obtain the most recent timecode value available in the stream. The application can use this to monitor the timecode and verify the generator is working properly.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTimecodeGenerator Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtimecodegenerator)

[IAMTimecodeGenerator::SetTimecode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtimecodegenerator-settimecode)