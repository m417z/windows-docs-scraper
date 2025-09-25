# StopTraceW function

## Description

The **StopTrace** function stops the specified event tracing session.

This function is obsolete. The
[ControlTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-controltracew) function
supersedes this function.

## Parameters

### `TraceHandle`

Handle to the event tracing session to be stopped, or 0. You must specify a
non-zero _TraceHandle_ if _InstanceName_ is **NULL**. This parameter will be
used only if _InstanceName_ is **NULL**. The handle is returned by the
[StartTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-starttracew).

### `InstanceName`

Name of the event tracing session to be stopped, or **NULL**. You must specify
_InstanceName_ if _TraceHandle_ is 0.

To specify the NT Kernel Logger session, set _InstanceName_ to
**KERNEL_LOGGER_NAME**.

### `Properties`

Pointer to an
[EVENT_TRACE_PROPERTIES](https://learn.microsoft.com/windows/desktop/ETW/event-trace-properties) structure
that receives the final properties and statistics for the session.

If you are using a newly initialized structure, you only need to set the
**Wnode.BufferSize**, **Wnode.Guid**, **LoggerNameOffset**, and
**LogFileNameOffset** members of the structure. You can use the maximum session
name (1024 characters) and maximum log file name (1024 characters) lengths to
calculate the buffer size and offsets if not known.

**Starting with Windows 10, version 1703:** For better performance in cross
process scenarios, you can now pass filtering in to **StopTrace** for system
wide private loggers. You will need to pass in the new
[EVENT_TRACE_PROPERTIES_V2](https://learn.microsoft.com/windows/desktop/ETW/event-trace-properties-v2)
structure to include filtering information. See
[Configuring and Starting a Private Logger Session](https://learn.microsoft.com/windows/desktop/ETW/configuring-and-starting-a-private-logger-session)
for more details.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the
[system error codes](https://learn.microsoft.com/windows/win32/debug/system-error-codes). The following
are some common errors and their causes.

- **ERROR_BAD_LENGTH**

 One of the following is true:

  - The **Wnode.BufferSize** member of _Properties_ specifies an incorrect size.
  - _Properties_ does not have sufficient space allocated to hold a copy of the
session name and log file name (if used).

- **ERROR_INVALID_PARAMETER**

 One of the following is true:

  - _Properties_ is **NULL**.
  - _InstanceName_ and _TraceHandle_ are both **NULL**.
  - _InstanceName_ is **NULL** and _TraceHandle_ is not a valid handle.

- **ERROR_ACCESS_DENIED** Only users with administrative privileges, users in
the Performance Log Users group, and services running as LocalSystem,
LocalService, NetworkService can control event tracing sessions. To grant a
restricted user the ability to control trace sessions, add them to the
Performance Log Users group.

  **Windows XP and Windows 2000:** Anyone can control a trace session.

## Remarks

Event trace controllers call this function.

This function is obsolete. Instead, use
[ControlTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-controltracew) with
_ControlCode_ set to **EVENT_TRACE_CONTROL_STOP**.

If **LogFileMode** contains **EVENT_TRACE_FILE_MODE_PREALLOCATE**,
[StartTrace](https://learn.microsoft.com/windows/desktop/ETW/starttrace) extends the log file to
**MaximumFileSize** bytes. The file occupies the entire space during logging,
for both circular and sequential logs. When you stop the logger, the log file is
reduced to the size needed.

Do not call **StopTrace** from DllMain (may cause deadlock).

> [!NOTE]
> The evntrace.h header defines StopTrace as an alias which
> automatically selects the ANSI or Unicode version of this function based on
> the definition of the UNICODE preprocessor constant. Mixing usage of the
> encoding-neutral alias with code that not encoding-neutral can lead to
> mismatches that result in compilation or runtime errors. For more information,
> see
> [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ControlTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-controltracew)

[StartTrace](https://learn.microsoft.com/windows/desktop/ETW/starttrace)