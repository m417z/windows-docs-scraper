# D3D12_RT_FORMAT_ARRAY structure

## Description

Wraps an array of render target formats.

## Members

### `RTFormats`

Specifies a fixed-size array of DXGI_FORMAT values that define the format of up to 8 render targets.

### `NumRenderTargets`

Specifies the number of render target formats stored in the array.

## Remarks

This structure is primarily intended to be used when creating pipeline state stream descriptions that contain multiple contiguous render target format descriptions.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)