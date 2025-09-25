## Description

The **ACX_AUDIOMODULE_CONFIG_INIT** function initializes an [ACX_AUDIOMODULE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_audiomodule_config) structure.

## Parameters

### `cfg`

An [ACX_AUDIOMODULE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_audiomodule_config) structure.

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_AUDIOMODULE_CONFIG          audioModuleCfg;
    ACX_AUDIOMODULE_CONFIG_INIT(&audioModuleCfg);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)