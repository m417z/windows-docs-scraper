# D3DKMT_CREATEDEVICEFLAGS structure

## Description

The **D3DKMT_CREATEDEVICEFLAGS** structure identifies the type of device context to be created in a call to [**D3DKMT_CREATEDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createdevice).

## Members

### `LegacyMode`

A UINT value that specifies whether the device should imitate several behaviors of legacy devices (that is, from Microsoft DirectDraw through Microsoft Direct3D 9.0 device types).

When legacy mode is enabled, the video memory manager does not allow the device to allocate more video memory than can fit in the combined GPU segment. Primaries are allocated in place in video memory and not preserved across mode switches.

### `RequestVSync`

A UINT value that specifies whether the device requires vertical sync to operate. If **RequestVSync** is set, the operating system will enable vertical sync on the graphics hardware until the display device is released.

### `DisableGpuTimeout`

Supported in Windows 8 and later versions.A UINT value that specifies whether the device has disabled [Timeout Detection and Recovery (TDR)](https://learn.microsoft.com/windows-hardware/drivers/display/timeout-detection-and-recovery).

### `TestDevice`

The device is created by a test. Supported starting in Windows 11, version 22H2 (WDDM 3.1).

### `Reserved`

This member is reserved and should be set to zero.

## See also

[**D3DKMT_CREATEDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createdevice)