## Description

Specifies flags for move region info in video encoding.

## Constants

### `D3D12_VIDEO_ENCODER_MOVEREGION_INFO_FLAG_NONE` : 0x0

No flags.

### `D3D12_VIDEO_ENCODER_MOVEREGION_INFO_FLAG_MULTIPLE_HINTS` : 0x1

Indicates that pMoveRegions contains overlapped rects, producing multiple hints for positions where the overlap occurs. Check support with D3D12_VIDEO_ENCODER_MOTION_SEARCH_SUPPORT_FLAG_MULTIPLE_HINTS before using this flag.

## Remarks

## See also