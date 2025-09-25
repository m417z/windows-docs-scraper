# PFND3D11DDI_SETRESOURCEMINLOD callback function

## Description

The *SetResourceMinLOD* function sets the minimum level of detail (LOD) for a resource.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hResource* [in]

A handle to the driver's private data for the resource.

### `unnamedParam3`

*MinLOD* [in]

A single-precision float vector to set for the minimum level of detail (LOD) for the resource.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime determines that the error is critical. Even if the device is removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interferes with the operation of *SetResourceMinLOD* (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

The Direct3D runtime calls the driver's *SetResourceMinLOD* function to set the minimum LOD (that is, the lowest MIP map) that a shader can sample from. This minimum LOD is ignored for some operations like for the operation that the driver's [ResourceCopy](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcecopy) function performs.

## See also

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)