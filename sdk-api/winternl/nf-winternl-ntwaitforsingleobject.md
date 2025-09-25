# NtWaitForSingleObject function

## Description

Deprecated. Waits until the specified object attains a state of
`signaled`. **NtWaitForSingleObject** is superseded by [WaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject).

## Parameters

### `Handle` [in]

The handle to the wait object.

### `Alertable` [in]

Specifies whether an alert can be delivered when the object is waiting.

#### TRUE

The alert can be delivered.

#### FALSE

The alert cannot be delivered.

### `Timeout` [in]

A pointer to an absolute or relative time over
which the wait is to occur. Can be null. If a timeout is specified, and
the object has not attained a state of `signaled` when the timeout
expires, then the wait is automatically satisfied. If an explicit
timeout value of zero is specified, then no wait occurs if the
wait cannot be satisfied immediately.

## Return value

The wait completion status. The various NTSTATUS values are defined in NTSTATUS.H, which is distributed with the Windows DDK.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The specified object satisfied the wait. |
| **STATUS_TIMEOUT** | A timeout occurred. |
| **STATUS_ALERTED** | The wait was aborted to deliver an alert to the current thread. |
| **STATUS_USER_APC** | The wait was aborted to deliver a user [Asynchronous Procedure Call (APC)](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls) to the current thread. |

## Remarks

Because there is no import library for this function, you must use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).