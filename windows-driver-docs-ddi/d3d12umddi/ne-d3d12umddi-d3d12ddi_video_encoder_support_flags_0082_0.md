## Description

The **D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAGS_0082_0** enumeration reports the support for a given configuration. Use [**D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAGS_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_support_flags_0083_0) for windows 11 (WDDM 3.0).

## Constants

### `D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAG_0082_0_NONE`

No flags are set (indicates no support).

### `D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAG_0082_0_GENERAL_SUPPORT_OK`

Indicates whether the given configuration is generally supported by the encoder, in combination with the remaining flags to convey certain limitations or no general support. The D3D12 Debug layer can provide further information.

### `D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAG_0082_0_RATE_CONTROL_RECONFIGURATION_AVAILABLE`

Indicates support for changing the rate control in the middle of the encoding session.

### `D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAG_0082_0_RESOLUTION_RECONFIGURATION_AVAILABLE`

Indicates support for changing the resolution in the middle of the encoding session.

### `D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAG_0082_0_RATE_CONTROL_VBV_SIZE_CONFIG_AVAILABLE`

When set, enables configuring the video buffering verifier (VBV) initial fullness and capacity for rate control algorithms.

### `D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAG_0082_0_RATE_CONTROL_FRAME_ANALYSIS_AVAILABLE`

Indicates support for rate control modes that involve frame analysis to optimize the bitrate usage at the cost of slower performance.

### `D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAG_0082_0_RECONSTRUCTED_FRAMES_REQUIRE_CONTIGUOUS_TEXTURE_ARRAYS`

When set, textures that refer reconstructed pictures can only be referenced as a texture array, as opposed to an array of separate texture 2D resources with each resource having array size of 1.

### `D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAG_0082_0_RATE_CONTROL_DELTA_QP_AVAILABLE`

Indicates support for delta quantization parameter (QP) usage in rate control.

### `D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAG_0082_0_SUBREGION_LAYOUT_RECONFIGURATION_AVAILABLE`

Indicates support for dynamic subregion layout changes during an encoding session.

### `D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAG_0082_0_RATE_CONTROL_ADJUSTABLE_QP_RANGE_AVAILABLE`

Indicates support for adjustable QP range in rate control.

### `D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAG_0082_0_RATE_CONTROL_INITIAL_QP_AVAILABLE`

Indicates support for adjustable initial QP in rate control.

### `D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAG_0082_0_RATE_CONTROL_MAX_FRAME_SIZE_AVAILABLE`

Indicates support for setting a maximum cap in the bitrate algorithm per each encoded frame.

### `D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAG_0082_0_SEQUENCE_GOP_RECONFIGURATION_AVAILABLE`

Indicates support for dynamic group of pictures (GOP) changes during an encoding session.

## Remarks

Use [**D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAGS_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_support_flags_0083_0) for windows 11 (WDDM 3.0).