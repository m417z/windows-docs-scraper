# PFND3DDDI_DESTROYRESOURCE callback function

## Description

The **DestroyResource** function releases a specified resource.

## Parameters

### `hDevice`

A handle to the display device (graphics context) that is used to destroy the resource.

### `unnamedParam2`

*hResource* [in]

A handle to the resource that the [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource) or [OpenResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_openresource) function created.

## Return value

**DestroyResource** returns S_OK or an appropriate error result is the resource is not released.

## Remarks

After the Microsoft Direct3D runtime calls the user-mode display driver's **DestroyResource** function, the user-mode display driver must first flush any batched commands that depend on the resource that is being destroyed by calling the runtime's [pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) function. The driver must then call the runtime's [pfnDeallocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocatecb) function to destroy allocations that are associated with the resource.

**Note** The driver's **DestroyResource** function is not required to call [pfnDeallocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocatecb) before returning; instead, the driver can defer allocation destruction.

**Note** A separate **DestroyResource** call is not made for each surface that is part of the resource. So, if a group of surfaces is atomically created, the group is always atomically destroyed as well.

For more information about creating and destroying resources, see [Handling Resource Creation and Destruction](https://learn.microsoft.com/windows-hardware/drivers/display/handling-resource-creation-and-destruction).

## See also

[CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[OpenResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_openresource)

[pfnDeallocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocatecb)

[pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb)