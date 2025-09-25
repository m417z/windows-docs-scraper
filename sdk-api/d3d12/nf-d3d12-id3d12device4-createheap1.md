## Description

Creates a heap (optionally for a protected session) that can be used with placed resources and reserved resources. Also see [ID3D12Device::CreateHeap](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createheap).

## Parameters

### `pDesc` [in]

Type: **const [D3D12_HEAP_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_heap_desc)\***

A pointer to a constant **D3D12_HEAP_DESC** structure that describes the heap.

### `pProtectedSession` [in, optional]

Type: **[ID3D12ProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12protectedresourcesession)\***

An optional pointer to an object that represents a session for content protection. If provided, this session indicates that the heap should be protected. You can obtain an **ID3D12ProtectedResourceSession** by calling [ID3D12Device4::CreateProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device4-createprotectedresourcesession).

A heap with a protected session can't be created with the [D3D12_HEAP_FLAG_SHARED_CROSS_ADAPTER](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_flags) flag.

### `riid` [in]

Type: **REFIID**

A reference to the globally unique identifier (**GUID**) of the heap interface to return in *ppvHeap*.

While *riidResource* is most commonly the **GUID** of [ID3D12Heap](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12heap), it may be the **GUID** of any interface. If the resource object doesn't support the interface for this **GUID**, then creation fails with **E_NOINTERFACE**.

### `ppvHeap` [out, optional]

Type: **void\*\***

An optional pointer to a memory block that receives the requested interface pointer to the created heap object.

*ppvHeap* can be `nullptr`, to enable capability testing. When *ppvHeap* is `nullptr`, no object is created, and **S_FALSE** is returned when *pDesc* is valid.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

|Return value|Description|
|-|-|
|E_OUTOFMEMORY|There is insufficient memory to create the heap.|

See [Direct3D 12 return codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues) for other possible return values.

## Remarks

**CreateHeap1** creates a heap that can be used with placed resources and reserved resources.

Before releasing the final reference on the heap, your application must ensure that the GPU will no longer read or write to this heap.

A placed resource object holds a reference on the heap it is created on; but a reserved resource doesn't hold a reference for each mapping made to a heap.

## See also