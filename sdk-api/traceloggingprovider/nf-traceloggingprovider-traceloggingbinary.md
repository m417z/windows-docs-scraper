# TraceLoggingBinary macro

## Syntax

```cpp
void TraceLoggingBinary(
  [in]            const *void pValue,
  [in]            BYTE cbValue,
  [in, optional]  String name,
  [in, optional]  String description,
  [in, optional]  Integer tags
);
```

## Description

[TraceLogging wrapper macro](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)
that adds a field with binary data to the event.

## Parameters

### `pValue` [in]

A pointer to the data to be included in the event.

### `cbValue` [in]

The size, in bytes, of the data to be included in the event.

### `__VA_ARGS__` [in, optional]

Optional _name_, _description_, and _tags_ parameters for the field definition.

TraceLoggingBinary can be specified with 2, 3, 4, or 5 parameters. If an
optional parameter is not specified, a default will be used. For example,
`TraceLoggingBinary(&x.data, sizeof(x.data))` is equivalent to
`TraceLoggingBinary(&x.data, sizeof(x.data), "&x.data", "", 0)`.

- `[in, optional] name`

 The name to use for the event field. If provided, the name parameter must be a
string literal (not a variable) and must not contain any '\0' characters. If
not provided, the event field name will be based on _pValue_.

- `[in, optional] description`

 The description of the event field's value. If provided, the description
parameter must be a string literal and will be included in the
[PDB](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols).

- `[in, optional] tags`

 A compile-time constant integer value. The low 28 bits of the value will be
included in the field's metadata. The semantics of this value are defined by
the event consumer. During event processing, this value can be retrieved from
the [EVENT_PROPERTY_INFO](https://learn.microsoft.com/windows/win32/api/tdh/ns-tdh-event_property_info) Tags field.

## Remarks

`TraceLoggingBinary(pValue, cbValue, ...)` can be used as a parameter to an
invocation of a
[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite) macro. Each
TraceLoggingBinary parameter adds one field to the event.

## See also

[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite)

[TraceLogging wrapper macros](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)