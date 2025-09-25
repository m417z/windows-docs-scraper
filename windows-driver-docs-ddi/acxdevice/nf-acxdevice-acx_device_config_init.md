## Description

The **ACX_DEVICE_CONFIG_INIT** function initializes an [ACX_DEVICE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/ns-acxdevice-acx_device_config) structure to be used when calling the [AcxDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceinitialize) function.

## Parameters

### `Config`

Pointer to an [ACX_DEVICE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/ns-acxdevice-acx_device_config) structure.

## Remarks

### Example

```cpp
ACX_DEVICE_CONFIG devCfg;
ACX_DEVICE_CONFIG_INIT(&devCfg);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

* [ACX_DEVICE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/ns-acxdevice-acx_device_config)
* [AcxDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceinitialize)
* [acxdevice.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/)