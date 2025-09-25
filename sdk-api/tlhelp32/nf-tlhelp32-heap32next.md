# Heap32Next function

## Description

Retrieves information about the next block of a heap that has been allocated by a process.

## Parameters

### `lphe` [out]

A pointer to a
[HEAPENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-heapentry32) structure.

## Return value

Returns **TRUE** if information about the next block in the heap has been copied to the buffer or **FALSE** otherwise. The
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR_NO_MORE_FILES** when no more objects in the heap exist and **ERROR_INVALID_DATA** if the heap appears to be corrupt or is modified during the walk in such a way that
**Heap32Next** cannot continue.

## Remarks

To retrieve information for the first block of a heap, use the
[Heap32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-heap32first) function.

The **Heap32Next** function does not maintain a reference to the target process. If the target process dies, the system may create a new process using the same process identifier. Therefore, the caller should maintain a reference to the target process as long as it is using **Heap32Next**.

Walking the heap with **Heap32First** and **Heap32Next** is inefficient, particularly for large heaps.
Use
[HeapWalk](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapwalk) instead.

#### Examples

For an example, see
[Traversing the Heap List](https://learn.microsoft.com/windows/desktop/ToolHelp/traversing-the-heap-list).

## See also

[HEAPENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-heapentry32)

[Heap Lists and Heap Walking](https://learn.microsoft.com/windows/desktop/ToolHelp/heap-lists-and-heap-walking)

[Heap32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-heap32first)

[Tool Help Functions](https://learn.microsoft.com/windows/desktop/ToolHelp/tool-help-functions)