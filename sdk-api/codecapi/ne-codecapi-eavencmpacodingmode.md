# eAVEncMPACodingMode enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the MPEG audio encoding mode. This enumeration is used with the [AVEncMPACodingMode](https://learn.microsoft.com/windows/desktop/DirectShow/avencmpacodingmode-property) property.

## Constants

### `eAVEncMPACodingMode_Mono:0`

Single channel.
This mode corresponds to single_channel mode (bit code '11'), defined in ISO/IEC 11172-3.

### `eAVEncMPACodingMode_Stereo:1`

Stereo channels.
This mode corresponds to stereo mode ('00'), defined in ISO/IEC 11172-3.

### `eAVEncMPACodingMode_DualChannel:2`

Two mono channels.
This mode corresponds to dual_channel mode ('10'), defined in ISO/IEC 11172-3.

### `eAVEncMPACodingMode_JointStereo:3`

Joint stereo mode. This mode uses similarities between the two channels to achieve greater compression. This mode corresponds to joint_stereo mode ('01'), defined in ISO/IEC 11172-3.

### `eAVEncMPACodingMode_Surround:4`

Surround audio (5.1 channels).
This mode applies to MPEG-2 audio (ISO/IEC 13818-3).

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)