## Description

Specifies support flags for motion search in video encoding.

## Constants

### `D3D12_VIDEO_ENCODER_MOTION_SEARCH_SUPPORT_FLAG_NONE` : 0x0

Indicates no support for the given input parameters.

### `D3D12_VIDEO_ENCODER_MOTION_SEARCH_SUPPORT_FLAG_SUPPORTED` : 0x1

Indicates support for the given input parameters.

### `D3D12_VIDEO_ENCODER_MOTION_SEARCH_SUPPORT_FLAG_MULTIPLE_HINTS` : 0x2

For CPU buffer input, indicates that pMoveRegions can contain overlapping rects. For GPU texture input, indicates that NumHintsPerPixel can be greater than 1.

### `D3D12_VIDEO_ENCODER_MOTION_SEARCH_SUPPORT_FLAG_GPU_TEXTURE_MULTIPLE_REFERENCES` : 0x4

Indicates that each GPU motion map can have motion vectors that point to different DPB indices. When supported, the values (not equal to 255) in ppMotionVectorMapsMetadata[i] can point to different reference indices in the DPB.

## Remarks

## See also