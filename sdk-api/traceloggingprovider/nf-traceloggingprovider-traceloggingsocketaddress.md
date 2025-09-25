# TraceLoggingSocketAddress macro

## Syntax

```cpp
void TraceLoggingSocketAddress(
  [in]            SOCKADDR* pValue,
  [in]            byte cbValue,
  [in, optional]  String name,
  [in, optional]  String description,
  [in, optional]  Integer tags
);
```

## Description

[TraceLogging wrapper macro](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)
that adds a field with a socket address to the event.

## Parameters

### `pValue` [in]

A pointer to a sockaddr structure.

### `cbValue` [in]

The size, in bytes, of the value pointed to by the _pValue_ parameter.

> [!NOTE]
> The amount of data needed for a sockaddr field varies depending on the
> type of address. If the data is stored in a union variable, be sure to set the
> cbValue parameter to the size of the correct union member (or to the size of
> the union) to avoid truncating the data.

### `__VA_ARGS__` [in, optional]

Optional _name_, _description_, and _tags_ parameters for the field definition.

TraceLoggingSocketAddress can be specified with 2, 3, 4, or 5 parameters. If a
parameter is not specified, a default will be used. For example,
`TraceLoggingSocketAddress(&x.sockAddr, sizeof(x.sockAddr))` is equivalent to
`TraceLoggingSocketAddress(&x.sockAddr, sizeof(x.sockAddr), "&x.sockAddr", "", 0)`.

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

`TraceLoggingSocketAddress(pValue, cbValue, ...)` can be used as a parameter to
an invocation of a
[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite) macro. Each
TraceLoggingSocketAddress parameter adds one field to the event.

The value may be any Windows sockaddr type, e.g.
[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr),
[SOCKADDR_IN](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_in),
[SOCKADDR_IN6](https://learn.microsoft.com/windows/win32/api/ws2ipdef/ns-ws2ipdef-sockaddr_in6_lh),
[SOCKADDR_STORAGE](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh), etc. The event
will record the raw binary data and the data size. The event decoder will use
the `sa_family` field to determine the actual type of the socket address.

> [!NOTE]
> Not all decoders will support all sockaddr family types. If an
> unsupported sockaddr is encountered, the decoder might decode the field as raw
> binary data instead of formatting it as an address.

## See also

[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite)

[TraceLogging wrapper macros](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)