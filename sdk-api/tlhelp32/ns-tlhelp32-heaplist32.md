# HEAPLIST32 structure

## Description

Describes an entry from a list that enumerates the heaps used by a specified process.

## Members

### `dwSize`

The size of the structure, in bytes. Before calling the
[Heap32ListFirst](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-heap32listfirst) function, set this member to `sizeof(HEAPLIST32)`. If you do not initialize **dwSize**,
**Heap32ListFirst** will fail.

### `th32ProcessID`

The identifier of the process to be examined.

### `th32HeapID`

The heap identifier. This is not a handle, and has meaning only to the tool help functions.

### `dwFlags`

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **HF32_DEFAULT** | Process's default heap |

## See also

[Heap32ListFirst](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-heap32listfirst)

[Heap32ListNext](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-heap32listnext)