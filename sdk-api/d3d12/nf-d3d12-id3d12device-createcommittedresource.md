## Description

Creates both a resource and an implicit heap, such that the heap is big enough to contain the entire resource, and the resource is mapped to the heap.

## Parameters

### `pHeapProperties` [in]

Type: **const [D3D12_HEAP_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_heap_properties)\***

A pointer to a **D3D12_HEAP_PROPERTIES** structure that provides properties for the resource's heap.

### `HeapFlags` [in]

Type: **[D3D12_HEAP_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_flags)**

Heap options, as a bitwise-OR'd combination of **D3D12_HEAP_FLAGS** enumeration constants.

### `pDesc` [in]

Type: **const [D3D12_RESOURCE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_desc)\***

A pointer to a **D3D12_RESOURCE_DESC** structure that describes the resource.

### `InitialResourceState` [in]

Type: **[D3D12_RESOURCE_STATES](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states)**

The initial state of the resource, as a bitwise-OR'd combination of **D3D12_RESOURCE_STATES** enumeration constants.

When you create a resource together with a [D3D12_HEAP_TYPE_UPLOAD](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_type) heap, you must set *InitialResourceState* to [D3D12_RESOURCE_STATE_GENERIC_READ](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states).

When you create a resource together with a [D3D12_HEAP_TYPE_READBACK](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_type) heap, you must set *InitialResourceState* to [D3D12_RESOURCE_STATE_COPY_DEST](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states).

### `pOptimizedClearValue` [in, optional]

Type: **const [D3D12_CLEAR_VALUE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_clear_value)\***

Specifies a **D3D12_CLEAR_VALUE** structure that describes the default value for a clear color.

*pOptimizedClearValue* specifies a value for which clear operations are most optimal. When the created resource is a texture with either the [D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_flags) or **D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL** flags, you should choose the value with which the clear operation will most commonly be called. You can call the clear operation with other values, but those operations won't be as efficient as when the value matches the one passed in to resource creation.

When you use [D3D12_RESOURCE_DIMENSION_BUFFER](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_dimension), you must set *pOptimizedClearValue* to `nullptr`.

### `riidResource` [in]

Type: **REFIID**

A reference to the globally unique identifier (**GUID**) of the resource interface to return in *ppvResource*.

While *riidResource* is most commonly the **GUID** of [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource), it may be the **GUID** of any interface. If the resource object doesn't support the interface for this **GUID**, then creation fails with **E_NOINTERFACE**.

### `ppvResource` [out, optional]

Type: **void\*\***

An optional pointer to a memory block that receives the requested interface pointer to the created resource object.

*ppvResource* can be `nullptr`, to enable capability testing. When *ppvResource* is `nullptr`, no object is created, and **S_FALSE** is returned when *pDesc* is valid.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

|Return value|Description|
|-|-|
|E_OUTOFMEMORY|There is insufficient memory to create the resource.|

See [Direct3D 12 return codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues) for other possible return values.

## Remarks

This method creates both a resource and a heap, such that the heap is big enough to contain the entire resource, and the resource is mapped to the heap. The created heap is known as an implicit heap, because the heap object can't be obtained by the application. Before releasing the final reference on the resource, your application must ensure that the GPU will no longer read nor write to this resource.

The implicit heap is made resident for GPU access before the method returns control to your application. Also see [Residency](https://learn.microsoft.com/windows/win32/direct3d12/residency).

The resource GPU VA mapping can't be changed. See [ID3D12CommandQueue::UpdateTileMappings](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12commandqueue-updatetilemappings) and [Volume tiled resources](https://learn.microsoft.com/windows/win32/direct3d12/volume-tiled-resources).

This method may be called by multiple threads concurrently.

## Examples

The [D3D12Bundles](https://learn.microsoft.com/windows/win32/direct3d12/working-samples) sample uses **ID3D12Device::CreateCommittedResource** as follows:

Create a vertex buffer.

```cpp
auto heapProperties = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT);
auto resourceDesc = CD3DX12_RESOURCE_DESC::Buffer(SampleAssets::VertexDataSize);
ThrowIfFailed(m_device->CreateCommittedResource(
    &heapProperties,
    D3D12_HEAP_FLAG_NONE,
    &resourceDesc,
    D3D12_RESOURCE_STATE_COPY_DEST,
    nullptr,
    IID_PPV_ARGS(&m_vertexBuffer)));
```

See [Example code in the Direct3D 12 reference](https://learn.microsoft.com/windows/win32/direct3d12/notes-on-example-code).

## See also

[CreatePlacedResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createplacedresource)

[CreateReservedResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createreservedresource)

[D3D12_HEAP_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_flags)

[ID3D12Device](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device)