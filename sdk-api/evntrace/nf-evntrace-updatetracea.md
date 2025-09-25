# UpdateTraceA function

## Description

The **UpdateTrace** function updates the property setting of the specified event
tracing session.

This function is obsolete. The
[ControlTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-controltracea) function
supersedes this function.

## Parameters

### `TraceHandle`

Handle to the event tracing session to be updated, or 0. You must specify a
non-zero _TraceHandle_ if _InstanceName_ is **NULL**. This parameter will be
used only if _InstanceName_ is **NULL**. The handle is returned by the
[StartTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-starttracea).

### `InstanceName`

Name of the event tracing session to be updated, or **NULL**. You must specify
_InstanceName_ if _TraceHandle_ is 0.

To specify the NT Kernel Logger session, set _InstanceName_ to
**KERNEL_LOGGER_NAME**.

### `Properties`

Pointer to an initialized
[EVENT_TRACE_PROPERTIES](https://learn.microsoft.com/windows/desktop/ETW/event-trace-properties) structure.

On input, the members must specify the new values for the properties to update.
For information on which properties you can update, see Remarks.

On output, the structure members contains the updated settings and statistics
for the event tracing session.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the
[system error codes](https://learn.microsoft.com/windows/win32/debug/system-error-codes). The following
table includes some common errors and their causes.

- **ERROR_BAD_LENGTH**

 The **BufferSize** member of the **Wnode** member of _Properties_ specifies an
incorrect size.

- **ERROR_INVALID_PARAMETER**

 One of the following is true:

  - _Properties_ is **NULL**.
  - _InstanceName_ and _TraceHandle_ are both **NULL**.
  - _InstanceName_ is **NULL** and _TraceHandle_ is not a valid handle.
  - The **LogFileNameOffset** member of _Properties_ is not valid.
  - The **LoggerNameOffset** member of _Properties_ is not valid.

  **Windows Server 2003 and Windows XP:** The **Guid** member of the **Wnode**
structure is SystemTraceControlGuid, but the _InstanceName_ parameter is not
KERNEL_LOGGER_NAME.

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
_ControlCode_ set to **EVENT_TRACE_CONTROL_UPDATE**.

On input, the members must specify the new values for the properties to update.
You can update the following properties.

- **EnableFlags**: Set this member to 0 to disable all kernel providers.
Otherwise, you must specify the kernel providers that you want to enable or
keep enabled. Applies only to system logger sessions.

- **FlushTimer**: Set this member if you want to change the time to wait before
flushing buffers. If this member is 0, the member is not updated.

- **LogFileNameOffset**: Set this member if you want to switch to another log
file. If this member is 0, the file name is not updated. If the offset is not
zero and you do not change the log file name, the function returns an error.

- **LogFileMode**: Set this member if you want to turn
  **EVENT_TRACE_REAL_TIME_MODE** on and off. To turn real time consuming off,
set this member to 0. To turn real time consuming on, set this member to
  **EVENT_TRACE_REAL_TIME_MODE** and it will be OR'd with the current modes.

- **MaximumBuffers**: Set this member if you want to change the maximum
number of buffers that ETW uses. If this member is 0, the member is not
updated.

For private logger sessions, you can only update **LogFileNameOffset** and
**FlushTimer**.

If you are using a newly initialized
[EVENT_TRACE_PROPERTIES](https://learn.microsoft.com/windows/desktop/ETW/event-trace-properties) structure,
the only members you need to specify, other than the members you are updating,
are **Wnode.BufferSize**, **Wnode.Guid**, and **Wnode.Flags**.

If you use the property structure you passed to
[StartTrace](https://learn.microsoft.com/windows/desktop/ETW/starttrace), make sure the
**LogFileNameOffset** member is 0 unless you are changing the log file name.

If you call the [ControlTrace](https://learn.microsoft.com/windows/desktop/ETW/controltrace) function to
query the current session properties and then update those properties to update
the session, make sure you set **LogFileNameOffset** to 0 (unless you are
changing the log file name) and set
[EVENT_TRACE_PROPERTIES.Wnode.Flags](https://learn.microsoft.com/windows/desktop/ETW/event-trace-properties)
to **WNODE_FLAG_TRACED_GUID**.

To obtain the property settings and session statistics for an event tracing
session, call the [ControlTrace](https://learn.microsoft.com/windows/desktop/ETW/controltrace) function.

### Examples

For an example that uses **UpdateTrace**, see
[Updating an Event Tracing Session](https://learn.microsoft.com/windows/desktop/ETW/updating-an-event-tracing-session).

> [!NOTE]
> The evntrace.h header defines UpdateTrace as an alias which
> automatically selects the ANSI or Unicode version of this function based on
> the definition of the UNICODE preprocessor constant. Mixing usage of the
> encoding-neutral alias with code that not encoding-neutral can lead to
> mismatches that result in compilation or runtime errors. For more information,
> see
> [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ControlTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-controltracea)