# DisableThreadProfiling function

## Description

Disables thread profiling.

## Parameters

### `PerformanceDataHandle` [in]

The handle that the [EnableThreadProfiling](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enablethreadprofiling) function returned.

## Return value

 Returns ERROR_SUCCESS if the call is successful; otherwise, a system error code (see Winerror.h).

## Remarks

You must call this function from the same thread that enabled profiling for the specified handle. You must call this function before exiting the thread; otherwise, you will leak resources (the resources are not reclaimed until the process exits).

## See also

[EnableThreadProfiling](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enablethreadprofiling)

[QueryThreadProfiling](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-querythreadprofiling)