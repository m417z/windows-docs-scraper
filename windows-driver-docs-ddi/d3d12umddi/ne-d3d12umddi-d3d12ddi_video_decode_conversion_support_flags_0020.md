# D3D12DDI_VIDEO_DECODE_CONVERSION_SUPPORT_FLAGS_0020 enumeration

## Description

Contains flags for support of video decode conversion.

## Constants

### `D3D12DDI_VIDEO_DECODE_CONVERSION_SUPPORT_FLAG_0020_NONE`

No Flags set. The conversion is not supported.

### `D3D12DDI_VIDEO_DECODE_CONVERSION_SUPPORT_FLAG_0020_SUPPORTED`

The conversion is supported. Callers must inspect the **ClosestWidth** and **ClosestHeight** members to understand scale support.