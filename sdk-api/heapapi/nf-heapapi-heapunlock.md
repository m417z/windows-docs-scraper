# HeapUnlock function

## Description

Releases ownership of the critical section object, or lock, that is associated with a specified heap. It reverses the action of the [HeapLock](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heaplock) function.

## Parameters

### `hHeap` [in]

A handle to the heap to be unlocked. This handle is returned by either the [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) or [GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The [HeapLock](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heaplock) function is primarily useful for preventing the allocation and release of heap memory by other threads while the calling thread uses the [HeapWalk](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapwalk) function. The **HeapUnlock** function is the inverse of **HeapLock**.

Each call to [HeapLock](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heaplock) must be matched by a corresponding call to the **HeapUnlock** function. Failure to call **HeapUnlock** will block the execution of any other threads of the calling process that attempt to access the heap.

If the **HeapUnlock** function is called on a heap created with the [HEAP_NO_SERIALIZATION](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) flag, the results are undefined.

#### Examples

[Enumerating a Heap](https://learn.microsoft.com/windows/desktop/Memory/enumerating-a-heap)

## See also

[Heap Functions](https://learn.microsoft.com/windows/win32/Memory/heap-functions)

[HeapLock](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heaplock)

[HeapWalk](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapwalk)

[Memory Management Functions](https://learn.microsoft.com/windows/win32/Memory/memory-management-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)