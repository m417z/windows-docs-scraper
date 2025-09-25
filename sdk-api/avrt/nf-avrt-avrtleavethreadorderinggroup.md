# AvRtLeaveThreadOrderingGroup function

## Description

Enables client threads to leave a thread ordering group.

## Parameters

### `Context` [in]

A context handle. This handle is returned by the [AvRtJoinThreadOrderingGroup](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avrtjointhreadorderinggroup) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The parent thread for a thread ordering group should not remove itself from the group.

If a thread times out and attempts to call this function, the function fails with a last error code of ERROR_INVALID_PARAMETER.

## See also

[Thread Ordering Service](https://learn.microsoft.com/windows/desktop/ProcThread/thread-ordering-service)