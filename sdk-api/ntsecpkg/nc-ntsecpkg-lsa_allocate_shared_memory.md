# LSA_ALLOCATE_SHARED_MEMORY callback function

## Description

The **AllocateSharedMemory** function allocates a block of shared memory from a section of memory previously reserved by a call to the
[CreateSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_shared_memory) function.

## Parameters

### `SharedMem` [in]

Pointer to a section of reserved shared memory.

### `Size` [in]

Specifies the amount of shared memory to allocate, in bytes.

## Return value

If the function succeeds, the return value is a pointer to the allocated memory.

If the function fails, the return value is **NULL**.

## Remarks

Reserve a section of shared memory using the
[CreateSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_shared_memory) function. Free a block of memory allocated by **AllocateSharedMemory** using the
[FreeSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_free_shared_memory) function.

A pointer to the **AllocateSharedMemory** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[CreateSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_shared_memory)

[FreeSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_free_shared_memory)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)