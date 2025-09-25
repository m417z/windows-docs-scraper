# UfxDeviceIoInternalControl function

## Description

Passes kernel mode IOCTLs to UFX.

## Parameters

### `UfxDevice` [in]

A handle to a UFX device object that the driver created by calling [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

### `Request` [in]

A handle to a framework request object.

### `OutputBufferLength` [in]

The length, in bytes, of the request's output buffer, if an output buffer is available.

### `InputBufferLength` [in]

The length, in bytes, of the request's input buffer, if an input buffer is available.

### `IoControlCode` [in]

The driver-defined or system-defined IOCTL that is associated with the request.

## Return value

A Boolean value indicating if the call was successful.

## Remarks

The client driver calls **UfxDeviceIoInternalControl** to forward internal IOCTLs that it receives in its [EvtIoInternalDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_internal_device_control) callback function to UFX. The following example shows how:

```cpp
VOID
DefaultQueue_EvtIoInternalDeviceControl(
    _In_ WDFQUEUE Queue,
    _In_ WDFREQUEST Request,
    _In_ size_t OutputBufferLength,
    _In_ size_t InputBufferLength,
    _In_ ULONG IoControlCode
    )
/*++

Routine Description:

    EvtIoInternalDeviceControl handler for the default Queue

Arguments:

    Queue -  Handle to the framework queue object that is associated with the
             I/O request.

    Request - Handle to a framework request object.

    OutputBufferLength - Size of the output buffer in bytes

    InputBufferLength - Size of the input buffer in bytes

    IoControlCode - I/O control code.

--*/
{
    WDFDEVICE WdfDevice;
    PCONTROLLER_CONTEXT ControllerContext;
    BOOLEAN HandledbyUfx;

    TraceEntry();

    TraceVerbose("InternalQueue 0x%p, Request 0x%p, OutputBufferLength %d, "
                  "InputBufferLength %d, IoControlCode %d",
                  Queue, Request, (int) OutputBufferLength,
                  (int) InputBufferLength, IoControlCode);

    WdfDevice = WdfIoQueueGetDevice(Queue);
    ControllerContext = DeviceGetControllerContext(WdfDevice);

    HandledbyUfx = UfxDeviceIoInternalControl(
                        ControllerContext->UfxDevice,
                        Request,
                        OutputBufferLength,
                        InputBufferLength,
                        IoControlCode);

    if (!HandledbyUfx) {
        TraceError("Received an unsupported IOCTL");
        WdfRequestComplete(Request, STATUS_INVALID_DEVICE_REQUEST);
    }

    TraceExit();
}
```