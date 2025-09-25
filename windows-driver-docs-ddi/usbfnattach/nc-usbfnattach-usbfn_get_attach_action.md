# USBFN_GET_ATTACH_ACTION callback function

## Description

The filter driver's implementation that gets invoked when charger is attached to the port.

## Parameters

### `Context` [in]

 A pointer to a driver-defined context.

### `OnAttach` [out]

A pointer to a caller-allocated [USBFN_ON_ATTACH](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnattach/ns-usbfnattach-_usbfn_on_attach) structure that the driver populates with the type of attach and port.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

To support attach and detach detection, the USB lower filter driver must publish its support. During the publishing process, the driver also registers its implementation of this callback function. For more information, see [USB filter driver for supporting proprietary chargers](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188012(v=vs.85)).

#### Examples

```
NTSTATUS
UsbLowerFilter_GetAttachAction(
    __in PVOID Context,
    __out PUSBFN_ON_ATTACH OnAttach
    )
{
    NTSTATUS Status;
    PPDCP_CONTEXT PdcpContext = NULL;
    LARGE_INTEGER Timeout;

    PAGED_CODE();

    // Get driver context
    PdcpContext = DeviceGetUsbLowerFilterContext((WDFDEVICE)Context);

    // Clear the event
    KeClearEvent(&PdcpContext->AbortAttachOperation);

    // Wait for a while
    Timeout.QuadPart = WDF_REL_TIMEOUT_IN_MS(PdcpContext->DetectionDelayInms);

    Status = KeWaitForSingleObject(
        &PdcpContext->AbortAttachOperation,
        Executive,
        KernelMode,
        FALSE,
        &Timeout);

    switch (Status)
    {
    case STATUS_SUCCESS:
        // The abort event was set.
        Status = STATUS_REQUEST_ABORTED;
        break;

    case STATUS_TIMEOUT:
        Status = STATUS_SUCCESS;
        break;

    default:
        break;
    }

    if (NT_SUCCESS(Status))
    {
        OnAttach->AttachAction = PdcpContext->CurrentAttachAction;
        OnAttach->PortType = PdcpContext->CurrentPortType;
    }

    return Status;

```

## See also

[USB filter driver for supporting proprietary chargers](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188012(v=vs.85))