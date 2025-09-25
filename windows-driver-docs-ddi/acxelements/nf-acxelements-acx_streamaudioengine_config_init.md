## Description

The **ACX_STREAMAUDIOENGINE_CONFIG_INIT** function initializes an [ACX_STREAMAUDIOENGINE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_streamaudioengine_config) structure.

## Parameters

### `cfg`

An [ACX_STREAMAUDIOENGINE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_streamaudioengine_config) structure.

## Remarks

### Example

Example usage is shown below.

```cpp
        ACX_STREAMAUDIOENGINE_CONFIG audioEngineCfg;
        ACX_STREAMAUDIOENGINE_CONFIG_INIT(&audioEngineCfg);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)