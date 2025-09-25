# FlushTraceA function

## Description

The **FlushTrace** function causes an event tracing session to immediately
deliver buffered events for the specified session. By default, an event tracing
session will deliver events when an the buffer is full, the session's FlushTimer
expires, or the session is closed.

This function is obsolete. The
[ControlTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-controltracea) function
supersedes this function.

## Parameters

### `TraceHandle` [in]

Handle to the event tracing session to be flushed, or 0. You must specify a
non-zero _TraceHandle_ if _InstanceName_ is **NULL**. This parameter will be
used only if _InstanceName_ is **NULL**. The handle is returned by the
[StartTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-starttracea).

### `InstanceName` [in]

Name of the event tracing session to be flushed, or **NULL**. You must specify
_InstanceName_ if _TraceHandle_ is 0.

To specify the NT Kernel Logger session, set _InstanceName_ to
**KERNEL_LOGGER_NAME**.

### `Properties` [in, out]

Pointer to an initialized
[EVENT_TRACE_PROPERTIES](https://learn.microsoft.com/windows/desktop/ETW/event-trace-properties) structure.

If you are using a newly initialized structure, you only need to set the
**Wnode.BufferSize**, **Wnode.Guid**, **LoggerNameOffset**, and
**LogFileNameOffset** members of the structure. You can use the maximum session
name (1024 characters) and maximum log file name (1024 characters) lengths to
calculate the buffer size and offsets if not known.

On output, the structure receives the property settings and session statistics
of the event tracing session, which reflect the state of the session after the
flush.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the
[system error codes](https://learn.microsoft.com/windows/win32/debug/system-error-codes). The following
table includes some common errors and their causes.

- **ERROR_INVALID_PARAMETER**

 One of the following is true:

  - _Properties_ is **NULL**.
  - _InstanceName_ and _TraceHandle_ are both **NULL**.
  - _InstanceName_ is **NULL** and _TraceHandle_ is not a valid handle.

- **ERROR_BAD_LENGTH**

 One of the following is true:

  - The **Wnode.BufferSize** member of _Properties_ specifies an incorrect size.
  - _Properties_ does not have sufficient space allocated to hold a copy of the
session name and log file name (if used).

- **ERROR_ACCESS_DENIED**

 Only users with administrative privileges, users in the Performance Log Users
group, and services running as LocalSystem, LocalService, NetworkService can
control event tracing sessions. To grant a restricted user the ability to
control trace sessions, add them to the Performance Log Users group.

  **Windows XP and Windows 2000:** Anyone can control a trace session.

## Remarks

Event trace controllers call this function.

This function is obsolete. Instead, use
[ControlTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-controltracea) with
_ControlCode_ set to **EVENT_TRACE_CONTROL_FLUSH**.

This function can be used with an in-memory session (a session started with the
**EVENT_TRACE_BUFFERING_MODE** flag) to write the data from the trace to a file.

You do not normally need to flush file-based or real-time sessions because ETW
will automatically flush a buffer when it is full (i.e. when it does not have
room for the next event), when the trace session's FlushTimer expires, or when
the trace session is closed.

Do not call **FlushTrace** from DllMain (may cause deadlock).

> [!NOTE]
> The evntrace.h header defines FlushTrace as an alias which
> automatically selects the ANSI or Unicode version of this function based on
> the definition of the UNICODE preprocessor constant. Mixing usage of the
> encoding-neutral alias with code that not encoding-neutral can lead to
> mismatches that result in compilation or runtime errors. For more information,
> see
> [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ControlTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-controltracea)