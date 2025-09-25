# eAVEncVideoColorTransferMatrix enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the conversion matrix from the Y'Cb'Cr' color space to the R'G'B' color space. This enumeration is used with the [AVEncVideoInputColorTransferMatrix](https://learn.microsoft.com/windows/desktop/DirectShow/avencvideoinputcolortransfermatrix-property) and [AVEncVideoOutputColorTransferMatrix](https://learn.microsoft.com/windows/desktop/DirectShow/avencvideooutputcolortransfermatrix-property) properties.

## Constants

### `eAVEncVideoColorTransferMatrix_SameAsSource:0`

Use the same transfer matrix as the input video. This flag applies to the **AVEncVideoOutputColorTransferMatrix** property only.

### `eAVEncVideoColorTransferMatrix_BT709:1`

ITU-R BT.709 transfer matrix.

### `eAVEncVideoColorTransferMatrix_BT601:2`

ITU-R BT.601 transfer matrix.

### `eAVEncVideoColorTransferMatrix_SMPTE240M:3`

SMPTE 240M transfer matrix.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)