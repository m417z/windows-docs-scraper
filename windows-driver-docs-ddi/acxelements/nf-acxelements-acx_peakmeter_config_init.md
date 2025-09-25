## Description

The **ACX_PEAKMETER_CONFIG_INIT** function initializes an [ACX_PEAKMETER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_peakmeter_config) structure.

## Parameters

### `cfg`

An [ACX_PEAKMETER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_peakmeter_config) structure.

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_PEAKMETER_CONFIG peakmeterCfg;
    ACX_PEAKMETER_CONFIG_INIT(&peakmeterCfg);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)