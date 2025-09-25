# PFND3DDDI_DESTROYVIDEOPROCESSDEVICE callback function

## Description

The **DestroyVideoProcessDevice** function releases resources for a Microsoft DirectX Video Acceleration (VA) video processing device.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hVideoProcessor`

A handle to the DirectX VA video processing device that was created by the [CreateVideoProcessDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvideoprocessdevice) function.

## Return value

**DestroyVideoProcessDevice** should return S_OK or an appropriate error result if it cannot successfully release resources for the DirectX VA decode device.

## Remarks

The **DestroyVideoProcessDevice** function notifies the driver to destroy the handle to the DirectX VA video processing device that the [CreateVideoProcessDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvideoprocessdevice) function previously created. The driver can then release resources that are associated with the DirectX VA video processing device handle.

## See also

[CreateVideoProcessDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvideoprocessdevice)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)