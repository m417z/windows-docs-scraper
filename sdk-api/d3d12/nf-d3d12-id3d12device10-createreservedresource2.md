## Description

Creates a resource that is reserved, and not yet mapped to any pages in a heap.

Requires the DirectX 12 Agility SDK 1.7 or later.

## Parameters

### `pDesc`

Type: **const [D3D12_RESOURCE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_desc)\***

A pointer to a **D3D12_RESOURCE_DESC** structure that describes the resource.

### `InitialLayout`

The initial layout of the texture resource; **D3D12_BARRIER_LAYOUT::D3D12_BARRIER_LAYOUT_UNDEFINED** for buffers.

### `pOptimizedClearValue`

Type: **const [D3D12_CLEAR_VALUE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_clear_value)\***

Specifies a **D3D12_CLEAR_VALUE** structure that describes the default value for a clear color.

*pOptimizedClearValue* specifies a value for which clear operations are most optimal. When the created resource is a texture with either the [D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_flags) or **D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL** flags, you should choose the value with which the clear operation will most commonly be called. You can call the clear operation with other values, but those operations won't be as efficient as when the value matches the one passed in to resource creation.

When you use [D3D12_RESOURCE_DIMENSION_BUFFER](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_dimension), you must set *pOptimizedClearValue* to `nullptr`.

### `pProtectedSession`

Type: **[ID3D12ProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12protectedresourcesession)\***

An optional pointer to an object that represents a session for content protection. If provided, this session indicates that the resource should be protected. You can obtain an **ID3D12ProtectedResourceSession** by calling [ID3D12Device4::CreateProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device4-createprotectedresourcesession).

### `NumCastableFormats`

The number of elements in *pCastableFormats*.

### `pCastableFormats`

A contiguous array of [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) structures that this resource can be cast to.

### `riid` [in]

Type: **REFIID**

A reference to the globally unique identifier (**GUID**) of the resource interface to return in *ppvResource*. See **Remarks**.

While *riidResource* is most commonly the **GUID** of [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource), it may be the **GUID** of any interface. If the resource object doesn't support the interface for this **GUID**, then creation fails with **E_NOINTERFACE**.

### `ppvResource`

Type: **void\*\***

An optional pointer to a memory block that receives the requested interface pointer to the created resource object.

*ppvResource* can be `nullptr`, to enable capability testing. When *ppvResource* is `nullptr`, no object is created, and **S_FALSE** is returned when *pDesc* is valid.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

|Return value|Description|
|-|-|
|E_OUTOFMEMORY|There is insufficient memory to create the resource.|

See [Direct3D 12 return codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues) for other possible return values.

## Remarks

See **Remarks** for [ID3D12Device.CreateReservedResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createreservedresource).

## See also

[CreateCommittedResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createcommittedresource)

[CreatePlacedResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createplacedresource)

[ID3D12Device10](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device10)