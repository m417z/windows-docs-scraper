# PFND3DDDI_DESTROYDECODEDEVICE callback function

## Description

The **DestroyDecodeDevice** function releases resources for a Microsoft DirectX Video Acceleration (VA) decode device.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*hDecodeDevice* [in]

A handle to the DirectX VA decode device that was created by the [CreateDecodeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdecodedevice) function.

## Return value

**DestroyDecodeDevice** should return S_OK or an appropriate error result if it cannot successfully release resources for the DirectX VA decode device.

## Remarks

The **DestroyDecodeDevice** function notifies the driver to destroy the handle to the DirectX VA decode device that the [CreateDecodeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdecodedevice) function previously created. The driver can then release resources that are associated with the DirectX VA decode device handle.

## See also

[CreateDecodeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdecodedevice)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)