# USBFN_SET_DEVICE_STATE callback function

## Description

The filter driver's implementation to set the device state and operating bus speed.

## Parameters

### `Context` [in]

 A pointer to a driver-defined context.

### `DeviceState` [in]

 A [USBFN_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ne-usbfnbase-_usbfn_device_state)-typed flag that indicates the state of the device.

### `BusSpeed` [in]

A [USBFN_BUS_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ne-usbfnbase-_usbfn_bus_speed)-typed flag that indicates the bus speed.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

To support attach and detach detection, the USB lower filter driver must publish its support. During the publishing process, the driver also registers its implementation of this callback function. For more information, see [USB filter driver for supporting proprietary chargers](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188012(v=vs.85)).

The lower filter driver might implement a *USBFN_SET_DEVICE_STATE* even callback function if it requires notification of device state changes to properly configure charging when attached to a host, or in lab scenarios where charging via USB must be disabled.

#### Examples

```
NTSTATUS
UsbLowerFilter_SetDeviceState(
    _In_ PVOID Context,
    _In_ USBFN_DEVICE_STATE DeviceState,
    _In_ USBFN_BUS_SPEED BusSpeed
    )
{
    PPDCP_CONTEXT PdcpContext = NULL;

    PAGED_CODE();

    // Get our context
    PdcpContext = DeviceGetUsbLowerFilterContext((WDFDEVICE)Context);

    PdcpContext->CurrentDeviceState = DeviceState;
    PdcpContext->BusSpeed = BusSpeed;

    return STATUS_SUCCESS;
}

```

## See also

[USB filter driver for supporting proprietary chargers](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188012(v=vs.85))