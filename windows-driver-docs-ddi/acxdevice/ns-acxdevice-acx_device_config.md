## Description

The **ACX_DEVICE_CONFIG** structure provides configuration information to the class extension.

## Members

### `Size`

The size of all of the data in the **ACX_DEVICE_CONFIG** structure in bytes. This field is set by the [ACX_DEVICE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acx_device_config_init) function.

### `Flags`

An [ACX_DEVICE_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/ne-acxdevice-acx_device_config_flags) value.

### `Context`

Pointer to the context space for the class extension.

## Remarks

Instances of this structure must be initialized by calling the [ACX_DEVICE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acx_device_config_init) function. A pointer to an **ACX_DEVICE_CONFIG** structure is passed as a parameter to the [AcxDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceinitialize) function.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

* [ACX_DEVICE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acx_device_config_init)
* [ACX_DEVICE_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/ne-acxdevice-acx_device_config_flags)
* [AcxDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceinitialize)
* [acxdevice.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/)