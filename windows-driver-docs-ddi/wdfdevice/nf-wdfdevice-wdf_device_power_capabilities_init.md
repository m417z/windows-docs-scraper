# WDF_DEVICE_POWER_CAPABILITIES_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_DEVICE_POWER_CAPABILITIES_INIT** function initializes a [WDF_DEVICE_POWER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_capabilities) structure.

## Parameters

### `Caps` [out]

A pointer to a driver-supplied [WDF_DEVICE_POWER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_capabilities) structure.

## Remarks

The **WDF_DEVICE_POWER_CAPABILITIES_INIT** function zeros the [WDF_DEVICE_POWER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_capabilities) structure and sets the structure's **Size** member. Then, it does the following:

* Sets the **DeviceD1** and **DeviceD2** members to **WdfUseDefault**.
* Sets the **WakeFromD0**, **WakeFromD1**, WakeFromD2, and **WakeFromD3** members to **WdfUseDefault**.
* Sets all device states in the **DeviceState** array to **PowerDeviceMaximum**.
* Sets the **DeviceWake** and **SystemWake** members to **PowerDeviceMaximum**.
* Sets the **D1Latency**, **D2Latency**, and **D3Latency** members to -1.
* Sets the **IdealDxStateForSx** member to **PowerDeviceMaximum**.

For a code example that uses **WDF_DEVICE_POWER_CAPABILITIES_INIT**, see [WdfDeviceSetPowerCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetpowercapabilities).

## See also

[WDF_DEVICE_POWER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_capabilities)