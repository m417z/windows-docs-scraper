# CallEnclave function

## Description

Calls a function within an enclave. **CallEnclave** can also be called within an enclave to call a function outside of the enclave.

## Parameters

### `lpRoutine` [in]

The address of the function that you want to call.

### `lpParameter` [in]

The parameter than you want to pass to the function.

### `fWaitForThread` [in]

`TRUE` if the call to the specified function should block execution until an idle enclave thread becomes available when no idle enclave thread is available. `FALSE` if the call to the specified function should fail when no idle enclave thread is available.

This parameter is ignored when you use **CallEnclave** within an enclave to call a function that is not in any enclave.

### `lpReturnValue` [out]

The return value of the function, if it is called successfully.

## Return value

`TRUE` if the specified function was called successfully; otherwise `FALSE`. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Enclave functions](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-functions)

[TerminateEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-terminateenclave)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)