## Description

Specifies the type of an I/O ring operation.

## Constants

### `IORING_OP_NOP`

No operation. This value is provided to enable testing queue management and overhead performance./

### `IORING_OP_READ`

Read from a file to a buffer.

### `IORING_OP_REGISTER_FILES`

Register an array of file handles with the I/O ring.

If any existing registration exists, it is completely replaced by the registration for this opcode. Any entries in the array with INVALID_HANDLE_VALUE are sparse entries and are not used, which can be used to release one or more of the previously registered files.

Unregistration of all current files is accomplished by providing a zero length array. The input array must remain valid until the operation completes. The change impacts all entries in the queue after this completes. I.e. This implicitly has "link" semantics in that any subsequent entry will not start until after this is completed.

### `IORING_OP_REGISTER_BUFFERS`

Register an array of [IORING_BUFFER_INFO](https://learn.microsoft.com/windows/win32/api/ntioring_x/ns-ntioring_x-ioring_buffer_info) with the IORING.

If any existing registration exists, it is completely replaced by the registration for this opcode. Any entries in the array with INVALID_HANDLE_VALUE are sparse entries and are not used, which can be used to release one or more of the previously registered files.

Unregistration of all current files is accomplished by providing a zero length array. The input array must remain valid until the operation completes. The change impacts all entries in the queue after this completes. I.e. This implicitly has "link" semantics in that any subsequent entry will not start until after this is completed.

### `IORING_OP_CANCEL`

Request cancellation of a previously submitted operation. The *UserData* passed in when the operation was initiated is used to identify the operation to be cancelled. The cancellation operation completes after the canceled operation completes unless there is an error attempting the cancellation. For example, if no operation is found with the specified *UserData*.

## Remarks

## See also