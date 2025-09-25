## Description

The **ACX_JACK_CONFIG_INIT** macro calls the [ACX_JACK_CONFIG_INIT_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nf-acxpin-acx_jack_config_init_id) function with the default ID value.

## Syntax

```cpp
#define ACX_JACK_CONFIG_INIT(cfg) \
    ACX_JACK_CONFIG_INIT_ID(cfg, AcxJackPropertiesIdDefault)
```

## Parameters

### `cfg`

A pointer to the [ACX_JACK_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_jack_config) structure to initialize.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_JACK_CONFIG_INIT_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nf-acxpin-acx_jack_config_init_id)
- [ACX_JACK_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_jack_config)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)