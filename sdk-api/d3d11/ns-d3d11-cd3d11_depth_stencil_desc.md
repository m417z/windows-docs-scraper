# CD3D11_DEPTH_STENCIL_DESC structure

## Description

Represents a depth-stencil-state structure and provides convenience methods for creating depth-stencil-state structures.

## Members

## Remarks

Here is how D3D11.h defines **CD3D11_DEPTH_STENCIL_DESC**:

|  |
| --- |
| ``` struct CD3D11_DEPTH_STENCIL_DESC : public D3D11_DEPTH_STENCIL_DESC {     CD3D11_DEPTH_STENCIL_DESC()     {}     explicit CD3D11_DEPTH_STENCIL_DESC( const D3D11_DEPTH_STENCIL_DESC& o ) :         D3D11_DEPTH_STENCIL_DESC( o )     {}     explicit CD3D11_DEPTH_STENCIL_DESC( CD3D11_DEFAULT )     {         DepthEnable = TRUE;         DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;         DepthFunc = D3D11_COMPARISON_LESS;         StencilEnable = FALSE;         StencilReadMask = D3D11_DEFAULT_STENCIL_READ_MASK;         StencilWriteMask = D3D11_DEFAULT_STENCIL_WRITE_MASK;         const D3D11_DEPTH_STENCILOP_DESC defaultStencilOp =         { D3D11_STENCIL_OP_KEEP, D3D11_STENCIL_OP_KEEP, D3D11_STENCIL_OP_KEEP, D3D11_COMPARISON_ALWAYS };         FrontFace = defaultStencilOp;         BackFace = defaultStencilOp;     }     explicit CD3D11_DEPTH_STENCIL_DESC(         BOOL depthEnable,         D3D11_DEPTH_WRITE_MASK depthWriteMask,         D3D11_COMPARISON_FUNC depthFunc,         BOOL stencilEnable,         UINT8 stencilReadMask,         UINT8 stencilWriteMask,         D3D11_STENCIL_OP frontStencilFailOp,         D3D11_STENCIL_OP frontStencilDepthFailOp,         D3D11_STENCIL_OP frontStencilPassOp,         D3D11_COMPARISON_FUNC frontStencilFunc,         D3D11_STENCIL_OP backStencilFailOp,         D3D11_STENCIL_OP backStencilDepthFailOp,         D3D11_STENCIL_OP backStencilPassOp,         D3D11_COMPARISON_FUNC backStencilFunc )     {         DepthEnable = depthEnable;         DepthWriteMask = depthWriteMask;         DepthFunc = depthFunc;         StencilEnable = stencilEnable;         StencilReadMask = stencilReadMask;         StencilWriteMask = stencilWriteMask;         FrontFace.StencilFailOp = frontStencilFailOp;         FrontFace.StencilDepthFailOp = frontStencilDepthFailOp;         FrontFace.StencilPassOp = frontStencilPassOp;         FrontFace.StencilFunc = frontStencilFunc;         BackFace.StencilFailOp = backStencilFailOp;         BackFace.StencilDepthFailOp = backStencilDepthFailOp;         BackFace.StencilPassOp = backStencilPassOp;         BackFace.StencilFunc = backStencilFunc;     }     ~CD3D11_DEPTH_STENCIL_DESC() {}     operator const D3D11_DEPTH_STENCIL_DESC&() const { return *this; } }; ``` |

## See also

[CD3D11 Helper Structures](https://learn.microsoft.com/windows/desktop/direct3d11/cd3d11-helper-classes)