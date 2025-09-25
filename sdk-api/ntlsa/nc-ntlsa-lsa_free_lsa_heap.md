# LSA_FREE_LSA_HEAP callback function

## Description

Deallocates heap memory previously allocated by
[AllocateLsaHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_lsa_heap).

## Parameters

### `Base` [in]

Pointer to the buffer to be freed.

## Return value

This function does not return a value. However, if the function sets *Base* to **NULL**, the buffer was freed. If *Base* is not **NULL** after the function call ends, the buffer could not be freed.

## See also

[LSA_DISPATCH_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_dispatch_table)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)