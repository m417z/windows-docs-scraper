# PFND3DDDI_RESOLVESHAREDRESOURCE callback function

## Description

The *ResolveSharedResource* function informs a user-mode display driver that ownership of a shared surface changed or that a surface is being used for GDI interoperation.

## Parameters

### `hDevice`

A handle to the display device (that is, the graphics context) that is associated with the shared surface or GDI interoperable surface.

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_RESOLVESHAREDRESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_resolvesharedresource) structure that contains a handle to the surface.

## Return value

*ResolveSharedResource* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The resource is successfully resolved.|
|D3DDDIERR_DEVICEREMOVED|The driver detects that the graphics adapter was removed. Therefore, the driver did not complete the operation. If the driver never notices the adapter-removal condition, the driver is not required to return this error code.|

## Remarks

The Direct3D runtime calls *ResolveSharedResource* when an application calls one of the following functions:

* **IDXGIKeyedMutex::ReleaseSynch** on a synchronized shared surface
* **IDXGISurface1::GetDC** for a GDI interoperable surface

The runtime calls the driver's *ResolveSharedResource* function every time a shared surface owner changes or when a surface is used for GDI interoperation. The runtime supplies *ResolveSharedResource* with handles to the display device--via the *hDevice* parameter-- and the surface--via the *pData* parameter.

The driver implements *ResolveSharedResource* to appropriately manage resources for multiple GPU scenarios. Each resource might be divided across memory for multiple GPUs to render on. The driver can implement *ResolveSharedResource* to remerge each resource so that the new resource owner has the merged resource. The driver must flush any partially built command buffers that might modify the resource.

## See also

[D3DDDIARG_RESOLVESHAREDRESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_resolvesharedresource)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)