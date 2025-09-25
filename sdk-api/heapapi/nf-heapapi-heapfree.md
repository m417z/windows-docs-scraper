# HeapFree function

## Description

Frees a memory block allocated from a heap by the [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) or [HeapReAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heaprealloc) function.

## Parameters

### `hHeap` [in]

A handle to the heap whose memory block is to be freed. This handle is returned by either the [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) or [GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap) function.

### `dwFlags` [in]

The heap free options. Specifying the following value overrides the corresponding value specified in the *flOptions* parameter when the heap was created by using the [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) function.

| Value | Meaning |
| --- | --- |
| **HEAP_NO_SERIALIZE**<br><br>0x00000001 | Serialized access will not be used. For more information, see Remarks.<br><br>To ensure that serialized access is disabled for all calls to this function, specify **HEAP_NO_SERIALIZE** in the call to [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate). In this case, it is not necessary to additionally specify **HEAP_NO_SERIALIZE** in this function call.<br><br>Do not specify this value when accessing the process heap. The system may create additional threads within the application's process, such as a CTRL+C handler, that simultaneously access the process heap. |

### `lpMem` [in]

A pointer to the memory block to be freed. This pointer is returned by the [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) or [HeapReAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heaprealloc) function. This pointer can be **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. An application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for extended error information.

## Remarks

You should not refer in any way to memory that has been freed by **HeapFree**. After that memory is freed, any information that may have been in it is gone forever. If you require information, do not free memory containing the information. Function calls that return information about memory (such as [HeapSize](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapsize)) may not be used with freed memory, as they may return bogus data. Calling **HeapFree** twice with the same pointer can cause heap corruption, resulting in subsequent calls to [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) returning the same pointer twice.

Serialization ensures mutual exclusion when two or more threads attempt to simultaneously allocate or free blocks from the same heap. There is a small performance cost to serialization, but it must be used whenever multiple threads allocate and free memory from the same heap. Setting the **HEAP_NO_SERIALIZE** value eliminates mutual exclusion on the heap. Without serialization, two or more threads that use the same heap handle might attempt to allocate or free memory simultaneously, likely causing corruption in the heap. The **HEAP_NO_SERIALIZE** value can, therefore, be safely used only in the following situations:

- The process has only one thread.
- The process has multiple threads, but only one thread calls the heap functions for a specific heap.
- The process has multiple threads, and the application provides its own mechanism for mutual exclusion to a specific heap.

#### Examples

For an example, see [Getting Process Heaps](https://learn.microsoft.com/windows/desktop/Memory/getting-process-heaps).

## See also

[Heap Functions](https://learn.microsoft.com/windows/win32/Memory/heap-functions)

[HeapAlloc](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapalloc)

[HeapReAlloc](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heaprealloc)

[Memory Management Functions](https://learn.microsoft.com/windows/win32/Memory/memory-management-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)