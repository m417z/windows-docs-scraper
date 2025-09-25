# D3D12DDI_VIDEO_CODED_INTERLACE_TYPE_0020 enumeration

## Description

Indicates whether the compressed stream contains only frames (PROGRESSIVE_ONLY) or may contain a mix of progressive and interlaced frames (FIELDS).

## Constants

### `D3D12DDI_VIDEO_CODED_INTERLACE_TYPE_0020_NONE`

The coded video stream contains only progressive frames.

### `D3D12DDI_VIDEO_CODED_INTERLACE_TYPE_0020_FIELD_BASED`

The coded video stream may contain a mix of progressive and interlaced frames.

## Remarks

With H.264 for instance, D3D12DDI_VIDEO_CODED_TYPE_FIELDS is used for both PAFF (picture adaptive frame field) and MBAFF (macroblock-level adaptive frame/field).