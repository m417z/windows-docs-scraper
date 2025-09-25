# REQUEST_OPLOCK_INPUT_BUFFER structure

## Description

Contains the information to request an opportunistic lock (oplock) or to acknowledge an oplock break
with the [FSCTL_REQUEST_OPLOCK](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_request_oplock) control
code.

## Members

### `StructureVersion`

The version of the
**REQUEST_OPLOCK_INPUT_BUFFER** structure that
is being used. Set this member to **REQUEST_OPLOCK_CURRENT_VERSION**.

### `StructureLength`

The length of this structure, in bytes. Must be set to
`sizeof(REQUEST_OPLOCK_INPUT_BUFFER)`.

### `RequestedOplockLevel`

A valid combination of the following oplock level values.

| Value | Meaning |
| --- | --- |
| **OPLOCK_LEVEL_CACHE_READ** | Allows clients to cache reads. May be granted to multiple clients. |
| **OPLOCK_LEVEL_CACHE_HANDLE** | Allows clients to cache open handles. May be granted to multiple clients. |
| **OPLOCK_LEVEL_CACHE_WRITE** | Allows clients to cache writes and byte range locks. May be granted only to a single client. |

Valid combinations of these values are as follows:

* `OPLOCK_LEVEL_CACHE_READ`
* `OPLOCK_LEVEL_CACHE_READ | OPLOCK_LEVEL_CACHE_HANDLE`
* `OPLOCK_LEVEL_CACHE_READ | OPLOCK_LEVEL_CACHE_WRITE`
* `OPLOCK_LEVEL_CACHE_READ | OPLOCK_LEVEL_CACHE_WRITE | OPLOCK_LEVEL_CACHE_HANDLE`

For more information about these value combinations, see
[FSCTL_REQUEST_OPLOCK](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_request_oplock).

### `Flags`

A valid combination of the following request flag values.

| Value | Meaning |
| --- | --- |
| **REQUEST_OPLOCK_INPUT_FLAG_REQUEST** | Request for a new oplock. Setting this flag together with **REQUEST_OPLOCK_INPUT_FLAG_ACK** is not valid and will cause the request to fail with **ERROR_INVALID_PARAMETER**. |
| **REQUEST_OPLOCK_INPUT_FLAG_ACK** | Acknowledgment of an oplock break. Setting this flag together with **REQUEST_OPLOCK_ INPUT_FLAG_REQUEST** is not valid and will cause the request to fail with **ERROR_INVALID_PARAMETER**. |

## See also

[FSCTL_REQUEST_OPLOCK](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_request_oplock)

[REQUEST_OPLOCK_OUTPUT_BUFFER](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-request_oplock_output_buffer)