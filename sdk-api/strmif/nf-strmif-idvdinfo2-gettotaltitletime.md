# IDvdInfo2::GetTotalTitleTime

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetTotalTitleTime` method retrieves the total playback time for the current title.

## Parameters

### `pTotalTime` [out]

Pointer to a [DVD_HMSF_TIMECODE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_hmsf_timecode) structure that receives the total time in hours, minutes, seconds, and frames.

### `ulTimeCodeFlags` [out]

Receives a [DVD_TIMECODE_FLAGS](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_timecode_flags) value indicating the frame rate at which the disc was authored to play. Specify **NULL** if you don't want to receive the timecode information.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | Invalid argument. |
| **VFW_E_DVD_INVALIDDOMAIN** | The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) is not in the title domain. |
| **VFW_S_DVD_NON_ONE_SEQUENTIAL** | The title is not a one sequential video title, so the timing information might not be continuous. |

## Remarks

The total title time is the time required to play the title sequentially, not counting any stills, pauses, and so on.

This method is for use only with *one sequential video titles*, which are titles such as movies in which each chapter automatically branches to the next chapter so that the entire title plays continuously without stopping. *Nonsequential video titles* are titles whose chapters do not automatically play one after another. Because of variations in how DVD authors encode time information on nonsequential video titles, do not use this method to determine the total time for such titles.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)