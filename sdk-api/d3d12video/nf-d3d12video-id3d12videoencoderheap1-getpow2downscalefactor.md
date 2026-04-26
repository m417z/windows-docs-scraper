## Description

Gets the power-of-two downscale factor for the video encoder heap.

## Return value

When the [ID3D12VideoEncoderHeap1](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoencoderheap1) object was created with [D3D12_VIDEO_ENCODER_HEAP_FLAG_ALLOW_RATE_CONTROL_FRAME_ANALYSIS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_heap_flags), returns the value of *Pow2DownscaleFactor* used at creation. Zero otherwise.

## Remarks

## See also

[ID3D12VideoEncoderHeap1](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoencoderheap1)

[D3D12_VIDEO_ENCODER_HEAP_DESC1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_heap_desc1)