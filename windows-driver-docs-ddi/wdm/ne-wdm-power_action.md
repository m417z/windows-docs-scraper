# POWER_ACTION enumeration (wdm.h)

## Description

The **POWER_ACTION** enumeration identifies the [system power actions](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-power-actions) that can occur on a computer.

## Constants

### `PowerActionNone`

No power action is taking place.

### `PowerActionReserved`

Reserved for system use.

### `PowerActionSleep`

The computer is entering a [system sleeping (S1, S2, or S3) state](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-sleeping-states).

### `PowerActionHibernate`

The computer is entering its [hibernation (S4) state](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-sleeping-states).

### `PowerActionShutdown`

The computer is entering its [shutdown (S5) state](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-shutdown-state-s5). After all devices have entered their [off (D3) state](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-sleeping-states), the computer remains powered on until an administrator presses the power button.

### `PowerActionShutdownReset`

The computer is entering its shutdown (S5) state. After all devices have entered their off (D3) state, the computer automatically powers off and then immediately restarts and returns to its working (S0) state.

### `PowerActionShutdownOff`

The computer is entering its shutdown (S5) state. After all devices have entered their off (D3) state, the computer automatically powers off.

### `PowerActionWarmEject`

The computer is being ejected from an ACPI-compatible dock device. Typically, the computer's power state does not change.

### `PowerActionDisplayOff`

## Remarks