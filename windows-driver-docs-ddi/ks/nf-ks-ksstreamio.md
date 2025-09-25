## Description

The **KsStreamIo** function performs a stream read or write against the specified file object. The function attempts to use **FastIoDispatch** if possible, or it generates a read or write request against the device object.

## Parameters

### `FileObject` [in]

Specifies the file object to perform the I/O against.

### `Event` [in, optional]

Optionally contains the event to use in the I/O. If none is passed, the call is assumed to be on a synchronous file object or the caller is waiting for the file object's event, or else it can be asynchronously completed. If used, and the KSSTREAM_SYNCHRONOUS flag is not set, this must be an event allocated by the object manager. If the caller is performing asynchronous I/O, it must either wait for the file object's event or pass an event in this parameter and wait for it. If this is not done, then there is no way for the caller to know when the IoStatusBlock has been updated by the call.

### `PortContext` [in, optional]

Optionally contains context information for a completion port.

### `CompletionRoutine` [in, optional]

Optionally points to a completion routine for this IRP.

### `CompletionContext` [in, optional]

If *CompletionRoutine* is specified, this provides a context pointer in the completion routine callback.

### `CompletionInvocationFlags` [in, optional]

Specifies invocation flags specifying when the completion routine is invoked. See following table for the values used.

### `IoStatusBlock` [out]

Location to return the status information. This is always assumed to be a valid address, regardless of the requester mode. The value must remain valid until the call has updated the status. The caller must either perform synchronous I/O or must wait for the file object's event or an event passed in the Event parameter before allowing this address to become invalid.

### `StreamHeaders` [in, out]

Specifies the list of stream headers. This address, as well as the addresses of the data buffers, are assumed to have been probed for appropriate access. Kernel-mode clients submitting streaming headers must allocate the headers from NonPagedPool memory.

### `Length` [in]

Specifies the size of the *StreamHeaders* passed.

### `Flags` [in]

Specifies various flags for the I/O. See the following table for the values used.

### `RequestorMode` [in]

Indicates the processor mode to place in the IRP if one is needs to be generated. This variable also determines if a fast I/O call can be performed. If the requester mode is not kernel mode, but the previous mode is, then fast I/O cannot be used.

## Return value

The **KsStreamIo** function returns STATUS_SUCCESS if successful, STATUS_PENDING if action is pending, or if unsuccessful it returns an I/O error.

## Remarks

The following enumerated values are used for the *CompletionInvocationFlags* variable and are of type KSCOMPLETION_INVOCATION:

| *CompletionInvocationFlags* | Description |
|--|--|
| KsInvokeOnSuccess | Invokes the completion routine on success. |
| KsInvokeOnError | Invokes the completion routine on error. |
| KsInvokeOnCancel | Invokes the completion routine on cancellation. |

The following defined values are used for the *Flags* variable:

| *Flags* | Description |
|--|--|
| KSSTREAM_READ | Specifies that an IOCTL_KS_STREAMREAD IRP is to be built. This is the default. |
| KSSTREAM_WRITE | Specifies that an IOCTL_KS_STREAMWRITE IRP is to be built. |
| KSSTREAM_PAGED_DATA | Specifies that the data is pageable. This is the default and can be used at all times. |
| KSSTREAM_NONPAGED_DATA | Specifies that the data is nonpaged and can be used as a performance enhancement. |
| KSSTREAM_SYNCHRONOUS | Specifies that the IRP is synchronous. This means that if the *Event* parameter is passed, it is not treated as an object manager event and is not referenced or dereferenced. |

KSSTREAM_READ is equivalent to KSPROBE_STREAMREAD.

Similarly, KSSTREAM_WRITE is equivalent to KSPROBE_STREAMWRITE.