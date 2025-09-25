# FlsAlloc function

## Description

Allocates a fiber local storage (FLS) index. Any fiber in the process can subsequently use this index to store and retrieve values that are local to the fiber.

## Parameters

### `lpCallback` [in]

A pointer to the application-defined callback function of type **PFLS_CALLBACK_FUNCTION**. This parameter is optional. For more information, see
[FlsCallback](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-pfls_callback_function).

## Return value

If the function succeeds, the return value is an FLS index initialized to zero.

If the function fails, the return value is FLS_OUT_OF_INDEXES. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The fibers of the process can use the FLS index in subsequent calls to the
[FlsFree](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsfree),
[FlsSetValue](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flssetvalue), or
[FlsGetValue](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsgetvalue) functions.

FLS indexes are typically allocated during process or dynamic-link library (DLL) initialization. After an FLS index has been allocated, each fiber of the process can use it to access its own FLS storage slot. To store a value in its FLS slot, a fiber specifies the index in a call to
[FlsSetValue](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flssetvalue). The fiber specifies the same index in a subsequent call to
[FlsGetValue](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsgetvalue) to retrieve the stored value.

FLS indexes are not valid across process boundaries. A DLL cannot assume that an index assigned in one process is valid in another process.

## See also

[Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/fibers)

[FlsCallback](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-pfls_callback_function)

[FlsFree](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsfree)

[FlsGetValue](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsgetvalue)

[FlsSetValue](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flssetvalue)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)