# PFND3DDDI_FLUSH callback function

## Description

The *Flush* function submits outstanding hardware commands that are in the hardware command buffer to the display miniport driver.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

## Return value

*Flush* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|Hardware commands were successfully flushed.|
|E_OUTOFMEMORY|Flush could not allocate the required memory for it to complete.|

## Remarks

The Microsoft Direct3D runtime can call the user-mode display driver's *Flush* function at any time to notify the user-mode display driver to submit any outstanding hardware commands that are in the hardware command buffer to the display miniport driver. However, a call to *Flush* should never cause the user-mode display driver to submit invalid commands to the display miniport driver.

To submit commands to the display miniport driver, the user-mode display driver's *Flush* function should typically call the runtime's [pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) function.

## See also

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb)