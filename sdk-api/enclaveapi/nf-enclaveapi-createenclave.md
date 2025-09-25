# CreateEnclave function

## Description

Creates a new uninitialized enclave. An enclave is an isolated region of code and data within the address space for an application. Only code that runs within the enclave can access data within the same enclave.

## Parameters

### `hProcess` [in]

A handle to the process for which you want to create an enclave.

### `lpAddress` [in, optional]

The preferred base address of the enclave. Specify **NULL** to have the operating system assign the base address.

### `dwSize` [in]

The size of the enclave that you want to create, including the size of the code that you will load into the enclave, in bytes.

VBS enclaves must be a multiple of 2 MB in size.

SGX enclaves must be a power of 2 in size and must have their base aligned to the same power of 2 as the size, with a minimum alignment of 2 MB. As an example, if the enclave is 128 MB, then its base must be aligned to a 128 MB boundary.

### `dwInitialCommitment` [in]

The amount of memory to commit for the enclave, in bytes.

If the amount of enclave memory available is not sufficient to commit this number of bytes, enclave creation fails. Any memory that remains unused when you initialize the enclave by calling [InitializeEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-initializeenclave) is returned to the list of free pages.

The value of the *dwInitialCommittment* parameter must not exceed the value of the *dwSize* parameter.

This parameter is not used for virtualization-based security (VBS) enclaves.

### `flEnclaveType` [in]

The architecture type of the enclave that you want to create. To verify that an enclave type is supported, call [IsEnclaveTypeSupported](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-isenclavetypesupported).

| Value | Meaning |
|-------|---------|
| **ENCLAVE_TYPE_SGX**<br>`0x00000001` | An enclave for the Intel Software Guard Extensions (SGX) architecture extension. |
| **ENCLAVE_TYPE_SGX2**<br>`0x00000002` | Supports SGX2 and SGX1 enclaves. The platform and OS support SGX2 instructions with EDMM on this platform (in addition to other SGX2 constructs). |
| **ENCLAVE_TYPE_VBS**<br>`0x00000010` | A VBS enclave. |

### `lpEnclaveInformation` [in]

A pointer to the architecture-specific information to use to create the enclave.

For the **ENCLAVE_TYPE_SGX** and **ENCLAVE_TYPE_SGX2** enclave types, you must specify a pointer to an [ENCLAVE_CREATE_INFO_SGX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-enclave_create_info_sgx) structure.

For the **ENCLAVE_TYPE_VBS** enclave type, you must specify a pointer to an [ENCLAVE_CREATE_INFO_VBS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-enclave_create_info_vbs) structure.

### `dwInfoLength` [in]

The length of the structure that the *lpEnclaveInformation* parameter points to, in bytes. For the **ENCLAVE_TYPE_SGX** and **ENCLAVE_TYPE_SGX2** enclave types, this value must be 4096. For the **ENCLAVE_TYPE_VBS** enclave type, this value must be `sizeof(ENCLAVE_CREATE_INFO_VBS)`, which is 36 bytes.

### `lpEnclaveError` [out, optional]

An optional pointer to a variable that receives an enclave error code that is architecture-specific. For the **ENCLAVE_TYPE_SGX**, **ENCLAVE_TYPE_SGX2** and **ENCLAVE_TYPE_VBS** enclave types, the *lpEnclaveError* parameter is not used.

## Return value

If the function succeeds, the return value is the base address of the created enclave.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

For a list of common error codes, see [System Error Codes](https://learn.microsoft.com/windows/win32/Debug/system-error-codes). The following error codes also apply for this function.

| Return code | Description |
|-------------|-------------|
| **ERROR_NOT_SUPPORTED** | An unsupported enclave type was specified. |
| **ERROR_BAD_LENGTH** | The value of the *dwInfoLength* parameter did not match the value expected based on the value specified for the *lpEnclaveInformation* parameter. |

## Remarks

To load data into an enclave after you create it, call [LoadEnclaveData](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-loadenclavedata). To initialize the enclave after you load the data, call [InitializeEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-initializeenclave).

**Windows 10, version 1709:** To delete the enclave when you finish using it, call [DeleteEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-deleteenclave). You cannot delete a VBS enclave by calling the [VirtualFree](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualfree) or [VirtualFreeEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualfreeex) function. You can still delete an SGX enclave by calling **VirtualFree** or **VirtualFreeEx**.

**Windows 10, version 1507, Windows 10, version 1511, Windows 10, version 1607 and Windows 10, version 1703:** To delete the enclave when you finish using it, call the [VirtualFree](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualfree) or [VirtualFreeEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualfreeex) function and specify the following values:

- The base address of the enclave for the *lpAddress* parameter.
- 0 for the *dwSize* parameter.
- **MEM_RELEASE** for the *dwFreeType* parameter. The **MEM_DECOMMIT** value is not supported for enclaves.

For information about the Intel Software Guard Extensions (SGX) architecture extension, see [Intel Software Guard Extensions](https://software.intel.com/sgx).

## See also

[Enclave functions](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-functions)

[ENCLAVE_CREATE_INFO_SGX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-enclave_create_info_sgx)

[ENCLAVE_CREATE_INFO_VBS](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-enclave_create_info_vbs)

[InitializeEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-initializeenclave)

[IsEnclaveTypeSupported](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-isenclavetypesupported)

[LoadEnclaveData](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-loadenclavedata)

[VirtualFree](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualfree)

[VirtualFreeEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualfreeex)