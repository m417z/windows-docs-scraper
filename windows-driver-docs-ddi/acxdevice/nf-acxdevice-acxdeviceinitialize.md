## Description

The **AcxDeviceInitialize** function initializes an audio class extension (ACX) device.

## Parameters

### `Device`

Pointer to a **WDFDEVICE** representing the device to initialize.

### `DeviceConfig`

Pointer to an [ACX_DEVICE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/ns-acxdevice-acx_device_config) structure that has been initialized by calling the [ACX_DEVICE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acx_device_config_init) function.

## Return value

**AcxDeviceInitialize** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

## Remarks

### Example

```cpp
NTSTATUS          status;
WDFDEVICE         device = NULL;
ACX_DEVICE_CONFIG devCfg;

// Code to initialize WDFDEVICE...

ACX_DEVICE_CONFIG_INIT(&devCfg);

status = AcxDeviceInitialize(device, &devCfg);

if (!NT_SUCCESS(status))
{
    ASSERT(FALSE);
    goto exit;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_DEVICE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/ns-acxdevice-acx_device_config)
- [ACX_DEVICE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acx_device_config_init)
- [acxdevice.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/)