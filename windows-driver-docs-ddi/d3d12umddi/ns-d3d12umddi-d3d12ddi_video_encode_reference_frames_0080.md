## Description

The **D3D12DDI_VIDEO_ENCODE_REFERENCE_FRAMES_0080** structure encapsulates the reconstructed reference images for the encoding operation.

## Members

### `NumTexture2Ds`

Number of textures in the array.

### `hDrvTexture2Ds`

Pointer to the array of textures.

### `pSubresources`

Pointer to an array of sub-resource indices for the reference textures in **hDrvTexture2Ds**. A value of NULL indicates that sub-resource 0 should be assumed for each resource. With texture arrays within a single resource, the sub-resource indices point to the array index of the first resource plane. With an array of textures in individual resources, the sub-resource index is typically zero.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_DESC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_desc_0082_0)