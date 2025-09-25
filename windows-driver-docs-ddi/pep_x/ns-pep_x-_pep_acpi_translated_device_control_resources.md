# _PEP_ACPI_TRANSLATED_DEVICE_CONTROL_RESOURCES structure (pep_x.h)

## Description

The **PEP_ACPI_TRANSLATED_DEVICE_CONTROL_RESOURCES** structure contains a list of translated power-control resources for the platform extension plug-in (PEP) to use.

## Members

### `DeviceHandle`

A PEPHANDLE value that identifies the device's registration for ACPI services. The platform extension plug-in (PEP) supplied this handle in response to a previous [PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device) notification.

### `RequestFlags`

A set of input flags. No flags are currently defined for this member, which is always set to PEP_ACPI_TDCR_FLAG_NONE (0x0).

### `Status`

An NTSTATUS value that indicates the status of the resource translation. The PEP sets this member to STATUS_SUCCESS to indicate that the PEP successfully received the translated resources. Otherwise, the PEP sets this member to an appropriate error status code.

### `TranslatedResourcesSize`

The size, in bytes, of the *TranslatedResources* list data that follows this structure.

### `TranslatedResources`

A [CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list) structure that serves as the header for the resource list. The remainder of the resource list immediately follows this header.

## Remarks

This structure is used by the [PEP_NOTIFY_ACPI_TRANSLATED_DEVICE_CONTROL_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_translated_device_control_resources) notification to provide the PEP with a list of translated power control resources. The **RequestFlags**, **TranslatedResourcesSize**, and **TranslatedResources** members of the structure contain input values that the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) supplies when this notification is sent. The **Status** member contains an output value that the PEP writes to the structure in response to the notification.

## See also

- [CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list)
- [PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device)
- [PEP_NOTIFY_ACPI_TRANSLATED_DEVICE_CONTROL_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_translated_device_control_resources)