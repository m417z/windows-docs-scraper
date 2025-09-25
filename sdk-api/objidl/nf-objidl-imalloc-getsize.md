# IMalloc::GetSize

## Description

Retrieves the size of a previously allocated block of memory.

## Parameters

### `pv` [in]

A pointer to the block of memory.

## Return value

The size of the allocated memory block in bytes or, if *pv* is a **NULL** pointer, -1.

## Remarks

To get the size in bytes of a memory block, the block must have been previously allocated with [IMalloc::Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc) or [IMalloc::Realloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-realloc). The size returned is the actual size of the allocation, which may be greater than the size requested when the allocation was made.

## See also

[IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc)