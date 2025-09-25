# FlsSetValue function

## Description

Stores a value in the calling fiber's fiber local storage (FLS) slot for the specified FLS index. Each fiber has its own slot for each FLS index.

## Parameters

### `dwFlsIndex` [in]

The FLS index that was allocated by the
[FlsAlloc](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsalloc) function.

### `lpFlsData` [in, optional]

The value to be stored in the FLS slot for the calling fiber.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following errors can be returned.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The index is not in range. |
| **ERROR_NO_MEMORY** | The FLS array has not been allocated. |

## Remarks

FLS indexes are typically allocated by the
[FlsAlloc](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsalloc) function during process or DLL initialization. After an FLS index is allocated, each fiber of the process can use it to access its own FLS slot for that index. A thread specifies an FLS index in a call to
**FlsSetValue** to store a value in its slot. The thread specifies the same index in a subsequent call to
[FlsGetValue](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsgetvalue) to retrieve the stored value.

## See also

[Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/fibers)

[FlsAlloc](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsalloc)

[FlsGetValue](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsgetvalue)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)