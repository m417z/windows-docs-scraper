# USBFN_GET_ATTACH_ACTION_ABORT callback function

## Description

The filter driver's implementation to abort an attach-detect operation.

## Parameters

### `Context` [in]

 A pointer to a driver-defined context.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

To support attach and detach detection, the USB lower filter driver must publish its support. During the publishing process, the driver also registers its implementation of this callback function. For more information, see [USB filter driver for supporting proprietary chargers](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188012(v=vs.85)).

#### Examples

```
NTSTATUS
UsbLowerFilter_GetAttachActionAbortOperation(
    __in PVOID Context
    )
{
    PPDCP_CONTEXT PdcpContext = NULL;

    PAGED_CODE();

    // Get our context
    PdcpContext = DeviceGetUsbLowerFilterContext((WDFDEVICE)Context);

    // Set our event
    (void) KeSetEvent(&PdcpContext->AbortAttachOperation, LOW_REALTIME_PRIORITY, FALSE);

    return STATUS_SUCCESS;
}

```

## See also

[USB filter driver for supporting proprietary chargers](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188012(v=vs.85))