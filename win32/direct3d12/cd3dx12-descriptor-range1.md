# CD3DX12\_DESCRIPTOR\_RANGE1 structure

A helper structure to enable easy initialization of a [**D3D12\_DESCRIPTOR\_RANGE1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range1) structure.

## Members

**CD3DX12\_DESCRIPTOR\_RANGE1()**

Creates a new, uninitialized, instance of a CD3DX12\_DESCRIPTOR\_RANGE1.

**explicit CD3DX12\_DESCRIPTOR\_RANGE1(const D3D12\_DESCRIPTOR\_RANGE1 &o)**

Creates a new instance of a CD3DX12\_DESCRIPTOR\_RANGE1, initialized with the contents of another [**D3D12\_DESCRIPTOR\_RANGE1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range1) structure.

**CD3DX12\_DESCRIPTOR\_RANGE1(D3D12\_DESCRIPTOR\_RANGE\_TYPE rangeType, UINT numDescriptors, UINT baseShaderRegister, UINT registerSpace = 0, D3D12\_DESCRIPTOR\_RANGE\_FLAGS flags = D3D12\_DESCRIPTOR\_RANGE\_FLAG\_NONE, UINT offsetInDescriptorsFromTableStart = D3D12\_DESCRIPTOR\_RANGE\_OFFSET\_APPEND)**

Creates a new instance of a CD3DX12\_DESCRIPTOR\_RANGE1, initializing the following parameters:

[**D3D12\_DESCRIPTOR\_RANGE\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_range_type) rangeType

UINT numDescriptors

UINT baseShaderRegister

UINT registerSpace = 0

[**D3D12\_DESCRIPTOR\_RANGE\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_range_flags) flags = D3D12\_DESCRIPTOR\_RANGE\_FLAG\_NONE

UINT offsetInDescriptorsFromTableStart = D3D12\_DESCRIPTOR\_RANGE\_OFFSET\_APPEND

**inline Init(D3D12\_DESCRIPTOR\_RANGE\_TYPE rangeType, UINT numDescriptors, UINT baseShaderRegister, UINT registerSpace = 0, D3D12\_DESCRIPTOR\_RANGE\_FLAGS flags = D3D12\_DESCRIPTOR\_RANGE\_FLAG\_NONE, UINT offsetInDescriptorsFromTableStart = D3D12\_DESCRIPTOR\_RANGE\_OFFSET\_APPEND)**

Specifies a function that initializes the following parameters:

[**D3D12\_DESCRIPTOR\_RANGE\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_range_type) rangeType

UINT numDescriptors

UINT baseShaderRegister

UINT registerSpace = 0

[**D3D12\_DESCRIPTOR\_RANGE\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_range_flags) flags = D3D12\_DESCRIPTOR\_RANGE\_FLAG\_NONE

UINT offsetInDescriptorsFromTableStart = D3D12\_DESCRIPTOR\_RANGE\_OFFSET\_APPEND

**static inline Init(D3D12\_DESCRIPTOR\_RANGE1 ⦥, D3D12\_DESCRIPTOR\_RANGE\_TYPE rangeType, UINT numDescriptors, UINT baseShaderRegister, UINT registerSpace = 0, D3D12\_DESCRIPTOR\_RANGE\_FLAGS flags = D3D12\_DESCRIPTOR\_RANGE\_FLAG\_NONE, UINT offsetInDescriptorsFromTableStart = D3D12\_DESCRIPTOR\_RANGE\_OFFSET\_APPEND)**

Specifies a function that initializes the following parameters:

[**D3D12\_DESCRIPTOR\_RANGE1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range1) ⦥

[**D3D12\_DESCRIPTOR\_RANGE\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_range_type) rangeType

UINT numDescriptors

UINT baseShaderRegister

UINT registerSpace = 0

[**D3D12\_DESCRIPTOR\_RANGE\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_range_flags) flags = D3D12\_DESCRIPTOR\_RANGE\_FLAG\_NONE

UINT offsetInDescriptorsFromTableStart = D3D12\_DESCRIPTOR\_RANGE\_OFFSET\_APPEND

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_DESCRIPTOR\_RANGE1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range1)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

