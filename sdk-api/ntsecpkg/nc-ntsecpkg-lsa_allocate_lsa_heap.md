# LSA_ALLOCATE_LSA_HEAP callback function

## Description

Allocates memory on the heap. Some information passed back to the LSA is expected to be allocated using this function. Memory allocated with this routine must be deallocated with the
[FreeLsaHeap](https://learn.microsoft.com/windows/desktop/api/ntlsa/nc-ntlsa-lsa_free_lsa_heap) function.

## Parameters

### `Length` [in]

Number of bytes to allocate from the heap.

## Return value

This function returns a pointer to the allocated heap memory. If memory could not be allocated, the function returns **NULL**.

## See also

[LSA_DISPATCH_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_dispatch_table)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)