# PFND3D11DDI_DESTROYUNORDEREDACCESSVIEW callback function

## Description

Destroys an unordered access view.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hUnorderedAccessView* [in]

A handle to the driver's private data for the unordered access view to destroy. The Microsoft Direct3D runtime frees the memory region that it previously allocated for the unordered access view. Therefore, the driver can no longer access this memory region.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime determines that the error is critical. Even if the device is removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interferes with the operation of *DestroyUnorderedAccessView* (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

**Note** During the destruction of the immediate context and device or the destruction of a deferred context, Windows 7 does not clear the Compute Shader Unordered Access View (CS UAV) bind points.
As a result, a driver sees a UAV handle to still be bound to a context, which violates the general guarantees provided by the runtime.
The driver can work around this problem by following these steps:

* Use either the [AbandonCommandList](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_abandoncommandlist) or the [CreateCommandList](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createcommandlist) method because each marks the end of a command list.
* Deduce the unbinding of CS UAV bind points by verifying that any one of the following states is set to NULL: blend state, rasterizer state, and depth/stencil state.

## See also

[AbandonCommandList](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_abandoncommandlist)

[CreateCommandList](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createcommandlist)

[CreateUnorderedAccessView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createunorderedaccessview)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)