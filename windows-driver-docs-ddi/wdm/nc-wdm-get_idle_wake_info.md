# GET_IDLE_WAKE_INFO callback function

## Description

The *GetIdleWakeInfo* routine enables the driver for a device to discover the device power states from which the device can signal a wake event.

## Parameters

### `Context` [in, optional]

A pointer to interface-specific context information. The caller sets this parameter to the value of the **Context** member of the [D3COLD_SUPPORT_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_d3cold_support_interface) structure for the interface.

### `SystemPowerState` [in]

System power state. Set this parameter to one of the following [SYSTEM_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_system_power_state) enumeration values:

* **PowerSystemWorking**
* **PowerSystemSleeping1**
* **PowerSystemSleeping2**
* **PowerSystemSleeping3**
* **PowerSystemHibernate**

These values represent system power states S0 (system working state) through S4. For the *SystemPowerState* value supplied by the caller, the routine determines the deepest device power state from which the device can issue a wake signal.

### `DeepestWakeableDstate` [out]

Deepest wakeable Dx state. This parameter is a pointer to a [DEVICE_WAKE_DEPTH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_device_wake_depth) variable. If the call is successful, the routine writes one of the following enumeration values to this variable:

* **DeviceWakeDepthNotWakeable**
* **DeviceWakeDepthD0**
* **DeviceWakeDepthD1**
* **DeviceWakeDepthD2**
* **DeviceWakeDepthD3hot**
* **DeviceWakeDepthD3cold**

A value in the range **DeviceWakeDepthD0** to **DeviceWakeDepthD3cold** indicates the lowest-powered Dx state from which the device can send a wake signal when the computer is in the system power state specified by the *SystemPowerState* parameter. **DeviceWakeDepthNotWakeable** indicates that there is no device power state from which the device can send a wake signal when the computer is in the system power state specified by *SystemPowerState*.

If the routine cannot determine the deepest wakeable device state (perhaps because the platform firmware does not contain this information), the call fails and the routine returns an error status code. If a *GetIdleWakeInfo* call fails for any *SystemPowerState* parameter value in the range **PowerSystemWorking** to **PowerSystemHibernate**, it will fail for all such values.

## Return value

The *GetIdleWakeInfo* routine returns STATUS_SUCCESS if it successfully retrieves the deepest wakeable device state. Otherwise, it returns an appropriate error status code.

## Remarks

For the system power state specified by the caller, this routine tries to determine the lowest-powered device power state from which the device can signal a wake event to the processor. If successful, the routine writes the device power state to the location pointed to by the *DeepestWakeableDstate* parameter, and returns STATUS_SUCCESS. Or, if the routine determines that the device cannot signal a wake event from any device power state, the routine writes the value **DeviceWakeDepthNotWakeable** to this location, and returns STATUS_SUCCESS.

The driver for a device uses the information supplied by the *GetIdleWakeInfo* routine to determine the conditions under which the device can signal a wake event. A device that needs to be able to signal certain wake events should not enter a device power state from which it cannot signal these events. For some types of devices, the wake signals that the device should send when the computer is in the S0 (working) system power state differ from those that the device should send when the computer appears to be off.

For example, when a card is inserted into a PCI Express card slot, and the PCI Express hot-plug controller device for the slot is in the D0 device power state, this device signals an interrupt to the processor. However, if the controller device is in a low-power Dx state when the card is inserted, the system power state of the computer might determine whether this device should signal a wake event to the processor. Ideally, the controller device should behave as follows:

* If the computer is in the S0 (working) system power state, the device should signal a wake event to the processor.
* If the computer is sleeping (in a low-power Sx state), the device should not signal a wake event.

Some older devices might not support this ideal behavior. If the PCI Express hot-plug controller device in this example can signal a wake event only when the computer is in the S3 state, the driver (which, in this case, is the inbox Pci.sys driver) for the controller should keep the controller in D0 when the computer is in S0 (and is not preparing to enter a sleeping state).

The driver in this example can call the *GetIdleWakeInfo* routine to determine whether the hot-plug controller device should leave the D0 state while the computer is in S0. For this call, the driver sets *SystemPowerState* = **PowerSystemWorking**. This device should not leave the D0 state (when the computer is in S0) in either of the following cases:

* The *GetIdleWakeInfo* call sets the output parameter to either **DeviceWakeDepthNotWakeable** or **DeviceWakeDepthD0** and returns STATUS_SUCCESS.
* The *GetIdleWakeInfo* call fails and returns an error status code.

The driver should interpret either of these results to mean that the device cannot signal a wake event when the computer is in S0. Based on this information, the driver should keep the device in D0 until the computer prepares to exit S0.

The drivers for most devices can treat an output value of **DeviceWakeDepthD0** the same as **DeviceWakeDepthNotWakeable**. Only a few drivers might have a reason to arm a wake signal when their devices are in D0. These are drivers for simple devices that monitor external events that trigger wake signals regardless of whether the devices are in D0 or low-power Dx states. An example of such a device is a power button or a sleep button on a computer.

The *GetIdleWakeInfo* routine queries the underlying bus driver and ACPI system firmware to determine the lowest device power state from which the device can signal a wake event. If the bus driver and firmware cannot supply this information, the routine fails and returns an error status code.

The [DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_capabilities) structure includes a **DeviceWake** member that provides information similar to that available from the *GetIdleWakeInfo* routine. However, the information in the **DeviceWake** member applies only to the system low-power states S1 to S4. For some devices, the information in the **DeviceWake** member might also apply to the S0 system power state, but drivers should not rely on such behavior. Only the *GetIdleWakeInfo* routine reliably reports the ability of a device to signal a wake event if the computer is in S0.

An inline helper function, **MapWakeDepthToDstate**, is provided to convert the [DEVICE_WAKE_DEPTH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_device_wake_depth) output value from the *GetIdleWakeInfo* routine to a [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state) value that can be used as an input parameter by the [PoRequestPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-porequestpowerirp) routine.

## See also

[D3COLD_SUPPORT_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_d3cold_support_interface)

[DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_capabilities)

[DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state)

[DEVICE_WAKE_DEPTH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_device_wake_depth)

[PoRequestPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-porequestpowerirp)

[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_system_power_state)