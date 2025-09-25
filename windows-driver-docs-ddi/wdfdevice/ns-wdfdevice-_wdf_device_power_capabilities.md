# _WDF_DEVICE_POWER_CAPABILITIES structure

## Description

[Applies to KMDF and UMDF]

The WDF_DEVICE_POWER_CAPABILITIES structure describes a device's power capabilities.

## Members

### `Size`

The size, in bytes, of this structure.

### `DeviceD1`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value that indicates, if set to **WdfTrue**, that the device supports device sleeping state D1. For more information about the **WDF_TRI_STATE** value, see the following Remarks section.

### `DeviceD2`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value that indicates, if set to **WdfTrue**, that the device supports device sleeping state D2.

### `WakeFromD0`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value that indicates, if set to **WdfTrue**, that the device can respond to a wake signal while in its D0 state.

### `WakeFromD1`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value that indicates, if set to **WdfTrue**, that the device can respond to a wake signal while in its D1 state.

### `WakeFromD2`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value that indicates, if set to **WdfTrue**, that the device can respond to a wake signal while in its D2 state.

### `WakeFromD3`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value that indicates, if set to **WdfTrue**, that the device can respond to a wake signal while in its D3 state.

### `DeviceState`

An array of DEVICE_POWER_STATE-typed values that indicates the most-powered device state that the device supports for each system power state. This array uses the SYSTEM_POWER_STATE enumeration as index values. If an array element's value is **PowerDeviceMaximum**, the framework uses whatever value that the operating system has stored for that element. The DEVICE_POWER_STATE and SYSTEM_POWER_STATE enumerations are defined in *wdm.h*. For more information about the **DeviceState** member, see [DeviceState](https://learn.microsoft.com/windows-hardware/drivers/kernel/devicestate).

### `DeviceWake`

A DEVICE_POWER_STATE-typed value that indicates the lowest device power state from which the device can send a wake signal to the system. If this value is **PowerDeviceMaximum**, the framework uses whatever value is currently stored in the system for this member.

### `SystemWake`

A SYSTEM_POWER_STATE-typed value that indicates the lowest system power state from which the device can send a wake signal to the system. If this value is **PowerSystemMaximum**, the framework uses whatever value is currently stored in the system for this member. SYSTEM_POWER_STATE values are defined in *wdm.h*.

### `D1Latency`

The approximate time, in 100-nanosecond units, that the device requires to return to its D0 state from its D1 state. If this value is -1, the framework uses whatever value is currently stored in the system for this member.

### `D2Latency`

The approximate time, in 100-nanosecond units, that the device requires to return to its D0 state from its D2 state. If this value is -1, the framework uses whatever value is currently stored in the system for this member.

### `D3Latency`

The approximate time, in 100-nanosecond units, that the device requires to return to its D0 state from its D3 state. If this value is -1, the framework uses whatever value is currently stored in the system for this member.

### `IdealDxStateForSx`

A DEVICE_POWER_STATE-typed value that indicates the [device sleeping state](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-sleeping-states) that the device should enter when the system enters any [system sleeping state](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-sleeping-states) and the device is not enabled to wake the system. If this value is zero, the framework uses **PowerDeviceD3**. This value cannot be **PowerDeviceD0**.

If a driver specifies an **IdealDxStateForSx** value that represents a higher-powered device sleeping state than the device's stack has specified in the device's [DeviceState](https://learn.microsoft.com/windows-hardware/drivers/kernel/devicestate) array, the framework uses the lower-powered state that is in the array. For example, if the driver specifies an **IdealDxStateForSx** value of D1 and the device's **DeviceState** array specifies D2, the framework uses D2.

## Remarks

The WDF_DEVICE_POWER_CAPABILITIES structure is used as input to [WdfDeviceSetPowerCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetpowercapabilities).

Several members use the [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state) type. For these members, the following rules apply:

* A value of **WdfTrue** indicates that the device supports the capability and a value of **WdfFalse** indicates it does not.
* Function drivers and filter drivers can specify **WdfTrue** or **WdfFalse**, or a value of **WdfUseDefault** to indicate that the framework should use the value that was provided by a lower driver in the stack. For example, if a bus driver specifies **WdfTrue** for **DeviceD1** and the device's function driver specifies **WdfUseDefault**, the framework uses **WdfTrue** for the capability.
* When a bus driver calls [WdfDeviceSetPowerCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetpowercapabilities) after it [creates a device object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-device-objects-in-a-bus-driver) for a child device, it should specify **WdfTrue** or **WdfFalse**. A bus driver can specify **WdfUseDefault** for a child device, but in this case **WdfUseDefault** is the same as **WdfFalse**.

To initialize a WDF_DEVICE_POWER_CAPABILITIES structure, a driver should call [WDF_DEVICE_POWER_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_power_capabilities_init).

## See also

[WDF_DEVICE_PNP_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_pnp_capabilities)