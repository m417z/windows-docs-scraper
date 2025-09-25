## Description

This routine retrieves the creation time of a given thread.

## Parameters

### `Thread` [in]

A pointer to an executive thread object structure (ETHREAD) for which to get the creation time.

## Return value

Returns a long long integer that represents the thread's creation time in 100-nanosecond intervals since January 1, 1601. This is a standard timestamp format used in Windows known as FILETIME.

## Remarks

A driver might call PsGetThreadCreateTime for several reasons:

* Debugging and Logging: The creation time of a thread can be useful information when debugging or logging system behavior.

* Performance Monitoring: The creation time can be used in performance monitoring to identify long-lived threads that might be a performance concern.

## See also