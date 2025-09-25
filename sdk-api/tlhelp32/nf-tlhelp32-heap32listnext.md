# Heap32ListNext function

## Description

Retrieves information about the next heap that has been allocated by a process.

## Parameters

### `hSnapshot` [in]

A handle to the snapshot returned from a previous call to the
[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot) function.

### `lphl` [out]

A pointer to a
[HEAPLIST32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-heaplist32) structure.

## Return value

Returns **TRUE** if the next entry of the heap list has been copied to the buffer or **FALSE** otherwise. The **ERROR_NO_MORE_FILES** error value is returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function when no more entries in the heap list exist.

## Remarks

To retrieve information about the first heap in a heap list, use the
[Heap32ListFirst](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-heap32listfirst) function.

#### Examples

For an example, see
[Traversing the Heap List](https://learn.microsoft.com/windows/desktop/ToolHelp/traversing-the-heap-list).

## See also

[CreateToolhelp32Snapshot](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot)

[HEAPLIST32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-heaplist32)

[Heap Lists and Heap Walking](https://learn.microsoft.com/windows/desktop/ToolHelp/heap-lists-and-heap-walking)

[Heap32ListFirst](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-heap32listfirst)

[Tool Help Functions](https://learn.microsoft.com/windows/desktop/ToolHelp/tool-help-functions)