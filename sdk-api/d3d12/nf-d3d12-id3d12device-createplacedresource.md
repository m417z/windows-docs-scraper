## Description

Creates a resource that is placed in a specific heap. Placed resources are the lightest weight resource objects available, and are the fastest to create and destroy.

Your application can re-use video memory by overlapping multiple Direct3D placed and reserved resources on heap regions. The simple memory re-use model (described in [Remarks](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createplacedresource#remarks)) exists to clarify which overlapping resource is valid at any given time. To maximize graphics tool support, with the simple model data-inheritance isn't supported; and finer-grained tile and sub-resource invalidation isn't supported. Only full overlapping resource invalidation occurs.

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

### `InitialState`

Type: **[D3D12_RESOURCE_STATES](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states)**

The initial state of the resource, as a bitwise-OR'd combination of **D3D12_RESOURCE_STATES** enumeration constants.

When a resource is created together with a **D3D12_HEAP_TYPE_UPLOAD** heap, *InitialState* must be **D3D12_RESOURCE_STATE_GENERIC_READ**. When a resource is created together with a **D3D12_HEAP_TYPE_READBACK** heap, *InitialState* must be **D3D12_RESOURCE_STATE_COPY_DEST**.

### `pOptimizedClearValue`

Type: [in, optional] **const [D3D12_CLEAR_VALUE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_clear_value)***

Specifies a **D3D12_CLEAR_VALUE** that describes the default value for a clear color.

*pOptimizedClearValue* specifies a value for which clear operations are most optimal. When the created resource is a texture with either the **D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET** or **D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL** flags, your application should choose the value that the clear operation will most commonly be called with.

Clear operations can be called with other values, but those operations will not be as efficient as when the value matches the one passed into resource creation.

*pOptimizedClearValue* must be NULL when used with **D3D12_RESOURCE_DIMENSION_BUFFER**.

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

**CreatePlacedResource** is similar to fully mapping a reserved resource to an offset within a heap; but the virtual address space associated with a heap may be reused as well.

Placed resources are lighter weight to create and destroy than committed resources are. This is because no heap is created nor destroyed during those operations. In addition, placed resources enable an even lighter weight technique to reuse memory than resource creation and destruction—that is, reuse through aliasing, and aliasing barriers. Multiple placed resources may simultaneously overlap each other on the same heap, but only a single overlapping resource can be used at a time.

There are two placed resource usage semantics—a simple model, and an advanced model. We recommend that you choose the simple model (it maximizes graphics tool support across the diverse ecosystem of GPUs), unless and until you find that you need the advanced model for your app.

### Simple model

In this model, you can consider a placed resource to be in one of two states: active, or inactive. It's invalid for the GPU to either read or write from an inactive resource. Placed resources are created in the inactive state.

To activate a resource with an aliasing barrier on a command list, your application must pass the resource in [**D3D12_RESOURCE_ALIASING_BARRIER::pResourceAfter**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_aliasing_barrier). **pResourceBefore** can be left NULL during an activation. All resources that share physical memory with the activated resource now become inactive, which includes overlapping placed and reserved resources.

Aliasing barriers should be grouped up and submitted together, in order to maximize efficiency.

After activation, resources with either the render target or depth stencil flags must be further initialized. See the notes on the required resource initialization below.

#### Notes on the required resource initialization

Certain resource types still require initialization. Resources with either the render target or depth stencil flags must be initialized with either a clear operation or a collection of full subresource copies. If an aliasing barrier was used to denote the transition between two aliased resources, the initialization must occur after the aliasing barrier. This initialization is still required whenever a resource would've been activated in the simple model.

Placed and reserved resources with either the render target or depth stencil flags must be initialized with one of the following operations before other operations are supported.

- A *Clear* operation; for example [ClearRenderTargetView](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-clearrendertargetview) or [ClearDepthStencilView](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-cleardepthstencilview).
- A [DiscardResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-discardresource) operation.
- A *Copy* operation; for example [CopyBufferRegion](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copybufferregion), [CopyTextureRegion](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copytextureregion), or [CopyResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copyresource).

Applications should prefer the most explicit operation that results in the least amount of texels modified. Consider the following examples.

- Using a depth buffer to solve pixel visibility typically requires each depth texel start out at 1.0 or 0. Therefore, a *Clear* operation should be the most efficient option for aliased depth buffer initialization.
- An application may use an aliased render target as a destination for tone mapping. Since the application will render over every pixel during the tone mapping, [DiscardResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-discardresource) should be the most efficient option for initialization.

### Advanced model

In this model, you can ignore the active/inactive state abstraction. Instead, you must honor these lower-level rules.

- An aliasing barrier must be between two different GPU resource accesses of the same physical memory, as long as those accesses are within the same [ExecuteCommandLists](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12commandqueue-executecommandlists) call.
- The first rendering operation to certain types of aliased resource must still be an initialization, just like the simple model.

Initialization operations must occur either on an entire subresource, or on a 64KB granularity. An entire subresource initialization is supported for all resource types. A 64KB initialization granularity, aligned at a 64KB offset, is supported for buffers and textures with either the 64KB_UNDEFINED_SWIZZLE or 64KB_STANDARD_SWIZZLE texture layout (refer to [D3D12_TEXTURE_LAYOUT](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_texture_layout)).

### Notes on the aliasing barrier

The aliasing barrier may set NULL for both *pResourceAfter* and *pResourceBefore*. The memory coherence definition of [**ExecuteCommandLists**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12commandqueue-executecommandlists) and an aliasing barrier are the same, such that two aliased accesses to the same physical memory need no aliasing barrier when the accesses are in two different **ExecuteCommandLists** invocations.

For D3D12 advanced usage models, the synchronization definition of [**ExecuteCommandLists**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12commandqueue-executecommandlists) is equivalent to an aliasing barrier. Therefore, applications may either insert an aliasing barrier between reusing physical memory, or ensure the two aliased usages of physical memory occurs in two separate calls to **ExecuteCommandLists**.

The amount of inactivation varies based on resource properties. Textures with undefined memory layouts are the worst case, as the entire texture must be inactivated atomically. For two overlapping resources with defined layouts, inactivation can result in only the overlapping aligned regions of a resource. Data inheritance can even be well-defined. For more details, see [Memory aliasing and data inheritance](https://learn.microsoft.com/windows/win32/direct3d12/memory-aliasing-and-data-inheritance).

## See also

[CreateCommittedResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createcommittedresource)

[CreateReservedResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createreservedresource)

[ID3D12Device](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device)

[Shared Heaps](https://learn.microsoft.com/windows/win32/direct3d12/shared-heaps)