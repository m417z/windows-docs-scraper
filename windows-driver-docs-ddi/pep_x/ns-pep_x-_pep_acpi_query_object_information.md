# _PEP_ACPI_QUERY_OBJECT_INFORMATION structure (pep_x.h)

## Description

The **PEP_ACPI_QUERY_OBJECT_INFORMATION** structure contains information about an ACPI object.

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the device's registration for ACPI services. The platform extension plug-in (PEP) supplied this handle in response to a previous [PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device) notification.

### `Name` [in]

A [PEP_ACPI_OBJECT_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_object_name) union that specifies the path-relative, four-character name of the object.

### `Type` [in]

A [PEP_ACPI_OBJECT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_acpi_object_type) enumeration value that specifies the object type. Currently, a control method is the only object type that is defined for this member (**Type** = **PepAcpiObjectTypeMethod**).

### `ObjectFlags` [in]

A set of input flags. No flags are currently defined for this member, which is always set to PEP_ACPI_OBJECT_FLAG_NONE (0x0).

### `DUMMYUNIONNAME`

The query result. If the specified object is a control method, the platform extension plug-in (PEP) writes the query result to the **MethodObject** member of this union.

### `DUMMYUNIONNAME.MethodObject` [out]

Information about a control method object.

### `DUMMYUNIONNAME.MethodObject.InputArgumentCount`

The number of input arguments expected by the control method.

### `DUMMYUNIONNAME.MethodObject.OutputArgumentCount`

The number of output arguments produced by the control method.

## Remarks

This structure is used by the [PEP_NOTIFY_ACPI_QUERY_OBJECT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_kernel_information_struct_v1) notification. The **Name**, **Type**, and **Flags** members of the structure contain input values that the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) supplies when this notification is sent. The **MethodObject** member contains an output value that the PEP writes to the structure in response to the notification.

## See also

[PEP_ACPI_OBJECT_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_object_name)

[PEP_ACPI_OBJECT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_acpi_object_type)

[PEP_NOTIFY_ACPI_QUERY_OBJECT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_kernel_information_struct_v1)

[PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device)