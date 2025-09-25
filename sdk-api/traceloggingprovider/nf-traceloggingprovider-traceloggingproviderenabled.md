## Description

TraceLogging macro to determine whether a any trace consumer is listening for an
event from this provider.

## Parameters

### `hProvider`

The handle to the TraceLogging provider to check.

### `eventLevel`

The event level that you want to check. An event level of 0 indicates any
events.

### `eventKeyword`

The keyword that you want to check. A keyword of 0 indicates no specific
keywords.

## Return value

Returns **TRUE** if any trace consumer session is listening to events matching
the specified criteria, **FALSE** otherwise.

## Remarks

This API provides a simple way to determine whether an event is enabled, i.e.
whether any event consumer sessions would be interested in receiving an event
from the specified provider with the specified level and keyword.

> [!NOTE]
> This API performs a conservative quick test. It is possible for this
> API to return true in certain cases where subsequent in-depth filtering would
> determine that no sessions actually need to record the event.

Most event providers will not call **TraceLoggingProviderEnabled** directly. The
[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite) macro
performs its own TraceLoggingProviderEnabled test and returns immediately if the
event is not enabled. However, it may be useful for a provider to call
**TraceLoggingProviderEnabled** before performing complex preparations before
invoking a **TraceLoggingWrite** macro.

### Examples

```cpp
// Skip GetMyInformation() if nobody is listening for MyInformationEvent:
if (TraceLoggingProviderEnabled(MyProvider, MyEventLevel, MyEventKeyword))
{
    MY_INFORMATION info;
    GetMyInformation(&info);

    TraceLoggingWrite(
        MyProvider,
        "MyInformationEvent",
        TraceLoggingLevel(MyEventLevel),
        TraceLoggingKeyword(MyEventKeyword),
        TraceLoggingValue(info.Val1),
        TraceLoggingValue(info.Val2));
}
```

## See also

[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite)

[TraceLogging wrapper macros](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)

[EventProviderEnabled](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventproviderenabled)