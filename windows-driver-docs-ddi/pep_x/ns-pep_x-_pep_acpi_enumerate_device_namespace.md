# _PEP_ACPI_ENUMERATE_DEVICE_NAMESPACE structure (pep_x.h)

## Description

The **PEP_ACPI_ENUMERATE_DEVICE_NAMESPACE** structure contains an enumeration of the objects in the namespace of the device.

## Members

### `DeviceHandle`

A PEPHANDLE value that identifies the device's registration for ACPI services. The platform extension plug-in (PEP) supplied this handle in response to a previous [PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device) notification.

### `RequestFlags`

A set of input flags. No flags are currently defined for this member, which is always set to PEP_ACPI_EDN_FLAG_NONE (0x0).

### `Status`

An NTSTATUS value that indicates the status of the requested device-namespace enumeration. Set this member to STATUS_SUCCESS if the PEP succeeds in enumerating the objects in the device namespace. Set to STATUS_BUFFER_TOO_SMALL if the input value in the **ObjectBufferSize** member indicates that the allocated buffer is not large enough to contain the **Objects** array.

### `ObjectCount`

The number of elements in the **Objects** array.

### `ObjectBufferSize`

The size, in bytes, of the buffer that the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) allocated for the **Objects** array elements that follow the structure. If the input value of **ObjectBufferSize** is not large enough to contain all the **Objects** array elements, the PEP overwrites the input value with the required size and sets the **Status** member to STATUS_BUFFER_TOO_SMALL. For more information, see [Remarks](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_acpi_enumerate_device_namespace#remarks).

### `Objects`

The first element in an array of [PEP_ACPI_OBJECT_NAME_WITH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_object_name_with_type) structures that describe the objects in the ACPI namespace of the device. If this array contains more than one element, the additional array elements follow the end of the **PEP_ACPI_ENUMERATE_DEVICE_NAMESPACE** structure.

## Remarks

This structure is used by the [PEP_NOTIFY_ACPI_ENUMERATE_DEVICE_NAMESPACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_enumerate_device_namespace) notification. The **RequestFlags** and **ObjectBufferSize** members contain input values supplied by PoFx when the notification is sent. The PEP may overwrite the **ObjectBufferSize** input value with an output value if the input value is less than the required output buffer size. The **Status**, **ObjectCount**, and **Objects** members contain output values that the PEP writes to the structure.

**ObjectCount** is the number of objects listed in the ACPI namespace under this device. The PEP should verify that the storage allocated by PoFx for the **Objects** array is large enough to contain **ObjectCount** array elements. If `ObjectCount > 1`, the additional ObjectCount–1 array elements follow the end of the **PEP_ACPI_ENUMERATE_DEVICE_NAMESPACE** structure. The buffer size required to contain the structure and additional array elements is calculated as follows:

``` cpp
sizeof(PEP_ACPI_ENUMERATE_DEVICE_NAMESPACE) + ((ObjectCount-1) * sizeof(PEP_ACPI_OBJECT_NAME_WITH_TYPE));
```

If the input value specified in the **ObjectBufferSize** member is less than the required size, the PEP overwrites the **ObjectBufferSize** input value with the required size, and sets the **Status** member to STATUS_BUFFER_TOO_SMALL. In response, PoFx will allocate a buffer of the required size and send a second [PEP_NOTIFY_ACPI_ENUMERATE_DEVICE_NAMESPACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_enumerate_device_namespace) notification to the PEP for this device.

## See also

- [PEP_ACPI_OBJECT_NAME_WITH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_object_name_with_type)
- [PEP_NOTIFY_ACPI_ENUMERATE_DEVICE_NAMESPACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_enumerate_device_namespace)
- [PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device)