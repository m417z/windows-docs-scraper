# IAMTimecodeReader::get_VITCLine

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_VITCLine` method retrieves the vertical interval line that the timecode reader is using to read timecode.

This method is not implemented.

## Parameters

### `pLine` [out]

Pointer to the vertical line containing timecode information (valid lines are from 11 through 20).

## Return value

Returns E_NOTIMPL.

## Remarks

The high bit indicates that multiple lines are used and successive calls will cycle through the line numbers.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTimecodeReader Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtimecodereader)

[IAMTimecodeReader::put_VITCLine](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtimecodereader-put_vitcline)