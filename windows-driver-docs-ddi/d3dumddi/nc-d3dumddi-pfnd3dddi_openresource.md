# PFND3DDDI_OPENRESOURCE callback function

## Description

The *OpenResource* function informs the driver that a shared resource is opened.

## Parameters

### `hDevice`

A handle to the display device (graphics context) that is used to open the resource.

### `unnamedParam2`

*pResource* [in, out]

A pointer to a [D3DDDIARG_OPENRESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_openresource) structure that describes the resource that is opened.

## Return value

*OpenResource* returns S_OK or an appropriate error result if the resource is not successfully opened.

## Remarks

The Microsoft Direct3D runtime calls the user-mode display driver's *OpenResource* function to inform the user-mode display driver that a shared resource is opened. The driver should store any information that is required to describe the resource and return a unique handle in the **hResource** member of the D3DDDIARG_OPENRESOURCE structure (pointed to by the *pResource* parameter) that identifies the new resource in subsequent calls that the Direct3D runtime makes to the driver. The private driver data that is passed to *OpenResource* is the same private driver data that was passed to the display miniport driver's [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function when the resource was created.

For more information about creating and destroying resources, see [Handling Resource Creation and Destruction](https://learn.microsoft.com/windows-hardware/drivers/display/handling-resource-creation-and-destruction).

## See also

[D3DDDIARG_OPENRESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_openresource)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[D3DDDI_OPENALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_openallocationinfo)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)