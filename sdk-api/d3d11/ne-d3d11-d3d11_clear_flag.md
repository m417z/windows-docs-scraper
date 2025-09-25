# D3D11_CLEAR_FLAG enumeration

## Description

Specifies the parts of the depth stencil to clear.

## Constants

### `D3D11_CLEAR_DEPTH:0x1L`

Clear the depth buffer, using fast clear if possible, then place the resource in a compressed state.

### `D3D11_CLEAR_STENCIL:0x2L`

Clear the stencil buffer, using fast clear if possible, then place the resource in a compressed state.

## Remarks

These flags are used when calling [ID3D11DeviceContext::ClearDepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-cleardepthstencilview); the flags can be combined with a bitwise OR.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-enums)