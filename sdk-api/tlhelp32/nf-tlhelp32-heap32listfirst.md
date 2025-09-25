# Heap32ListFirst function

## Description

Retrieves information about the first heap that has been allocated by a specified process.

## Parameters

### `hSnapshot` [in]

A handle to the snapshot returned from a previous call to the
[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot) function.

### `lphl` [in, out]

A pointer to a
[HEAPLIST32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-heaplist32) structure.

## Return value

Returns **TRUE** if the first entry of the heap list has been copied to the buffer or **FALSE** otherwise. The **ERROR_NO_MORE_FILES** error value is returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function when no heap list exists or the snapshot does not contain heap list information.

## Remarks

The calling application must set the **dwSize** member of
[HEAPLIST32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-heapentry32) to the size, in bytes, of the structure.
**Heap32ListFirst** changes **dwSize** to the number of bytes written to the structure. This will never be greater than the initial value of **dwSize**, but it may be smaller. If the value is smaller, do not rely on the values of any members whose offsets are greater than this value.

To retrieve information about other heaps in the heap list, use the
[Heap32ListNext](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-heap32listnext) function.

#### Examples

For an example, see
[Traversing the Heap List](https://learn.microsoft.com/windows/desktop/ToolHelp/traversing-the-heap-list).

## See also

[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot)

[HEAPLIST32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-heaplist32)

[Heap Lists and Heap Walking](https://learn.microsoft.com/windows/desktop/ToolHelp/heap-lists-and-heap-walking)

[Heap32ListNext](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-heap32listnext)

[Tool Help Functions](https://learn.microsoft.com/windows/desktop/ToolHelp/tool-help-functions)