# UfxDeviceNotifyReset function

## Description

Notifies UFX about a USB bus reset event.

## Parameters

### `UfxDevice` [in]

A handle to a UFX device object that the driver created by calling [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

### `DeviceSpeed` [in]

Contains a value of type [USB_DEVICE_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ne-usbspec-_usb_device_speed) that indicates the speed of the device.

## Remarks

The client driver calls **UfxDeviceNotifyReset** when it receives a bus reset event. All non-default endpoints should be disabled and the default endpoint should be reset. The device moves to the default state.

The client driver typically calls **UfxDeviceNotifyReset** from its [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function. The following example shows how to handle a reset event.

```

VOID
HandleUsbConnect (
    WDFDEVICE WdfDevice
    )
/*++

Routine Description:

    Handles a connect event from the controller.

Arguments:

    WDfDevice - WDFDEVICE object representing the controller.

--*/
{
    PCONTROLLER_CONTEXT ControllerContext;
    USB_DEVICE_SPEED DeviceSpeed;

    TraceEntry();

    ControllerContext = DeviceGetControllerContext(WdfDevice);

    //
    // Read the device speed.
    //

    //
    // #### TODO: Add code to read device speed from the controller ####
    //

    // Sample will assume SuperSpeed operation for illustration purposes
    DeviceSpeed = UsbSuperSpeed;

    //
    // #### TODO: Add any code needed to configure the controller after connect has occurred ####
    //

    ControllerContext->Speed = DeviceSpeed;
    TraceInformation("Connected Speed is %d!", DeviceSpeed);

    //
    // Notify UFX about reset, which will take care of updating
    // Max Packet Size for EP0 by calling descriptor update.
    //
    UfxDeviceNotifyReset(ControllerContext->UfxDevice, DeviceSpeed);

    ControllerContext->Connect = TRUE;

    TraceExit();
}
```