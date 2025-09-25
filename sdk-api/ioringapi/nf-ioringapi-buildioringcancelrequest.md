## Description

Attempts to cancel a previously submitted I/O ring operation.

## Parameters

### `ioRing`

An **HIORING** representing a handle to the I/O ring for which a cancellation is requested.

### `file`

An [IORING_HANDLE_REF](https://learn.microsoft.com/windows/win32/api/ioringapi/ns-ioringapi-ioring_handle_ref) representing the file associated with the operation to cancel.

### `opToCancel`

A **UINT_PTR** specifying the operation to cancel. This value is the same value provided in the *userData* parameter when the operation was registered. To support cancellation, the *userData* value must be unique for each operation.

### `userData`

A UINT_PTR value identifying the cancellation operation. Specify this value when cancelling the operation with a call to [BuildIoRingCancelRequest](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-buildioringcancelrequest). If an app implements cancellation behavior for the operation, the *userData* value must be unique. Otherwise, the value is treated as opaque by the system and can be anything, including 0.

## Return value

| Value | Description |
|-------|-------------|
| S_OK | Success |
| IORING_E_SUBMISSION_QUEUE_FULL | The submission queue is full, and no additional entries are available to build. The application must submit the existing entries and wait for some of them to complete before adding more operations to the queue. |
| IORING_E_UNKNOWN_REQUIRED_FLAG | The application provided a required flag that is not known to the implementation. Library code should check the *IoRingVersion* field of the [IORING_INFO](https://learn.microsoft.com/windows/win32/api/ioringapi/ns-ioringapi-ioring_info) obtained from a call to [GetIoRingInfo](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-getioringinfo) to determine the API version of an I/O ring which determines the operations and flags that are supported. Applications should know the version they used to create the I/O ring and therefore should not provide unsupported flags at runtime. |

## Remarks

Since I/O ring operations are performed asynchronously this function call is only a request for cancellation. The specified operation may complete before the cancellation is processed. The cancellation operation may complete after the operation it is canceling is completed. The completion of the cancel operation is not dependent on the actual completion of the I/O operations it cancels. Apps should look for the completion of the original operation in the completion queue by calling [PopIoRingCompletion](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-popioringcompletion) to observe the final status of the operation. The operation may have completed successfully or with an error rather than being cancelled by the call to this function.

## See also