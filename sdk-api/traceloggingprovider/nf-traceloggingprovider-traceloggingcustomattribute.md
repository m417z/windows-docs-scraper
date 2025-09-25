# TraceLoggingCustomAttribute macro

## Syntax

```cpp
void TraceLoggingCustomAttribute(
  [in]  string key,
  [in]  string value
);
```

## Description

[TraceLogging wrapper macro](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)
that adds custom information about the event into the PDB.

## Parameters

### `key` [in]

A string literal with the key for the custom attribute.

### `value` [in]

A string literal with the value of the custom attribute.

## Remarks

`TraceLoggingCustomAttribute("key", "value")` can be used as a parameter to an
invocation of a
[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite) macro. Most
TraceLogging events do not need custom attributes and should not use
TraceLoggingCustomAttribute.

Custom attributes are stored in the
[PDB](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols). They are not available at
runtime.

## See also

[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite)

[TraceLogging wrapper macros](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)