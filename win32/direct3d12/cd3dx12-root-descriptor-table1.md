# CD3DX12\_ROOT\_DESCRIPTOR\_TABLE1 structure

A helper structure to enable easy initialization of a [**D3D12\_ROOT\_DESCRIPTOR\_TABLE1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor_table1) structure.

## Members

**CD3DX12\_ROOT\_DESCRIPTOR\_TABLE1()**

Creates a new, uninitialized, instance of a CD3DX12\_ROOT\_DESCRIPTOR\_TABLE1.

**explicit CD3DX12\_ROOT\_DESCRIPTOR\_TABLE1(const D3D12\_ROOT\_DESCRIPTOR\_TABLE1 &o)**

Creates a new instance of a CD3DX12\_ROOT\_DESCRIPTOR\_TABLE1, initialized with the contents of another [**D3D12\_ROOT\_DESCRIPTOR\_TABLE1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor_table1) structure.

**CD3DX12\_ROOT\_DESCRIPTOR\_TABLE1(UINT numDescriptorRanges, const D3D12\_DESCRIPTOR\_RANGE1\* \_pDescriptorRanges)**

Creates a new instance of a CD3DX12\_ROOT\_DESCRIPTOR\_TABLE1, initializing the following parameters:

UINT numDescriptorRanges

const [**D3D12\_DESCRIPTOR\_RANGE1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range1)\* \_pDescriptorRanges

**inline Init(UINT numDescriptorRanges, const D3D12\_DESCRIPTOR\_RANGE1\* \_pDescriptorRanges)**

Specifies a function that initializes the following parameters:

UINT numDescriptorRanges

const [**D3D12\_DESCRIPTOR\_RANGE1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range1)\* \_pDescriptorRanges

**static inline Init(D3D12\_ROOT\_DESCRIPTOR\_TABLE1 &rootDescriptorTable, UINT numDescriptorRanges, const D3D12\_DESCRIPTOR\_RANGE1\* \_pDescriptorRanges)**

Specifies a function that initializes the following parameters:

[**D3D12\_ROOT\_DESCRIPTOR\_TABLE1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor_table1) &rootDescriptorTable

UINT numDescriptorRanges

const [**D3D12\_DESCRIPTOR\_RANGE1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range1)\* \_pDescriptorRanges

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_ROOT\_DESCRIPTOR\_TABLE1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor_table1)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

