# _PEP_ACPI_GPIO_RESOURCE structure (pep_x.h)

## Description

The **PEP_ACPI_GPIO_RESOURCE** structure describes the ACPI configuration for a general purpose input/output (GPIO) resource.

## Members

### `Type`

A [PEP_ACPI_RESOURCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_acpi_resource_type) enumeration value that identifies the resource type for this ACPI resource.

### `Flags`

A [PEP_ACPI_RESOURCE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_resource_flags) structure that describes the capabilities of this ACPI resource.

### `InterruptType`

A [KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode) enumeration value that identifies the interrupt type.

### `InterruptPolarity`

A [KINTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_polarity) enumeration value that identifies how a device signals an interrupt request on an interrupt line.

### `PinConfig`

A [GPIO_PIN_CONFIG_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_gpio_pin_config_type) enumeration value that identifies the GPIO pin configuration type.

### `IoRestrictionType`

A [GPIO_PIN_IORESTRICTION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_gpio_pin_iorestriction_type) enumeration value that identifies the type of IO that the pin supports.

### `DriveStrength`

Specifies the output drive capability of the pin, in hundredths of milliamperes.

### `DebounceTimeout`

Specifies the hardware debounce wait time, in hundredths of milliseconds.

### `PinTable`

A list of pin numbers on the resource that are described by this descriptor.

### `PinCount`

The number of pins in **PinTable**.

### `ResourceSourceIndex`

This member is always zero.

### `ResourceSourceName`

This member is always set to "ResourceConsumer."

### `VendorData`

A pointer to a raw data buffer containing vendor-defined byte data to be decoded by the OS driver.

### `VendorDataLength`

The size of the **VendorData** buffer.

## See also

[GPIO_PIN_CONFIG_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_gpio_pin_config_type)

[GPIO_PIN_IORESTRICTION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_gpio_pin_iorestriction_type)

[KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode)

[KINTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_polarity)

[PEP_ACPI_RESOURCE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_resource_flags)

[PEP_ACPI_RESOURCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_acpi_resource_type)