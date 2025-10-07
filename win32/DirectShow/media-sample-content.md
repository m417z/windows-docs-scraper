# MEDIA\_SAMPLE\_CONTENT enumeration

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Describes the contents of an elementary stream within an MPEG-2 transport stream. This enumeration is used in the [**IMPEG2PIDMap**](https://learn.microsoft.com/previous-versions/windows/desktop/api/Bdaiface/nn-bdaiface-impeg2pidmap) interface, which is implemented on the output pins of the [MPEG-2 Demultiplexer](https://learn.microsoft.com/windows/win32/directshow/mpeg-2-demultiplexer).

## Constants

**MEDIA\_TRANSPORT\_PACKET**

Specifies a complete transport stream packet to be passed through without processing.

**MEDIA\_ELEMENTARY\_STREAM**

Specifies an audio or video PES payload.

**MEDIA\_MPEG2\_PSI**

Specifies a PAT, PMT, CAT, or Private data stream. These are complete PSI sections which do not need to be reassembled.

**MEDIA\_TRANSPORT\_PAYLOAD**

Specifies gathered TS packet payloads, such as PES packets.

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------------------------|
| Header<br> | Bdatypes.h (include Bdaiface.h) |

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/win32/directshow/directshow-enumerated-types)

