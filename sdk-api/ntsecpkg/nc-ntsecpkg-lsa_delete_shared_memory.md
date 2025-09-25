# LSA_DELETE_SHARED_MEMORY callback function

## Description

The **DeleteSharedMemory** function releases a section of memory that is shared by clients and a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `SharedMem` [in]

Pointer to shared memory previously reserved by the
[CreateSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_shared_memory) function.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**.

## Remarks

The **DeleteSharedMemory** function releases the shared memory reserved by the
[CreateSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_shared_memory) function.

To release shared memory allocated by the
[AllocateSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_shared_memory) function, use the
[FreeSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_free_shared_memory) function.

Pointers to these functions are available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[AllocateSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_shared_memory)

[CreateSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_shared_memory)

[FreeSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_free_shared_memory)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)