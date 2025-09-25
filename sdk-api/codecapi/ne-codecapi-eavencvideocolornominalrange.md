# eAVEncVideoColorNominalRange enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the nominal range for a video source. This enumeration is used with the [AVEncVideoInputChromaSubsampling](https://learn.microsoft.com/windows/desktop/DirectShow/avencvideoinputchromasubsampling-property) and [AVEncVideoOutputChromaSubsampling](https://learn.microsoft.com/windows/desktop/DirectShow/avencvideooutputchromasubsampling-property) properties.

The nominal range describes how luma components normalized to a range of [0..1] map to 8-bit or 10-bit samples. The mapping determines whether the color data includes headroom and toeroom. Headroom allows for values beyond 1.0 white ("whiter than white"), and toeroom allows for values below reference 0.0 black ("blacker than black").

## Constants

### `eAVEncVideoColorNominalRange_SameAsSource:0`

Use the same nominal range as the input video. This flag applies to the **AVEncVideoOutputChromaSubsampling** property only.

### `eAVEncVideoColorNominalRange_0_255:1`

The normalized range [0..1] maps to [0...255] for 8-bit samples, or [0..1023] for 10-bit samples.

### `eAVEncVideoColorNominalRange_16_235:2`

The normalized range [0..1] maps to [16...235] for 8-bit samples, or [64..940] for 10-bit samples.

### `eAVEncVideoColorNominalRange_48_208:3`

The normalized range [0..1] maps to [48...208] for 8-bit samples.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)