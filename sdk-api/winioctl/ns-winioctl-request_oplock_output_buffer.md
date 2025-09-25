# REQUEST_OPLOCK_OUTPUT_BUFFER structure

## Description

Contains the opportunistic lock (oplock) information returned by the
[FSCTL_REQUEST_OPLOCK](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_request_oplock) control code.

## Members

### `StructureVersion`

The version of the
**REQUEST_OPLOCK_OUTPUT_BUFFER** structure that
is being used.

### `StructureLength`

The length of this structure, in bytes.

### `OriginalOplockLevel`

One or more **OPLOCK_LEVEL_CACHE_***XXX* values that indicate
the level of the oplock that was broken.

For possible values, see the **RequestedOplockLevel** member of the
[REQUEST_OPLOCK_INPUT_BUFFER](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-request_oplock_input_buffer) structure.

### `NewOplockLevel`

One or more **OPLOCK_LEVEL_CACHE_***XXX* values that indicate
the level to which an oplock is being broken, or an oplock level that may be available for granting, depending
on the operation returning this buffer.

For possible values, see the **RequestedOplockLevel** member of the
[REQUEST_OPLOCK_INPUT_BUFFER](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-request_oplock_input_buffer) structure.

### `Flags`

One or more **REQUEST_OPLOCK_OUTPUT_FLAG_***XXX* values.

| Value | Meaning |
| --- | --- |
| **REQUEST_OPLOCK_OUTPUT_FLAG_ACK_REQUIRED** | Indicates that an acknowledgment is required, and the oplock described in **OriginalOplockLevel** will continue to remain in force until the break is successfully acknowledged. |
| **REQUEST_OPLOCK_OUTPUT_FLAG_MODES_PROVIDED** | Indicates that the **ShareMode** and **AccessMode** members contain the share and access flags, respectively, of the request causing the oplock break. For more information, see the Remarks section. |

### `AccessMode`

If the **REQUEST_OPLOCK_OUTPUT_FLAG_MODES_PROVIDED** flag is set and the
**OPLOCK_LEVEL_CACHE_HANDLE** level is being lost in an oplock break, contains the access
mode of the request that is causing the break.

### `ShareMode`

If the **REQUEST_OPLOCK_OUTPUT_FLAG_MODES_PROVIDED** flag is set and the
**OPLOCK_LEVEL_CACHE_HANDLE** level is being lost in an oplock break, contains the share
mode of the request that is causing the break.

## Remarks

The **REQUEST_OPLOCK_OUTPUT_FLAG_MODES_PROVIDED** flag indicates that the
**ShareMode** and **AccessMode** fields contain the share and access
flags, respectively, of the request causing the oplock break. This information may be provided on breaks where the
**OPLOCK_LEVEL_CACHE_HANDLE** level is being lost and may be useful to callers who can close
handles whose share and access modes conflict with the handle causing the break. This may enable them to maintain
at least some handle cache state. Note that not all breaks where the
**OPLOCK_LEVEL_CACHE_HANDLE** level is being lost will have this flag set. The primary case
where this flag will be set is if the break is a result of a create operation that needs the
**OPLOCK_LEVEL_CACHE_HANDLE** oplock to be broken to avoid failing with
**ERROR_SHARING_VIOLATION**.

## See also

[FSCTL_REQUEST_OPLOCK](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_request_oplock)

[Oplock Semantics](https://learn.microsoft.com/windows-hardware/drivers/ifs/oplock-semantics)

[REQUEST_OPLOCK_INPUT_BUFFER](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-request_oplock_input_buffer)