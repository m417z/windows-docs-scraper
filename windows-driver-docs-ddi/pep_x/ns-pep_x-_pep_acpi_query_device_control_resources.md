# _PEP_ACPI_QUERY_DEVICE_CONTROL_RESOURCES structure (pep_x.h)

## Description

The **PEP_ACPI_QUERY_DEVICE_CONTROL_RESOURCES** structure contains a list of raw resources that are needed to control power to the device.

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the device's registration for ACPI services. The platform extension plug-in (PEP) supplied this handle in response to a previous [PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device) notification.

### `RequestFlags` [in]

A set of input flags. No flags are currently defined for this member, which is always set to PEP_ACPI_QDCR_FLAG_NONE (0x0).

### `Status` [out]

An NTSTATUS value that indicates the status of this query. Set this member to STATUS_SUCCESS if the PEP succeeded in providing the requested list of resources. Set to STATUS_BUFFER_TOO_SMALL to indicate that the output buffer is not large enough to contain the resource list.

### `BiosResourcesSize` [in, out]

On input, the size, in bytes, of the buffer allocated for the **BiosResources** member. This buffer size includes any associated data that might follow this member.

If this buffer is not large enough to contain the **ACPI_METHOD_ARGUMENT** structure and its associated data, the PEP overwrites the input value of **BiosResourcesSize** with the required size and sets the **Status** member to STATUS_BUFFER_TOO_SMALL.

### `BiosResources` [in]

An output buffer to which the PEP writes an [ACPI_METHOD_ARGUMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1) structure that contains the requested resource list. The **Data** member of this structure is the first member in an array that might extend past the end of the structure. The buffer size specified by **BiosResourcesSize** includes both the **ACPI_METHOD_ARGUMENT** structure and any **Data** array elements that follow this structure.

## Remarks

This structure is used by the [PEP_NOTIFY_ACPI_QUERY_DEVICE_CONTROL_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_query_device_control_resources) notification. The **RequestFlags**, **BiosResourcesSize**, and **BiosResources** members of the structure contain input values supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) when this notification is sent. If the **BiosResourcesSize** input value is too small, the PEP should overwrite this value. The **Status** member contains an output value that the PEP writes to this structure in response to the notification.

If the input value specified in the **BiosResourcesSize** member is less than the required size, the PEP overwrites the **BiosResourcesSize** input value with the required size, and sets the **Status** member to STATUS_BUFFER_TOO_SMALL. In response, PoFx will try to allocate a buffer of the required size and send a second **PEP_NOTIFY_ACPI_QUERY_DEVICE_CONTROL_RESOURCES** notification to the PEP for this device.

## See also

[ACPI_METHOD_ARGUMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1)

[PEP_NOTIFY_ACPI_QUERY_DEVICE_CONTROL_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_query_device_control_resources)

[PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device)