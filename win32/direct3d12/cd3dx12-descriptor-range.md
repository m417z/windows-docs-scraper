# CD3DX12\_DESCRIPTOR\_RANGE structure

A helper structure to enable easy initialization of a [**D3D12\_DESCRIPTOR\_RANGE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range) structure.

## Members

**CD3DX12\_DESCRIPTOR\_RANGE()**

Creates a new, uninitialized, instance of a D3DX12\_DESCRIPTOR\_RANGE.

**explicit CD3DX12\_DESCRIPTOR\_RANGE(const D3D12\_DESCRIPTOR\_RANGE &o)**

Creates a new instance of a D3DX12\_DESCRIPTOR\_RANGE, initialized with the contents of another [**D3D12\_DESCRIPTOR\_RANGE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range) structure.

**CD3DX12\_DESCRIPTOR\_RANGE(D3D12\_DESCRIPTOR\_RANGE\_TYPE rangeType, UINT numDescriptors, UINT baseShaderRegister, UINT registerSpace = 0, UINT offsetInDescriptorsFromTableStart = D3D12\_DESCRIPTOR\_RANGE\_OFFSET\_APPEND)**

Creates a new instance of a D3DX12\_DESCRIPTOR\_RANGE, initializing the following parameters:

[**D3D12\_DESCRIPTOR\_RANGE\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_range_type) rangeType

UINT numDescriptors

UINT baseShaderRegister

UINT registerSpace = 0

UINT offsetInDescriptorsFromTableStart = D3D12\_DESCRIPTOR\_RANGE\_OFFSET\_APPEND

**inline Init(D3D12\_DESCRIPTOR\_RANGE\_TYPE rangeType, UINT numDescriptors, UINT baseShaderRegister, UINT registerSpace = 0, UINT offsetInDescriptorsFromTableStart = D3D12\_DESCRIPTOR\_RANGE\_OFFSET\_APPEND)**

Specifies a function that initializes the following parameters:

[**D3D12\_DESCRIPTOR\_RANGE\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_range_type) rangeType

UINT numDescriptors

UINT baseShaderRegister

UINT registerSpace = 0

UINT offsetInDescriptorsFromTableStart = D3D12\_DESCRIPTOR\_RANGE\_OFFSET\_APPEND

**static inline Init(D3D12\_DESCRIPTOR\_RANGE ⦥, D3D12\_DESCRIPTOR\_RANGE\_TYPE rangeType, UINT numDescriptors, UINT baseShaderRegister, UINT registerSpace = 0, UINT offsetInDescriptorsFromTableStart = D3D12\_DESCRIPTOR\_RANGE\_OFFSET\_APPEND)**

Specifies a function that initializes the following parameters:

[**D3D12\_DESCRIPTOR\_RANGE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range) ⦥

[**D3D12\_DESCRIPTOR\_RANGE\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_range_type) rangeType

UINT numDescriptors

UINT baseShaderRegister

UINT registerSpace = 0

UINT offsetInDescriptorsFromTableStart = D3D12\_DESCRIPTOR\_RANGE\_OFFSET\_APPEND

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_DESCRIPTOR\_RANGE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

