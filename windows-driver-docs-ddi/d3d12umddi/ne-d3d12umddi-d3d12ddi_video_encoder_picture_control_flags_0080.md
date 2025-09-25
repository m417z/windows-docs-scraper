## Description

The **D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_FLAGS_0080** enumeration defines the set of flags for picture control properties.

## Constants

### `D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_FLAG_0080_NONE`

No flags.

### `D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_FLAG_0080_USED_AS_REFERENCE_PICTURE`

When set, indicates that this frame will be used as a reference frame in future encode commands. This value also indicates to output the reconstructed picture along with the bitstream for the host to place it, in future calls, in the reconstructed pictures reference list. Check feature support before setting this flag because there might be limitations for some frame types to be marked as references.

> [!NOTE]
>
> If this flag is not set, **pReconstructedPicture** can be a NULL pointer on the [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) call.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_DESC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_desc_0082_0)

[**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0)