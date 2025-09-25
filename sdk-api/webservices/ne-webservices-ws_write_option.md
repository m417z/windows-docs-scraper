## Description

Specifies whether a storage specified contains the value, or a pointer to the value,
and whether the value can be represented as nil in the XML content.

## Constants

### `WS_WRITE_REQUIRED_VALUE:1`

The storage specified contains the value. The size of the storage
specified should be the size of the value.

This option specifies that the value will always be written to the XML content.

```
int value;
Api(..., &value, sizeof(value), ...);
```

```
// always written
123
```

This option is not supported for pointer types
([WS_WSZ_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type) and **WS_XML_BUFFER_TYPE**).
The [WS_WRITE_REQUIRED_POINTER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_write_option) option should be used for these types.

### `WS_WRITE_REQUIRED_POINTER:2`

The storage specified contains a pointer to the value. The
size of the storage specified is always the size of a pointer, regardless
of the type being serialized.

This option specifies that the value will always be written to the XML content.

```
int* valuePointer; // may not be NULL
Api(..., &valuePointer, sizeof(valuePointer), ...);
```

```
// always written
123
```

If the pointer to the value specified in the storage is **NULL**,
**E_INVALIDARG** is returned.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

### `WS_WRITE_NILLABLE_VALUE:3`

The storage specified contains a pointer to the value. The
size of the storage specified is always the size of a pointer, regardless
of the type being serialized.

If the value is nil, then a nil element is written in the XML content.
If non-nil, then the value is serialized normally.

```
WS_STRING value; // may contain a nil value (see WS_STRING_TYPE)
Api(..., &value, sizeof(value), ...);
```

```
// if value is non-nil
hello

// if value is nil
```

This option is only supported for the following types, listed below,
which have a intrinsic way to represent a nil value. See the documentation
for each type for information on how nil is represented.

* [WS_STRING_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)
* [WS_XML_STRING_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)
* [WS_BYTES_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)

### `WS_WRITE_NILLABLE_POINTER:4`

For all types, the storage specified contains a pointer to the value. The
size of the storage specified is always the size of a pointer, regardless
of the type being serialized.

If the pointer to the value specified in the storage is **NULL**, then
a nil element is written in the XML content.

```
int* valuePointer; // may be NULL
Api(..., &valuePointer, sizeof(valuePointer), ...);
```

```
// if value is non-NULL
123

// if value is NULL
```