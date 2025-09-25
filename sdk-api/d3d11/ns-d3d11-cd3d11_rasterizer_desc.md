# CD3D11_RASTERIZER_DESC structure

## Description

Represents a rasterizer-state structure and provides convenience methods for creating rasterizer-state structures.

## Members

## Remarks

Here is how D3D11.h defines **CD3D11_RASTERIZER_DESC**:

|  |
| --- |
| ``` struct CD3D11_RASTERIZER_DESC : public D3D11_RASTERIZER_DESC {     CD3D11_RASTERIZER_DESC()     {}     explicit CD3D11_RASTERIZER_DESC( const D3D11_RASTERIZER_DESC& o ) :         D3D11_RASTERIZER_DESC( o )     {}     explicit CD3D11_RASTERIZER_DESC( CD3D11_DEFAULT )     {         FillMode = D3D11_FILL_SOLID;         CullMode = D3D11_CULL_BACK;         FrontCounterClockwise = FALSE;         DepthBias = D3D11_DEFAULT_DEPTH_BIAS;         DepthBiasClamp = D3D11_DEFAULT_DEPTH_BIAS_CLAMP;         SlopeScaledDepthBias = D3D11_DEFAULT_SLOPE_SCALED_DEPTH_BIAS;         DepthClipEnable = TRUE;         ScissorEnable = FALSE;         MultisampleEnable = FALSE;         AntialiasedLineEnable = FALSE;     }     explicit CD3D11_RASTERIZER_DESC(         D3D11_FILL_MODE fillMode,         D3D11_CULL_MODE cullMode,         BOOL frontCounterClockwise,         INT depthBias,         FLOAT depthBiasClamp,         FLOAT slopeScaledDepthBias,         BOOL depthClipEnable,         BOOL scissorEnable,         BOOL multisampleEnable,         BOOL antialiasedLineEnable )     {         FillMode = fillMode;         CullMode = cullMode;         FrontCounterClockwise = frontCounterClockwise;         DepthBias = depthBias;         DepthBiasClamp = depthBiasClamp;         SlopeScaledDepthBias = slopeScaledDepthBias;         DepthClipEnable = depthClipEnable;         ScissorEnable = scissorEnable;         MultisampleEnable = multisampleEnable;         AntialiasedLineEnable = antialiasedLineEnable;     }     ~CD3D11_RASTERIZER_DESC() {}     operator const D3D11_RASTERIZER_DESC&() const { return *this; } }; ``` |

## See also

[CD3D11 Helper Structures](https://learn.microsoft.com/windows/desktop/direct3d11/cd3d11-helper-classes)