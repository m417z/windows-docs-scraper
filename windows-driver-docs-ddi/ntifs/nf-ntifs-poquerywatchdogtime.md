# PoQueryWatchdogTime function (ntifs.h)

## Description

The **PoQueryWatchdogTime** routine indicates whether the power manager has enabled a watchdog time-out counter for any power IRP that is currently assigned to the device stack.

## Parameters

### `Pdo` [in]

A pointer to a physical device object (PDO). This parameter points to a [**DEVICE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents a physical device.

### `SecondsRemaining` [out]

A pointer to a location into which the routine writes the time, in seconds, that remains before the next power watchdog time-out is set to occur.

## Return value

**PoQueryWatchdogTime** returns TRUE if a watchdog-enabled power IRP is currently assigned to the device stack. Otherwise, it returns FALSE.

## Remarks

This routine enables kernel-mode drivers to monitor watchdog time-out counters that the power manager has enabled to keep track of power IRPs that it has issued. If one or more watchdog time-out counters are currently enabled, the routine returns **TRUE** and provides the amount of time that remains before the next time-out.

For example, a driver that experiences delays when shutting down a device can call this routine to determine how much time remains before the driver must respond to a power IRP to prevent a controlled shutdown (a bug check) of the operating system.

The power manager sets a watchdog time-out counter when it issues a power IRP to the device stack. The time-out period for this counter is typically several minutes. If a device in the stack is unresponsive and causes the IRP to stall for the time-out period, the power manager treats this condition as an unrecoverable error and initiates a controlled shutdown of the operating system.

If more than one power watchdog time-out is currently enabled, the routine sets **SecondsRemaining* to the time that remains to the next time-out.

## See also

[**DEVICE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)