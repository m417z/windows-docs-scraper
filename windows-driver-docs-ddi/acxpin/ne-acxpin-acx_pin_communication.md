## Description

The **ACX_PIN_COMMUNICATION** enumeration is used by the [ACX_PIN_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_pin_config) structure to indicate the communication type of a pin.

## Constants

### `AcxPinCommunicationNone`

Indicates that the pin is not used for communication.

### `AcxPinCommunicationSink`

Indicates that the pin is a communication sink.

### `AcxPinCommunicationSource`

Indicates that the pin is a communication source.

### `AcxPinCommunicationMaximum`

For internal validation, do not use.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_PIN_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_pin_config)
- [ACX_PIN_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nf-acxpin-acx_pin_config_init)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)