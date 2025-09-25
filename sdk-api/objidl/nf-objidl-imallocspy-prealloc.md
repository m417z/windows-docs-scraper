# IMallocSpy::PreAlloc

## Description

Performs operations required before calling [IMalloc::Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc).

## Parameters

### `cbRequest` [in]

The number of bytes specified in the allocation request the caller is passing to [Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc).

## Return value

The number of bytes specified in the call to [Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc), which can be greater than or equal to the value of *cbRequest*.

## Remarks

The **PreAlloc** implementation may extend and/or modify the allocation to store debug-specific information with the allocation.

**PreAlloc** can force memory allocation failure by returning 0, allowing testing to ensure that the application handles allocation failure gracefully in all cases. In this case, [IMallocSpy::PostAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-postalloc) is not called and [Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc) returns **NULL**. Forcing allocation failure is effective only if *cbRequest* is not equal to 0. If **PreAlloc** is forcing failure by returning **NULL**, **PostAlloc** is not called. However, **Alloc** encounters a real memory failure and returns **NULL**, **PostAlloc** is called.

The call to **PreAlloc** through the return from [PostAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-postalloc) is guaranteed to be thread-safe.

## See also

[IMalloc::Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc)

[IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy)

[IMallocSpy::PostAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-postalloc)