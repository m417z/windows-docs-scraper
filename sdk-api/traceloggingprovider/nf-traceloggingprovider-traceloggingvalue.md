# TraceLoggingValue macro

## Syntax

```cpp
void TraceLoggingValue(
  [in]             value,
  [in, optional]  UINT name,
  [in, optional]  UINT description,
  [in, optional]  int tags
);
```

## Description

[TraceLogging wrapper macro](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)
for C++ that adds a field with an automatically-deduced type to the event.

## Parameters

### `value` [in]

The event field value.

### `__VA_ARGS__` [in, optional]

Optional _name_, _description_, and _tags_ parameters for the field definition.

TraceLoggingValue can be specified with 1, 2, 3, or 4 parameters. If a parameter
is not specified, a default will be used. For example, `TraceLoggingValue(a+b)`
is equivalent to `TraceLoggingValue(a+b, "a+b", "", 0)`.

- `[in, optional] name`

 The name to use for the event field. If provided, the name parameter must be a
string literal (not a variable) and must not contain any '\0' characters. If
not provided, the event field name will be based on _value_.

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

In C++ code, `TraceLoggingValue(value, ...)` can be used as a parameter to an
invocation of a
[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite) macro. Each
TraceLoggingValue parameter adds one field to the event.

The type of the field in the ETW event is automatically deduced from the type of
the _value_ expression. Based on the type of _value_,
`TraceLoggingValue(value, ...)` is equivalent to one of the standard
TraceLogging wrapper macros as follows:

| Type of _value_ | Equivalent to | Notes |
| --------------- | ---------------------- | -------------------------------------------------------- |
| `bool` | TraceLoggingBoolean |
| `char` | TraceLoggingChar | Only for char, not for signed char or unsigned char. |
| `char16_t` | TraceLoggingChar16 |
| `wchar_t` | TraceLoggingWChar | Only for native wchar_t, not for USHORT. |
| `intNN_t` | TraceLoggingIntNN | For signed char, short, int, long, and long long. |
| `uintNN_t` | TraceLoggingUIntNN | For unsigned char, short, int, long, and long long. |
| `float` | TraceLoggingFloat32 |
| `double` | TraceLoggingFloat64 |
| `GUID` | TraceLoggingGuid |
| `FILETIME` | TraceLoggingFileTime |
| `SYSTEMTIME` | TraceLoggingSystemTime |
| `SID*` | TraceLoggingSid | Must be non-NULL and must point to a valid `SID`. |
| `void*` | TraceLoggingPointer | Logs the pointer value, not the referenced data. |
| `char*` | TraceLoggingString | Zero-terminated CP_ACP string. NULL is treated as `""`. |
| `char16_t*` | TraceLoggingString16 | Zero-terminated UTF-16 string. NULL is treated as `u""`. |
| `wchar_t*` | TraceLoggingWideString | Zero-terminated UTF-16 string. NULL is treated as `L""`. |

## See also

[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite)

[TraceLogging wrapper macros](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)