## Description

The **ACX_KEYWORDSPOTTER_CONFIG_INIT** function initializes an [ACX_KEYWORDSPOTTER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_keywordspotter_config) structure.

## Parameters

### `cfg`

An [ACX_KEYWORDSPOTTER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_keywordspotter_config) structure.

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_KEYWORDSPOTTER_CONFIG       keywordSpotterCfg;

    ACX_KEYWORDSPOTTER_CONFIG_INIT(&keywordSpotterCfg);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)