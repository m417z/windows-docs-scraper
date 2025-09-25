# GetProcessHeaps function

## Description

Returns the number of active heaps and retrieves handles to all of the active heaps for the calling process.

## Parameters

### `NumberOfHeaps` [in]

The maximum number of heap handles that can be stored into the buffer pointed to by *ProcessHeaps*.

### `ProcessHeaps` [out]

A pointer to a buffer that receives an array of heap handles.

## Return value

The return value is the number of handles to heaps that are active for the calling process.

If the return value is less than or equal to *NumberOfHeaps*, the function has stored that number of heap handles in the buffer pointed to by *ProcessHeaps*.

If the return value is greater than *NumberOfHeaps*, the buffer pointed to by *ProcessHeaps* is too small to hold all the heap handles for the calling process, and the function stores *NumberOfHeaps* handles in the buffer. Use the return value to allocate a buffer that is large enough to receive all of the handles, and call the function again.

If the return value is zero, the function has failed because every process has at least one active heap, the default heap for the process. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetProcessHeaps** function obtains a handle to the default heap of the calling process, plus handles to any additional private heaps created by calling the [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) function on any thread in the process.

The **GetProcessHeaps** function is primarily useful for debugging, because some of the private heaps retrieved by the function may have been created by other code running in the process and may be destroyed after **GetProcessHeaps** returns. Destroying a heap invalidates the handle to the heap, and continued use of such handles can cause undefined behavior in the application. Heap functions should be called only on the default heap of the calling process and on private heaps that the process creates and manages.

To obtain a handle to the process heap of the calling process, use the [GetProcessHeap](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-getprocessheap) function.

#### Examples

For an example, see [Getting Process Heaps](https://learn.microsoft.com/windows/desktop/Memory/getting-process-heaps).

## See also

[GetProcessHeap](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-getprocessheap)

[Heap Functions](https://learn.microsoft.com/windows/win32/Memory/heap-functions)

[HeapCreate](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapcreate)

[Memory Management Functions](https://learn.microsoft.com/windows/win32/Memory/memory-management-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)