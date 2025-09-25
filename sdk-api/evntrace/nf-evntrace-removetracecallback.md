# RemoveTraceCallback function

## Description

> [!Important]
> Do not use this function. It may be unavailable in subsequent
> versions.

The **RemoveTraceCallback** function stops an
[EventCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_callback)
function from receiving events for an event trace class.

## Parameters

### `pGuid` [in]

Pointer to the class GUID of the event trace class for which the callback
receives events. Use the same class GUID that you passed to the
[SetTraceCallback](https://learn.microsoft.com/windows/desktop/ETW/settracecallback) to begin receiving the
events.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the
[system error codes](https://learn.microsoft.com/windows/win32/debug/system-error-codes). The following
are some common errors and their causes.

- **ERROR_INVALID_PARAMETER**

 The _pGuid_ parameter is **NULL**.

- **ERROR_WMI_GUID_NOT_FOUND**

 There is no
[EventCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_callback)
function associated with the event trace class.

## Remarks

Consumers call this function.

## See also

[EventCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_callback)

[ProcessTrace](https://learn.microsoft.com/windows/desktop/ETW/processtrace)

[SetTraceCallback](https://learn.microsoft.com/windows/desktop/ETW/settracecallback)