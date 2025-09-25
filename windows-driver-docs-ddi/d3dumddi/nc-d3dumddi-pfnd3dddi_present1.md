# PFND3DDDI_PRESENT1 callback function

## Description

Notifies the user-mode display driver that an application finished rendering and that all ownership of the shared resource is released, and requests that the driver display to the destination surface.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pPresentData* [in]

A pointer to a [D3DDDIARG_PRESENT1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_present1) structure that describes how to display to the destination surface.

## Return value

Returns **S_OK** or an appropriate error result if the function does not complete successfully.

## Remarks

The user-mode display driver must submit all partially built render data (command buffers) by calling the [pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) function. The driver must make only a single call to **pfnRenderCb**.

## See also

[D3DDDIARG_PRESENT1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_present1)

[pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb)