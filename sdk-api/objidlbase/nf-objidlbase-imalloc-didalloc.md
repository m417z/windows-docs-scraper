# IMalloc::DidAlloc

## Description

Determines whether this allocator was used to allocate the specified block of memory.

## Parameters

### `pv` [in]

A pointer to the block of memory. If this parameter is a **NULL** pointer, -1 is returned.

## Return value

This method can return the following values.

| Return value | Description |
| --- | --- |
| 1 | The block of memory was allocated by this allocator. |
| 0 | The block of memory was not allocated by this allocator. |
| -1 | This method cannot determine whether this allocator allocated the block of memory. |

## See also

[IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc)