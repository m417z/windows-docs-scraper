# PFND3D11DDI_DESTROYCOMMANDLIST callback function

## Description

The **DestroyCommandList** function destroys a command list.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hCommandList* [in]

A handle to the driver's private data for the command list to destroy. The Microsoft Direct3D runtime frees the memory region that it previously allocated for the command list. Therefore, the driver can no longer access this memory region.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver is only required to implement **DestroyCommandList** if the driver supports the D3D11DDICAPS_COMMANDLISTS_BUILD_2 capability that can be returned in the [D3D11DDI_THREADING_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps) structure from a call to the [GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps) function.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime determines that the error is critical. Even if the device is removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interferes with the operation of **DestroyCommandList** (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

The driver can implement a **DestroyCommandList** function that contains a **switch** statement to process the destruction of command lists and the lightweight destruction of command lists. That is, the driver can implement one **DestroyCommandList**, and can set the **pfnRecycleDestroyCommandList** member of the [D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs) structure to point to **DestroyCommandList** along with the **pfnRecycleDestroyCommandList** member of D3D11DDI_DEVICEFUNCS to point to **DestroyCommandList**. However, to improve performance, the driver can implement separate **DestroyCommandList** and **RecycleDestroyCommandList** functions.

For more information about **RecycleDestroyCommandList**, see [Optimization for Small Command Lists](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-command-lists).

## See also

[CreateCommandList](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createcommandlist)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[D3D11DDI_THREADING_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps)

[GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)