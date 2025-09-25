# HEAPENTRY32 structure

## Description

Describes one entry (block) of a heap that is being examined.

## Members

### `dwSize`

The size of the structure, in bytes. Before calling the
[Heap32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-heap32first) function, set this member to `sizeof(HEAPENTRY32)`. If you do not initialize **dwSize**,
**Heap32First** fails.

### `hHandle`

A handle to the heap block.

### `dwAddress`

The linear address of the start of the block.

### `dwBlockSize`

The size of the heap block, in bytes.

### `dwFlags`

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **LF32_FIXED** | The memory block has a fixed (unmovable) location. |
| **LF32_FREE** | The memory block is not used. |
| **LF32_MOVEABLE** | The memory block location can be moved. |

### `dwLockCount`

This member is no longer used and is always set to zero.

### `dwResvd`

Reserved; do not use or alter.

### `th32ProcessID`

The identifier of the process that uses the heap.

### `th32HeapID`

The heap identifier. This is not a handle, and has meaning only to the tool help functions.

## See also

[Heap32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-heap32first)

[Heap32Next](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-heap32next)