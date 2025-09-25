# D3D12DDI_VIDEO_PROCESS_DEINTERLACE_FLAGS_0020 enumeration

## Description

Defines the deinterlacing video processor capabilities.

## Constants

### `D3D12DDI_VIDEO_PROCESS_DEINTERLACE_FLAG_0020_NONE`

No deinterlacing.

### `D3D12DDI_VIDEO_PROCESS_DEINTERLACE_FLAG_0020_BOB`

The video processor can perform bob deinterlacing. In bob deinterlacing, missing field lines are interpolated from the lines above and below. Bob deinterlacing does not require reference frames.

### `D3D12DDI_VIDEO_PROCESS_DEINTERLACE_FLAG_0020_CUSTOM`

The video processor can perform a custom high quality deinterlacing. This feature requires the number of reference frames indicated in [D3D12DDI_VIDEO_DECODE_REFERENCE_FRAMES_0032](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_decode_reference_frames_0032). If the video processor does not have the necessary number of reference frames, it falls back to bob deinterlacing.