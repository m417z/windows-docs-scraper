# D3D12DDI_VIDEO_DECODE_SUPPORT_FLAGS_0020 enumeration

## Description

Contains video decode support flags.

## Constants

### `D3D12DDI_VIDEO_DECODE_SUPPORT_FLAG_0020_NONE`

No Flags set.

### `D3D12DDI_VIDEO_DECODE_SUPPORT_FLAG_0020_SUPPORTED`

Indicates if real-time decoding is supported with the specified input data. The presence of this flag is a hint that the decoder is capable of decoding the compressed bitstream fast enough to support realtime decoding. The absence of this flag indicates that the decoder with the specified input parameters is only appropriate for non-realtime scenarios like transcoding.