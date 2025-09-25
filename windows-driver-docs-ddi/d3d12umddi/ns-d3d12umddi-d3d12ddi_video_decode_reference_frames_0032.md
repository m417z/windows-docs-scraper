# D3D12DDI_VIDEO_DECODE_REFERENCE_FRAMES_0032 structure

## Description

Contains the list of reference frames for the current decode operation. Either a Texture Array or an array of textures can be specified.

## Members

### `hDrvTexture2Ds`

The list of reference textures.

### `pSubresources`

An array of subresource indices for the list of reference textures. NULL indicates a subresource of 0 for each resource.

### `hDrvVideoDecoderHeaps`

Supplies the heap object for a corresponding reference frame. NULL indicates that decoder state allocations for all references is included with the decoder heap in the input stream arguments.
Typically, this parameter is null. VP9 uses this parameter when changing resolution on a non-key frame.

### `NumTexture2Ds`

The number of reference textures.

## Remarks

This structure sets the list of reference frames for the current decode operation. Decode profiles reporting D3D12DDI_VIDEO_DECODE_TIER_1 or D3D12DDI_VIDEO_DECODE_TIER_2 requires the use of a texture array, so the list of hDrvTexture2Ds will always be the same texture and pSubresources is used to index into the texture array. For D3D12DDI_VIDEO_DECODE_TIER_3, either a Texture Array or an array of textures can be specified.