## Description

The **ACX_PIN_CONFIG_INIT_ID** function initializes an [ACX_PIN_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_pin_config) structure with the specified ID.

## Parameters

### `Config` [out]

A pointer to the **ACX_PIN_CONFIG** structure to initialize.

### `Id` [in]

The ID to use when initializing the **ACX_PIN_CONFIG** structure.

## Remarks

At this time the only valid accepted ID is AcxPinIdDefault.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_PIN_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_pin_config)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)