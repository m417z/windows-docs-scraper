# _DEVICE_POWER_STATE enumeration (wudfddi.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **DEVICE_POWER_STATE** enumeration identifies the [device power states](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states) that a device can enter.

## Constants

### `PowerDeviceUnspecified`

The device power state is unspecified.

### `PowerDeviceD0`

The device's working (D0) state. This is the device's highest power state.

### `PowerDeviceD1`

The device's D1 [sleeping state](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-sleeping-states).

### `PowerDeviceD2`

The device's D2 sleeping state.

### `PowerDeviceD3`

The device's D3 sleeping state.

### `PowerDeviceMaximum`

For system use only.

## Remarks

The **DEVICE_POWER_STATE** enumeration is used as input to [IWDFDevice2::AssignS0IdleSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-assigns0idlesettings) and [IWDFDevice2::AssignSxWakeSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-assignsxwakesettings).

## See also

[IWDFDevice2::AssignS0IdleSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-assigns0idlesettings)

[IWDFDevice2::AssignSxWakeSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-assignsxwakesettings)