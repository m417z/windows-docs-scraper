## Description

Represents a reference to a file handle used in an I/O ring operation.

## Members

### `Kind`

A value from the [IORING_REF_KIND](https://learn.microsoft.com/windows/win32/api/ioringapi/ne-ioringapi-ioring_ref_kind) enumeration specifying the kind of handle represented by the structure.

### `HandleUnion`

### `HandleUnion.Handle`

The handle to a file if the *Kind* value is IORING_REF_RAW.

### `HandleUnion.Index`

The index of the registered file handle if the *Kind* value is IORING_REF_REGISTERED.

### `Handle`

## Remarks

## See also