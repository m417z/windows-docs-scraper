# IMallocSpy::PreFree

## Description

Performs operations required before calling [IMalloc::Free](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-free). This method ensures that the pointer passed to **Free** points to the beginning of the actual allocation.

## Parameters

### `pRequest` [in]

A pointer to the block of memory that the caller is passing to [Free](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-free).

### `fSpyed` [in]

Indicates whether the block of memory to be freed was allocated while the current spy was active.

## Return value

The value to be passed to [IMalloc::Free](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-free).

## Remarks

If [IMallocSpy::PreAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-prealloc) modified the original allocation request passed to [IMalloc::Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc) (or [IMalloc::Realloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-realloc)), **PreFree** must supply a pointer to the actual allocation, which COM will pass to [IMalloc::Free](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-free). For example, if the **PreAlloc**/[PostAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-postalloc) pair attached a header used to store debug information to the beginning of the caller's allocation, **PreFree** must return a pointer to the beginning of this header so that all of the block that was allocated can be freed.

## See also

[IMalloc::Free](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-free)

[IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy)

[IMallocSpy::PostFree](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-postfree)