# PFND3DDDI_CLOSEADAPTER callback function

## Description

The **CloseAdapter** function releases resources for a graphics adapter object.

## Parameters

### `hAdapter`

A handle to the graphics adapter object that was created with the [OpenAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_openadapter) function.

## Return value

**CloseAdapter** returns S_OK if the operation succeeds. Otherwise, this function returns an appropriate error result.

## Remarks

The user-mode display driver's **CloseAdapter** function should free all of the resources that it allocated for the graphics adapter object.

Before **CloseAdapter** closes the graphics adapter object, all of the display devices that were created by using the graphics adapter object in calls to the user-mode display driver's [CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice) function must be destroyed in calls to the driver's [DestroyDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroydevice) function.

## See also

[CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice)

[D3DDDI_ADAPTERFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_adapterfuncs)

[DestroyDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroydevice)

[OpenAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_openadapter)