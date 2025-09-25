# TerminateEnclave function

## Description

Ends the execution of the threads that are running within an enclave.

## Parameters

### `lpAddress` [in]

The base address of the enclave in which to end the execution of the threads.

### `fWait` [in]

`TRUE` if **TerminateEnclave** should not return until all of the threads in the enclave end execution. `FALSE` if **TerminateEnclave** should return immediately.

## Return value

`TRUE` if the function succeeds; otherwise `FALSE`. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Enclave functions](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-functions)

[CallEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-callenclave)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)