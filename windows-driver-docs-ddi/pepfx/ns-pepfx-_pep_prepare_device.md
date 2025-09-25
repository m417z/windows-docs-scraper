# _PEP_PREPARE_DEVICE structure (pepfx.h)

## Description

The **PEP_PREPARE_DEVICE** structure identifies a device that must be started up in preparation for its use by the operating system.

## Members

### `DeviceId` [in]

A string that uniquely identifies the device. This member is a pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a [device identification string](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

### `DeviceAccepted` [out]

Whether the PEP claims ownership of the device. The PEP sets this member to TRUE to claim ownership of the device, or to FALSE to indicate that it does not own the device. The PEP that claims ownership is responsible for handling [Device power management (DPM) notifications](https://learn.microsoft.com/windows-hardware/drivers/kernel/dpm-notifications) for the device.

## Remarks

This structure is used by the [PEP_DPM_PREPARE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_prepare_device) notification. The **DeviceId** member of the structure contains an input value that is supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) (PoFx). The **DeviceAccepted** member contains an output value that the PEP writes to the structure in response to this notification.

## See also

[PEP_DPM_PREPARE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_prepare_device)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)