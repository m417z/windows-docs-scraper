# TraceLoggingStruct macro

## Syntax

```cpp
void TraceLoggingStruct(
  [in]            int fieldCount,
  [in]            string name,
  [in, optional]  string description,
  [in, optional]  int tags
);
```

## Description

[TraceLogging wrapper macro](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)
that adds a field that contains other fields to the event.

## Parameters

### `fieldCount` [in]

The number of fields that will be considered part of the structure. This
parameter must be a compile-time constant.

### `name` [in]

The name to use for the structure in the event. The name parameter must be a
string literal (not a variable) and must not contain any '\0' characters.

### `__VA_ARGS__` [in, optional]

Optional _description_ and _tags_ parameters for the field definition.

TraceLoggingStruct can be specified with 2, 3, or 4 parameters. If a parameter
is not specified, a default will be used. For example,
`TraceLoggingStruct(3, "MyStruct")` is equivalent to
`TraceLoggingStruct(3, "MyStruct", "", 0)`.

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

`TraceLoggingStruct(fieldCount, name, ...)` can be used as a parameter to an
invocation of a
[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite) macro. Each
TraceLoggingStruct parameter adds one logical field to the event. The field is a
structure or group that contains the subsequent _fieldCount_ logical fields as
its value.

### Examples

```c
TraceLoggingWrite(
    g_hProvider,
    "MyEventWithStruct",
    TraceLoggingLevel(WINEVENT_LEVEL_WARNING), // Levels defined in <winmeta.h>
    TraceLoggingKeyword(MyEventCategories), // Provider-defined categories
    TraceLoggingInt32(num1, "BeforeStruct"),
    TraceLoggingStruct(3, "StructWith3Fields"),
        TraceLoggingInt32(num2, "StructField1"),
        TraceLoggingInt32(num3, "StructField2"),
        TraceLoggingInt32(num4, "StructField3"),
    TraceLoggingInt32(num5, "AfterStruct));

TraceLoggingWrite(
    g_hProvider,
    "MyEventWithNestedStruct",
    TraceLoggingLevel(WINEVENT_LEVEL_VERBOSE), // Levels defined in <winmeta.h>
    TraceLoggingKeyword(MyEventCategories), // Provider-defined categories
    TraceLoggingInt32(num1, "BeforeStruct"),
    TraceLoggingStruct(3, "StructWith3Fields"),
        TraceLoggingInt32(num2, "StructField1"),
        TraceLoggingStruct(2, "StructField2"),
            TraceLoggingInt32(num3, "StructField2NestedField1"),
            TraceLoggingInt32(num4, "StructField2NestedField2"),
        TraceLoggingInt32(num5, "StructField3"),
    TraceLoggingInt32(num6, "AfterStruct));
```

## See also

[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite)

[TraceLogging wrapper macros](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)