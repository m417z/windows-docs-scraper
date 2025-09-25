# GetProcessHeap function

## Description

Retrieves a handle to the default heap of the calling process. This handle can then be used in subsequent calls to the heap functions.

## Return value

If the function succeeds, the return value is a handle to the calling process's heap.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetProcessHeap** function obtains a handle to the default heap for the calling process. A process can use this handle to allocate memory from the process heap without having to first create a private heap using the [HeapCreate](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapcreate) function.

**Windows Server 2003 and Windows XP:** To enable the low-fragmentation heap for the default heap of the process, call the [HeapSetInformation](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapsetinformation) function with the handle returned by **GetProcessHeap**.

#### Examples

For an example, see [Getting Process Heaps](https://learn.microsoft.com/windows/desktop/Memory/getting-process-heaps).

## See also

[Heap Functions](https://learn.microsoft.com/windows/win32/Memory/heap-functions)

[HeapCreate](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapcreate)

[Memory Management Functions](https://learn.microsoft.com/windows/win32/Memory/memory-management-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)