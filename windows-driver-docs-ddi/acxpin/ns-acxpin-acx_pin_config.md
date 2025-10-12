## Description

The **ACX_PIN_CONFIG** structure is used to configure a pin.

## Members

### `Size`

The size of all of the data in the **ACX_PIN_CONFIG** structure in bytes. This field is set by the [ACX_PIN_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nf-acxpin-acx_pin_config_init) function.

### `Flags`

A combination of values from the [ACX_PIN_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_pin_config_flags) enum that describe the pin.

### `Id`

An identifier associated with the pin.

### `Type`

An [ACX_PIN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_pin_type) enum value that specifies the type of the pin.

### `Communication`

An [ACX_PIN_COMMUNICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_pin_communication) enum value that specifies the communication type of the pin.

### `Qualifier`

An [ACX_PIN_QUALIFIER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_pin_qualifier) enum value that specifies how the pin is connected in the multi-circuit audio topology.

### `Category`

A GUID value representing the category of the pin.

### `Name`

A GUID value representing the name of the pin.

### `PinCallbacks`

A pointer to an [ACX_PIN_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_pin_callbacks) structure that specifies the callback functions for the pin.

### `PropertiesCount`

Specifies the size of the array pointed to by the *Properties* field.

### `MethodsCount`

Specifies the size of the array pointed to by the *Methods* field.

### `Properties`

A pointer to an array of [ACX_PROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ns-acxrequest-acx_property_item) structures containing pin properties.

### `Methods`

A pointer to an array of [ACX_METHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ns-acxrequest-acx_method_item) structures containing pin methods.

### `u`

A union used to specify the additional type configuration of the pin.

### `u.MicrophoneConfig`

A pointer to an [ACX_MICROPHONE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_microphone_config) structure associated with the pin.

### `MaxStreams`

Specifies the maximum number of streams supported by the pin.

## Remarks

Instances of the **ACX_PIN_CONFIG** structure must be initialized by calling the [ACX_PIN_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nf-acxpin-acx_pin_config_init) function.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_PIN_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nf-acxpin-acx_pin_config_init)
- [ACX_PIN_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_pin_config_flags)
- [ACX_PROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ns-acxrequest-acx_property_item)
- [ACX_METHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ns-acxrequest-acx_method_item)
- [ACX_PIN_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_pin_callbacks)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)