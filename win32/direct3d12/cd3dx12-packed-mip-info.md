# CD3DX12\_PACKED\_MIP\_INFO structure

A helper structure to enable easy initialization of a [**D3D12\_PACKED\_MIP\_INFO**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_packed_mip_info) structure.

## Members

**CD3DX12\_PACKED\_MIP\_INFO()**

Creates a new, uninitialized, instance of a CD3DX12\_PACKED\_MIP\_INFO.

**explicit CD3DX12\_PACKED\_MIP\_INFO(const D3D12\_PACKED\_MIP\_INFO &o)**

Creates a new instance of a CD3DX12\_PACKED\_MIP\_INFO, initialized with the contents of another [**D3D12\_PACKED\_MIP\_INFO**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_packed_mip_info) structure.

**CD3DX12\_PACKED\_MIP\_INFO(UINT8 numStandardMips, UINT8 numPackedMips, UINT numTilesForPackedMips, UINT startTileIndexInOverallResource)**

Creates a new instance of a CD3DX12\_PACKED\_MIP\_INFO, initializing the following parameters:

UINT8 numStandardMips

UINT8 numPackedMips

UINT numTilesForPackedMips

UINT startTileIndexInOverallResource

**operator const D3D12\_PACKED\_MIP\_INFO&() const**

Defines the & pass-by-reference operator for the parent structure type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_PACKED\_MIP\_INFO**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_packed_mip_info)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

