# WdfRequestProbeAndLockUserBufferForWrite function

## Description

[Applies to KMDF only]

The **WdfRequestProbeAndLockUserBufferForWrite** method verifies that an I/O request's user-mode buffer is writeable, and then it locks the buffer's physical memory pages so drivers in the driver stack can write into the buffer.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `Buffer` [in]

A pointer to the request's output buffer. For more information, see the following Remarks section.

### `Length` [in]

The length, in bytes, of the request's output buffer.

### `MemoryObject` [out]

A pointer to a location that receives a handle to a framework memory object that represents the user output buffer.

## Return value

**WdfRequestProbeAndLockUserBufferForWrite** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter is invalid. |
| **STATUS_INVALID_USER_BUFFER** | The *Length* parameter is zero. |
| **STATUS_INVALID_DEVICE_REQUEST** | The request has already been completed or is otherwise invalid. |
| **STATUS_ACCESS_VIOLATION** | The current thread is not the creator of the I/O request. |
| **STATUS_INSUFFICIENT_RESOURCES** | There is insufficient memory to complete the operation. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The user output buffer typically receives information that the driver has read from the device.

Only a top-level driver can call the **WdfRequestProbeAndLockUserBufferForWrite** method, because the method requires the process context of the process that created the I/O request.

The user-mode buffer that the *Buffer* parameter specifies can be the buffer that [WdfRequestRetrieveUnsafeUserOutputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveunsafeuseroutputbuffer) retrieves, or it can be a different user-mode output buffer. For example, an I/O control code that uses the buffered access method might pass a structure that contains an embedded pointer to a user-mode buffer. In such a case, the driver can use**WdfRequestProbeAndLockUserBufferForWrite** to obtain a memory object for the buffer.

The buffer length that the *Length* parameter specifies must not be larger than the buffer's actual size. Otherwise, drivers can access memory outside of the buffer, which is a security risk.

If **WdfRequestProbeAndLockUserBufferForWrite** returns STATUS_SUCCESS, the driver receives a handle to a framework memory object that represents the user-mode buffer. To access the buffer, the driver must call [WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer).

The framework memory object is automatically released when the driver calls [**WdfRequestComplete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete).

For more information about **WdfRequestProbeAndLockUserBufferForWrite**, see [Accessing Data Buffers in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

#### Examples

For a code example that uses **WdfRequestProbeAndLockUserBufferForWrite**, see [WdfRequestProbeAndLockUserBufferForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestprobeandlockuserbufferforread).

## See also

[WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer)

[WdfRequestProbeAndLockUserBufferForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestprobeandlockuserbufferforread)

[WdfRequestRetrieveUnsafeUserOutputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveunsafeuseroutputbuffer)