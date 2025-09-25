# IMallocSpy::PreRealloc

## Description

Performs operations required before calling [IMalloc::Realloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-realloc).

## Parameters

### `pRequest` [in]

The pointer to the block of memory specified in the call to [IMalloc::Realloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-realloc).

### `cbRequest` [in]

The byte count of the block of memory as specified in the original call to [IMalloc::Realloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-realloc).

### `ppNewRequest` [out]

Address of pointer variable that receives a pointer to the memory block to be reallocated. This may be different from the pointer in *pRequest* if the implementation of **PreRealloc** extends or modifies the reallocation. This is pointer should always be stored by **PreRealloc**.

### `fSpyed` [in]

Indicates whether the block of memory was allocated while this spy was active.

## Return value

The byte count to be passed to [IMalloc::Realloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-realloc).

## Remarks

The **PreRealloc** implementation may extend and/or modify the allocation to store debug-specific information with the allocation. Thus, the *ppNewRequest* parameter may differ from *pRequest*, a pointer to the request specified in the original call to [Realloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-realloc).

**PreRealloc** can force memory allocation failure by returning 0, allowing testing to ensure that the application handles allocation failure gracefully in all cases. In this case, [PostRealloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-postrealloc) is not called and [Realloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-realloc) returns **NULL**. However, if **Realloc** encounters a real memory failure and returns **NULL**, **PostRealloc** is called. Forcing allocation failure is effective only if *cbRequest* is not equal to 0.

## See also

[IMalloc::Realloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-realloc)

[IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy)

[IMallocSpy::PostRealloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-postrealloc)