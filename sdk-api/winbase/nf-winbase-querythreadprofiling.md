# QueryThreadProfiling function

## Description

Determines whether thread profiling is enabled for the specified thread.

## Parameters

### `ThreadHandle` [in]

The handle to the thread of interest.

### `Enabled` [out]

Is **TRUE** if thread profiling is enabled for the specified thread; otherwise, **FALSE**.

## Return value

 Returns ERROR_SUCCESS if the call is successful; otherwise, a system error code (see Winerror.h).

## See also

[DisableThreadProfiling](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-disablethreadprofiling)

[EnableThreadProfiling](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enablethreadprofiling)