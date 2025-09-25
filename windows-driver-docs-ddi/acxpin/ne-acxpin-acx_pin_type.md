## Description

The **ACX_PIN_TYPE** enumeration is used by the [ACX_PIN_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_pin_config) structure to indicate the type of a pin.

## Constants

### `AcxPinTypeOther`

Indicates that the pin type is not a sink nor a source.

### `AcxPinTypeSink`

Indicates that the pin type is a sink.

### `AcxPinTypeSource`

Indicates that the pin type is a source.

### `AcxPinTypeMaximum`

For internal validation, do not use.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_PIN_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_pin_config)
- [ACX_PIN_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nf-acxpin-acx_pin_config_init)
- [AcxPinGetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nf-acxpin-acxpingettype)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)