# PFND3DDDI_GETMULTISAMPLEMETHODLISTCB callback function

## Description

The **pfnGetMultisampleMethodListCb** function retrieves a list of multiple-sample methods that are used for the given width, height, and format of an allocation.

## Parameters

### `hAdapter`

A handle to the graphics adapter object.

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDICB_GETMULTISAMPLEMETHODLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_getmultisamplemethodlist) structure that describes the list of multiple-sample methods for an allocation.

## Return value

**pfnGetMultisampleMethodListCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The list of multiple-sample methods was successfully retrieved.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other HRESULT values.

## Remarks

The user-mode display driver typically uses the **pfnGetMultisampleMethodListCb** function with its [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource), [CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource), or [CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource) function and the [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function. The driver uses **pfnGetMultisampleMethodListCb** when the Direct3D runtime calls the driver's *CreateResource*, *CreateResource(D3D10)*, or *CreateResource(D3D11)* to request that the driver create a multiple-sampled primary. The driver also uses **pfnGetMultisampleMethodListCb** when it must perform multiple-sampling while scanning out from the primary. This type of multiple-sampling might consume additional memory bandwidth, beyond the bandwidth required for scanning out the display mode. Therefore, **pfnGetMultisampleMethodListCb** queries the display mode manager (DMM) (and indirectly the display miniport driver) to retrieve a list of supported multiple-sampling methods for the given width, height, and format. If **pfnGetMultisampleMethodListCb** reports that no methods are supported, the user-mode display driver must use a nonscan-out version of multiple-sampling, typically by creating a standard nonmultiple-sampled primary.

## See also

[CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource)

[CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource)

[CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource)

[D3DDDICB_GETMULTISAMPLEMETHODLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_getmultisamplemethodlist)

[D3DDDI_ADAPTERCALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_adaptercallbacks)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)