# LSA_FREE_SHARED_MEMORY callback function

## Description

The **FreeSharedMemory** function frees a block of shared memory previously allocated by the
[AllocateSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_shared_memory) function.

## Parameters

### `SharedMem` [in]

Pointer to the shared memory section previously reserved using the
[CreateSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_shared_memory) function.

### `Memory` [in]

Pointer to the memory previously allocated from the shared memory section specified by the *SharedMem* parameter, using the
[AllocateSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_shared_memory) function.

## Remarks

A pointer to the **FreeSharedMemory** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[AllocateSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_shared_memory)

[CreateSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_shared_memory)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)