# IMallocSpy::PreDidAlloc

## Description

Performs operations required before calling [IMalloc::DidAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-didalloc).

## Parameters

### `pRequest` [in]

The pointer specified in the call to [DidAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-didalloc).

### `fSpyed` [in]

Indicates whether the allocation was done while this spy was active.

## Return value

The value passed to [DidAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-didalloc) as the *fActual* parameter.

## Remarks

When a spy object implementing [IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy) is registered with the [CoRegisterMallocSpy](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coregistermallocspy) function, COM calls this method immediately before any call to [IMalloc::DidAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-didalloc). This method is included for completeness and consistency; it is not anticipated that developers will implement significant functionality in this method.

## See also

[IMalloc::DidAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-didalloc)

[IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy)

[IMallocSpy::PostDidAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-postdidalloc)