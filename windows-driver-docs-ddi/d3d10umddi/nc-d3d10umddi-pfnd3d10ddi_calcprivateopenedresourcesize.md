# PFND3D10DDI_CALCPRIVATEOPENEDRESOURCESIZE callback function

## Description

The **CalcPrivateOpenedResourceSize** function determines the size of the user-mode display driver's private shared region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for an opened resource.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pOpenResource* [in]

A pointer to a [D3D10DDIARG_OPENRESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_openresource) structure that describes the parameters that the user-mode display driver uses to calculate the size of the shared memory region.

## Return value

**CalcPrivateOpenedResourceSize** returns the size of the shared memory region that the driver requires for opening resources.

## See also

[D3D10DDIARG_OPENRESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_openresource)

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)