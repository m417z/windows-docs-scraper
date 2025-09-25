# IMallocSpy::PostFree

## Description

Performs operations required after calling [IMalloc::Free](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-free).

## Parameters

### `fSpyed` [in]

Indicates whether the block of memory to be freed was allocated while the current spy was active.

## Remarks

When a spy object implementing [IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy) is registered using [CoRegisterMallocSpy](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coregistermallocspy) function, COM calls this method immediately after any call to [IMalloc::Free](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-free). This method is included for completeness and consistency; it is not anticipated that developers will implement significant functionality in this method.

## See also

[IMalloc::Free](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-free)

[IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy)

[IMallocSpy::PreFree](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-prefree)