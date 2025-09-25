# CreateTraceInstanceId function

## Description

A
[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa)-based
("Classic") event provider may use the **CreateTraceInstanceId** function to
create a unique transaction identifier and map it to a registration handle. The
provider then uses the transaction identifier when calling the
[TraceEventInstance](https://learn.microsoft.com/windows/desktop/ETW/traceeventinstance) function to mark
events as belonging to the specified transaction. The transaction identifier can
be used by trace analysis tools to group events.

## Parameters

### `RegHandle` [in]

Handle to a registered event trace class. The
[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa)
function returns this handle in the **RegHandle** member of the
[TRACE_GUID_REGISTRATION](https://learn.microsoft.com/windows/desktop/ETW/trace-guid-registration)
structure.

### `InstInfo` [out]

Pointer to an [EVENT_INSTANCE_INFO](https://learn.microsoft.com/windows/desktop/ETW/event-instance-info)
structure. The **InstanceId** member of this structure contains the transaction
identifier.

## Return value

If the function is successful, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the
[system error codes](https://learn.microsoft.com/windows/win32/debug/system-error-codes). The following are
some common errors and their causes.

- **ERROR_INVALID_PARAMETER**

 One of the following is true:

  - _RegHandle_ is **NULL**.
  - _pInstInfo_ is **NULL**.

## Remarks

RegisterTraceGuids-based ("Classic") providers call this function. Use
[EventActivityIdControl](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventactivityidcontrol)
for similar functionality with an EventRegister-based ("Crimson") provider.

ETW creates the identifier in the user-mode process, so it might return the same
number for different instances in different processes. The value starts over at
`1` when **InstanceId** reaches the maximum value for a **ULONG**. Only
user-mode providers can call the **CreateTraceInstanceId** function (drivers
cannot call this function).

### Examples

For an example that uses **CreateTraceInstanceId**, see
[Tracing Event Instances](https://learn.microsoft.com/windows/desktop/ETW/tracing-event-instances).

## See also

[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa)

[TraceEventInstance](https://learn.microsoft.com/windows/desktop/ETW/traceeventinstance)