## Description

The **ACX_JACK_CONFIG** structure is used to configure an audio jack.

## Members

### `Size`

The size of all of the data in the **ACX_JACK_CONFIG** structure in bytes.

### `Id`

An identifier associated with the jack. Currently not used, set to AcxJackPropertiesIdDefault.

### `Flags`

A combination of values from the [ACX_JACK_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_jack_config_flags) enum that describe the jack.

### `Callbacks`

A pointer to an [ACX_JACK_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_jack_callbacks) structure that specifies the callback functions for the jack.

### `Description`

An [ACX_JACK_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_jack_description) structure that describes the jack, including the connection type, location of the jack, and so on.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_JACK_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_jack_config_flags)
- [ACX_JACK_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_jack_callbacks)
- [ACX_JACK_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_jack_description)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)