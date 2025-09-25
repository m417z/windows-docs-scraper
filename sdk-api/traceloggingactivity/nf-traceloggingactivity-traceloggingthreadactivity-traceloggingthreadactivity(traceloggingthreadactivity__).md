# TraceLoggingThreadActivity::TraceLoggingThreadActivity(TraceLoggingThreadActivity &&)

## Description

Initializes a new instance of the
[TraceLoggingThreadActivity](https://learn.microsoft.com/windows/win32/api/traceloggingactivity/nl-traceloggingactivity-traceloggingthreadactivity)
class.

**TraceLoggingThreadActivity** is a class template.

## Parameters

### `rhs`

A reference to a **TraceLoggingThreadActivity**.

## Remarks

> [!Note]
> **TraceLoggingThreadActivity** is a class template.

Template parameters are:

- TraceLoggingHProvider HProvider const& provider
- UINT64 Keyword = 0
- UINT8 Level = `WINEVENT_LEVEL_VERBOSE`
- typename TlgReflectorTag = `_TlgReflectorTag_Param0IsHProvider`

## See also

[TraceLoggingActivity](https://learn.microsoft.com/windows/win32/api/traceloggingactivity/nl-traceloggingactivity-traceloggingactivity)

[TraceLoggingThreadActivity](https://learn.microsoft.com/windows/win32/api/traceloggingactivity/nl-traceloggingactivity-traceloggingthreadactivity)