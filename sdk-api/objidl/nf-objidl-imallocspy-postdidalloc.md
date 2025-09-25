# IMallocSpy::PostDidAlloc

## Description

Performs operations required after calling [IMalloc::DidAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-didalloc).

## Parameters

### `pRequest` [in]

The pointer specified in the call to [DidAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-didalloc).

### `fSpyed` [in]

Indicates whether the allocation was done while this spy was active.

### `fActual` [in]

The value returned by [DidAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-didalloc).

## Return value

The value returned to the caller of [DidAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-didalloc).

## Remarks

When a spy object implementing [IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy) is registered using the [CoRegisterMallocSpy](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coregistermallocspy) function, COM calls this method immediately after any call to [DidAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-didalloc). This method is included for completeness and consistency; it is not anticipated that developers will implement significant functionality in this method.

For convenience, *pRequest*, the original pointer passed in the call to [DidAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-didalloc), is passed to **PostDidAlloc**. In addition, the parameter *fActual* is a Boolean value that indicates whether this value was actually passed to **DidAlloc**. If not, it would indicate that [IMallocSpy::PreDidAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-predidalloc) was implemented to alter this pointer for some debugging purpose.

## See also

[IMalloc::DidAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-didalloc)

[IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy)

[IMallocSpy::PreDidAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-predidalloc)