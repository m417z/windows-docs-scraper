## Description

Creates a resource (optionally for a protected session) that is reserved, and not yet mapped to any pages in a heap. Also see [ID3D12Device::CreateReservedResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createreservedresource).

> [!NOTE]
> Only tiles from heaps created with the same protected resource session can be mapped into a protected reserved resource.

## Parameters

### `pDesc` [in]

Type: **const [D3D12_RESOURCE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_desc)\***

A pointer to a **D3D12_RESOURCE_DESC** structure that describes the resource.

### `InitialState` [in]

Type: **[D3D12_RESOURCE_STATES](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states)**

The initial state of the resource, as a bitwise-OR'd combination of **D3D12_RESOURCE_STATES** enumeration constants.

### `pOptimizedClearValue` [in, optional]

Type: **const [D3D12_CLEAR_VALUE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_clear_value)\***

Specifies a **D3D12_CLEAR_VALUE** structure that describes the default value for a clear color.

*pOptimizedClearValue* specifies a value for which clear operations are most optimal. When the created resource is a texture with either the [D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_flags) or **D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL** flags, you should choose the value with which the clear operation will most commonly be called. You can call the clear operation with other values, but those operations won't be as efficient as when the value matches the one passed in to resource creation.

When you use [D3D12_RESOURCE_DIMENSION_BUFFER](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_dimension), you must set *pOptimizedClearValue* to `nullptr`.

### `pProtectedSession` [in, optional]

Type: **[ID3D12ProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12protectedresourcesession)\***

An optional pointer to an object that represents a session for content protection. If provided, this session indicates that the resource should be protected. You can obtain an **ID3D12ProtectedResourceSession** by calling [ID3D12Device4::CreateProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device4-createprotectedresourcesession).

### `riid` [in]

Type: **REFIID**

A reference to the globally unique identifier (**GUID**) of the resource interface to return in *ppvResource*. See **Remarks**.

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

**CreateReservedResource** is equivalent to [D3D11_RESOURCE_MISC_TILED](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) in Direct3D 11. It creates a resource with virtual memory only, no backing store.

You need to map the resource to physical memory (that is, to a heap) using [CopyTileMappings](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12commandqueue-copytilemappings) and [UpdateTileMappings](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12commandqueue-updatetilemappings).

These resource types can only be created when the adapter supports tiled resource tier 1 or greater. The tiled resource tier defines the behavior of accessing a resource that is not mapped to a heap.

## See also

[CreateCommittedResource1](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device4-createcommittedresource1)

[CreatePlacedResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createplacedresource)

[ID3D12Device4](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device4)