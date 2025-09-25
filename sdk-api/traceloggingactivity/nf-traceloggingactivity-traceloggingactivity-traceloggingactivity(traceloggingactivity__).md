# TraceLoggingActivity::TraceLoggingActivity(TraceLoggingActivity &&)

## Description

Creates a new
[TraceLoggingActivity](https://learn.microsoft.com/windows/win32/api/traceloggingactivity/nl-traceloggingactivity-traceloggingactivity)
object.

**TraceLoggingActivity** is a class template.

## Parameters

### `rhs`

A reference to a **TraceLoggingActivity**.

## Remarks

> [!Note]
> TraceLoggingActivity is a class template.

Template parameters are:

- TraceLoggingHProvider HProvider const& provider
- UINT64 Keyword = 0
- UINT8 Level = `WINEVENT_LEVEL_VERBOSE`
- typename TlgReflectorTag = `_TlgReflectorTag_Param0IsHProvider`

## See also

[TraceLoggingActivity](https://learn.microsoft.com/windows/win32/api/traceloggingactivity/nl-traceloggingactivity-traceloggingactivity)