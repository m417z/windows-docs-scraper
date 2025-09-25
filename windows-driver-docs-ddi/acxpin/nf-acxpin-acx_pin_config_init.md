## Description

The **ACX_PIN_CONFIG_INIT** macro calls the [ACX_PIN_CONFIG_INIT_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nf-acxpin-acx_pin_config_init_id) function with the default ID value.

## Syntax

```cpp
#define ACX_PIN_CONFIG_INIT(cfg) \
    ACX_PIN_CONFIG_INIT_ID(cfg, AcxPinIdDefault)
```

## Parameters

### `cfg`

A pointer to the [ACX_PIN_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_pin_config) structure to initialize.

## Remarks

This call uses AcxPinIdDefault as the ID for all newly added ACXPINs. When AcxPinIdDefault is specified, ACX assigns the next sequential ID based on the previous added ACXPINs.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_PIN_CONFIG_INIT_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nf-acxpin-acx_pin_config_init_id)
- [ACX_PIN_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_pin_config)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)