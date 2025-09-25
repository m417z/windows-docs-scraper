# PEP_ACPI_INITIALIZE_INTERRUPT_RESOURCE function (pep_x.h)

## Description

The **PEP_ACPI_INITIALIZE_INTERRUPT_RESOURCE** function initializes a platform extension plug-in's (PEP) [PEP_ACPI_INTERRUPT_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_interrupt_resource) structure.

## Parameters

### `ResourceUsage` [in]

Indicates if this device is in use.

### `EdgeLevel` [in]

A [KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode) enumeration value that identifies the interrupt type.

### `InterruptLevel` [in]

A [KINTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_polarity) enumeration value that identifies how a device signals an interrupt request on an interrupt line.

### `ShareType` [in]

Indicates if the device can be shared.

### `Wake` [in]

Indicates if the device can be woken from a low-power state.

### `PinTable` [in]

A list of pin numbers on the resource.

### `PinCount` [in]

The number of pins described by the *PinTable* parameter.

### `Resource` [out]

A pointer to the resource. The structure behind the pointer is of type [PEP_ACPI_INTERRUPT_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_interrupt_resource).

## See also

[PEP_ACPI_INTERRUPT_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_interrupt_resource)