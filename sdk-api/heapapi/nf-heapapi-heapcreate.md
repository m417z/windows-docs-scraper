# HeapCreate function

## Description

Creates a private heap object that can be used by the calling process. The function reserves space in the virtual address space of the process and allocates physical storage for a specified initial portion of this block.

## Parameters

### `flOptions` [in]

The heap allocation options. These options affect subsequent access to the new heap through calls to the heap functions. This parameter can be 0 or one or more of the following values.

| Value | Meaning |
| --- | --- |
| **HEAP_CREATE_ENABLE_EXECUTE**<br><br>0x00040000 | All memory blocks that are allocated from this heap allow code execution, if the hardware enforces [data execution prevention](https://learn.microsoft.com/windows/desktop/Memory/data-execution-prevention). Use this flag heap in applications that run code from the heap. If **HEAP_CREATE_ENABLE_EXECUTE** is not specified and an application attempts to run code from a protected page, the application receives an exception with the status code **STATUS_ACCESS_VIOLATION**. |
| **HEAP_GENERATE_EXCEPTIONS**<br><br>0x00000004 | The system raises an exception to indicate failure (for example, an out-of-memory condition) for calls to [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) and [HeapReAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heaprealloc) instead of returning **NULL**. |
| **HEAP_NO_SERIALIZE**<br><br>0x00000001 | Serialized access is not used when the heap functions access this heap. This option applies to all subsequent heap function calls. Alternatively, you can specify this option on individual heap function calls.<br><br>The low-fragmentation heap (LFH) cannot be enabled for a heap created with this option.<br><br> A heap created with this option cannot be locked.<br><br>For more information about serialized access, see the Remarks section of this topic. |

### `dwInitialSize` [in]

The initial size of the heap, in bytes. This value determines the initial amount of memory that is committed for the heap. The value is rounded up to a multiple of the system page size. The value must be smaller than *dwMaximumSize*.

If this parameter is 0, the function commits one page. To determine the size of a page on the host computer, use the [GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo) function.

### `dwMaximumSize` [in]

The maximum size of the heap, in bytes. The **HeapCreate** function rounds *dwMaximumSize* up to a multiple of the system page size and then reserves a block of that size in the process's virtual address space for the heap. If allocation requests made by the [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) or [HeapReAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heaprealloc) functions exceed the size specified by *dwInitialSize*, the system commits additional pages of memory for the heap, up to the heap's maximum size.

If *dwMaximumSize* is not zero, the heap size is fixed and cannot grow beyond the maximum size. Also, the largest memory block that can be allocated from the heap is slightly less than 512 KB for a 32-bit process and slightly less than 1,024 KB for a 64-bit process. Requests to allocate larger blocks fail, even if the maximum size of the heap is large enough to contain the block.

If *dwMaximumSize* is 0, the heap can grow in size. The heap's size is limited only by the available memory. Requests to allocate memory blocks larger than the limit for a fixed-size heap do not automatically fail; instead, the system calls the [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc) function to obtain the memory that is needed for large blocks. Applications that need to allocate large memory blocks should set *dwMaximumSize* to 0.

## Return value

If the function succeeds, the return value is a handle to the newly created heap.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **HeapCreate** function creates a private heap object from which the calling process can allocate memory blocks by using the [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) function. The initial size determines the number of committed pages that are allocated initially for the heap. The maximum size determines the total number of reserved pages. These pages create a block in the process's virtual address space into which the heap can grow. If requests by **HeapAlloc** exceed the current size of committed pages, additional pages are automatically committed from this reserved space, if the physical storage is available.

**Windows Server 2003 and Windows XP:** By default, the newly created private heap is a standard heap. To enable the low-fragmentation heap, call the [HeapSetInformation](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapsetinformation) function with a handle to the private heap.

The memory of a private heap object is accessible only to the process that created it. If a dynamic-link library (DLL) creates a private heap, the heap is created in the address space of the process that calls the DLL, and it is accessible only to that process.

The system uses memory from the private heap to store heap support structures, so not all of the specified heap size is available to the process. For example, if the [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) function requests 64 kilobytes (K) from a heap with a maximum size of 64K, the request may fail because of system overhead.

If **HEAP_NO_SERIALIZE** is not specified (the simple default), the heap serializes access within the calling process. Serialization ensures mutual exclusion when two or more threads attempt simultaneously to allocate or free blocks from the same heap. There is a small performance cost to serialization, but it must be used whenever multiple threads allocate and free memory from the same heap. The [HeapLock](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heaplock) and [HeapUnlock](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapunlock) functions can be used to block and permit access to a serialized heap.

Setting **HEAP_NO_SERIALIZE** eliminates mutual exclusion on the heap. Without serialization, two or more threads that use the same heap handle might attempt to allocate or free memory simultaneously, which may cause corruption in the heap. Therefore, **HEAP_NO_SERIALIZE** can safely be used only in the following situations:

* The process has only one thread.
* The process has multiple threads, but only one thread calls the heap functions for a specific heap.
* The process has multiple threads, and the application provides its own mechanism for mutual exclusion to a specific heap.

If the [HeapLock](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heaplock) and [HeapUnlock](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapunlock) functions are called on a heap created with the **HEAP_NO_SERIALIZE** flag, the results are undefined.

To obtain a handle to the default heap for a process, use the [GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap) function. To obtain handles to the default heap and private heaps that are active for the calling process, use the [GetProcessHeaps](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheaps) function.

#### Examples

[Enumerating a Heap](https://learn.microsoft.com/windows/desktop/Memory/enumerating-a-heap)

## See also

[Heap Functions](https://learn.microsoft.com/windows/win32/Memory/heap-functions)

[HeapAlloc](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapalloc)

[HeapDestroy](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapdestroy)

[HeapValidate](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapvalidate)

[Memory Management Functions](https://learn.microsoft.com/windows/win32/Memory/memory-management-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)