# HeapValidate function

## Description

Validates the specified heap. The function scans all the memory blocks in the heap and verifies that the heap control structures maintained by the heap manager are in a consistent state. You can also use the
**HeapValidate** function to validate a single memory block within a specified heap without checking the validity of the entire heap.

## Parameters

### `hHeap` [in]

A handle to the heap to be validated. This handle is returned by either the
[HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) or
[GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap) function.

### `dwFlags` [in]

The heap access options. This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **HEAP_NO_SERIALIZE**<br><br>0x00000001 | Serialized access will not be used. For more information, see Remarks.<br><br>To ensure that serialized access is disabled for all calls to this function, specify **HEAP_NO_SERIALIZE** in the call to [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate). In this case, it is not necessary to additionally specify **HEAP_NO_SERIALIZE** in this function call.<br><br>This value should not be specified when accessing the process default heap. The system may create additional threads within the application's process, such as a CTRL+C handler, that simultaneously access the process default heap. |

### `lpMem` [in, optional]

A pointer to a memory block within the specified heap. This parameter may be **NULL**.

If this parameter is **NULL**, the function attempts to validate the entire heap specified by *hHeap*.

If this parameter is not **NULL**, the function attempts to validate the memory block pointed to by *lpMem*. It does not attempt to validate the rest of the heap.

## Return value

If the specified heap or memory block is valid, the return value is nonzero.

If the specified heap or memory block is invalid, the return value is zero. On a system set up for debugging, the
**HeapValidate** function then displays debugging messages that describe the part of the heap or memory block that is invalid, and stops at a hard-coded breakpoint so that you can examine the system to determine the source of the invalidity. The
**HeapValidate** function does not set the thread's last error value. There is no extended error information for this function; do not call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **HeapValidate** function is primarily useful for debugging because validation is potentially time-consuming. Validating a heap can block other threads from accessing the heap and can degrade performance, especially on symmetric multiprocessing (SMP) computers. These side effects can last until **HeapValidate** returns.

There are heap control structures for each memory block in a heap, and for the heap as a whole. When you use the
**HeapValidate** function to validate a complete heap, it checks all of these control structures for consistency.

When you use
**HeapValidate** to validate a single memory block within a heap, it checks only the control structures pertaining to that element.
**HeapValidate** can only validate allocated memory blocks. Calling
**HeapValidate** on a freed memory block will return **FALSE** because there are no control structures to validate.

If you want to validate the heap elements enumerated by the
[HeapWalk](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapwalk) function, you should only call
**HeapValidate** on the elements that have **PROCESS_HEAP_ENTRY_BUSY** in the **wFlags** member of the
[PROCESS_HEAP_ENTRY](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-process_heap_entry) structure.
**HeapValidate** returns **FALSE** for all heap elements that do not have this bit set.

Serialization ensures mutual exclusion when two or more threads attempt to simultaneously allocate or free blocks from the same heap. There is a small performance cost to serialization, but it must be used whenever multiple threads allocate and free memory from the same heap. Setting the **HEAP_NO_SERIALIZE** value eliminates mutual exclusion on the heap. Without serialization, two or more threads that use the same heap handle might attempt to allocate or free memory simultaneously, likely causing corruption in the heap. The **HEAP_NO_SERIALIZE** value can, therefore, be safely used only in the following situations:

* The process has only one thread.
* The process has multiple threads, but only one thread calls the heap functions for a specific heap.
* The process has multiple threads, and the application provides its own mechanism for mutual exclusion to a specific heap.

## See also

[Heap Functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions)

[HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate)

[HeapWalk](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapwalk)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[PROCESS_HEAP_ENTRY](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-process_heap_entry)