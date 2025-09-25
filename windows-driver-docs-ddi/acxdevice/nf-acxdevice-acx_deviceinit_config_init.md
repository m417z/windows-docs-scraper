## Description

The **ACX_DEVICEINIT_CONFIG_INIT** function initializes the [ACX_DEVICEINIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/ns-acxdevice-acx_deviceinit_config) structure.

## Parameters

### `Config`

A pointer to the [ACX_DEVICEINIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/ns-acxdevice-acx_deviceinit_config) structure to initialize.

## Remarks

### Example

```cpp
ACX_DEVICEINIT_CONFIG devInitCfg;
ACX_DEVICEINIT_CONFIG_INIT(&devInitCfg);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

* [ACX_DEVICEINIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/ns-acxdevice-acx_deviceinit_config)
* [acxdevice.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/)