# CoTaskMemAlloc function

## Description

Allocates a block of task memory in the same way that [IMalloc::Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc) does.

## Parameters

### `cb` [in]

The size of the memory block to be allocated, in bytes.

## Return value

If the function succeeds, it returns the allocated memory block. Otherwise, it returns **NULL**.

## Remarks

**CoTaskMemAlloc** uses the default allocator to allocate a memory block in the same way that [IMalloc::Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc) does. It is not necessary to call the [CoGetMalloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetmalloc) function before calling **CoTaskMemAlloc**.

The initial contents of the returned memory block are undefined – there is no guarantee that the block has been initialized. The allocated block may be larger than *cb* bytes because of the space required for alignment and for maintenance information.

If *cb* is 0, **CoTaskMemAlloc** allocates a zero-length item and returns a valid pointer to that item. If there is insufficient memory available, **CoTaskMemAlloc** returns **NULL**. Applications should always check the return value from this function, even when requesting small amounts of memory, because there is no guarantee that the memory will be allocated.

## See also

[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)

[CoTaskMemRealloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemrealloc)

[IMalloc::Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc)