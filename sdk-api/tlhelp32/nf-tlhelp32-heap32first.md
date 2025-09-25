# Heap32First function

## Description

Retrieves information about the first block of a heap that has been allocated by a process.

## Parameters

### `lphe` [in, out]

A pointer to a
[HEAPENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-heapentry32) structure.

### `th32ProcessID` [in]

The identifier of the process context that owns the heap.

### `th32HeapID` [in]

The identifier of the heap to be enumerated.

## Return value

Returns **TRUE** if information for the first heap block has been copied to the buffer or **FALSE** otherwise. The **ERROR_NO_MORE_FILES** error value is returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function if the heap is invalid or empty.

## Remarks

The calling application must set the **dwSize** member of
[HEAPENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-heapentry32) to the size, in bytes, of the structure.
**Heap32First** changes **dwSize** to the number of bytes written to the structure. This will never be greater than the initial value of **dwSize**, but it may be smaller. If the value is smaller, do not rely on the values of any members whose offsets are greater than this value.

To access subsequent blocks of the same heap, use the
[Heap32Next](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-heap32next) function.

Walking the heap with **Heap32First** and **Heap32Next** is inefficient, particularly for large heaps.
Use
[HeapWalk](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapwalk) instead.

#### Examples

For an example, see
[Traversing the Heap List](https://learn.microsoft.com/windows/desktop/ToolHelp/traversing-the-heap-list).

## See also

[HEAPENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-heapentry32)

[Heap Lists and Heap Walking](https://learn.microsoft.com/windows/desktop/ToolHelp/heap-lists-and-heap-walking)

[Heap32Next](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-heap32next)

[Tool Help Functions](https://learn.microsoft.com/windows/desktop/ToolHelp/tool-help-functions)