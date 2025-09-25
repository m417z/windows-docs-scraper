# LSA_CREATE_SHARED_MEMORY callback function

## Description

The **CreateSharedMemory** function creates a section of memory that is shared by client processes and the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `MaxSize` [in]

Specifies the maximum size of the shared memory.

### `InitialSize` [in]

Specifies the initial size of the shared memory.

## Return value

The function returns a pointer to the block of shared memory, or **NULL** if the block was not reserved.

## Remarks

Creating a shared section for each client is not advisable because it is a resource-intensive operation and may exhaust system resources.

The package's clients can write to shared memory which makes it susceptible to attack. Data in the shared segment should not be trusted.

The pointer returned by the **CreateSharedMemory** function is required by the
[AllocateSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_shared_memory),
[DeleteSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_delete_shared_memory), and
[FreeSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_free_shared_memory) functions.

Use the [DeleteSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_delete_shared_memory) function to release memory reserved by the **CreateSharedMemory** function.

Pointers to these functions are available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[AllocateSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_shared_memory)

[DeleteSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_delete_shared_memory)

[FreeSharedMemory](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_free_shared_memory)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)