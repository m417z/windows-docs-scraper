# LSA_ALLOCATE_PRIVATE_HEAP callback function

## Description

Allocates memory on the private heap.

Memory allocated with this routine must be deallocated with the
[FreePrivateHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_free_private_heap) function.

## Parameters

### `Length` [in]

Number of bytes to allocate from the heap.

## Return value

This function returns a pointer to the allocated heap memory. If memory could not be allocated, the function returns **NULL**.

## Remarks

A pointer to the **AllocatePrivateHeap** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)