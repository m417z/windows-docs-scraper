## Description

This function enables a set of optional XState features for the current process.

## Parameters

### `Features`

A bitmask in which each bit represents an optional XState feature to enable for the current process.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

In general, optional XState features are disabled by default for newly created threads and enabled on demand later.
When this function returns, the specified optional XState features will be enabled for all existing threads in the current process, and all future threads created in the process will have the specified optional XState features enabled at thread creation time.

Only XState feature bits supported by the system are allowed to be supplied to this function, otherwise an error is returned. The XState feature bits supported by the system can be obtained via the [GetEnabledXStateFeatures](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getenabledxstatefeatures) routine.
If non-optional XState feature bits supported by the system are supplied (for example AVX, AVX2, etc. are non-optional XState features), those are ignored and will not cause this function to return an error. Note that all non-optional XState features supported by the system are always enabled for every thread by default.

## See also

[GetEnabledXStateFeatures](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getenabledxstatefeatures)

[GetThreadEnabledXStateFeatures](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getthreadenabledxstatefeatures)