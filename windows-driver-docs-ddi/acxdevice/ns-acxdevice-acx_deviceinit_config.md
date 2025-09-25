## Description

The **ACX_DEVICEINIT_CONFIG** structure provides configuration information to the class extension.

## Members

### `Size`

This field is set by the [ACX_DEVICE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acx_device_config_init) function.

### `Flags`

Reserved.

### `SynchronizationScope`

A [WDF_SYNCHRONIZATION_SCOPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ne-wdfobject-_wdf_synchronization_scope) value specifying how the framework will synchronize execution of an object's event callback functions.

Internal only. Do not change the default value.

### `ExecutionLevel`

A [WDF_EXECUTION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ne-wdfobject-_wdf_execution_level) value specifying the maximum IRQL at which the framework will call the event callback functions that a driver has supplied for a framework object.

Internal only. Do not change the default value.

### `Context`

Pointer to the context space for the class extension.

## Remarks

Instances of this structure must be initialized by calling the [ACX_DEVICEINIT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acx_deviceinit_config_init) function. A pointer to an **ACX_DEVICEINIT_CONFIG** structure is passed as a parameter to the [AcxDeviceInitInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceinitinitialize) function.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

* [ACX_DEVICE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acx_device_config_init)
* [AcxDeviceInitInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acxdeviceinitinitialize)
* [acxdevice.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/)