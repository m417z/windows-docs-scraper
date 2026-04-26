## Description

Specifies how subregion output buffers are passed in [D3D12_VIDEO_ENCODER_SUBREGION_COMPRESSED_BITSTREAM](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_subregion_compressed_bitstream).

## Constants

### `D3D12_VIDEO_ENCODER_SUBREGION_COMPRESSED_BITSTREAM_BUFFER_MODE_ARRAY_OF_BUFFERS`

Each subregion is written to a different [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) buffer object. Requires **D3D12_VIDEO_ENCODER_SUPPORT_FLAG_SUBREGION_NOTIFICATION_AVAILABLE_ARRAY_OF_BUFFERS** support.

### `D3D12_VIDEO_ENCODER_SUBREGION_COMPRESSED_BITSTREAM_BUFFER_MODE_SINGLE_BUFFER`

All subregions are written into the same [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) buffer. The driver partitions the buffer into non-overlapping regions. Requires **D3D12_VIDEO_ENCODER_SUPPORT_FLAG_SUBREGION_NOTIFICATION_AVAILABLE_SINGLE_BUFFER** support.

## Remarks

The associated [ID3D12VideoEncoderHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoencoderheap) must be created with the corresponding [D3D12_VIDEO_ENCODER_HEAP_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_heap_flags) flag set.

## See also

[D3D12_VIDEO_ENCODER_SUBREGION_COMPRESSED_BITSTREAM](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_subregion_compressed_bitstream)