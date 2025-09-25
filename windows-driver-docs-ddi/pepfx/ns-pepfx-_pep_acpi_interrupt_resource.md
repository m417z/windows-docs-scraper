# _PEP_ACPI_INTERRUPT_RESOURCE structure (pepfx.h)

## Description

The **PEP_ACPI_INTERRUPT_RESOURCE** structure describes an ACPI interrupt resource.

## Members

### `Type`

A [PEP_ACPI_RESOURCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_acpi_resource_type) enumeration value describing this resource.

### `InterruptType`

A [KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode) enumeration value that identifies the interrupt type.

### `InterruptPolarity`

A [KINTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_polarity) enumeration value that identifies how a device signals an interrupt request on an interrupt line.

### `Flags`

A [PEP_ACPI_RESOURCE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_resource_flags) structure that describes the capabilities of this ACPI resource.

### `Count`

The count of items in the **Pins** array.

### `Pins`

A list of pin numbers on the resource that are described by this descriptor.

## See also

[KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode)

[KINTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_polarity)

[PEP_ACPI_RESOURCE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_resource_flags)

[PEP_ACPI_RESOURCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_acpi_resource_type)