# _PEP_ACPI_REGISTER_DEVICE structure (pepfx.h)

## Description

The **PEP_ACPI_REGISTER_DEVICE** structure contains registration information about a device for which the platform extension plug-in (PEP) is to provide ACPI services.

## Members

### `AcpiDeviceName` [in]

An [ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string) structure that contains the fully qualified BIOS name for the device. The same name was previously supplied as an input value in the [PEP_ACPI_PREPARE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_prepare_device) notification for the device. This name specifies the path and name of the device in the ACPI namespace. For more information, see [Enumerating Child Devices and Control Methods](https://learn.microsoft.com/windows-hardware/drivers/acpi/enumerating-child-devices-and-control-methods).

### `InputFlags` [in]

A set of input flags. No flags are currently defined for this member, which is always set to PEP_ACPI_REGISTER_DEVICE_INPUT_FLAG_NONE (0x0).

### `KernelHandle` [in]

A POHANDLE value that represents the registration of the device with the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The PEP can use this handle to identify the device in subsequent communications with PoFx.

### `DeviceHandle` [out]

A PEPHANDLE value that identifies the registration of this device for ACPI services. This handle is created by the PEP. In subsequent ACPI service notifications, PoFx will use this handle to identify the device.

### `OutputFlags` [out]

A set of output flags. No flags are currently defined for this member. Set this member to PEP_ACPI_REGISTER_DEVICE_OUTPUT_FLAG_NONE (0x0).

## Remarks

This structure is used by the [PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device) notification. The **AcpiDeviceName**, **InputFlags**, and **KernelHandle** members of the structure contain input values that are supplied by PoFx when this notification is sent to the PEP. The **DeviceHandle** and **OutputFlags** members contains output values that the PEP writes to this structure in response to the notification.

## See also

[ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)

[PEP_ACPI_PREPARE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_prepare_device)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device)