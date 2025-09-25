# SetTraceCallback function

## Description

> [!Important]
> Do not use this function; it may be unavailable in subsequent
> versions. Instead, filter for the event trace class in your
> [EventRecordCallback](https://learn.microsoft.com/windows/desktop/ETW/eventrecordcallback) function.

The **SetTraceCallback** function specifies an
[EventCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_callback)
function to process events for the specified event trace class.

## Parameters

### `pGuid` [in]

Pointer to the class GUID of an event trace class for which you want to receive
events. For a list of kernel provider class GUIDs, see
[NT Kernel Logger Constants](https://learn.microsoft.com/windows/desktop/ETW/nt-kernel-logger-constants).

### `EventCallback` [in]

Pointer to an
[EventCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_callback)
function used to process events belonging to the event trace class.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the
[system error codes](https://learn.microsoft.com/windows/win32/debug/system-error-codes). The following
are some common errors and their causes.

- **ERROR_INVALID_PARAMETER**

 One of the following is true:

  - _pGuid_ is **NULL**.
  - _EventCallback_ is **NULL**.

## Remarks

Consumers call this function.

You can only specify one callback function for an event trace class. If you
specify more than one callback function for the event trace class, the last
callback function receives the events for that event trace class.

To stop the callback function from receiving events for the event trace class,
call the [RemoveTraceCallback](https://learn.microsoft.com/windows/desktop/ETW/removetracecallback)
function. The callback automatically stops receiving callbacks when you close
the trace.

You can use this function to receive events written using one of the
[TraceEvent](https://learn.microsoft.com/windows/desktop/ETW/traceevent) functions. You cannot use this
function to consume events from a provider that used one of the
[EventWrite](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwrite) functions to
log events.

## See also

[EventCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_callback)

[ProcessTrace](https://learn.microsoft.com/windows/desktop/ETW/processtrace)

[RemoveTraceCallback](https://learn.microsoft.com/windows/desktop/ETW/removetracecallback)