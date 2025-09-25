# IDvdControl::ChapterPlayAutoStop

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IDvdControl** interface is deprecated. Use [IDvdControl2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2) instread.

Instructs the DVD player to start playing at the specified chapter within the specified title and play the number of chapters specified.

## Parameters

### `ulTitle` [in]

Title number for playback.

### `ulChapter` [in]

Chapter number to start playback.

### `ulChaptersToPlay` [in]

Number of chapters to play from the start chapter.

## Return value

Returns an **HRESULT** value.

## Remarks

This method is valid in any domain. For more information, see [DVD_DOMAIN](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_domain).

Chapters range from 1 through 999. See EC_DVD_CHAPTER_AUTOSTOP in [DVD Event Notification Codes](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-notification-codes) for more information.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol)