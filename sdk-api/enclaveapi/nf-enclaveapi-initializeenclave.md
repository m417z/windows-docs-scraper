# InitializeEnclave function

## Description

Initializes an enclave that you created and loaded with data.

## Parameters

### `hProcess` [in]

A handle to the process for which the enclave was created.

### `lpAddress` [in]

Any address within the enclave.

### `lpEnclaveInformation` [in]

A pointer to architecture-specific information to use to initialize the enclave.

For the **ENCLAVE_TYPE_SGX** and **ENCLAVE_TYPE_SGX2** enclave types, specify a pointer to an [ENCLAVE_INIT_INFO_SGX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-enclave_init_info_sgx) structure.

For the **ENCLAVE_TYPE_VBS** enclave type, specify a pointer to an [ENCLAVE_INIT_INFO_VBS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-enclave_init_info_vbs) structure.

### `dwInfoLength` [in]

The length of the structure that the *lpEnclaveInformation* parameter points to, in bytes. For the **ENCLAVE_TYPE_SGX** and **ENCLAVE_TYPE_SGX2** enclave types, this value must be 4096. For the **ENCLAVE_TYPE_VBS** enclave type, this value must be `sizeof(ENCLAVE_INIT_INFO_VBS)`, which is 8 bytes.

### `lpEnclaveError` [in]

An optional pointer to a variable that receives an enclave error code that is architecture-specific.

For the **ENCLAVE_TYPE_SGX** and **ENCLAVE_TYPE_SGX2** enclave types, the *lpEnclaveError* parameter contains the error that the EINIT instruction generated if the function fails and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_ENCLAVE_FAILURE**.

For the **ENCLAVE_TYPE_VBS** enclave type, the *lpEnclaveError* parameter is not used.

## Return value

If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

For a list of common error codes, see [System Error Codes](https://learn.microsoft.com/windows/win32/Debug/system-error-codes). The following error codes also apply for this function.

| Return code | Description |
|-------------|-------------|
| **ERROR_ENCLAVE_FAILURE** | An failure specific to the underlying enclave architecture occurred. The value for the *lpEnclaveError* parameter contains the architecture-specific error.<br><br>For the **ENCLAVE_TYPE_SGX** and **ENCLAVE_TYPE_SGX2** enclave types, the EINIT instruction that the [ENCLAVE_INIT_INFO_SGX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-enclave_init_info_sgx) structure specified generated an error. The value of the *lpEnclaveError* parameter contains the error that the instruction generated. |
| **ERROR_BAD_LENGTH** | The value of the *dwInfoLength* parameter did not match the value expected based on the value specified for the *lpEnclaveInformation* parameter. |
| **ERROR_RETRY** | The processor was not able to initialize the enclave in a timely fashion. Try to initialize the enclave again. |

## Remarks

To create an enclave, use the [CreateEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-createenclave) function. To load data into the enclave before you initialize it, use the [LoadEnclaveData](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-loadenclavedata) function.

**Windows 10, version 1709 and later and Windows 11:** To delete the enclave when you finish using it, call [DeleteEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-deleteenclave). You cannot delete a VBS enclave by calling the [VirtualFree](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualfree) or [VirtualFreeEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualfreeex) function. You can still delete an SGX enclave by calling **VirtualFree** or **VirtualFreeEx**.

**Windows 10, version 1507, Windows 10, version 1511, Windows 10, version 1607 and Windows 10, version 1703:** To delete the enclave when you finish using it, call the [VirtualFree](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualfree) or [VirtualFreeEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualfreeex) function and specify the following values:

- The base address of the enclave for the *lpAddress* parameter.
- 0 for the *dwSize* parameter.
- **MEM_RELEASE** for the *dwFreeType* parameter.

## See also

[Enclave functions](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-functions)

[CreateEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-createenclave)

[ENCLAVE_INIT_INFO_SGX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-enclave_init_info_sgx)

[LoadEnclaveData](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-loadenclavedata)

[VirtualFree](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualfree)

[VirtualFreeEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualfreeex)