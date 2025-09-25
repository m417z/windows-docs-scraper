# OpenTraceA function

## Description

The **OpenTrace** function opens an ETW trace processing handle for consuming events from an ETW real-time trace session or an ETW log file.

## Parameters

### `Logfile` [in, out]

Pointer to an
[EVENT_TRACE_LOGFILE](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_logfilea)
structure. The structure specifies the source from which to consume events (from
an ETW log file or a real-time ETW session) and specifies the callbacks the
consumer wants to use to receive the events. On success, **OpenTrace** will
update the structure with information from the opened file or session.

## Return value

If the function succeeds, it returns the trace processing handle. The handle
should be closed using
[CloseTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-closetrace).

If the function fails, it returns **INVALID_PROCESSTRACE_HANDLE**.
(**INVALID_PROCESSTRACE_HANDLE** is equivalent to `(UINT64)UINTPTR_MAX`.)

> [!Note]
> Prior to Windows Vista, OpenTrace returned `UINT64_MAX` in case of
> failure. If your code supports both older operating systems (Windows XP or
> Windows Server 2003) and newer versions of Windows (Windows Vista and later),
> you must determine the operating system on which you are running and compare
> the return value to the appropriate value.

| Operating system | Process Type | Value indicating failure |
| ---------------------- | ------------- | -------------------------------------------- |
| Prior to Windows Vista | 32- or 64-bit | `0XFFFFFFFFFFFFFFFF` = `UINT64_MAX` |
| Windows Vista or later | 32-bit | `0x00000000FFFFFFFF` = `(UINT64)UINTPTR_MAX` |
| Windows Vista or later | 64-bit | `0XFFFFFFFFFFFFFFFF` = `(UINT64)UINTPTR_MAX` |

If the function fails, you can use the
[GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror)
function to obtain extended error information. The following are some common
errors and their causes.

- **ERROR_INVALID_PARAMETER**

 The _Logfile_ parameter is **NULL**.

- **ERROR_BAD_PATHNAME**

 If you did not specify the **LoggerName** member of
[EVENT_TRACE_LOGFILE](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_logfilea),
you must specify a valid log file name.

- **ERROR_ACCESS_DENIED**

 Only users with administrative privileges, users in the Performance Log Users
group, and services running as LocalSystem, LocalService, NetworkService can
consume events in real time. To grant a restricted user the ability to consume
events in real time, add them to the Performance Log Users group.

  **Windows XP and Windows 2000:** Anyone can consume real time events.

## Remarks

Trace consumers call this function to open a trace processing session.

After calling **OpenTrace**, call the
[ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace) function to
process the events. When you have finished processing events, call the
[CloseTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-closetrace) function to
close the trace processing handle.

### Examples

For an example that uses **OpenTrace**, see
[Using TdhFormatProperty to Consume Event Data](https://learn.microsoft.com/windows/win32/etw/using-tdhformatproperty-to-consume-event-data).

> [!NOTE]
> The evntrace.h header defines OpenTrace as an alias which
> automatically selects the ANSI or Unicode version of this function based on
> the definition of the UNICODE preprocessor constant. Mixing usage of the
> encoding-neutral alias with code that not encoding-neutral can lead to
> mismatches that result in compilation or runtime errors. For more information,
> see
> [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CloseTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-closetrace)

[EVENT_TRACE_LOGFILE](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_logfilea)

[ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace)