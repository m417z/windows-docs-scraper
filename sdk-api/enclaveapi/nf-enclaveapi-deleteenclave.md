# DeleteEnclave function

## Description

Deletes the specified enclave.

## Parameters

### `lpAddress` [in]

The base address of the enclave that you want to delete.

## Return value

`TRUE` if the enclave was deleted successfully; otherwise `FALSE`. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

For a list of common error codes, see [System Error Codes](https://learn.microsoft.com/windows/win32/Debug/system-error-codes). The following error codes also apply for this function.

| Return code | Description |
|-------------|-------------|
| **ERROR_ENCLAVE_NOT_TERMINATED** | The execution of threads running with the enclave was not ended, because either [TerminateEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-terminateenclave) was not called, or the execution of the threads has not yet ended in response to an earlier call to **TerminateEnclave**. |

## See also

[Enclave functions](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-functions)

[TerminateEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-terminateenclave)

[CreateEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-createenclave)