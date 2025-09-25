# PFND3D10DDI_CLOSEADAPTER callback function

## Description

The **CloseAdapter(D3D10)** function releases resources for a graphics adapter object.

## Parameters

### `unnamedParam1`

*hAdapter* [in]

A handle to the graphics adapter object that was created with the [OpenAdapter10](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_openadapter) function.

## Return value

**CloseAdapter(D3D10)** returns S_OK if the operation succeeds. Otherwise, this function returns an appropriate error result.

## Remarks

The user-mode display driver's **CloseAdapter(D3D10)** function should free all of the resources that the driver allocated for the graphics adapter object.

Before **CloseAdapter(D3D10)** closes the graphics adapter object, all of the display devices that were created by using the graphics adapter object in calls to the user-mode display driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function will be destroyed in calls to the driver's [DestroyDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroydevice) function.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDI_ADAPTERFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_adapterfuncs)

[DestroyDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroydevice)

[OpenAdapter10](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_openadapter)