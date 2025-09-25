# D3D12_RESOLVE_MODE enumeration

## Description

Specifies a resolve operation.

## Constants

### `D3D12_RESOLVE_MODE_DECOMPRESS:0`

Resolves compressed source samples to their uncompressed values. When using this operation, the source and destination resources must have the same sample count, unlike the min, max, and average operations that require the destination to have a sample count of 1.

### `D3D12_RESOLVE_MODE_MIN:1`

Resolves the source samples to their minimum value. It can be used with any render target or depth stencil format.

### `D3D12_RESOLVE_MODE_MAX:2`

Resolves the source samples to their maximum value. It can be used with any render target or depth stencil format.

### `D3D12_RESOLVE_MODE_AVERAGE:3`

Resolves the source samples to their average value. It can be used with any non-integer render target format, including the depth plane. It can't be used with integer render target formats, including the stencil plane.

## Remarks

This enum is used by the [ID3D12GraphicsCommandList1::ResolveSubresourceRegion](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist1-resolvesubresourceregion) function.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)