# CoGetMalloc function

## Description

Retrieves a pointer to the default OLE task memory allocator (which supports the system implementation of the [IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc) interface) so applications can call its methods to manage memory.

## Parameters

### `dwMemContext` [in]

This parameter must be 1.

### `ppMalloc` [out]

The address of an **IMalloc*** pointer variable that receives the interface pointer to the memory allocator.

## Return value

This function can return the standard return values S_OK, E_INVALIDARG, and E_OUTOFMEMORY.

## Remarks

The pointer to the [IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc) interface pointer received through the *ppMalloc* parameter cannot be used from a remote process; each process must have its own allocator.

## See also

[CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc)

[IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc)