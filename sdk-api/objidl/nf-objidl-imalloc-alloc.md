# IMalloc::Alloc

## Description

Allocates a block of memory.

## Parameters

### `cb` [in]

The size of the memory block to be allocated, in bytes.

## Return value

If the method succeeds, the return value is a pointer to the allocated block of memory. Otherwise, it is **NULL**.

Applications should always check the return value from this method, even when requesting small amounts of memory, because there is no guarantee the memory will be allocated.

## Remarks

The initial contents of the returned memory block are undefined and there is no guarantee that the block has been initialized, so you should initialize it in your code. The allocated block may be larger than *cb* bytes because of the space required for alignment and for maintenance information.

If *cb* is zero, **Alloc** allocates a zero-length item and returns a valid pointer to that item. If there is insufficient memory available, **Alloc** returns **NULL**.

## See also

[CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc)

[IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc)