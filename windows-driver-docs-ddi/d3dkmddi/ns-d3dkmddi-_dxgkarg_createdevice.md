# _DXGKARG_CREATEDEVICE structure

## Description

The DXGKARG_CREATEDEVICE structure describes a graphics context device.

## Members

### `hDevice`

A handle to the graphics context device. On input to the [DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice) function, **hDevice** specifies the handle that the driver should use when it calls back into the Microsoft DirectX graphics kernel subsystem.

The driver generates a unique handle and passes it back to the DirectX graphics subsystem. On output from the [DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice) function, **hDevice** specifies the handle that the DirectX graphics subsystem should use in subsequent driver calls to identify the device.

### `Flags`

 A [DXGK_CREATEDEVICEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createdeviceflags) structure that identifies how to create the device.

### `pInfo`

A pointer to a [DXGK_DEVICEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_deviceinfo) structure that contains parameters that the DirectX graphics subsystem requires from the display miniport driver.

### `Pasid`

The owner process PASID for a support vector machine GPU.

Supported starting with Windows 10.

### `hKmdProcess`

A handle to the corresponding kernel mode driver process object.

Supported starting with Windows 10.

## See also

[DXGK_CREATEDEVICEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createdeviceflags)

[DXGK_DEVICEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_deviceinfo)

[DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice)