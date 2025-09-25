## Description

Creates a resource that is placed in a specific heap. Placed resources are the lightest weight resource objects available, and are the fastest to create and destroy.

Your application can re-use video memory by overlapping multiple Direct3D placed and reserved resources on heap regions. The simple memory re-use model (described in [Remarks](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device10-createplacedresource2#remarks)) exists to clarify which overlapping resource is valid at any given time. To maximize graphics tool support, with the simple model data-inheritance isn't supported; and finer-grained tile and sub-resource invalidation isn't supported. Only full overlapping resource invalidation occurs.

Requires the DirectX 12 Agility SDK 1.7 or later.

## Parameters

### `pHeap`

Type: [in] **[ID3D12Heap](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12heap)***

A pointer to the **ID3D12Heap** interface that represents the heap in which the resource is placed.

### `HeapOffset`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The offset, in bytes, to the resource. The *HeapOffset* must be a multiple of the resource's alignment, and *HeapOffset* plus the resource size must be smaller than or equal to the heap size. [**GetResourceAllocationInfo**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-getresourceallocationinfo(uint_uint_constd3d12_resource_desc)) must be used to understand the sizes of texture resources.

### `pDesc`

Type: [in] **const [D3D12_RESOURCE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_desc)***

A pointer to a **D3D12_RESOURCE_DESC** structure that describes the resource.

### `InitialLayout`

The initial layout of the texture resource; **D3D12_BARRIER_LAYOUT::D3D12_BARRIER_LAYOUT_UNDEFINED** for buffers.

### `pOptimizedClearValue`

Type: [in, optional] **const [D3D12_CLEAR_VALUE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_clear_value)***

Specifies a **D3D12_CLEAR_VALUE** that describes the default value for a clear color.

*pOptimizedClearValue* specifies a value for which clear operations are most optimal. When the created resource is a texture with either the **D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET** or **D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL** flags, your application should choose the value that the clear operation will most commonly be called with.

Clear operations can be called with other values, but those operations will not be as efficient as when the value matches the one passed into resource creation.

*pOptimizedClearValue* must be NULL when used with **D3D12_RESOURCE_DIMENSION_BUFFER**.

### `NumCastableFormats`

The number of elements in *pCastableFormats*.

### `pCastableFormats`

A contiguous array of [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) structures that this resource can be cast to.

### `riid`

Type: **REFIID**

The globally unique identifier (**GUID**) for the resource interface. This is an input parameter.

The **REFIID**, or **GUID**, of the interface to the resource can be obtained by using the `__uuidof` macro. For example, `__uuidof(ID3D12Resource)` gets the **GUID** of the interface to a resource. Although **riid** is, most commonly, the GUID for [**ID3D12Resource**](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource), it may be any **GUID** for any interface. If the resource object doesn't support the interface for this **GUID**, then creation fails with **E_NOINTERFACE**.

### `ppvResource`

Type: [out, optional] **void****

A pointer to a memory block that receives a pointer to the resource. *ppvResource* can be NULL, to enable capability testing. When *ppvResource* is NULL, no object will be created and S_FALSE will be returned when *pResourceDesc* and other parameters are valid.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns **E_OUTOFMEMORY** if there is insufficient memory to create the resource. See [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues) for other possible return values.

## Remarks

See **Remarks** for [ID3D12Device::CreatePlacedResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createplacedresource).

## See also

[CreateCommittedResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createcommittedresource)

[CreateReservedResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createreservedresource)

[ID3D12Device10](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device10)

[Shared heaps](https://learn.microsoft.com/windows/win32/direct3d12/shared-heaps)