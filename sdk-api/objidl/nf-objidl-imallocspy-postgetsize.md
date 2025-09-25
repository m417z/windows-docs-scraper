# IMallocSpy::PostGetSize

## Description

Performs operations required after calling [IMalloc::GetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-getsize).

## Parameters

### `cbActual` [in]

The number of bytes in the allocation, as returned by [GetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-getsize).

### `fSpyed` [in]

Indicates whether the block of memory was allocated while the current spy was active.

## Return value

The value returned by [IMalloc::GetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-getsize), which is the size of the allocated block of memory, in bytes.

## Remarks

The size determined by [GetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-getsize) is the value returned by the [HeapSize](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapsize) function. This is the size originally requested. For example, a memory allocation request of 27 bytes returns an allocation of 32 bytes and **GetSize** returns 27.

## See also

[IMalloc::GetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-getsize)

[IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy)

[IMallocSpy::PreGetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-pregetsize)