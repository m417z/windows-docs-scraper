## Description

Describes parameters needed to allocate resources, including offset.

## Members

### `Offset`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The offset, in bytes, of the resource.

### `Alignment`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The alignment value for the resource; one of 4KB (4096), 64KB (65536), or 4MB (4194304) alignment.

### `SizeInBytes`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The size, in bytes, of the resource.

## Remarks

This structure is used by the [ID3D12Device::GetResourceAllocationInfo1](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device4-getresourceallocationinfo1(uint_uint_constd3d12_resource_desc_d3d12_resource_allocation_info1).md) method.

## See also

[Core structures](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-structures)