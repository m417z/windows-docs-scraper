# DVD_VideoAttributes structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DVD_VideoAttributes` structure describes the attributes of the video stream for the current title or menu.

## Members

### `fPanscanPermitted`

**TRUE** means the picture can be shown as pan-scan if the display aspect ratio is 4 x 3.

### `fLetterboxPermitted`

**TRUE** means the picture can be shown as letterbox if the display aspect ratio is 4 x 3.

### `ulAspectX`

The video stream's X aspect (4 or 16).

### `ulAspectY`

The video stream's Y aspect (3 or 9).

### `ulFrameRate`

The frame rate in hertz (Hz), either 50 or 60.

### `ulFrameHeight`

The frame height in lines (525 for a frame rate of 60 Hz or 625 for 50 Hz).

### `Compression`

Variable of type [DVD_VIDEO_COMPRESSION](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_video_compression) indicating the MPEG compression type used on the disc.

### `fLine21Field1InGOP`

**TRUE** means there is user data in line 21, field 1.

### `fLine21Field2InGOP`

**TRUE** means there is user data in line 21, field 2.

### `ulSourceResolutionX`

The x-axis source resolution (352, 704, or 720).

### `ulSourceResolutionY`

The y-axis source resolution (240, 480, 288, or 576).

### `fIsSourceLetterboxed`

**TRUE** means the source video is in letterbox format. Subpictures and menu buttons can only be displayed in the active video area.

### `fIsFilmMode`

For 625/50 Hz systems, **TRUE** means "film mode" and **FALSE** means "camera mode."

## Remarks

This structure is filled when an application calls the [IDvdInfo2::GetCurrentVideoAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getcurrentvideoattributes) method.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)