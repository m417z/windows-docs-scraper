## Description

Gets rich info about the size and alignment of memory required for a collection of resources on this adapter. Also see [ID3D12Device::GetResourceAllocationInfo](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-getresourceallocationinfo(uint_uint_constd3d12_resource_desc).md).

In addition to the [D3D12_RESOURCE_ALLOCATION_INFO](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_allocation_info) returned from the method, this version also returns an array of [D3D12_RESOURCE_ALLOCATION_INFO1](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_allocation_info1) structures, which provide additional details for each resource description passed as input. See the *pResourceAllocationInfo1* parameter.

## Parameters

### `visibleMask` [in]

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

For single-GPU operation, set this to zero. If there are multiple GPU nodes, then set bits to identify the nodes (the device's physical adapters). Each bit in the mask corresponds to a single node. Also see [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

### `numResourceDescs` [in]

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The number of resource descriptors in the *pResourceDescs* array. This is also the size (the number of elements in) *pResourceAllocationInfo1*.

### `pResourceDescs` [in]

Type: **const [D3D12_RESOURCE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_desc)\***

An array of **D3D12_RESOURCE_DESC** structures that described the resources to get info about.

### `pResourceAllocationInfo1` [out]

Type: **[D3D12_RESOURCE_ALLOCATION_INFO1](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_allocation_info1)\***

An array of [D3D12_RESOURCE_ALLOCATION_INFO1](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_allocation_info1) structures, containing additional details for each resource description passed as input. This makes it simpler for your application to allocate a heap for multiple resources, and without manually computing offsets for where each resource should be placed.

## Return value

Type: **[D3D12_RESOURCE_ALLOCATION_INFO](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_allocation_info)**

A [D3D12_RESOURCE_ALLOCATION_INFO](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_allocation_info) structure that provides info about video memory allocated for the specified array of resources.

## Remarks

When you're using [CreatePlacedResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createplacedresource), your application must use **GetResourceAllocationInfo** in order to understand the size and alignment characteristics of texture resources. The results of this method vary depending on the particular adapter, and must be treated as unique to this adapter and driver version.

Your application can't use the output of **GetResourceAllocationInfo** to understand packed mip properties of textures. To understand packed mip properties of textures, your application must use [GetResourceTiling](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-getresourcetiling).

Texture resource sizes significantly differ from the information returned by **GetResourceTiling**, because some adapter architectures allocate extra memory for textures to reduce the effective bandwidth during common rendering scenarios. This even includes textures that have constraints on their texture layouts, or have standardized texture layouts. That extra memory can't be sparsely mapped nor remapped by an application using [CreateReservedResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createreservedresource) and [UpdateTileMappings](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12commandqueue-updatetilemappings), so it isn't reported by **GetResourceTiling**.

Your application can forgo using **GetResourceAllocationInfo** for buffer resources ([D3D12_RESOURCE_DIMENSION_BUFFER](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_dimension)). Buffers have the same size on all adapters, which is merely the smallest multiple of 64KB that's greater or equal to [D3D12_RESOURCE_DESC::Width](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_desc).

When multiple resource descriptions are passed in, the C++ algorithm for calculating a structure size and alignment are used. For example, a three-element array with two tiny 64KB-aligned resources and a tiny 4MB-aligned resource, reports differing sizes based on the order of the array. If the 4MB aligned resource is in the middle, then the resulting **Size** is 12MB. Otherwise, the resulting **Size** is 8MB. The **Alignment** returned would always be 4MB, because it's the superset of all alignments in the resource array.

## See also

[ID3D12Device4](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device4)