# HeapWalk function

## Description

Enumerates the memory blocks in the specified heap.

## Parameters

### `hHeap` [in]

A handle to the heap. This handle is returned by either the
[HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) or
[GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap) function.

### `lpEntry` [in, out]

A pointer to a [PROCESS_HEAP_ENTRY](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-process_heap_entry) structure
that maintains state information for a particular heap enumeration.

If the **HeapWalk** function succeeds, returning the value
**TRUE**, this structure's members contain information about the next memory block in the
heap.

To initiate a heap enumeration, set the **lpData** field of the
[PROCESS_HEAP_ENTRY](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-process_heap_entry) structure to
**NULL**. To continue a particular heap enumeration, call the
**HeapWalk** function repeatedly, with no changes to
*hHeap*, *lpEntry*, or any of the members of the
**PROCESS_HEAP_ENTRY** structure.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the heap enumeration terminates successfully by reaching the end of the heap, the function returns
**FALSE**, and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)
returns the error code **ERROR_NO_MORE_ITEMS**.

## Remarks

The **HeapWalk** function is primarily useful for debugging
because enumerating a heap is a potentially time-consuming operation. Locking the heap during enumeration blocks
other threads from accessing the heap and can degrade performance, especially on symmetric multiprocessing (SMP)
computers. The side effects can last until the heap is unlocked. Use the
[HeapLock](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heaplock) and
[HeapUnlock](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapunlock) functions to control heap locking during heap
enumeration.

To initiate a heap enumeration, call **HeapWalk** with the
**lpData** field of the
[PROCESS_HEAP_ENTRY](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-process_heap_entry) structure pointed to by
*lpEntry* set to **NULL**.

To continue a heap enumeration, call **HeapWalk** with the same
*hHeap* and *lpEntry* values, and with the
[PROCESS_HEAP_ENTRY](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-process_heap_entry) structure unchanged from the
preceding call to **HeapWalk**. Repeat this process until you
have no need for further enumeration, or until the function returns **FALSE** and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_NO_MORE_ITEMS**, indicating that all of the heap's memory blocks have been
enumerated.

No special call of **HeapWalk** is needed to terminate the
heap enumeration, since no enumeration state data is maintained outside the contents of the
[PROCESS_HEAP_ENTRY](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-process_heap_entry) structure.

**HeapWalk** can fail in a multithreaded application if the
heap is not locked during the heap enumeration.

#### Examples

[Enumerating a Heap](https://learn.microsoft.com/windows/desktop/Memory/enumerating-a-heap)

## See also

[Heap Functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions)

[HeapLock](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heaplock)

[HeapReAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heaprealloc)

[HeapUnlock](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapunlock)

[HeapValidate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapvalidate)

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[PROCESS_HEAP_ENTRY](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-process_heap_entry)