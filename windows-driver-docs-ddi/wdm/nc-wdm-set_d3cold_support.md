## Description

The SetD3ColdSupport callback routine enables or disables transitions to the D3cold device power state.

## Parameters

### `Context` [in, optional]

A pointer to interface-specific context information. The caller sets this parameter to the value of the **Context** member of the [**D3COLD_SUPPORT_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_d3cold_support_interface) structure for the interface.

### `D3ColdSupport` [in]

Whether to allow transitions from D3hot to D3cold. Set to **TRUE** to enable these transitions. Otherwise, set to **FALSE.** For more information, see Remarks.

## Remarks

The driver that is the power policy owner (PPO) for a device can call this routine to enable or disable transitions to the D3cold substate that might occur when the computer is in the S0 (working) system power state and is not preparing to exit S0.

If a device must be able to signal a wake event from any low-power Dx state that it enters, the driver for this device should not enable transitions to the D3cold substate unless the device can signal a wake event from this substate. Otherwise, after entering D3cold, the device will be unavailable until the computer restarts or wakes from a sleeping state.

The driver for the device can call the [GetIdleWakeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_idle_wake_info) routine to determine whether the device can signal a wake event from D3cold.

If necessary, the driver for a device can make a series of *SetD3ColdSupport* calls to alternately enable and disable D3cold transitions in response to dynamically changing conditions.

For example, a graphics device might have a large hardware context to restore after a transition from D3cold to D0. The time required to restore this context may or may not be acceptable depending on the set of tasks that the user is currently performing. In addition, the restore time might vary with this task mix. The driver might need to dynamically enable and disable transitions to D3cold as the task mix changes.

A device can enter the D3cold substate only from the D3hot substate. If the driver calls *SetD3ColdSupport* to enable transitions from D3hot to D3cold, the device may or may not enter D3cold after it enters D3hot. In response to a wake event, a device might enter D0 directly from D3hot without ever passing through D3cold.

When a device moves from D3hot to D3cold, it probably does so because the power source that it shares with some number of other devices was turned off. Some time after these devices enter D3cold, the driver for one of the devices might request a transition to D0. In response to this request, the parent bus driver or ACPI filter driver turns on the power source, and all the devices that share the power source enter their default, power-on states.

The only device driver that expects this power state change is the driver that requested the change. The drivers for the other devices must receive notification of this change so that they can properly initialize their devices to operate in D0. Only a driver that can receive this notification should enable its device to enter D3cold. Otherwise, the driver will not know when the device enters D0.

Starting with Windows 8, a WDM driver can register its device with the power framework (PoFx) and be notified by the [DevicePowerRequiredCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_device_power_required_callback) routine when the device enters D0. Similarly, a KMDF driver can register its device with PoFx and be notified by the [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry) event callback.

A driver that does not register its device with PoFx can still be notified of a transition to D0 if the device is armed for wake. When the bus drivers turn on the power to the device, they complete the driver's [IRP_MN_WAIT_WAKE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-wait-wake) request. In response, the driver initializes its device to operate in D0.

After a power source shared by several devices turns on, the device whose driver requested the transition to D0 might be the only one of these devices that has work to do. The other devices are likely to be idle, in which case their drivers, after some time, will move these devices to D3hot.

If the driver calls *SetD3ColdSupport* to disable transitions to D3cold, D0 is the only device power state that the device can enter from D3hot.

If the driver calls *SetD3ColdSupport* to enable transitions to D3cold, these transitions might be disabled for other reasons. The driver can call the [GetD3ColdCapability](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh967711(v=vs.85)) routine to determine whether the device is capable of entering the D3cold substate. However, a driver might not need this information. If a device is not capable of entering D3cold, calls to *SetD3ColdSupport* have no effect, but are harmless.

The *SetD3ColdSupport* routine affects only D3hot-to-D3cold transitions that might occur when the computer is in (and is not preparing to exit) the S0 state. This routine has no effect on the case in which the computer is preparing to exit S0 and enter a low-power system state. A device in the D3hot substate might always enter the D3cold substate just before the computer enters a system low-power state.

By default, before the first call to the *SetD3ColdSupport* routine, D3hot-to-D3cold transitions are disabled. To change this default so that D3hot-to-D3cold transitions are enabled before the first *SetD3ColdSupport* call, the driver package for the device can include the following two lines in the **DDInstall.HW** section of the INF file that installs the driver:

```inf
Include = machine.inf
Needs = PciD3ColdSupported
```

Windows 8 is the first version of Windows to support devices that can enter and exit the D3cold substate while the computer remains in the S0 state. For more information, see [Device Low-Power States](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-sleeping-states).

## See also

[**D3COLD_SUPPORT_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_d3cold_support_interface)

[DevicePowerRequiredCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_device_power_required_callback)

[EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry)

[GetD3ColdCapability](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh967711(v=vs.85))

[IRP_MN_WAIT_WAKE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-wait-wake)