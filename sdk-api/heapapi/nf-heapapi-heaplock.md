# HeapLock function

## Description

Attempts to acquire the critical section object, or lock, that is associated with a specified heap.

## Parameters

### `hHeap` [in]

A handle to the heap to be locked. This handle is returned by either the [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) or [GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the function succeeds, the calling thread owns the heap lock. Only the calling thread will be able to allocate or release memory from the heap. The execution of any other thread of the calling process will be blocked if that thread attempts to allocate or release memory from the heap. Such threads will remain blocked until the thread that owns the heap lock calls the [HeapUnlock](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapunlock) function.

The **HeapLock** function is primarily useful for preventing the allocation and release of heap memory by other threads while the calling thread uses the [HeapWalk](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapwalk) function.

If the **HeapLock** function is called on a heap created with the [HEAP_NO_SERIALIZE](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) flag, the results are undefined.

Each successful call to **HeapLock** must be matched by a corresponding call to [HeapUnlock](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapunlock). Failure to call **HeapUnlock** will block the execution of any other threads of the calling process that attempt to access the heap.

#### Examples

[Enumerating a Heap](https://learn.microsoft.com/windows/desktop/Memory/enumerating-a-heap)

## See also

[Heap Functions](https://learn.microsoft.com/windows/win32/Memory/heap-functions)

[HeapUnlock](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapunlock)

[HeapWalk](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapwalk)

[Memory Management Functions](https://learn.microsoft.com/windows/win32/Memory/memory-management-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)