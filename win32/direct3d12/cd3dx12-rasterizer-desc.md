# CD3DX12\_RASTERIZER\_DESC structure

A helper structure to enable easy initialization of a [**D3D12\_RASTERIZER\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_rasterizer_desc) structure.

## Members

**CD3DX12\_RASTERIZER\_DESC()**

Creates a new, uninitialized, instance of a CD3DX12\_RASTERIZER\_DESC.

**explicit CD3DX12\_RASTERIZER\_DESC(const D3D12\_RASTERIZER\_DESC& o)**

Creates a new instance of a CD3DX12\_RASTERIZER\_DESC, initialized with the contents of another [**D3D12\_RASTERIZER\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_rasterizer_desc) structure.

**explicit CD3DX12\_RASTERIZER\_DESC(CD3DX12\_DEFAULT)**

Creates a new instance of a CD3DX12\_RASTERIZER\_DESC, initialized with default parameters.

``` syntax
        FillMode = D3D12_FILL_MODE_SOLID;
        CullMode = D3D12_CULL_MODE_BACK;
        FrontCounterClockwise = FALSE;
        DepthBias = D3D12_DEFAULT_DEPTH_BIAS;
        DepthBiasClamp = D3D12_DEFAULT_DEPTH_BIAS_CLAMP;
        SlopeScaledDepthBias = D3D12_DEFAULT_SLOPE_SCALED_DEPTH_BIAS;
        DepthClipEnable = TRUE;
        MultisampleEnable = FALSE;
        AntialiasedLineEnable = FALSE;
        ForcedSampleCount = 0;
        ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
```

**explicit CD3DX12\_RASTERIZER\_DESC(D3D12\_FILL\_MODE fillMode, D3D12\_CULL\_MODE cullMode, BOOL frontCounterClockwise, INT depthBias, FLOAT depthBiasClamp, FLOAT slopeScaledDepthBias, BOOL depthClipEnable, BOOL multisampleEnable, BOOL antialiasedLineEnable, UINT forcedSampleCount, D3D12\_CONSERVATIVE\_RASTERIZATION\_MODE conservativeRaster)**

Creates a new instance of a CD3DX12\_RASTERIZER\_DESC, initializing the following parameters:

[**D3D12\_FILL\_MODE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_fill_mode) fillMode

[**D3D12\_CULL\_MODE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_cull_mode) cullMode

BOOL frontCounterClockwise

INT depthBias

FLOAT depthBiasClamp

FLOAT slopeScaledDepthBias

BOOL depthClipEnable

BOOL multisampleEnable

BOOL antialiasedLineEnable

UINT forcedSampleCount

[**D3D12\_CONSERVATIVE\_RASTERIZATION\_MODE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_conservative_rasterization_mode) conservativeRaster

**~CD3DX12\_RASTERIZER\_DESC()**

Destroys an instance of a CD3DX12\_RASTERIZER\_DESC.

**operator const D3D12\_RASTERIZER\_DESC&() const**

Defines the & pass-by-reference operator for the parent structure type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_RASTERIZER\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_rasterizer_desc)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

