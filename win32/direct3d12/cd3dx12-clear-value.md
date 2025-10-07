# CD3DX12\_CLEAR\_VALUE structure

A helper structure to enable easy initialization of a [**D3D12\_CLEAR\_VALUE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_clear_value) structure.

## Members

**CD3DX12\_CLEAR\_VALUE()**

Creates a new, uninitialized, instance of a CD3DX12\_CLEAR\_VALUE.

**explicit CD3DX12\_CLEAR\_VALUE(const D3D12\_CLEAR\_VALUE &o)**

Creates a new instance of a CD3DX12\_CLEAR\_VALUE, initialized with the contents of another [**D3D12\_CLEAR\_VALUE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_clear_value) structure.

**CD3DX12\_CLEAR\_VALUE(DXGI\_FORMAT format, const FLOAT color\[ 4 \])**

Creates a new instance of a CD3DX12\_CLEAR\_VALUE, initializing the following parameters:

[**DXGI\_FORMAT**](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) format

FLOAT color\[ 4 \]

**CD3DX12\_CLEAR\_VALUE(DXGI\_FORMAT format, FLOAT depth, UINT8 stencil)**

Creates a new instance of a CD3DX12\_CLEAR\_VALUE, initializing the following parameters:

[**DXGI\_FORMAT**](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) format

FLOAT depth

UINT8 stencil

**operator const D3D12\_CLEAR\_VALUE&() const**

Defines the & pass-by-reference operator for the parent structure type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_CLEAR\_VALUE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_clear_value)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

