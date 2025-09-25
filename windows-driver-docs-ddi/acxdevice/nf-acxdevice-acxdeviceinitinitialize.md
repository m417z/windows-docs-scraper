## Description

The client driver must call **AcxDeviceInitInitialize** in its [EVT_WDF_DRIVER_DEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback, before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

## Parameters

### `DeviceInit`

Pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure representing the device to initialize.

### `Config`

Pointer to an [ACX_DEVICEINIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/ns-acxdevice-acx_deviceinit_config) structure that has been initialized by calling the [ACX_DEVICEINIT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acx_deviceinit_config_init) function.

## Return value

**AcxDeviceInitInitialize** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

## Remarks

### Example

```cpp
WDFDEVICE             Parent;
NTSTATUS              status;
PWDFDEVICE_INIT       devInit = NULL;
ACX_DEVICEINIT_CONFIG devInitCfg;

// Code to initialize WDFDEVICE...

//
// Create a child audio device for this circuit.
//
devInit = WdfPdoInitAllocate(Parent);

if (NULL == devInit)
{
    status = STATUS_INSUFFICIENT_RESOURCES;
    ASSERT(FALSE);
    goto exit;
}

//
// Allow ACX to add any pre-requirement it needs on this device.
//
ACX_DEVICEINIT_CONFIG_INIT(&devInitCfg);

devInitCfg.Flags |= AcxDeviceInitConfigRawDevice;

status = AcxDeviceInitInitialize(devInit, &devInitCfg);

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

- [EVT_WDF_DRIVER_DEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)
- [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)
- [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init)
- [ACX_DEVICEINIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/ns-acxdevice-acx_deviceinit_config)
- [ACX_DEVICEINIT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/nf-acxdevice-acx_deviceinit_config_init)
- [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)
- [acxdevice.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdevice/)