# WdfDeviceGetSystemPowerAction function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceGetSystemPowerAction** method returns the [system power action](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-power-actions), if any, that is currently occurring for the computer.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

**WdfDeviceGetSystemPowerAction** returns a POWER_ACTION-typed enumerator value. The value indicates the [system power action](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-power-actions) that is currently occurring for the computer. For more information, see the following Remarks section. The POWER_ACTION enumeration is defined in *wdm.h*.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Starting in WDF version 1.31/2.31 (referred to as "v31"), **WdfDeviceGetSystemPowerAction** has been updated to more accurately report system power action when the device is the power policy owner. Drivers need to be recompiled with v31 or later to get the following new behavior:

* If the device enters or exits D0 due to S0 Idle (see [**WdfDeviceAssignS0IdleSettings**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigns0idlesettings)) while an unrelated system power transition is in progress, **WdfDeviceGetSystemPowerAction** might return **PowerActionSleep**. This is fixed in v31 and now it returns **PowerActionNone**.
* When the system wakes up from Hybrid Sleep (sleep with a hibernation file), before v31, **WdfDeviceGetSystemPowerAction** always returned **PowerActionHibernate**. This is fixed in v31 and now it returns:

   - **PowerActionSleep** if it wakes without power loss, which means the system remained in S3
   - **PowerActionHibernate** if it wakes after power loss, which means the system resumed from the hibernation file

The **WdfDeviceGetSystemPowerAction** method enables a driver to determine whether a device's power transition is occurring because the device is idle (or waking up), or because the entire computer is entering (or leaving) a low-power state.

The driver must call **WdfDeviceGetSystemPowerAction** only from the event callback functions that the framework calls when the device is [entering a low-power state](https://learn.microsoft.com/windows-hardware/drivers/wdf/a-device-enters-a-low-power-state) or [returning to its working state](https://learn.microsoft.com/windows-hardware/drivers/wdf/a-device-returns-to-its-working-state).

The value that **WdfDeviceGetSystemPowerAction** returns depends on the following situations:

* If the computer is entering a low-power state when the driver calls **WdfDeviceGetSystemPowerAction**, the method returns the reason that the computer is entering the low-power state. For example, the method returns **PowerActionSleep** if the computer is entering its S1, S2, or S3 low-power state.
* If the computer is returning to its working (S0) state from a low-power state when the driver calls **WdfDeviceGetSystemPowerAction**, the method returns the reason that the computer entered the low-power state. For example, the method returns **PowerActionSleep** if the computer is leaving its S1, S2, or S3 low-power state.
* If the computer is powering up (after having been turned off) when the driver calls **WdfDeviceGetSystemPowerAction**, the method returns **PowerActionNone**.
* If the device is entering a low-power idle state or returning to its working (D0) state when the driver calls **WdfDeviceGetSystemPowerAction**, while the rest of the system remains at its working (S0) state, the method returns **PowerActionNone**.
* If the computer and the device are both in their working states when the driver calls **WdfDeviceGetSystemPowerAction**, the method returns **PowerActionNone**.

For more information about low-power states, see [A Device Enters a Low-Power State](https://learn.microsoft.com/windows-hardware/drivers/wdf/a-device-enters-a-low-power-state).

#### Examples

The following code example obtains the power transition activity that is currently occurring for the computer.

```cpp
POWER_ACTION SysPowerAction;

SysPowerAction = WdfDeviceGetSystemPowerAction(device);
```