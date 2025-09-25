# IAMTimecodeReader::put_VITCLine

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_VITCLine` method specifies the vertical interval line that the timecode reader will use to read timecode.

This method is not implemented.

## Parameters

### `Line` [in]

Vertical line containing timecode information (valid lines are 11-20; 0 means autoselect).

## Return value

Returns E_NOTIMPL.

## Remarks

If VITC mode is specified in the [IAMTimecodeReader::SetTCRMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtimecodereader-settcrmode) method, you must specify which line or lines will contain timecode information. To read VITC on specific multiple lines, the caller would make successive calls to `IAMTimecodeReader::put_VITCLine`, once for each line desired.

Set the high bit to add to the list of lines for readers that test across multiple lines.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTimecodeReader Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtimecodereader)

[IAMTimecodeReader::get_VITCLine](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtimecodereader-get_vitcline)