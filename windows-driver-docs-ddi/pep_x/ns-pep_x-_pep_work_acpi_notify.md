# _PEP_WORK_ACPI_NOTIFY structure (pep_x.h)

## Description

The **PEP_WORK_ACPI_NOTIFY** structure contains the ACPI Notify code for a device that has generated a hardware event.

## Members

### `DeviceHandle`

A POHANDLE value that represents the registration of the device with PoFx. The platform extension plug-in (PEP) previously received this handle from the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) during the [PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device) notification in which the PEP elected to provide ACPI services for the device.

### `NotifyCode`

The Notify code. For a list of Notify codes and their meanings, see section 5.6.6, "Device Object Notifications", of the [ACPI 5.0 specification](https://uefi.org/specifications).

## Remarks

The **AcpiNotify** member of the [PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information) structure is a **PEP_WORK_ACPI_NOTIFY** structure.

## See also

[PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device)

[PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information)