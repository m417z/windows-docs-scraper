# WdfRequestRetrieveUnsafeUserInputBuffer function

## Description

[Applies to KMDF only]

The **WdfRequestRetrieveUnsafeUserInputBuffer** method retrieves an I/O request's input buffer, if the request's technique for accessing data buffers is [neither buffered nor direct I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers).

## Parameters

### `Request` [in]

A handle to a framework request object.

### `MinimumRequiredLength` [in]

The minimum buffer size, in bytes, that the driver needs to process the I/O request.

### `InputBuffer` [out]

A pointer to a location that receives the buffer's address.

### `Length` [out, optional]

A pointer to a location that receives the buffer's size, in bytes. This parameter is optional and can be **NULL**.

## Return value

**WdfRequestRetrieveUnsafeUserInputBuffer** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter is invalid. |
| **STATUS_INVALID_DEVICE_REQUEST** | This value is returned if one of the following occurs:<br><br>* The method was not called from within the driver's [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context) callback function.<br>* The I/O request's I/O control code is [IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read) or [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control).<br>* The request specifies [buffered I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers) or [direct I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers). |
| **STATUS_BUFFER_TOO_SMALL** | The *MinimumRequiredLength* parameter specifies a buffer size that is larger than the buffer's actual size. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfRequestRetrieveUnsafeUserInputBuffer** method must be called from an [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context) callback function. After calling **WdfRequestRetrieveUnsafeUserInputBuffer**, the driver must call [WdfRequestProbeAndLockUserBufferForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestprobeandlockuserbufferforread).

The driver can call **WdfRequestRetrieveUnsafeUserInputBuffer** if a request's I/O control code is [IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write) or [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control).

The driver can access the retrieved buffer until it [completes the I/O request](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests) that the *Request* parameter represents.

For more information about **WdfRequestRetrieveUnsafeUserInputBuffer**, see [Accessing Data Buffers in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

#### Examples

For a code example that uses **WdfRequestRetrieveUnsafeUserInputBuffer**, see [WdfRequestProbeAndLockUserBufferForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestprobeandlockuserbufferforread).

## See also

[EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context)

[WdfRequestProbeAndLockUserBufferForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestprobeandlockuserbufferforread)

[WdfRequestRetrieveUnsafeUserOutputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveunsafeuseroutputbuffer)