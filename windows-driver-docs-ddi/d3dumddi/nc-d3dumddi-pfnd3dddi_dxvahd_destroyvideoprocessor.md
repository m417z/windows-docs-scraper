# PFND3DDDI_DXVAHD_DESTROYVIDEOPROCESSOR callback function

## Description

The **DestroyVideoProcessor** function releases resources for a Microsoft DirectX Video Acceleration (VA) video processor.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hVideoProcessor* [in]

A handle to the DirectX VA video processor that the [CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_createvideoprocessor) function creates.

## Return value

**DestroyVideoProcessor** should return S_OK or an appropriate error result if it cannot successfully release resources for the DirectX VA video processor.

## Remarks

The **DestroyVideoProcessor** function notifies the driver to destroy the handle to the DirectX VA video processor that the [CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_createvideoprocessor) function previously created. The driver can then release resources that are associated with the DirectX VA video processor handle.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_createvideoprocessor)