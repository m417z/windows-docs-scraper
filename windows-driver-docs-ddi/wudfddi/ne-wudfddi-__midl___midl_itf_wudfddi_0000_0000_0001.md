# __MIDL___MIDL_itf_wudfddi_0000_0000_0001 enumeration (wudfddi.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

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

## Remarks

The **POWER_ACTION** enumeration is used as the return value for [IWDFDevice2::GetSystemPowerAction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-getsystempoweraction).

## See also

[IWDFDevice2::GetSystemPowerAction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-getsystempoweraction)