## Description

Registers an array of file handles with the system for future I/O ring operations.

## Parameters

### `ioRing`

An **HIORING** representing a handle to the I/O ring for which file handles are registered.

### `count`

A UINT32 specifying the number of handles provided in the *handles* parameter.

### `handles`

An array of HANDLE values to be registered.

### `userData`

A UINT_PTR value identifying the registration operation. Specify this value when cancelling the operation with a call to [BuildIoRingCancelRequest](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-buildioringcancelrequest). If an app implements cancellation behavior for the operation, the *userData* value must be unique. Otherwise, the value is treated as opaque by the system and can be anything, including 0.

## Return value

Returns an HRESULT including, but not limited to the following:

| Value | Description |
|-------|-------------|
| S_OK | Success |
| IORING_E_SUBMISSION_QUEUE_FULL | The submission queue is full, and no additional entries are available to build. The application must submit the existing entries and wait for some of them to complete before adding more operations to the queue. |
| IORING_E_UNKNOWN_REQUIRED_FLAG | The application provided a required flag that is not known to the implementation. Library code should check the *IoRingVersion* field of the [IORING_INFO](https://learn.microsoft.com/windows/win32/api/ioringapi/ns-ioringapi-ioring_info) obtained from a call to [GetIoRingInfo](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-getioringinfo) to determine the API version of an I/O ring which determines the operations and flags that are supported. Applications should know the version they used to create the I/O ring and therefore should not provide unsupported flags at runtime. |

## Remarks

 This function allows the kernel implementation to perform the validation and internal mapping just once avoiding the overhead on each I/O operation. Subsequent entries in the submission queue may refer to the handles registered with this function using an integer index into the array. If a previous registration exists, this replaces the previous registration completely.

## See also