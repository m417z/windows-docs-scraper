# WS_READ_OPTION enumeration

## Description

Specifies whether a value is required, and how the value should be allocated.

## Constants

### `WS_READ_REQUIRED_VALUE:1`

The option specifies that the value must exist in the XML content.

The caller must specify the storage to read the top-level type into.

The size of the storage specified by the caller varies by the type
being deserialized, as follows:

* For primitives (such as [WS_INT32_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)), the storage should
  be the size of the primitive. In this case, the heap does not need to be specified.
* For structures (whether user defined ones that use [WS_STRUCT_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type),
  or predefined ones like [WS_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_string)), the storage should be the
  exact size of the structure.
  Note that fields of the structure that point to other data is still required to
  be allocated from the [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap). If no fields exist for the
  specific structure, then the heap does not need to be specified.

Pointer types ([WS_WSZ_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type) and **WS_XML_BUFFER_TYPE**),
may not be used with [WS_READ_REQUIRED_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option). The **WS_READ_REQUIRED_POINTER**
value should be used instead.

If the value is not present in the XML being read,
a **WS_E_INVALID_FORMAT** error will be returned.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

### `WS_READ_REQUIRED_POINTER:2`

The option specifies that the value must exist in the XML content.

The deserialized value is always allocated on the [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap), regardless of its size.
The pointer to the deserialized value is returned. When using this option,
the caller should pass the address of a pointer, and size of a pointer,
regardless of the type being deserialized.

If the value is not present, then an error will be returned.
**NULL** will never be returned when this option is used. If the
value is optional, use [WS_READ_OPTIONAL_POINTER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).

### `WS_READ_OPTIONAL_POINTER:3`

The option specifies that the value need not exist in the XML content.

The deserialized value is always allocated on the [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap), regardless of its size.
The pointer to the deserialized value is returned. When using this option,
the caller should pass the address of a pointer, and size of a pointer,
regardless of the type being deserialized.

If the value is not present in the XML being read, the function will
succeed and **NULL** will be returned for the value.

An application that uses this option should be careful to check for **NULL** before accessing the value.
If a **NULL** value is never expected, use [WS_READ_REQUIRED_POINTER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).

### `WS_READ_NILLABLE_POINTER:4`

The option specifies that the value may be nil or missing in the XML content.

The deserialized value is always allocated on the [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap), regardless of its size.
The pointer to the deserialized value is returned. When using this option,
the caller should pass the address of a pointer, and size of a pointer,
regardless of the type being deserialized.

If the element is nil or missing in the XML being read, the function will succeed and
a **NULL** pointer will be returned.
If the element is not nil in the XML being read, then the value is returned normally.

An application that uses this option should be careful to check for **NULL** before accessing the value.
If a **NULL** value is never expected, use [WS_READ_REQUIRED_POINTER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).

This option is not supported in combination with [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) in APIs
that read XML, including [WsReadType](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadtype) and [WsReadElement](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadelement) calls.

### `WS_READ_NILLABLE_VALUE:5`

The option specifies that the value may be nil or missing in the XML content.

The caller must specify the storage to read the top-level type into.

If the XML element is nil or missing, then a nil value is returned. If the XML element is
non-nil, then the value is deserialized normally.

This option is not supported in combination with [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) in APIs
that read XML, including [WsReadType](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadtype) and [WsReadElement](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadelement) calls.

This option is only supported for the following types, listed below,
which have a intrinsic way to represent a nil value. See the documentation
for each type for information on how nil is represented.

* [WS_STRING_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)
* [WS_XML_STRING_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)
* [WS_BYTES_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)

## Remarks

Each **WS_READ_OPTION** discusses when a [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap) object must be specified. Depending on the function, it may still be
possible to pass a **NULL** heap parameter in this case; see the documentation
for the specific function for details on whether a default heap is used
if the heap parameter is **NULL**.

The following are things to consider when deserializing values into
a heap object ([WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap)):

* Deserialized values remain allocated until the heap
  is freed ([WsFreeHeap](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreeheap)) or reset ([WsResetHeap](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetheap)).
* Each time values are deserialized, they are appended to the heap (instead
  of replacing existing values).
* If errors are encountered during the deserialization function and the
  function fails, the memory allocated from the heap object up until
  the error will not be released.
* The size of the heap can be used to limit the total allocations made
  during deserialization. The max size of the heap can be determined
  in the following way:
  + Determine the max size, in bytes, of each value that will be
    allocated on the heap during deserialization. Remember to take into
    account that sizes of deserialized data structures may vary by platform.
  + Each array is considered one value. Note that the actual size of an item
    in the array may by affected by the required alignment of the item.
  + Round the max size of each value to a 16-byte boundary.