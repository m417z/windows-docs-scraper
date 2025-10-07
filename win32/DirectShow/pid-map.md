# PID\_MAP structure

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `PID_MAP` structure contains identifies the contents of an MPEG-2 transport stream packet ID.

## Members

**ulPID**

Specifies the packet ID (PID)

**MediaSampleContent**

Specifies the contents of the packet payload, as a [**MEDIA\_SAMPLE\_CONTENT**](https://learn.microsoft.com/windows/win32/directshow/media-sample-content) enumeration type.

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------------------------|
| Header<br> | Bdatypes.h (include Bdaiface.h) |

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/win32/directshow/directshow-structures)

[**IEnumPIDMap Interface**](https://learn.microsoft.com/previous-versions/windows/desktop/api/Bdaiface/nn-bdaiface-ienumpidmap)

