# AvRtWaitOnThreadOrderingGroup function

## Description

Enables client threads of a thread ordering group to wait until they should execute.

## Parameters

### `Context` [in]

A context handle. This handle is returned by the [AvRtCreateThreadOrderingGroup](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avrtcreatethreadorderinggroup) or [AvRtJoinThreadOrderingGroup](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avrtjointhreadorderinggroup) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When this function returns, the thread should complete its processing for the period and then call the function again.

If the thread fails to complete its processing during the time-out interval specified by the parent thread when creating the group, it is deleted from the thread ordering group. Therefore, when the thread finishes its processing loop, the next call to **AvRtWaitOnThreadOrderingGroup** fails and the last error code is set to ERROR_ACCESS_DENIED.

If the thread ordering group is deleted during the wait, this function eventually times out and return ERROR_ACCESS_DENIED.

#### Examples

```cpp
#include <windows.h>
#include <avrt.h>
#include <stdio.h>

#pragma comment(lib, "Avrt.lib")

HANDLE Context;

int main( void )
{
    while(AvRtWaitOnThreadOrderingGroup(Context))
    {
        // Complete task for this period.
    }

return 0;
}

```

## See also

[Thread Ordering Service](https://learn.microsoft.com/windows/desktop/ProcThread/thread-ordering-service)