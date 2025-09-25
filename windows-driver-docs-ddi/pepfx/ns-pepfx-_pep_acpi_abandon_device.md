# _PEP_ACPI_ABANDON_DEVICE structure (pepfx.h)

## Description

The **PEP_ACPI_ABANDON_DEVICE** structure indicates whether the platform extension plug-in (PEP) accepts ownership of an abandoned device.

## Members

### `AcpiDeviceName` [in]

A pointer to an [ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string) structure that contains the fully qualified BIOS name for the device. This name specifies the path and name of the device in the ACPI namespace. For more information, see [Enumerating Child Devices and Control Methods](https://learn.microsoft.com/windows-hardware/drivers/acpi/enumerating-child-devices-and-control-methods).

### `DeviceAccepted` [out]

Whether the PEP claims ownership of the device specified by the **AcpiDeviceName** member. Set to TRUE if the PEP claims ownership, and to FALSE if the PEP does not own the device.

## Remarks

This structure is used by the [PEP_NOTIFY_ACPI_ABANDON_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_abandon_device) notification. This notification provides an opportunity for the PEP to clean up any remaining device state after the operating system has abandoned the device. The **AcpiDeviceName** member of the structure contains an input value that is supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The **DeviceAccepted** member contains an output value that the PEP writes to the structure in response to the notification.

## See also

[ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)

[PEP_NOTIFY_ACPI_ABANDON_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_abandon_device)