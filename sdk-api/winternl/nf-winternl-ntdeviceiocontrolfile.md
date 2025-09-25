# NtDeviceIoControlFile function

## Description

Deprecated. Builds descriptors for the supplied buffer(s) and
passes the untyped data to the device driver associated with the file
handle. **NtDeviceIoControlFile** is superseded by [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol).

## Parameters

### `FileHandle` [in]

Open file handle to the file or device to which the control information should be given.

### `Event` [in]

A handle to an event to be set to the `signaled` state when the operation completes. This parameter can be **NULL**.

### `ApcRoutine` [in]

Procedure to be invoked once the operation completes. This parameter can be **NULL**. For more information on Asynchronous Procedure Calls (APCs), see [Asynchronous Procedure Calls](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls).

### `ApcContext` [in]

A pointer to pass to *ApcRoutine* when the operation completes. This parameter is required if an *ApcRoutine* is specified.

### `IoStatusBlock` [out]

Variable to receive the final completion status and information about the operation. Service calls that return information return the length of the data that is written to the output buffer in the Information field of this variable.

### `IoControlCode` [in]

Code that indicates which device I/O control function is to be executed.

### `InputBuffer` [in]

A pointer to a buffer that contains the information to be given to the target device. This parameter can be **NULL**. This information is device-dependent.

### `InputBufferLength` [in]

Length of the *InputBuffer* in bytes. If the buffer is not supplied, then this value is ignored.

### `OutputBuffer` [out]

A pointer to a buffer that is to receive the device-dependent return information from the target device. This parameter can be **NULL**.

### `OutputBufferLength` [in]

Length of the *OutputBuffer* in bytes. If the buffer is not supplied, then this value is ignored.

## Return value

The various NTSTATUS values are defined in NTSTATUS.H, which is distributed with the Windows DDK.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The control operation was properly queued to the I/O system. Once the operation completes, the status can be determined by examining the Status field of the I/O status block. |

## Remarks

The **NtDeviceIoControlFile** service is a device-dependent interface that extends the control that applications have over various devices within the system. This API provides a consistent view of the input and output data to the system while still providing the application and the driver a device-dependent method of specifying a communications interface.

The type of access to the file that the caller needs is dependent on the actual operation being performed.

Once the service is complete the *Event*, if specified, is set to the `signaled` state. If no *Event* parameter is specified, then the file object specified by the *FileHandle* is set to the `signaled` state. If an *ApcRoutine* is specified, it is invoked with the *ApcContext* and the *IoStatusBlock* as its arguments.

Because there is no import library for this function, you must use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).

## See also

[Asynchronous Procedure Calls](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls)