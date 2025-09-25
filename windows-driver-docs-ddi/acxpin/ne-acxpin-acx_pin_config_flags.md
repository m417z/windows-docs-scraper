## Description

The **ACX_PIN_CONFIG_FLAGS** enumeration specifies pin configuration settings used in the ACX_PIN_CONFIG structure.

## Constants

### `AcxPinConfigNoFlags`

Indicates that there are no flags set.

### `AcxPinConfigMicrophoneConfigSpecified`

Indicates that an [ACX_MICROPHONE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_microphone_config) structure is available for this pin.

### `AcxPinConfigNoDefaultDataFormatLists`

Indicates that there are no default data format lists for this pin.

### `AcxPinConfigValidFlags`

For internal validation, do not use.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_MICROPHONE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_microphone_config)
- [ACX_PIN_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_pin_config)
- [EVT_ACX_PIN_DATAFORMAT_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nc-acxpin-evt_acx_pin_dataformat_change_notification)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)