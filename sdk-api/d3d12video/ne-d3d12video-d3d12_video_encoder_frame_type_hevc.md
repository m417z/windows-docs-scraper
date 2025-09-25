## Description

Specifies the type of an HEVC video frame.

## Constants

### `D3D12_VIDEO_ENCODER_FRAME_TYPE_HEVC_I_FRAME`

I-Frame. Completely intra-coded frame.

### `D3D12_VIDEO_ENCODER_FRAME_TYPE_HEVC_P_FRAME`

P-Frame. Allows references to past frames.

### `D3D12_VIDEO_ENCODER_FRAME_TYPE_HEVC_B_FRAME`

B-Frame. Allows references to both past and future (in display order) frames.

### `D3D12_VIDEO_ENCODER_FRAME_TYPE_HEVC_IDR_FRAME`

Instantaneous decode refresh frame. A special type of I-frame where no frame after it can reference any frame before it.

## Remarks

The following table lists the expected HEVC header frame type for each HEVC frame type value.

| Syntax element | Expected default value |
|---------------|---------------------------|
| D3D12_VIDEO_ENCODER_FRAME_TYPE_HEVC_I_FRAME | nal_unit_type = CRA_NUT |
| D3D12_VIDEO_ENCODER_FRAME_TYPE_HEVC_P_FRAME | nal_unit_type = TRAIL_R |
| D3D12_VIDEO_ENCODER_FRAME_TYPE_HEVC_B_FRAME | nal_unit_type = TRAIL_R |
| D3D12_VIDEO_ENCODER_FRAME_TYPE_HEVC_IDR_FRAME | nal_unit_type = IDR_W_RADL |

If [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_P_FRAMES_IMPLEMENTED_AS_LOW_DELAY_B_FRAMES](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec_configuration_support_hevc_flags) is set, it informs the caller that when encoding frames with type **D3D12_VIDEO_ENCODER_FRAME_TYPE_HEVC_P_FRAME**, they will be written as low delay B-Frames in the compressed bitstream. If bit is not set, it informs the caller P frames will be written in the compressed bitstream. Note that When operating under this mode, is the caller's responsibility to code the correct frame type in AUD_NUT and other parts of the HEVC bitstream, taking into account that P frames will be treated as generalized B frames with only references to past frames in POC order.

## See also