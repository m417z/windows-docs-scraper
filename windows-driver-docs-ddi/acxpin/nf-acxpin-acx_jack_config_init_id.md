## Description

The **ACX_JACK_CONFIG_INIT_ID** function initializes an [ACX_JACK_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_jack_config) structure with the specified ID.

## Parameters

### `Config` [out]

A pointer to the **ACX_JACK_CONFIG** structure to initialize.

### `Id` [in]

The ID to use when initializing the **ACX_JACK_CONFIG** structure.

## Remarks

At this time, driver must use AcxJackPropertiesIdDefault as ID for the Jack.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_JACK_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_jack_config)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)