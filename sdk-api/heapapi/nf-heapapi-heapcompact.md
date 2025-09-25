# HeapCompact function

## Description

Returns the size of the largest committed free block in the specified heap. If the [Disable heap coalesce on free](https://learn.microsoft.com/windows-hardware/drivers/debugger/disable-heap-coalesce-on-free) global flag is set, this function also coalesces adjacent free blocks of memory in the heap.

## Parameters

### `hHeap` [in]

A handle to the heap. This handle is returned by either the [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) or [GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap) function.

### `dwFlags` [in]

The heap access options. This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **HEAP_NO_SERIALIZE**<br><br>0x00000001 | Serialized access will not be used.<br><br>For more information, see Remarks.<br><br>To ensure that serialized access is disabled for all calls to this function, specify **HEAP_NO_SERIALIZE** in the call to [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate). In this case, it is not necessary to additionally specify **HEAP_NO_SERIALIZE** in this function call.<br><br>Do not specify this value when accessing the process heap. The system may create additional threads within the application's process, such as a CTRL+C handler, that simultaneously access the process heap. |

## Return value

If the function succeeds, the return value is the size of the largest committed free block in the heap, in bytes.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

In the unlikely case that there is absolutely no space available in the heap, the function return value is zero, and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the value NO_ERROR.

## Remarks

The **HeapCompact** function is primarily useful for debugging. Ordinarily, the system compacts the heap whenever the [HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree) function is called, and the **HeapCompact** function returns the size of the largest free block in the heap but does not compact the heap any further. If the [Disable heap coalesce on free](https://learn.microsoft.com/windows-hardware/drivers/debugger/disable-heap-coalesce-on-free) global flag is set during debugging, the system does not compact the heap and calling the **HeapCompact** function does compact the heap. For more information about global flags, see the [GFlags](https://learn.microsoft.com/windows-hardware/drivers/debugger/gflags) documentation.

There is no guarantee that an application can successfully allocate a memory block of the size returned by **HeapCompact**. Other threads or the commit threshold might prevent such an allocation.

Serialization ensures mutual exclusion when two or more threads attempt to simultaneously allocate or free blocks from the same heap. There is a small performance cost to serialization, but it must be used whenever multiple threads allocate and free memory from the same heap. Setting the **HEAP_NO_SERIALIZE** value eliminates mutual exclusion on the heap. Without serialization, two or more threads that use the same heap handle might attempt to allocate or free memory simultaneously, likely causing corruption in the heap. The **HEAP_NO_SERIALIZE** value can, therefore, be safely used only in the following situations:

- The process has only one thread.
- The process has multiple threads, but only one thread calls the heap functions for a specific heap.
- The process has multiple threads, and the application provides its own mechanism for mutual exclusion to a specific heap.

## See also

[Heap Functions](https://learn.microsoft.com/windows/win32/Memory/heap-functions)

[HeapCreate](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapcreate)

[HeapValidate](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapvalidate)

[Memory Management Functions](https://learn.microsoft.com/windows/win32/Memory/memory-management-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)