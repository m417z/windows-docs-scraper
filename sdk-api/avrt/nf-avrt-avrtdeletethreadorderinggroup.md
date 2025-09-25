# AvRtDeleteThreadOrderingGroup function

## Description

Deletes the specified thread ordering group created by the caller. It cleans up resources for the thread ordering group, including the context information, and returns.

## Parameters

### `Context` [in]

A context handle. This handle is returned by the [AvRtCreateThreadOrderingGroup](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avrtcreatethreadorderinggroup) function when creating the group.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function can only be called successfully by the parent thread for the thread ordering group. If a thread other than the parent thread calls this function, the function fails with a last error code of ERROR_INVALID_FUNCTION.

If the parent thread times out and attempts to call this function, the function fails with a last error code of ERROR_INVALID_PARAMETER.

#### Examples

The following code deletes a thread ordering group.

```cpp
#include <windows.h>
#include <avrt.h>
#include <stdio.h>

#pragma comment(lib, "Avrt.lib")

HANDLE Context;

int main( void )
{
    if(!AvRtDeleteThreadOrderingGroup(Context))
    {
        printf("Error deleting group (%d)\n", GetLastError());
        return 1;
    }

    return 0;
}

```

## See also

[Thread Ordering Service](https://learn.microsoft.com/windows/desktop/ProcThread/thread-ordering-service)