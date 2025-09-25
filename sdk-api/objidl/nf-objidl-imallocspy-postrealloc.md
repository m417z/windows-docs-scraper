# IMallocSpy::PostRealloc

## Description

Performs operations required after calling [IMalloc::Realloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-realloc).

## Parameters

### `pActual` [in]

The pointer specified in the call to [Realloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-realloc).

### `fSpyed` [in]

Indicates whether the block of memory was allocated while the current spy was active.

## Return value

The method returns a pointer to the beginning of the block actually allocated. This pointer is also returned to the caller of [IMalloc::Realloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-realloc). If debug information is written at the front of the caller's allocation, it should be a forward offset from *pActual*. The value should be the same as *pActual* if debug information is appended or if no debug information is attached.

## Remarks

If memory is successfully reallocated while the spy is active, *fSpyed* will be **TRUE** in subsequent calls to [IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy) methods that track the reallocated memory, even if *fSpyed* was previously **FALSE**.

## See also

[IMalloc::Realloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-realloc)

[IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy)

[IMallocSpy::PreRealloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-prerealloc)