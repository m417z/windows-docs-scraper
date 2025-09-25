# IMallocSpy::PreGetSize

## Description

Performs operations required before calling [IMalloc::GetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-getsize).

## Parameters

### `pRequest` [in]

The pointer that the caller is passing to [GetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-getsize).

### `fSpyed` [in]

Indicates whether the block of memory was allocated while the current spy was active.

## Return value

A pointer to the actual allocation for which the size is to be determined.

## Remarks

The **PreGetSize** method receives as its *pRequest* parameter the pointer the caller is passing to [IMalloc::GetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-getsize). It must then return a pointer to the actual allocation, which may have altered *pRequest* in the implementation of either the [PreAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-prealloc) or the [PreRealloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-prerealloc) method of [IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy). The pointer to the true allocation is then passed to **GetSize** as its *pv* parameter.

[IMalloc::GetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-getsize) then returns the size determined, and COM passes this value to [IMallocSpy::PostGetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-postgetsize) in *cbActual*.

The size determined by [GetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-getsize) is the value returned by the [HeapSize](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapsize) function. This is the size originally requested. For example, a memory allocation request of 27 bytes returns an allocation of 32 bytes and **GetSize** returns 27.

## See also

[IMalloc::GetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-getsize)

[IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy)

[IMallocSpy::PostGetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-postgetsize)