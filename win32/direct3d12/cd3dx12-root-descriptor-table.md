# CD3DX12\_ROOT\_DESCRIPTOR\_TABLE structure

A helper structure to enable easy initialization of a [**D3D12\_ROOT\_DESCRIPTOR\_TABLE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor_table) structure.

## Members

**CD3DX12\_ROOT\_DESCRIPTOR\_TABLE()**

Creates a new, uninitialized, instance of a CD3DX12\_ROOT\_DESCRIPTOR\_TABLE.

**explicit CD3DX12\_ROOT\_DESCRIPTOR\_TABLE(const D3D12\_ROOT\_DESCRIPTOR\_TABLE &o)**

Creates a new instance of a CD3DX12\_ROOT\_DESCRIPTOR\_TABLE, initialized with the contents of another [**D3D12\_ROOT\_DESCRIPTOR\_TABLE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor_table) structure.

**CD3DX12\_ROOT\_DESCRIPTOR\_TABLE(UINT numDescriptorRanges, const D3D12\_DESCRIPTOR\_RANGE\* \_pDescriptorRanges)**

Creates a new instance of a CD3DX12\_ROOT\_DESCRIPTOR\_TABLE, initializing the following parameters:

UINT numDescriptorRanges

[**D3D12\_DESCRIPTOR\_RANGE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range)\* \_pDescriptorRanges

**inline Init(UINT numDescriptorRanges, const D3D12\_DESCRIPTOR\_RANGE\* \_pDescriptorRanges)**

Specifies a function that initializes the following parameters:

UINT numDescriptorRanges

[**D3D12\_DESCRIPTOR\_RANGE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range)\* \_pDescriptorRanges

**static inline Init(D3D12\_ROOT\_DESCRIPTOR\_TABLE &rootDescriptorTable, UINT numDescriptorRanges, const D3D12\_DESCRIPTOR\_RANGE\* \_pDescriptorRanges)**

Specifies a function that initializes the following parameters:

[**D3D12\_ROOT\_DESCRIPTOR\_TABLE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor_table) &rootDescriptorTable

UINT numDescriptorRanges

[**D3D12\_DESCRIPTOR\_RANGE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range)\* \_pDescriptorRanges

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_ROOT\_DESCRIPTOR\_TABLE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor_table)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

