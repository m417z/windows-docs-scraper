# _WDF_RELEASE_HARDWARE_ORDER_ON_FAILURE enumeration

## Description

[Applies to KMDF and UMDF]

 The **WDF_RELEASE_HARDWARE_ORDER_ON_FAILURE** enumeration specifies when the framework calls a driver's [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback function.

## Constants

### `WdfReleaseHardwareOrderOnFailureInvalid:0`

Reserved for system use.

### `WdfReleaseHardwareOrderOnFailureEarly`

Except under certain error conditions, the framework calls the driver's [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback function after it has called the *EvtDeviceReleaseHardware* function for all child devices that the driver enumerates. For more information, see Remarks.

### `WdfReleaseHardwareOrderOnFailureAfterDescendants`

The framework always calls the driver's [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback function after it has called the *EvtDeviceReleaseHardware* function for all child devices that the driver enumerates.

## Remarks

The **WDF_RELEASE_HARDWARE_ORDER_ON_FAILURE** enumeration is used as input to [WdfDeviceInitSetReleaseHardwareOrderOnFailure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetreleasehardwareorderonfailure).

If a driver specifies **WdfReleaseHardwareOrderOnFailureEarly**, then in normal device removal, the framework calls the driver's [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) after it has called the *EvtDeviceReleaseHardware* function for all child devices that the driver enumerates. However, in the event of a device power-up or power-down failure, the framework might call the driver's *EvtDeviceReleaseHardware* before it has called the *EvtDeviceReleaseHardware* functions for all child devices.

If a driver specifies **WdfReleaseHardwareOrderOnFailureAfterDescendants**, then the framework waits to call the driver's [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) until it has called the *EvtDeviceReleaseHardware* functions of the child devices.

## See also

[EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware)

[WdfDeviceInitSetReleaseHardwareOrderOnFailure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetreleasehardwareorderonfailure)