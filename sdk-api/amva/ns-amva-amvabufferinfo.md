# AMVABUFFERINFO structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AMVABUFFERINFO** structure specifies a buffer for the
[IAMVideoAccelerator::Execute](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-execute) method.

## Members

### `dwTypeIndex`

Type of buffer. The following buffer types are defined.

| Value | Meaning |
| --- | --- |
| **DXVA_ALPHA_BLEND_COMBINATION_BUFFER** | Alpha blend combination buffer. |
| **DXVA_AYUV_BUFFER** | AYUV alpha blending sample buffer. |
| **DXVA_BITSTREAM_DATA_BUFFER** | Raw bitstream data buffer. |
| **DXVA_DCCMD_SURFACE_BUFFER** | Display control command (DCCMD) data buffer. |
| **DXVA_DEBLOCKING_CONTROL_BUFFER** | Deblocking Filter control command buffer. |
| **DXVA_DPXD_SURFACE_BUFFER** | Decoded PXD (DPXD) alpha blending surface buffer. |
| **DXVA_HIGHLIGHT_BUFFER** | Highlight data buffers. |
| **DXVA_IA44_SURFACE_BUFFER** | IA44 alpha blending sample buffer. |
| **DXVA_INVERSE_QUANTIZATION_MATRIX_BUFFER** | Inverse quantization matrix buffer. |
| **DXVA_MACROBLOCK_CONTROL_BUFFER** | Macroblock control command buffer. |
| **DXVA_PICTURE_DECODE_BUFFER** | Picture parameters buffer. |
| **DXVA_PICTURE_RESAMPLE_BUFFER** | Alpha blend combination buffer. |
| **DXVA_READ_BACK_BUFFER** | Read-back command buffers containing commands to read macroblocks of the resulting picture back to the host. |
| **DXVA_RESIDUAL_DIFFERENCE_BUFFER** | Residual difference block data buffer. |
| **DXVA_SLICE_CONTROL_BUFFER** | Slice control buffer. |

For complete descriptions of these buffer types, refer to the DirectX Video Acceleration 1.0 specification.

### `dwBufferIndex`

Buffer index.

### `dwDataOffset`

The offset of the relevant data from the beginning of the buffer.

### `dwDataSize`

Size of the relevant data in the buffer, in bytes.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[IAMVideoAccelerator::Execute](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-execute)