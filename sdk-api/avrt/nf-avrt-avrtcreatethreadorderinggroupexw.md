# AvRtCreateThreadOrderingGroupExW function

## Description

Creates a thread ordering group and associates the server thread with a task.

## Parameters

### `Context` [out]

A pointer to a context handle.

### `Period` [in]

A pointer to a value, in 100-nanosecond increments, that specifies the period for the thread ordering group. Each thread in the thread ordering group runs one time during this period. If all threads complete their execution before a period ends, all threads wait until the remainder of the period elapses before any are executed again.

The possible values for this parameter depend on the platform, but this parameter can be as low as 500 microseconds or as high as 0x1FFFFFFFFFFFFFFF. If this parameter is less than 500 microseconds, then it is set to 500 microseconds. If this parameter is greater than the maximum, then it is set to 0x1FFFFFFFFFFFFFFF.

### `ThreadOrderingGuid` [in, out]

A pointer to the unique identifier for the thread ordering group to be created. If this value is not unique to the thread ordering service, the function fails.

If the identifier is GUID_NULL on input, the thread ordering service generates and returns a unique identifier.

### `Timeout` [in, optional]

A pointer to a time-out value. All threads within the group should complete their execution within *Period* plus *Timeout*.

If a thread fails to complete its processing within the period plus this time-out interval, it is removed from the thread ordering group. If the parent fails to complete its processing within the period plus the time-out interval, the thread ordering group is destroyed.

The possible values for this parameter depend on the platform, but can be as low as 500 microseconds or as high as 0x1FFFFFFFFFFFFFFF. If this parameter is less than 500 microseconds, then it is set to 500 microseconds. If this parameter is greater than the maximum, then it is set to 0x1FFFFFFFFFFFFFFF.

If this parameter is **NULL** or 0, the default is five times the value of *Period*.

If this parameter is THREAD_ORDER_GROUP_INFINITE_TIMEOUT, the group is created with an infinite time-out interval. This can be useful for debugging purposes.

### `TaskName` [in]

The name of the task.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If a thread ordering group with the specified identifier already exists, the function fails and sets the last error to ERROR_ALREADY_EXISTS.

## Remarks

The calling thread is considered to be the parent thread. Each thread ordering group has one parent thread. Each parent thread can have zero or more predecessor threads and zero or more successor threads. A client thread can join a thread ordering group and specify whether it is a predecessor or successor using the [AvRtJoinThreadOrderingGroup](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avrtjointhreadorderinggroup) function.

The parent thread encloses the code to be executed during each period within a loop that is controlled by the [AvRtWaitOnThreadOrderingGroup](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avrtwaitonthreadorderinggroup) function.

To delete the thread ordering group, call the [AvRtDeleteThreadOrderingGroup](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avrtdeletethreadorderinggroup) function.

A thread can create more than one thread ordering group and join more than one thread ordering group. However, a thread cannot join the same thread ordering group more than one time.

The parent and client threads of a thread ordering group run at high priorities. However, the server thread that manages the thread ordering group runs at normal priority. Therefore, there can be a delay switching from one client thread to another if there are other high-priority threads running. The *TaskName* parameter of this function specifies the task to be associated with the server thread.

#### Examples

The following snippet creates a thread ordering group.

```cpp
#include <windows.h>
#include <avrt.h>
#include <stdio.h>

#pragma comment(lib, "Avrt.lib")

#define _100NS_IN_1MS 10000

int main( void )
{
    HANDLE hContext = NULL;
    LARGE_INTEGER period, timeout;
    GUID guid = { 0 };
    BOOL bRes;

    period.QuadPart = Int32x32To64(_100NS_IN_1MS, 1000);   // 1 second
    timeout.QuadPart = Int32x32To64(_100NS_IN_1MS, 10000); // 10 seconds

    bRes = AvRtCreateThreadOrderingGroupEx(
            &hContext,
            &period,
            &guid,
            &timeout,
            TEXT("Audio") );

    if( bRes != TRUE )
    {
        printf("Error creating group (%d)\n", GetLastError());
            return 1;
    }

    return 0;
}

```

> [!NOTE]
> The avrt.h header defines AvRtCreateThreadOrderingGroupEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Thread Ordering Service](https://learn.microsoft.com/windows/desktop/ProcThread/thread-ordering-service)