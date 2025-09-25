# PEP_ACPI_INITIALIZE_GPIO_INT_RESOURCE function (pepfx.h)

## Description

The **PEP_ACPI_INITIALIZE_GPIO_INT_RESOURCE** function initializes a platform extension plug-in's (PEP) [PEP_ACPI_GPIO_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_gpio_resource) structure.

## Parameters

### `InterruptType` [in]

A [KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode) enumeration value that identifies the interrupt type.

### `LevelType` [in]

A [KINTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_polarity) enumeration value that identifies how a device signals an interrupt request on an interrupt line.

### `Shareable` [in]

Indicates if the device can be shared.

### `CanWake` [in]

Indicates if the device can be woken from a low-power state.

### `PinConfig` [in]

A [GPIO_PIN_CONFIG_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_gpio_pin_config_type) enumeration value that identifies the GPIO pin configuration type.

### `DebounceTimeout` [in]

Specifies the hardware debounce wait time, in hundredths of milliseconds.

### `ResourceSourceIndex` [in]

This parameter should always be zero.

### `ResourceSourceName` [in]

This parameter should always be "ResourceConsumer."

### `ResourceUsage` [in]

Indicates if this device is in use.

### `VendorData` [in]

A pointer to a raw data buffer containing vendor-defined byte data to be decoded by the OS driver.

### `VendorDataLength` [in]

The size of the buffer in the *VendorData* parameter.

### `PinTable` [in]

A list of pin numbers on the resource.

### `PinCount` [in]

The number of pins described by the *PinTable* parameter.

### `Resource` [out]

A pointer to the resource. The structure behind the pointer is of type [PEP_ACPI_GPIO_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_gpio_resource).

## See also

[GPIO_PIN_CONFIG_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_gpio_pin_config_type)

[KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode)

[KINTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_polarity)

[PEP_ACPI_GPIO_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_gpio_resource)