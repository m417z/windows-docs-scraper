# CoTaskMemFree function

## Description

Frees a block of task memory previously allocated through a call to the [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) or [CoTaskMemRealloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemrealloc) function.

## Parameters

### `pv` [in, optional]

A pointer to the memory block to be freed. If this parameter is **NULL**, the function has no effect.

## Remarks

The **CoTaskMemFree** function uses the default OLE allocator.

The number of bytes freed equals the number of bytes that were originally allocated or reallocated. After the call, the memory block pointed to by pv is invalid and can no longer be used.

## See also

[CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc)

[CoTaskMemRealloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemrealloc)

[IMalloc::Free](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-free)