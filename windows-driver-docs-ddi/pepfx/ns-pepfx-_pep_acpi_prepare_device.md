# _PEP_ACPI_PREPARE_DEVICE structure (pepfx.h)

## Description

The **PEP_ACPI_PREPARE_DEVICE** structure indicates whether a platform extension plug-in (PEP) is prepared to provide ACPI services for the specified device.

## Members

### `AcpiDeviceName` [in]

A pointer to an [ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string) structure that contains the fully qualified BIOS name for the device. This name specifies the path and name of the device in the ACPI namespace. For more information, see [Enumerating Child Devices and Control Methods](https://learn.microsoft.com/windows-hardware/drivers/acpi/enumerating-child-devices-and-control-methods).

### `InputFlags` [in]

A set of input flags. No flags are currently defined for this member, which is always set to PEP_ACPI_PREPARE_DEVICE_INPUT_FLAG_NONE (0x0).

### `DeviceAccepted` [out]

Whether the PEP is prepared to provide ACPI services for the device. Set this member to TRUE if the PEP is prepared to be the sole provider of ACPI services for this device, and to FALSE if it is not.

### `OutputFlags` [out]

A set of output flags. No flags are currently defined for this member. Set this member to PEP_ACPI_PREPARE_DEVICE_OUTPUT_FLAG_NONE (0x0).

## Remarks

This structure is used by the [PEP_NOTIFY_ACPI_PREPARE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_prepare_device) notification. The **AcpiDeviceName** and **InputFlags** members of the structure contain input values that are supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) when this notification is sent to the PEP. The **DeviceAccepted** and **OutputFlags** members contain output values that the PEP writes to the structure in response to the notification.

## See also

[ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)

[PEP_NOTIFY_ACPI_PREPARE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_prepare_device)