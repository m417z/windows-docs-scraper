# EVT_UFX_DEVICE_SUPER_SPEED_POWER_FEATURE callback function

## Description

The client driver's implementation to set or clear the specified power feature on the function controller.

## Parameters

### `unnamedParam1` [in]

The handle to a USB device object that the client driver received in a previous call to the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

### `unnamedParam2` [in]

Feature selector for the power feature that is set or cleared, as defined in section 9.4 of the USB 3.0 Specification. The feature selector can be one of these values:

* U1_ENABLE
* U2_ENABLE

### `unnamedParam3` [in]

If TRUE, set the feature.

If FALSE, clear the feature.

## Remarks

The client driver for the function host controller registers its *EVT_UFX_DEVICE_SUPER_SPEED_POWER_FEATURE* implementation with the USB function class extension (UFX) by calling the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate) method.

This event callback is only required for controllers that support SuperSpeed operation.

The client driver indicates completion of this event by calling the [UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete) method.

#### Examples

```

EVT_UFX_DEVICE_SUPER_SPEED_POWER_FEATURE UfxDevice_EvtDeviceSuperSpeedPowerFeature;

VOID
UfxDevice_EvtDeviceSuperSpeedPowerFeature (
    _In_ UFXDEVICE Device,
    _In_ USHORT Feature,
    _In_ BOOLEAN Set
    )
/*++

Routine Description:

    EvtDeviceSuperSpeedPowerFeature handler for the UFXDEVICE object.

    Handles a set or clear U1/U2 request from the host.

Arguments:

    UfxDevice - UFXDEVICE object representing the device.

    Feature - Indicates the feature being set or cleared.  Either U1 or U2 enable.

    Set - Indicates if the feature should be set or cleared

--*/
{
    TraceEntry();

    if (Feature == USB_FEATURE_U1_ENABLE) {
        if (Set == TRUE) {
            //
            // #### TODO: Insert code to initiate U1  ####
            //
        } else {
            //
            // #### TODO: Insert code to exit U1 ####
            //
        }
    } else if (Feature == USB_FEATURE_U2_ENABLE) {
        if (Set == TRUE) {
            //
            // #### TODO: Insert code to initiate U2 ####
            //
        } else {
            //
            // #### TODO: Insert code to exit U2 ####
            //
        }
    } else {
        NT_ASSERT(FALSE);
    }

    UfxDeviceEventComplete(Device, STATUS_SUCCESS);
    TraceExit();
}

```

## See also

[UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate)

[UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete)