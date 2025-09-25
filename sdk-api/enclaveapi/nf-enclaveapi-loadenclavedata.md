# LoadEnclaveData function

## Description

Loads data into an uninitialized enclave that you created by calling [CreateEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-createenclave).

## Parameters

### `hProcess` [in]

A handle to the process for which the enclave was created.

### `lpAddress` [in]

The address in the enclave where you want to load the data.

### `lpBuffer` [in]

A pointer to the data the you want to load into the enclave.

### `nSize` [in]

The size of the data that you want to load into the enclave, in bytes. This value must be a whole-number multiple of the page size.

### `flProtect` [in]

The memory protection to use for the pages that you want to add to the enclave. For a list of memory protection values, see [memory protection constants](https://learn.microsoft.com/windows/win32/Memory/memory-protection-constants). This value must not include the following constants:

- **PAGE_GUARD**
- **PAGE_NOCACHE**
- **PAGE_WRITECOMBINE**
- **PAGE_NOACCESS**

This value can include the enclave specific constants that the following table describes:

| Constant | Description |
| --- | --- |
| **PAGE_ENCLAVE_THREAD_CONTROL** | The page contains a thread control structure (TCS). |
| **PAGE_ENCLAVE_UNVALIDATED** | The page contents that you supply are excluded from measurement with the EEXTEND instruction of the Intel Software Guard Extensions programming model. |

### `lpPageInformation` [in]

A pointer to information that describes the pages that you want to add to the enclave. The *lpPageInformation* parameter is not used.

### `dwInfoLength` [in]

The length of the structure that the *lpPageInformation* parameter points to, in bytes. This value must be `0`.

### `lpNumberOfBytesWritten` [out]

A pointer to a variable that receives the number of bytes that **LoadEnclaveData** copied into the enclave.

### `lpEnclaveError` [out, optional]

An optional pointer to a variable that receives an enclave error code that is architecture-specific. The *lpEnclaveError* parameter is not used.

## Return value

If all of the data is loaded into the enclave successfully, the return value is nonzero. Otherwise, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

For a list of common error codes, see [System Error Codes](https://learn.microsoft.com/windows/win32/Debug/system-error-codes). The following error codes also apply for this function.

| Return code | Description |
|------|--------|
| **ERROR_BAD_LENGTH** | The value of the *dwInfoLength* parameter did not match the value expected based on the value specified for the *lpPageInformation* parameter. |

## Remarks

To initialize the enclave after you load data into the enclave, call [InitializeEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-initializeenclave).

**LoadEnclaveData** is only supported enclaves that have the **ENCLAVE_TYPE_SGX** and **ENCLAVE_TYPE_SGX2** enclave types.

## See also

[Enclave functions](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-functions)

[CreateEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-createenclave)

[InitializeEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-initializeenclave)

[Memory protection constants](https://learn.microsoft.com/windows/win32/Memory/memory-protection-constants)