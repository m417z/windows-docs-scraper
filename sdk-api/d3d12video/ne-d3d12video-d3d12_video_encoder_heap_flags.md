## Description

Specifies heap options for video encoding.

## Constants

### `D3D12_VIDEO_ENCODER_HEAP_FLAG_NONE`

No flags.

### `D3D12_VIDEO_ENCODER_HEAP_FLAG_ALLOW_DIRTY_REGIONS`

Indicates that the encoder heap supports dirty regions. Required when using [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_FLAG_ENABLE_DIRTY_REGIONS_INPUT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_picture_control_flags).

### `D3D12_VIDEO_ENCODER_HEAP_FLAG_ALLOW_RATE_CONTROL_FRAME_ANALYSIS`

Indicates to the driver that two pass will be used with the associated [ID3D12VideoEncoderHeap1](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoencoderheap1). The driver uses this flag to allocate and initialize the internal state required for storing two pass context in this object.

## Remarks

## See also