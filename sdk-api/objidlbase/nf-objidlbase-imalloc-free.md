# IMalloc::Free

## Description

Frees a previously allocated block of memory.

## Parameters

### `pv` [in]

A pointer to the memory block to be freed. If this parameter is **NULL**, this method has no effect.

## Remarks

This method frees a block of memory previously allocated through a call to [IMalloc::Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc) or [IMalloc::Realloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-realloc). The number of bytes freed equals the number of bytes that were allocated. After the call, the block of memory pointed to by *pv* is invalid and can no longer be used.

## See also

[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)

[IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc)