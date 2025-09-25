## Description

Specifies required flags for creating an I/O ring with a call to [CreateIoRing](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-createioring).

## Constants

### `IORING_CREATE_REQUIRED_FLAGS_NONE`

None.

## Remarks

Use the [IORING_CREATE_FLAGS](https://learn.microsoft.com/windows/win32/api/ioringapi/ns-ioringapi-ioring_create_flags) structure to pass flags into **CreateIoRing**. If any unknown required flags are provided to an API, the API will fail the associated call.

## See also