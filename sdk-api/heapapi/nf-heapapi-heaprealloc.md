# HeapReAlloc function

## Description

Reallocates a block of memory from a heap. This function enables you to resize a memory block and change other memory block properties. The allocated memory is not movable.

## Parameters

### `hHeap` [in]

A handle to the heap from which the memory is to be reallocated. This handle is a returned by either the [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) or [GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap) function.

### `dwFlags` [in]

The heap reallocation options. Specifying a value overrides the corresponding value specified in the *flOptions* parameter when the heap was created by using the [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) function. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **HEAP_GENERATE_EXCEPTIONS**<br><br>0x00000004 | The operating-system raises an exception to indicate a function failure, such as an out-of-memory condition, instead of returning **NULL**.<br><br>To ensure that exceptions are generated for all calls to this function, specify **HEAP_GENERATE_EXCEPTIONS** in the call to [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate). In this case, it is not necessary to additionally specify **HEAP_GENERATE_EXCEPTIONS** in this function call. |
| **HEAP_NO_SERIALIZE**<br><br>0x00000001 | Serialized access will not be used. For more information, see Remarks.<br><br>To ensure that serialized access is disabled for all calls to this function, specify **HEAP_NO_SERIALIZE** in the call to [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate). In this case, it is not necessary to additionally specify **HEAP_NO_SERIALIZE** in this function call.<br><br>This value should not be specified when accessing the process heap. The system may create additional threads within the application's process, such as a CTRL+C handler, that simultaneously access the process heap. |
| **HEAP_REALLOC_IN_PLACE_ONLY**<br><br>0x00000010 | There can be no movement when reallocating a memory block. If this value is not specified, the function may move the block to a new location. If this value is specified and the block cannot be resized without moving, the function fails, leaving the original memory block unchanged. |
| **HEAP_ZERO_MEMORY**<br><br>0x00000008 | If the reallocation request is for a larger size, the additional region of memory beyond the original size be initialized to zero. The contents of the memory block up to its original size are unaffected. |

### `lpMem` [in]

A pointer to the block of memory that the function reallocates. This pointer is returned by an earlier call to the [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) or **HeapReAlloc** function.

### `dwBytes` [in]

The new size of the memory block, in bytes. A memory block's size can be increased or decreased by using this function.

If the heap specified by the *hHeap* parameter is a "non-growable" heap, *dwBytes* must be less than 0x7FFF8. You create a non-growable heap by calling the [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) function with a nonzero value.

## Return value

If the function succeeds, the return value is a pointer to the reallocated memory block.

If the function fails and you have not specified **HEAP_GENERATE_EXCEPTIONS**, the return value is **NULL**.

If the function fails and you have specified **HEAP_GENERATE_EXCEPTIONS**, the function may generate either of the exceptions listed in the following table. For more information, see [GetExceptionCode](https://learn.microsoft.com/windows/desktop/Debug/getexceptioncode).

| Exception code | Description |
| --- | --- |
| **STATUS_NO_MEMORY** | The allocation attempt failed because of a lack of available memory or heap corruption. |
| **STATUS_ACCESS_VIOLATION** | The allocation attempt failed because of heap corruption or improper function parameters. |

The alignment of memory returned by **HeapReAlloc** is **MEMORY_ALLOCATION_ALIGNMENT** in WinNT.h:

```cpp
#if defined(_WIN64) || defined(_M_ALPHA)
#define MEMORY_ALLOCATION_ALIGNMENT 16
#else
#define MEMORY_ALLOCATION_ALIGNMENT 8
#endif
```

If the function fails, it does not call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror). An application cannot call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for extended error information.

## Remarks

If **HeapReAlloc** succeeds, it allocates at least the amount of memory requested.

If **HeapReAlloc** fails, the original memory is not freed, and the original handle and pointer are still valid.

**HeapReAlloc** is guaranteed to preserve the content of the memory being reallocated, even if the new memory is allocated at a different location. The process of preserving the memory content involves a memory copy operation that is potentially very time-consuming.

To free a block of memory allocated by **HeapReAlloc**, use the [HeapFree](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapfree) function.

Serialization ensures mutual exclusion when two or more threads attempt to simultaneously allocate or free blocks from the same heap. There is a small performance cost to serialization, but it must be used whenever multiple threads allocate and free memory from the same heap. Setting the **HEAP_NO_SERIALIZE** value eliminates mutual exclusion on the heap. Without serialization, two or more threads that use the same heap handle might attempt to allocate or free memory simultaneously, likely causing corruption in the heap. The **HEAP_NO_SERIALIZE** value can, therefore, be safely used only in the following situations:

- The process has only one thread.
- The process has multiple threads, but only one thread calls the heap functions for a specific heap.
- The process has multiple threads, and the application provides its own mechanism for mutual exclusion to a specific heap.

## See also

[Heap Functions](https://learn.microsoft.com/windows/win32/Memory/heap-functions)

[HeapAlloc](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapalloc)

[HeapFree](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapfree)

[Memory Management Functions](https://learn.microsoft.com/windows/win32/Memory/memory-management-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)