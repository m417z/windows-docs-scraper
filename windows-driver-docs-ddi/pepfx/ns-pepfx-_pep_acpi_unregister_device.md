# _PEP_ACPI_UNREGISTER_DEVICE structure (pepfx.h)

## Description

The **PEP_ACPI_UNREGISTER_DEVICE** structure contains information about a device that has been unregistered from ACPI services.

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the device's registration for ACPI services. The platform extension plug-in (PEP) supplied this handle in response to a previous [PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device) notification.

### `InputFlags` [in]

A set of input flags. No flags are currently defined for this member, which is always set to PEP_ACPI_UNREGISTER_DEVICE_INPUT_FLAG_NONE (0x0).

## Remarks

This structure is used by the [PEP_NOTIFY_ACPI_UNREGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-peps-for-acpi-services) notification. The **DeviceHandle** and **InputFlags** members contain input values that are supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) when this notification is sent.

## See also

[PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device)

[PEP_NOTIFY_ACPI_UNREGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-peps-for-acpi-services)