## Description

Represents a reference to a buffer used in an I/O ring operation.

## Members

### `Kind`

A value from the [IORING_REF_KIND](https://learn.microsoft.com/windows/win32/api/ioringapi/ne-ioringapi-ioring_ref_kind) enumeration specifying the kind of buffer represented by the structure.

### `BufferUnion`

### `BufferUnion.Address`

A void pointer specifying the address of a buffer if the *Kind* value is IORING_REF_RAW.

### `BufferUnion.IndexAndOffset`

The index and offset of the registered buffer if the *Kind* value is IORING_REF_REGISTERED.

### `Buffer`

## Remarks

## See also