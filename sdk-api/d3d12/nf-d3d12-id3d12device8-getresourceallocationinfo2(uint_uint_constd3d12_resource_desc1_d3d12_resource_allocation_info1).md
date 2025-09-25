## Description

Gets rich info about the size and alignment of memory required for a collection of resources on this adapter. Also see [ID3D12Device4::GetResourceAllocationInfo1](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device4-getresourceallocationinfo1(uint_uint_constd3d12_resource_desc_d3d12_resource_allocation_info1).md).

This version also returns an array of [D3D12_RESOURCE_DESC1](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_desc1) structures.

## Parameters

UINT numResourceDescs,
_In_reads_(numResourceDescs) const D3D12_RESOURCE_DESC1 *pResourceDescs,
_Out_writes_opt_(numResourceDescs) D3D12_RESOURCE_ALLOCATION_INFO1 *pResourceAllocationInfo1) = 0;

### `visibleMask`

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

For single-GPU operation, set this to zero. If there are multiple GPU nodes, then set bits to identify the nodes (the device's physical adapters). Each bit in the mask corresponds to a single node. Also see [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

### `numResourceDescs`

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The number of resource descriptors in the *pResourceDescs* array. This is also the size (the number of elements in) *pResourceAllocationInfo1*.

### `pResourceDescs`

Type: **const [D3D12_RESOURCE_DESC1](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_desc1)\***

An array of **D3D12_RESOURCE_DESC1** structures that described the resources to get info about.

### `pResourceAllocationInfo1`

Type: **[D3D12_RESOURCE_ALLOCATION_INFO1](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_allocation_info1)\***

An array of [D3D12_RESOURCE_ALLOCATION_INFO1](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_allocation_info1) structures, containing additional details for each resource description passed as input. This makes it simpler for your application to allocate a heap for multiple resources, and without manually computing offsets for where each resource should be placed.

## Return value

Type: **[D3D12_RESOURCE_ALLOCATION_INFO](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_allocation_info)**

A [D3D12_RESOURCE_ALLOCATION_INFO](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_allocation_info) structure that provides info about video memory allocated for the specified array of resources.

## Remarks

For remarks, see [ID3D12Device4::GetResourceAllocationInfo1](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device4-getresourceallocationinfo1(uint_uint_constd3d12_resource_desc_d3d12_resource_allocation_info1).md).

## See also

* [ID3D12Device8](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device8)

* [Sampler feedback specification](https://microsoft.github.io/DirectX-Specs/d3d/SamplerFeedback.html)