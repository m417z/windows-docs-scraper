# IsEnclaveTypeSupported function

## Description

Retrieves whether the specified type of enclave is supported.

## Parameters

### `flEnclaveType` [in]

The type of enclave to check.

| Value | Meaning |
| --- | --- |
| **ENCLAVE_TYPE_SGX**<br>`0x00000001` | An enclave for the Intel Software Guard Extensions (SGX) architecture extension. |
| **ENCLAVE_TYPE_SGX2**<br>`0x00000002` | Supports SGX2 and SGX1 enclaves. The platform and OS support SGX2 instructions with EDMM on this platform (in addition to other SGX2 constructs). |
| **ENCLAVE_TYPE_VBS**<br>`0x00000010` | A virtualization-based security (VBS) enclave. |

## Return value

If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

For a list of common error codes, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following error codes also apply for this function.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_SUPPORTED** | An unsupported enclave type was specified. |

## Remarks

**ENCLAVE_TYPE_SGX2** will change some things about how the OS handles SGX functionality:

- It will support the new extensions to **VirtualAlloc**, **VirtualFree**, and **VirtualProtect**.

## See also

[Enclave functions](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-functions)