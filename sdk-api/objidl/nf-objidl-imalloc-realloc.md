# IMalloc::Realloc

## Description

Changes the size of a previously allocated block of memory.

## Parameters

### `pv` [in]

A pointer to the block of memory to be reallocated. This parameter can be **NULL**, as discussed in the Remarks section below.

### `cb` [in]

The size of the memory block to be reallocated, in bytes. This parameter can be 0, as discussed in the Remarks section below.

## Return value

If the method succeeds, the return value is a pointer to the reallocated block of memory. Otherwise, it is **NULL**.

## Remarks

This method reallocates a block of memory, but does not guarantee that its contents are initialized. Therefore, the caller is responsible for subsequently initializing the memory. The allocated block may be larger than *cb* bytes because of the space required for alignment and for maintenance information.

The *pv* argument points to the beginning of the block. If *pv* is **NULL**, **Realloc** allocates a new memory block in the same way that [IMalloc::Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc) does. If *pv* is not **NULL**, it should be a pointer returned by a prior call to **Alloc**.

The *cb* argument specifies the size of the new block, in bytes. The contents of the block are unchanged up to the shorter of the new and old sizes, although the new block can be in a different location. Because the new block can be in a different memory location, the pointer returned by **Realloc** is not guaranteed to be the pointer passed through the *pv* argument. If *pv* is not **NULL** and *cb* is zero, the memory pointed to by *pv* is freed.

**Realloc** returns a void pointer to the reallocated (and possibly moved) block of memory. The return value is **NULL** if the size is zero and the buffer argument is not **NULL**, or if there is not enough memory available to expand the block to the specified size. In the first case, the original block is freed; in the second, the original block is unchanged.

The storage space pointed to by the return value is guaranteed to be suitably aligned for storage of any type of object. To get a pointer to a type other than **void**, use a type cast on the return value.

## See also

[IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc)