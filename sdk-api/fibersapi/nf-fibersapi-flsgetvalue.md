# FlsGetValue function

## Description

Retrieves the value in the calling fiber's fiber local storage (FLS) slot for the specified FLS index. Each fiber has its own slot for each FLS index.

## Parameters

### `dwFlsIndex` [in]

The FLS index that was allocated by the
[FlsAlloc](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsalloc) function.

## Return value

If the function succeeds, the return value is the value stored in the calling fiber's FLS slot associated with the specified index.

If the function fails, the return value is NULL. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

FLS indexes are typically allocated by the
[FlsAlloc](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsalloc) function during process or DLL initialization. After an FLS index is allocated, each fiber of the process can use it to access its own FLS slot for that index. A fiber specifies an FLS index in a call to
[FlsSetValue](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flssetvalue) to store a value in its slot. The thread specifies the same index in a subsequent call to
**FlsSetValue** to retrieve the stored value.

## See also

[Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/fibers)

[FlsAlloc](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsalloc)

[FlsSetValue](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flssetvalue)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)