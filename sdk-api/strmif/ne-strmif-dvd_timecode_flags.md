# DVD_TIMECODE_FLAGS enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Indicates the frame rate at which a DVD has been authored to play.

## Constants

### `DVD_TC_FLAG_25fps:0x1`

Disc is authored to play at 25 frames per second.

### `DVD_TC_FLAG_30fps:0x2`

Disc is authored to play at 30 frames per second.

### `DVD_TC_FLAG_DropFrame:0x4`

Disc is authored to play at 29.97 frames per second.

### `DVD_TC_FLAG_Interpolated:0x8`

Value representing the [DVD Navigator Filter](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) filter's best estimate of the disc's frame rate.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IDvdInfo2::GetTotalTitleTime](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-gettotaltitletime)