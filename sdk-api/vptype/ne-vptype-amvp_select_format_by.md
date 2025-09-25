# AMVP_SELECT_FORMAT_BY enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the criteria that the [Overlay Mixer Filter](https://learn.microsoft.com/windows/desktop/DirectShow/overlay-mixer-filter) should use to select the video format.

## Constants

### `AMVP_DO_NOT_CARE`

Format does not matter.

### `AMVP_BEST_BANDWIDTH`

Use the largest bandwidth.

### `AMVP_INPUT_SAME_AS_OUTPUT`

Use the same input format as output format.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)