## Description

Specifies flags for creating an I/O ring with a call to [CreateIoRing](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-createioring).

## Members

### `Required`

A bitwise OR combination of flags from the [IORING_CREATE_REQUIRED_FLAGS](https://learn.microsoft.com/windows/win32/api/ioringapi/ne-ioringapi-ioring_create_required_flags) enumeration. If any unknown required flags are provided to an API, the API will fail the associated call.

### `Advisory`

A bitwise OR combination of flags from the [IORING_CREATE_ADVISORY_FLAGS](https://learn.microsoft.com/windows/win32/api/ioringapi/ne-ioringapi-ioring_create_advisory_flags) enumeration.Advisory flags. Any unknown or unsupported advisory flags provided to an API are ignored.

## Remarks

## See also