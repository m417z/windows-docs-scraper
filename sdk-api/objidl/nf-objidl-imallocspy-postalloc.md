# IMallocSpy::PostAlloc

## Description

Performs operations required after calling [IMalloc::Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc).

## Parameters

### `pActual` [in]

The pointer returned from [Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc).

## Return value

This method returns a pointer to the beginning of the block of memory actually allocated. This pointer is also returned to the caller of [Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc). If debug information is written at the front of the caller's allocation, this should be a forward offset from *pActual*. The value is the same as *pActual* if debug information is appended or if no debug information is attached.

## Remarks

When a spy object implementing [IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy) is registered using the [CoRegisterMallocSpy](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coregistermallocspy) function, COM calls **PostAlloc** after any call to [Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc). It takes as input a pointer to the allocation done by the call to **Alloc**, and returns a pointer to the beginning of the total allocation, which could include a forward offset from the other value if [IMallocSpy::PreAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-prealloc) was implemented to attach debug information to the allocation in this way. If not, the same pointer is returned and also becomes the return value to the caller of **Alloc**.

## See also

[IMalloc::Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc)

[IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy)

[IMallocSpy::PreAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-prealloc)