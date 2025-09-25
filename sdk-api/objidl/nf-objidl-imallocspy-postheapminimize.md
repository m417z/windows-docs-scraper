# IMallocSpy::PostHeapMinimize

## Description

Performs operations required after calling [IMalloc::HeapMinimize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-heapminimize).

## Remarks

When a spy object implementing [IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy) is registered using the [CoRegisterMallocSpy](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coregistermallocspy) function, COM calls this method immediately after any call to [IMalloc::Free](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-free). This method is included for completeness and consistency; it is not anticipated that developers will implement significant functionality in this method.

## See also

[IMalloc::HeapMinimize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-heapminimize)

[IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy)

[IMallocSpy::PreHeapMinimize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-preheapminimize)