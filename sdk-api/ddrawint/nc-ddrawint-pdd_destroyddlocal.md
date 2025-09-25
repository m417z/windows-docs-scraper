## Description

The **D3dDestroyDDLocal** function destroys all the Microsoft Direct3D surfaces previously created by the [D3dCreateSurfaceEx](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurfaceex) function that belong to the same given local Microsoft DirectDraw object.

## Parameters

### `unnamedParam1`

Points to a [DDHAL_DESTROYDDLOCALDATA](https://learn.microsoft.com/windows/desktop/api/ddrawi/ns-ddrawi-ddhal_destroyddlocaldata) structure that contains the information required for the driver to destroy the surfaces.

## Return value

**D3dDestroyDDLocal** returns one of the following callback codes:

## Remarks

All Direct3D drivers must support **D3dDestroyDDLocal**.

Direct3D calls **D3dDestroyDDLocal** when the application indicates that the Direct3D context is no longer required and it will be destroyed along with all surfaces associated to it. The association comes through the pointer to the local DirectDraw object. The driver must free any memory that the driver's [D3dCreateSurfaceEx](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurfaceex) callback allocated for each surface, if necessary.

The driver should not destroy the DirectDraw surfaces associated with these Direct3D surfaces. This is the application's responsibility.

The pointer to the [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that was passed in as the **lpDDLcl** member of the [D3DHAL_CONTEXTCREATEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/ns-d3dhal-_d3dhal_contextcreatedata) structure when [D3dContextCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/nc-d3dhal-lpd3dhal_contextcreatecb) was called is released by the operating system after **D3dDestroyDDLocal** returns.

**D3dDestroyDDLocal** can be called with a disabled [PDEV](https://learn.microsoft.com/windows-hardware/drivers/). A PDEV is disabled or enabled by calling the display driver's [DrvAssertMode](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvassertmode) function. See [Managing PDEVs](https://learn.microsoft.com/windows-hardware/drivers/display/managing-pdevs) for more information.

## See also

[D3DHAL_CONTEXTCREATEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/ns-d3dhal-_d3dhal_contextcreatedata)

[D3dContextCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/nc-d3dhal-lpd3dhal_contextcreatecb)

[D3dCreateSurfaceEx](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurfaceex)

[DDHAL_DESTROYDDLOCALDATA](https://learn.microsoft.com/windows/desktop/api/ddrawi/ns-ddrawi-ddhal_destroyddlocaldata)

[DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local)