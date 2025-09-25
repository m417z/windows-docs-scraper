# PFND3DDDI_SETRENDERSTATE callback function

## Description

The *SetRenderState* function updates a render state.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_RENDERSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_renderstate) structure that describes how to update the render state.

## Return value

*SetRenderState* returns S_OK or an appropriate error result if the render state is not successfully updated.

## Remarks

The Microsoft Direct3D runtime maps **BeginScene** and **EndScene** calls from applications to the user-mode display driver's *SetRenderState* function. When the runtime receives a **BeginScene** call, it sets the **State** member of the [D3DDDIARG_RENDERSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_renderstate) structure that is pointed to by *pData* to D3DRENDERSTATE_SCENECAPTURE and the **Value** member of D3DDDIARG_RENDERSTATE to **TRUE** and then calls *SetRenderState*. When the runtime receives an **EndScene** call, it sets the **State** member to D3DRENDERSTATE_SCENECAPTURE and the **Value** member to **FALSE** and then calls *SetRenderState*. In between these calls to *SetRenderState*, the driver captures geometric data within a frame.

## See also

[D3DDDIARG_RENDERSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_renderstate)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)