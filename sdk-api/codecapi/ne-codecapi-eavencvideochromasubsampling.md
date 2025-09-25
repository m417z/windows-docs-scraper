# eAVEncVideoChromaSubsampling enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies chroma siting. Chroma siting defines the positions of the chroma samples relative to the luma samples. This enumeration is used with the [AVEncVideoInputChromaSubsampling](https://learn.microsoft.com/windows/desktop/DirectShow/avencvideoinputchromasubsampling-property) and [AVEncVideoOutputChromaSubsampling](https://learn.microsoft.com/windows/desktop/DirectShow/avencvideooutputchromasubsampling-property) properties.

## Constants

### `eAVEncVideoChromaSubsamplingFormat_SameAsSource:0`

Use the same chroma siting as the input video. This flag applies to the **AVEncVideoOutputChromaResolution** property only. This flag may not be combined with other flags.

### `eAVEncVideoChromaSubsamplingFormat_ProgressiveChroma:0x8`

Chroma should be reconstructed as if the underlying video was progressive content, rather than skipping fields or applying chroma filtering to minimize artifacts from reconstructing 4:2:0 interlaced chroma.

### `eAVEncVideoChromaSubsamplingFormat_Horizontally_Cosited:0x4`

Chroma samples are aligned horizontally with multiples of the luma samples.

### `eAVEncVideoChromaSubsamplingFormat_Vertically_Cosited:0x2`

Chroma samples are aligned vertically with multiples of the luma samples.

### `eAVEncVideoChromaSubsamplingFormat_Vertically_AlignedChromaPlanes:0x1`

The chroma planes have the same phase alignment. It is not valid to omit this flag unless the data is vertically cosited. If the data is not vertically cosited, this flag is required. If this flag is absent, the Cb and Cr samples are sited on alternate lines. For example, interlaced PAL DV video uses non-aligned chroma planes.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)