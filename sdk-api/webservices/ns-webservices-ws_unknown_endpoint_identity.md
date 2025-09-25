# WS_UNKNOWN_ENDPOINT_IDENTITY structure

## Description

Type for unknown endpoint identity. This type is only used to represent
an endpoint identity type that was deserialized but was not understood.

## Members

### `identity`

The base type from which this type and all other endpoint identity types derive.

### `element`

An XML buffer containing a single XML Element which corresponds to the
identity element that was not understood. This field may not be **NULL**.