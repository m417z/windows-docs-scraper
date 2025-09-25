# D3D12_CLEAR_FLAGS enumeration

## Description

Specifies what to clear from the depth stencil view.

## Constants

### `D3D12_CLEAR_FLAG_DEPTH:0x1`

Indicates the depth buffer should be cleared.

### `D3D12_CLEAR_FLAG_STENCIL:0x2`

Indicates the stencil buffer should be cleared.

## Remarks

This enum is used by [ID3D12GraphicsCommandList::ClearDepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-cleardepthstencilview).
The flags can be combined to clear all.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)