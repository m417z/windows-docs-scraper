## Description

Describes parameters needed to allocate resources.

## Members

### `SizeInBytes`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The size, in bytes, of the resource.

### `Alignment`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The alignment value for the resource; one of 4KB (4096), 64KB (65536), or 4MB (4194304) alignment.

## Remarks

This structure is used by the [ID3D12Device::GetResourceAllocationInfo](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-getresourceallocationinfo(uint_uint_constd3d12_resource_desc).md) and [ID3D12Device::GetResourceAllocationInfo1](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device4-getresourceallocationinfo1(uint_uint_constd3d12_resource_desc_d3d12_resource_allocation_info1).md) methods.

## See also

[CD3DX12_RESOURCE_ALLOCATION_INFO](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-resource-allocation-info)

[Core structures](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-structures)