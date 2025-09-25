# HeapDestroy function

## Description

Destroys the specified heap object.

**HeapDestroy** de-commits and releases all the pages of a private heap object, and it invalidates the handle to the heap.

## Parameters

### `hHeap` [in]

A handle to the heap to be destroyed. This handle is returned by the [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) function. Do not use the handle to the process heap returned by the [GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Processes can call **HeapDestroy** without first calling the [HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree) function to free memory allocated from the heap.

#### Examples

[Enumerating a Heap](https://learn.microsoft.com/windows/desktop/Memory/enumerating-a-heap)

## See also

[Heap Functions](https://learn.microsoft.com/windows/win32/Memory/heap-functions)

[HeapCreate](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapcreate)

[Memory Management Functions](https://learn.microsoft.com/windows/win32/Memory/memory-management-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)