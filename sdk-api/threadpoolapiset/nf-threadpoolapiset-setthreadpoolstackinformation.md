# SetThreadpoolStackInformation function

## Description

Sets the stack reserve and commit sizes for new threads in the specified thread pool. Stack reserve and commit sizes for existing threads are not changed.

## Parameters

### `ptpp` [in, out]

A pointer to a **TP_POOL** structure that specifies the thread pool. The [CreateThreadpool](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpool) function returns this pointer.

### `ptpsi` [in]

A pointer to a **TP_POOL_STACK_INFORMATION** structure that specifies the stack reserve and commit size for threads in the pool.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that uses this function, set _WIN32_WINNT to _WIN32_WINNT_WIN7. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[QueryThreadpoolStackInformation](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-querythreadpoolstackinformation)