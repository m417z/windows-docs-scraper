# PFND3D11DDI_CREATERESOURCE callback function

## Description

Creates a resource.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateResource* [in]

A pointer to a [D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource) structure that describes the parameters that the user-mode display driver uses to create a resource.

### `unnamedParam3`

*hResource* [in]

A handle to the driver's private data for the resource.

### `unnamedParam4`

*hRTResource* [in]

A handle to the resource that the driver will use when it calls back into the Direct3D runtime.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver might run out of memory. Therefore, the driver can pass E_OUTOFMEMORY or D3DDDIERR_DEVICEREMOVED in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function. The driver can also pass DXGI_DDI_ERR_UNSUPPORTED in a call to **pfnSetErrorCb**. For more information about passing DXGI_DDI_ERR_UNSUPPORTED, see the Remarks section of the [BltDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) reference page. The Direct3D runtime determines that any other errors are critical. If the driver passes any errors, which includes D3DDDIERR_DEVICEREMOVED, the Direct3D runtime determines that the handle is invalid; therefore, the runtime does not call the [DestroyResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyresource) function to destroy the handle that the *hResource* parameter specifies.

The runtime validates all parameters against the parameters that an application sent to create the resource. Therefore, the driver should not receive invalid combinations.

If the application does not require the contents of the resource to persist across presentations, the runtime sets the D3D10_DDI_RESOURCE_MISC_DISCARD_ON_PRESENT flag of the [D3D10_DDI_RESOURCE_MISC_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_resource_misc_flag) enumeration in the **MiscFlags** member of the [D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource) structure that the *pCreateResource* parameter points to. Presentation occurs when the driver's [PresentDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) or [BltDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) (with the **Present** flag set in the [DXGI_DDI_ARG_BLT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_blt_flags) structure) function is called. The runtime uses the D3D10_DDI_RESOURCE_MISC_DISCARD_ON_PRESENT flag to create swap-chain back buffers when an application uses the DXGI_SWAP_EFFECT_DISCARD value to request swap chains.

### Creating a Stereo Back Buffer

Starting in Windows 8, if the driver must create a stereo back buffer, it must set members of the [D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource) structure pointed to by *pCreateResource* as follows:

1. Set the **ArraySize** member to a value of 2.
2. Set the D3D10_DDI_BIND_PRESENT flag value in the **BindFlags** member.

Additionally, to support stereo presentation, the [BltDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function must allow any values for the **DstSubresource** and **SrcSubresource** members of the [DXGI_DDI_ARG_BLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_blt) structure that are within the range of the source and destination resources.

### Restrictions on input values

For Windows Display Driver Model (WDDM) 1.3 and later drivers, the Microsoft Direct3D runtime supplies a restricted set of input values used by this function. For a list of all restricted values, see [Direct3D rendering performance improvements](https://learn.microsoft.com/windows-hardware/drivers/display/direct3d-rendering-performance-improvements).

## See also

[BltDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)

[CalcPrivateResourceSize(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_calcprivateresourcesize)

[D3D10_DDI_RESOURCE_MISC_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_resource_misc_flag)

[D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[DXGI_DDI_ARG_BLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_blt)

[DXGI_DDI_ARG_BLT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_blt_flags)

[DestroyResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyresource)

[PresentDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)