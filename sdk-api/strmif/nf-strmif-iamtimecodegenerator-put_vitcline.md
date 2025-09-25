# IAMTimecodeGenerator::put_VITCLine

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_VITCLine` method specifies which line to insert the vertical interval timecode information into.

## Parameters

### `Line` [in]

Vertical line to contain the timecode information (valid lines are 11-20; 0 means autoselect).

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

To generate VITC on specific multiple lines, make successive calls to this method, once for each line desired.

Set the high bit to add to this line to any previously set lines.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTimecodeGenerator Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtimecodegenerator)

[IAMTimecodeGenerator::get_VITCLine](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtimecodegenerator-get_vitcline)