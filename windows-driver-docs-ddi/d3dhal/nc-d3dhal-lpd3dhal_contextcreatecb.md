# LPD3DHAL_CONTEXTCREATECB callback function

## Description

The **D3dContextCreate** function creates a context.

## Parameters

### `unnamedParam1`

*pccd* [in]

Points to a [D3DHAL_CONTEXTCREATEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_contextcreatedata) structure that contains the information required to create a context and the data that the driver should store in the new context.

## Return value

**D3dContextCreate** returns one of the following callback codes:

## Remarks

**D3dContextCreate** must be implemented in drivers that support Microsoft Direct3D. It should perform the following steps:

* Initialize the driver's context with all information required by the driver to perform rendering. This includes associating the rendering target and depth buffer that the **lpDDSLcl** and **lpDDSZLcl** members of the D3DHAL_CONTEXTCREATEDATA structure at **pccd** point to, respectively, with the context.
* Generate a unique context ID for this new context and return it in the **dwhContext** member of D3DHAL_CONTEXTCREATEDATA. Direct3D uses this context ID in every subsequent callback it makes to this Direct3D device. The driver must never create a context handle of zero.
* Set the **ddrval** member of D3DHAL_CONTEXTCREATEDATA to DD_OK upon success, and to D3DHAL_OUTOFCONTEXTS if it cannot create the context.
* Return DDHAL_DRIVER_HANDLED.

**D3dContextCreate** should not cache the pointer to the [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that was passed in as the **lpDDLcl** member of D3DHAL_CONTEXTCREATEDATA. If the driver subsequently requires any information that is accessed through this DD_DIRECTDRAW_LOCAL pointer, the driver should store the information in the driver's private context data structure.

State is not shared between contexts; therefore, the driver must maintain full state information for each context. This state is changed by any subsequent calls to [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

The driver must be able to reference all texture handles that are created within a context. The driver can then clean up all driver-specific data related to textures created within this context when a [D3dContextDestroy](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_contextdestroycb) call is made.

**D3dContextCreate** can be called with a disabled [PDEV](https://learn.microsoft.com/windows-hardware/drivers/). A PDEV is disabled or enabled by calling the display driver's [DrvAssertMode](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvassertmode) function. See [Managing PDEVs](https://learn.microsoft.com/windows-hardware/drivers/display/managing-pdevs) for more information.

## See also

[D3DHAL_CONTEXTCREATEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_contextcreatedata)

[D3dContextDestroy](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_contextdestroycb)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)

[DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_directdraw_local)