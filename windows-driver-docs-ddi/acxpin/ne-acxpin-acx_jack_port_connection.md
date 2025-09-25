## Description

The **ACX_JACK_PORT_CONNECTION** enumeration is used by the [ACX_JACK_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_jack_description) structure and specifies the type of port represented by the jack.

## Constants

### `AcxPortConnJack`

Indicates that the port type is a physical jack.

### `AcxPortConnIntegratedDevice`

Indicates that the port type is a slot for an integrated device.

### `AcxPortConnBothIntegratedAndJack`

Indicates that the port type is both a jack and a slot for an integrated device.

### `AcxPortConnUnknown`

Indicates that the port type is unknown.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)