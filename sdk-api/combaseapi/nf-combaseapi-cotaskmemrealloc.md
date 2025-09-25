# CoTaskMemRealloc function

## Description

Changes the size of a previously allocated block of task memory.

## Parameters

### `pv` [in, optional]

A pointer to the memory block to be reallocated. This parameter can be **NULL**, as discussed in Remarks.

### `cb` [in]

The size of the memory block to be reallocated, in bytes. This parameter can be 0, as discussed in Remarks.

## Return value

If the function succeeds, it returns the reallocated memory block. Otherwise, it returns **NULL**.

## Remarks

This function changes the size of a previously allocated memory block in the same way that [IMalloc::Realloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-realloc) does. It is not necessary to call the [CoGetMalloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetmalloc) function to get a pointer to the OLE allocator before calling **CoTaskMemRealloc**.

The *pv* parameter points to the beginning of the memory block. If *pv* is **NULL**, **CoTaskMemRealloc** allocates a new memory block in the same way as the [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) function. If *pv* is not **NULL**, it should be a pointer returned by a prior call to **CoTaskMemAlloc**.

The *cb* parameter specifies the size of the new block. The contents of the block are unchanged up to the shorter of the new and old sizes, although the new block can be in a different location. Because the new block can be in a different memory location, the pointer returned by **CoTaskMemRealloc** is not guaranteed to be the pointer passed through the *pv* argument. If *pv* is not **NULL** and *cb* is 0, then the memory pointed to by *pv* is freed.

**CoTaskMemRealloc** returns a void pointer to the reallocated (and possibly moved) memory block. The return value is **NULL** if the size is 0 and the buffer argument is not **NULL**, or if there is not enough memory available to expand the block to the specified size. In the first case, the original block is freed; in the second case, the original block is unchanged.

The storage space pointed to by the return value is guaranteed to be suitably aligned for storage of any type of object. To get a pointer to a type other than **void**, use a type cast on the return value.

## See also

[CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc)

[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)

[IMalloc::Realloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-realloc)