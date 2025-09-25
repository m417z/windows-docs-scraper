## Description

Represents the reconstructed reference images for an encoding operation.

## Members

### `NumTexture2Ds`

The number of textures in the *ppTexture2Ds* array.

### `ppTexture2Ds`

An array of [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) textures containing the reference images.

### `pSubresources`

An array of subresource indices for the reference textures specified in *ppTexture2Ds*. NULL indicates that subresource 0 should be assumed for each resource.
With texture arrays within a single resource, the subresource indices point to the array index of the first resource plane. With an array of textures in individual resources, the subresource index is typically zero.

## Remarks

## See also