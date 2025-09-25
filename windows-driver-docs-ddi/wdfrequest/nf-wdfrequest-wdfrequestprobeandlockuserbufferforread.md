# WdfRequestProbeAndLockUserBufferForRead function

## Description

[Applies to KMDF only]

The **WdfRequestProbeAndLockUserBufferForRead** method verifies that an I/O request's user-mode buffer is readable, and then it locks the buffer's physical memory pages so drivers in the driver stack can read the buffer.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `Buffer` [in]

A pointer to the request's input buffer. For more information, see the following Remarks section.

### `Length` [in]

The length, in bytes, of the request's input buffer.

### `MemoryObject` [out]

A pointer to a location that receives a handle to a framework memory object that represents the user input buffer.

## Return value

**WdfRequestProbeAndLockUserBufferForRead** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

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

Only a top-level driver can call the **WdfRequestProbeAndLockUserBufferForRead** method, because the method requires the process context of the process that created the I/O request.

The user input buffer typically contains information to be written to the device.

The user-mode buffer that the *Buffer* parameter specifies can be the buffer that [WdfRequestRetrieveUnsafeUserInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveunsafeuserinputbuffer) retrieves, or it can be a different user-mode input buffer. For example, an I/O control code that uses the buffered access method might pass a structure that contains an embedded pointer to a user-mode buffer. In such a case, the driver can use**WdfRequestProbeAndLockUserBufferForRead** to obtain a memory object for the buffer.

The buffer length that the *Length* parameter specifies must not be larger than the buffer's actual size. Otherwise, drivers can access memory outside of the buffer, which is a security risk.

If **WdfRequestProbeAndLockUserBufferForRead** returns STATUS_SUCCESS, the driver receives a handle to a framework memory object that represents the user-mode buffer. To access the buffer, the driver must call [WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer).

The framework memory object is automatically released when the driver calls [**WdfRequestComplete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete).

For more information about **WdfRequestProbeAndLockUserBufferForRead**, see [Accessing Data Buffers in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

#### Examples

The following code example is a shortened version of the [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context) callback function that the [NONPNP](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver contains. When the callback function receives an I/O request, it determines if the request contains an I/O control code with a transfer type of METHOD_NEITHER. If the request does contain such an I/O control code, the function:

1. Calls [WdfRequestRetrieveUnsafeUserInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveunsafeuserinputbuffer) and [WdfRequestRetrieveUnsafeUserOutputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveunsafeuseroutputbuffer) to obtain the virtual addresses of the request's read and write buffers.
2. Calls **WdfRequestProbeAndLockUserBufferForRead** and [WdfRequestProbeAndLockUserBufferForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestprobeandlockuserbufferforwrite) to probe and lock the buffers and to obtain a handle to a framework memory object that represents each buffer.

```cpp
VOID
NonPnpEvtIoInCallerContext(
    IN WDFDEVICE  Device,
    IN WDFREQUEST Request
    )
{
    NTSTATUS  status = STATUS_SUCCESS;
    PREQUEST_CONTEXT  reqContext = NULL;
    WDF_OBJECT_ATTRIBUTES  attributes;
    WDF_REQUEST_PARAMETERS  params;
    size_t  inBufLen, outBufLen;
    PVOID  inBuf, outBuf;

    WDF_REQUEST_PARAMETERS_INIT(&params);
    WdfRequestGetParameters(
                            Request,
                            &params
                            );

    //
    // Check to see whether the driver received a METHOD_NEITHER I/O control code.
    // If not, just send the request back to the framework.
    //
    if(!(params.Type == WdfRequestTypeDeviceControl &&
            params.Parameters.DeviceIoControl.IoControlCode ==
                                    IOCTL_NONPNP_METHOD_NEITHER)) {
        status = WdfDeviceEnqueueRequest(
                                         Device,
                                         Request
                                         );
        if( !NT_SUCCESS(status) ) {
            goto End;
        }
        return;
    }

    //
    // The I/O control code is METHOD_NEITHER.
    // First, retrieve the virtual addresses of
    // the input and output buffers.
    //
    status = WdfRequestRetrieveUnsafeUserInputBuffer(
                                                     Request,
                                                     0,
                                                     &inBuf,
                                                     &inBufLen
                                                     );
    if(!NT_SUCCESS(status)) {
        goto End;
    }
    status = WdfRequestRetrieveUnsafeUserOutputBuffer(
                                                      Request,
                                                      0,
                                                      &outBuf,
                                                      &outBufLen
                                                      );
    if(!NT_SUCCESS(status)) {
       goto End;
    }

    //
    // Next, allocate context space for the request, so that the
    // driver can store handles to the memory objects that will
    // be created for input and output buffers.
    //
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes,
                                        REQUEST_CONTEXT);
    status = WdfObjectAllocateContext(
                                      Request,
                                      &attributes,
                                      &reqContext
                                      );
    if(!NT_SUCCESS(status)) {
        goto End;
    }

    //
    // Next, probe and lock the read and write buffers.
    //
    status = WdfRequestProbeAndLockUserBufferForRead(
                                                     Request,
                                                     inBuf,
                                                     inBufLen,
                                                     &reqContext->InputMemoryBuffer
                                                     );
    if(!NT_SUCCESS(status)) {
        goto End;
    }

    status = WdfRequestProbeAndLockUserBufferForWrite(
                                                      Request,
                                                      outBuf,
                                                      outBufLen,
                                                      &reqContext->OutputMemoryBuffer
                                                      );
    if(!NT_SUCCESS(status)) {
        goto End;
    }

    //
    // Finally, return the request to the framework.
    //
    status = WdfDeviceEnqueueRequest(
                                     Device,
                                     Request
                                     );
    if(!NT_SUCCESS(status)) {
        goto End;
    }
    return;

End:
    WdfRequestComplete(
                       Request,
                       status
                       );
    return;
}
```

## See also

[WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer)

[WdfRequestProbeAndLockUserBufferForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestprobeandlockuserbufferforwrite)

[WdfRequestRetrieveUnsafeUserInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveunsafeuserinputbuffer)