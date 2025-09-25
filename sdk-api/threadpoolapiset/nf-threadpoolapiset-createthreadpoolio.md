# CreateThreadpoolIo function

## Description

Creates a new I/O completion object.

## Parameters

### `fl` [in]

The file handle to bind to this I/O completion object.

### `pfnio` [in]

The callback function to be called each time an overlapped I/O operation completes on the file. For details, see [IoCompletionCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms684124(v=vs.85)).

### `pv` [in, out, optional]

Optional application-defined data to pass to the callback function.

### `pcbe` [in, optional]

A pointer to a **TP_CALLBACK_ENVIRON** structure that defines the environment in which to execute the callback. Use the [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment) function to initialize the structure before calling this function.

If this parameter is NULL, the callback executes in the default callback environment. For more information, see [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment).

## Return value

If the function succeeds, it returns a pointer to a **TP_IO** structure that defines the I/O object. Applications do not modify the members of this structure.

If the function fails, it returns NULL. To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To begin receiving overlapped I/O completion callbacks, call the [StartThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-startthreadpoolio) function.

If the file handle bound to the I/O completion object has the notification mode FILE_SKIP_COMPLETION_PORT_ON_SUCCESS and an asychronous I/O operation returns immediately with success, the I/O completion callback function is not called and threadpool I/O notifications must be canceled. For more information, see [CancelThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-cancelthreadpoolio).

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[CancelThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-cancelthreadpoolio)

[CloseThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolio)

[StartThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-startthreadpoolio)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[WaitForThreadpoolIoCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpooliocallbacks)