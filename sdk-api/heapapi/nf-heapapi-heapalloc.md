# HeapAlloc function

## Description

Allocates a block of memory from a heap. The allocated memory is not movable.

## Parameters

### `hHeap` [in]

A handle to the heap from which the memory will be allocated. This handle is returned by the [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) or [GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap) function.

### `dwFlags` [in]

The heap allocation options. Specifying any of these values will override the corresponding value specified when the heap was created with [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate). This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **HEAP_GENERATE_EXCEPTIONS**<br><br>0x00000004 | The system will raise an exception to indicate a function failure, such as an out-of-memory condition, instead of returning **NULL**.<br><br>To ensure that exceptions are generated for all calls to this function, specify **HEAP_GENERATE_EXCEPTIONS** in the call to [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate). In this case, it is not necessary to additionally specify **HEAP_GENERATE_EXCEPTIONS** in this function call. |
| **HEAP_NO_SERIALIZE**<br><br>0x00000001 | Serialized access will not be used for this allocation.<br><br>For more information, see Remarks.<br><br>To ensure that serialized access is disabled for all calls to this function, specify **HEAP_NO_SERIALIZE** in the call to [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate). In this case, it is not necessary to additionally specify **HEAP_NO_SERIALIZE** in this function call.<br><br>This value should not be specified when accessing the process's default heap. The system may create additional threads within the application's process, such as a CTRL+C handler, that simultaneously access the process's default heap. |
| **HEAP_ZERO_MEMORY**<br><br>0x00000008 | The allocated memory will be initialized to zero. Otherwise, the memory is not initialized to zero. |

### `dwBytes` [in]

The number of bytes to be allocated.

If the heap specified by the *hHeap* parameter is a "non-growable" heap, *dwBytes* must be less than 0x7FFF8. You create a non-growable heap by calling the [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) function with a nonzero value.

## Return value

If the function succeeds, the return value is a pointer to the allocated memory block.

If the function fails and you have not specified **HEAP_GENERATE_EXCEPTIONS**, the return value is **NULL**.

If the function fails and you have specified **HEAP_GENERATE_EXCEPTIONS**, the function may generate either of the exceptions listed in the following table. The particular exception depends upon the nature of the heap corruption. For more information, see [GetExceptionCode](https://learn.microsoft.com/windows/desktop/Debug/getexceptioncode).

| Exception code | Description |
| --- | --- |
| **STATUS_NO_MEMORY** | The allocation attempt failed because of a lack of available memory or heap corruption. |
| **STATUS_ACCESS_VIOLATION** | The allocation attempt failed because of heap corruption or improper function parameters. |

If the function fails, it does not call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror). An application cannot call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for extended error information.

## Remarks

If the **HeapAlloc** function succeeds, it allocates at least the amount of memory requested.

To allocate memory from the process's default heap, use **HeapAlloc** with the handle returned by the [GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap) function.

To free a block of memory allocated by **HeapAlloc**, use the [HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree) function.

Memory allocated by **HeapAlloc** is not movable. The address returned by **HeapAlloc** is valid until the memory block is freed or reallocated; the memory block does not need to be locked. Because the system cannot compact a private heap, it can become fragmented.

The alignment of memory returned by **HeapAlloc** is **MEMORY_ALLOCATION_ALIGNMENT** in WinNT.h:

```cpp
#if defined(_WIN64) || defined(_M_ALPHA)
#define MEMORY_ALLOCATION_ALIGNMENT 16
#else
#define MEMORY_ALLOCATION_ALIGNMENT 8
#endif
```

Applications that allocate large amounts of memory in various allocation sizes can use the [low-fragmentation heap](https://learn.microsoft.com/windows/desktop/Memory/low-fragmentation-heap) to reduce heap fragmentation.

Serialization ensures mutual exclusion when two or more threads attempt to simultaneously allocate or free blocks from the same heap. There is a small performance cost to serialization, but it must be used whenever multiple threads allocate and free memory from the same heap. Setting the **HEAP_NO_SERIALIZE** value eliminates mutual exclusion on the heap. Without serialization, two or more threads that use the same heap handle might attempt to allocate or free memory simultaneously, likely causing corruption in the heap. The **HEAP_NO_SERIALIZE** value can, therefore, be safely used only in the following situations:

- The process has only one thread.
- The process has multiple threads, but only one thread calls the heap functions for a specific heap.
- The process has multiple threads, and the application provides its own mechanism for mutual exclusion to a specific heap.

#### Examples

For an example, see [AWE Example](https://learn.microsoft.com/windows/win32/Memory/awe-example).

## See also

[Heap Functions](https://learn.microsoft.com/windows/win32/Memory/heap-functions)

[HeapFree](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapfree)

[HeapReAlloc](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heaprealloc)

[Memory Management Functions](https://learn.microsoft.com/windows/win32/Memory/memory-management-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)