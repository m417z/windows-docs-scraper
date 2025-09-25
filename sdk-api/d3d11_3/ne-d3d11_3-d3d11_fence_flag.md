# D3D11_FENCE_FLAG enumeration

## Description

Specifies fence options.

## Constants

### `D3D11_FENCE_FLAG_NONE:0`

No options are specified.

### `D3D11_FENCE_FLAG_SHARED:0x2`

The fence is shared.

### `D3D11_FENCE_FLAG_SHARED_CROSS_ADAPTER:0x4`

The fence is shared with another GPU adapter.

### `D3D11_FENCE_FLAG_NON_MONITORED:0x8`

## Remarks

This enum is used by the [ID3D11Device::CreateFence](https://learn.microsoft.com/windows/desktop/api/d3d11_4/nf-d3d11_4-id3d11device5-createfence) method.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-enums)