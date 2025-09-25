# EVT_UCX_CONTROLLER_QUERY_USB_CAPABILITY callback function

## Description

The client driver's implementation to determine if the controller supports a specific capability.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

### `CapabilityType` [in]

Pointer to a GUID specifying the requested capability. The possible *PGUID* values are as follows:

* GUID_USB_CAPABILITY_CHAINED_MDLS
* GUID_USB_CAPABILITY_STATIC_STREAMS
* GUID_USB_CAPABILITY_SELECTIVE_SUSPEND
* GUID_USB_CAPABILITY_FUNCTION_SUSPEND
* GUID_USB_CAPABILITY_DEVICE_CONNECTION_HIGH_SPEED_COMPATIBLE
* GUID_USB_CAPABILITY_DEVICE_CONNECTION_SUPER_SPEED_COMPATIBLE
* GUID_USB_CAPABILITY_CLEAR_TT_BUFFER_ON_ASYNC_TRANSFER_CANCEL
  + For typical host controllers, the query must fail (STATUS_NOT_SUPPORTED). If the controller succeeds this capability, it is requesting a Clear TT Buffer when canceling Low Speed/Full Speed asynchronous (Bulk or Control) transfers that have been sent to a TT hub.

See the Remarks section of [USBD_QueryUsbCapability](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406230(v=vs.85)) for more information.

### `OutputBufferLength` [in]

The length, in bytes, of the request's output buffer, if an output buffer is available.

### `OutputBuffer` [out, optional]

A pointer to a location that receives the buffer's address. Certain capabilities may need to provide additional information
to UCX in this buffer.

### `ResultLength` [out]

A location that, on return, contains the size, in bytes, of the information that the callback function stored in *OutputBuffer.*

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The requested USB capability is supported. |
| **STATUS_NOT_IMPLEMENTED** | The requested USB capability is unknown and not supported. |
| **STATUS_NOT_SUPPORTED** | Controller does not support the requested USB capability.<br><br>For GUID_USB_CAPABILITY_CLEAR_TT_BUFFER_ON_ASYNC_TRANSFER_CANCEL, the controller did not request a Clear TT Buffer when canceling Low Speed/Full Speed asynchronous (Bulk or Control) transfers that were sent to a TT hub. |

## Remarks

The UCX client driver registers its *EVT_UCX_CONTROLLER_QUERY_USB_CAPABILITY* implementation with the USB host controller extension (UCX) by calling the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

#### Examples

```
NTSTATUS
Controller_EvtControllerQueryUsbCapability(
    UCXCONTROLLER   UcxController,
    PGUID           CapabilityType,
    ULONG           OutputBufferLength,
    PVOID           OutputBuffer,
    PULONG          ResultLength
)

{
    NTSTATUS status;

    UNREFERENCED_PARAMETER(UcxController);
    UNREFERENCED_PARAMETER(OutputBufferLength);
    UNREFERENCED_PARAMETER(OutputBuffer);

    *ResultLength = 0;

    if (RtlCompareMemory(CapabilityType,
                         &GUID_USB_CAPABILITY_CHAINED_MDLS,
                         sizeof(GUID)) == sizeof(GUID)) {

        //
        // TODO: Is GUID_USB_CAPABILITY_CHAINED_MDLS supported?
        //
        DbgTrace(TL_INFO, Controller, "GUID_USB_CAPABILITY_CHAINED_MDLS not supported");
        status = STATUS_NOT_SUPPORTED;
    }
    else if (RtlCompareMemory(CapabilityType,
                              &GUID_USB_CAPABILITY_STATIC_STREAMS,
                              sizeof(GUID)) == sizeof(GUID)) {

        //
        // TODO: Is GUID_USB_CAPABILITY_STATIC_STREAMS supported?
        //
        DbgTrace(TL_INFO, Controller, "GUID_USB_CAPABILITY_STATIC_STREAMS supported");
        status = STATUS_NOT_SUPPORTED;
    }
    else if (RtlCompareMemory(CapabilityType,
                              &GUID_USB_CAPABILITY_FUNCTION_SUSPEND,
                              sizeof(GUID)) == sizeof(GUID)) {

        //
        // TODO: Is GUID_USB_CAPABILITY_FUNCTION_SUSPEND supported?
        //
        DbgTrace(TL_INFO, Controller, "GUID_USB_CAPABILITY_FUNCTION_SUSPEND not supported");
        status = STATUS_NOT_SUPPORTED;
    }
    else if (RtlCompareMemory(CapabilityType,
                              &GUID_USB_CAPABILITY_SELECTIVE_SUSPEND,
                              sizeof(GUID)) == sizeof(GUID)) {

        DbgTrace(TL_INFO, Controller, "GUID_USB_CAPABILITY_SELECTIVE_SUSPEND supported");
        status = STATUS_SUCCESS;
    }
    else if (RtlCompareMemory(CapabilityType,
                              &GUID_USB_CAPABILITY_CLEAR_TT_BUFFER_ON_ASYNC_TRANSFER_CANCEL,
                              sizeof(GUID)) == sizeof(GUID)) {

        //
        // TODO: Is GUID_USB_CAPABILITY_CLEAR_TT_BUFFER_ON_ASYNC_TRANSFER_CANCEL supported?
        //
        DbgTrace(TL_INFO, Controller, "GUID_USB_CAPABILITY_CLEAR_TT_BUFFER_ON_ASYNC_TRANSFER_CANCEL not supported");
        status = STATUS_NOT_SUPPORTED;
    }
    else {
        DbgTrace(TL_INFO, Controller, "Unhandled USB capability");
        status = STATUS_NOT_IMPLEMENTED;
    }

    return status;
}
```

## See also

[UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85))