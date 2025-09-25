# IDvdControl::AudioStreamChange

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IDvdControl** interface is deprecated. Use [IDvdControl2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2) instread.

Sets the current audio stream.

## Parameters

### `ulAudio` [in]

Value that specifies the audio track to use, which must be from 0 through 7.

## Return value

Returns an **HRESULT** value.

## Remarks

This method returns an error unless the domain is DVD_DOMAIN_VideoManagerMenu, DVD_DOMAIN_VideoTitleSetMenu, DVD_DOMAIN_Title, or DVD_DOMAIN_Stop. For more information, see [DVD_DOMAIN](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_domain).

`AudioStreamChange` affects the audio of the current Video Title Set (VTS). When called from within a menu, this method sets the audio stream of the title from which the menu was called.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol)