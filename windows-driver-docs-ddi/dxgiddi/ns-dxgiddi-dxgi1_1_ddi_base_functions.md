# DXGI1_1_DDI_BASE_FUNCTIONS structure

## Description

The DXGI1_1_DDI_BASE_FUNCTIONS structure contains pointers to functions that the user-mode display driver can implement to perform low-level tasks like presenting rendered frames to an output, controlling gamma, getting notifications regarding shared and GDI interoperable surfaces, and managing a full-screen transition.

## Members

### `pfnPresent`

A pointer to the driver's [PresentDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function.

### `pfnGetGammaCaps`

A pointer to the driver's [GetGammaCapsDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function.

### `pfnSetDisplayMode`

The *SetDisplayModeDXGI* function switches to a display mode or primary that the GDI desktop does not support.

The Microsoft Direct3D runtime calls *SetDisplayModeDXGI* to switch to a display mode or primary that the GDI desktop does not support. The following list describes examples of such primaries:

* Primaries that are created with 10-bits-per-channel (10:10:10:2) display and render target formats (for example, D3DFMT_A2R10G10B10)
* Multiple-sampled primaries where the multiple-sampling is performed while scanning-out
* Persistent primaries that full-screen Microsoft DirectX version 10 applications use

The Direct3D runtime calls the user-mode display driver's [CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) function to create the primary to be scanned out. However, the driver should program the hardware to scan out only when its *SetDisplayModeDXGI* function is called. Therefore, the runtime sets the **hResource** and **SubResourceIndex** members of the [DXGI_DDI_ARG_SETDISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_setdisplaymode) structure that is pointed to by the *pDisplayModeData* parameter to the primary that was created through the call to the driver's *CreateResourceD3D10* function. The driver should then translate the primary that **hResource** and **SubResourceIndex** represent to a primary allocation handle. After the driver makes this translation, the driver should pass the resulting handle in a call to the [pfnSetDisplayModeCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplaymodecb) function, which then initiates a call to the display miniport driver's [DxgkDdiCommitVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn) function.

The user-mode display driver can set the **hPrimaryAllocation** member of the [D3DDDICB_SETDISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_setdisplaymode) structure in the call to **pfnSetDisplayModeCb** to scan out any allocation. However, the allocation must be marked as a primary (that is, the user-mode display driver must have set the **Primary** bit-field flag in the **Flags** member of the [D3DDDI_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo) structure in a call to the [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function to create the allocation).

#### pDisplayModeData

A pointer to a [DXGI_DDI_ARG_SETDISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_setdisplaymode) structure that specifies parameters for setting the display mode.

### `pfnSetResourcePriority`

A pointer to the driver's [SetResourcePriorityDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function.

### `pfnQueryResourceResidency`

A pointer to the driver's [QueryResourceResidencyDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function.

### `pfnRotateResourceIdentities`

A pointer to the driver's [RotateResourceIdentitiesDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function.

### `pfnBlt`

A pointer to the driver's [BltDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function.

### `pfnResolveSharedResource`

The *ResolveSharedResourceDXGI* function informs a user-mode display driver that the ownership of a shared surface changed or that a surface is being used for GDI interoperation.

The Direct3D runtime calls *ResolveSharedResourceDXGI* when an application calls one of the following functions:

* **IDXGIKeyedMutex::ReleaseSynch** on a synchronized shared surface
* **IDXGISurface1::GetDC** for a GDI interoperable surface

The runtime calls the driver's *ResolveSharedResourceDXGI* function every time a shared surface owner changes or when a surface is used for GDI interoperation.

The driver implements *ResolveSharedResourceDXGI* to appropriately manage resources for multiple GPU scenarios. Each resource might be divided across memory for multiple GPUs to render on. The driver can implement *ResolveSharedResourceDXGI* to remerge each resource so that the new resource owner has the merged resource. The driver must flush any partially built command buffers that might modify the resource.

Windows 7 provides the IS_DXGI1_1_BASE_FUNCTIONS macro (which is defined in the *D3D10umddi.h* header file) to allow the user-mode display driver to determine whether it receives a pointer to a **DXGI1_1_DDI_BASE_FUNCTIONS** or [DXGI_DDI_BASE_FUNCTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) structure in a call to its [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function. The DXGI1_1_DDI_BASE_FUNCTIONS structure includes the **pfnResolveSharedResource** member that the driver can fill with a pointer to its *ResolveSharedResourceDXGI* function. If IS_DXGI1_1_BASE_FUNCTIONS returns **TRUE**, the driver expects to receive a pointer to a DXGI1_1_DDI_BASE_FUNCTIONS structure in the **pDXGIDDIBaseFunctions** member of the [DXGI_DDI_BASE_ARGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_args) structure that the **DXGIBaseDDI** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure specifies. Otherwise, if IS_DXGI1_1_BASE_FUNCTIONS returns **FALSE**, the driver expects to receive a pointer to a DXGI_DDI_BASE_FUNCTIONS structure. Windows 7 provides the IS_DXGI1_1_BASE_FUNCTIONS macro to allow newer version drivers to work on older version runtimes. The drivers can then determine whether they will corrupt memory if they attempt to fill the **pfnResolveSharedResource** member of **DXGI1_1_DDI_BASE_FUNCTIONS** with a pointer to the *ResolveSharedResourceDXGI* function.

#### pResourceData

A pointer to a [DXGI_DDI_ARG_RESOLVESHAREDRESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_resolvesharedresource) structure that specifies parameters for the display device and the surface that is associated with the display device.

## Remarks

Windows 7 provides the IS_DXGI1_1_BASE_FUNCTIONS macro (which is defined in the *D3D10umddi.h* header file) to allow the user-mode display driver to determine whether it receives a pointer to a DXGI1_1_DDI_BASE_FUNCTIONS or [DXGI_DDI_BASE_FUNCTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) structure in a call to its [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function. The DXGI1_1_DDI_BASE_FUNCTIONS structure includes the **pfnResolveSharedResource** member that the driver can fill with a pointer to its [ResolveSharedResourceDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_1_ddi_base_functions) function. If IS_DXGI1_1_BASE_FUNCTIONS returns **TRUE**, the driver expects to receive a pointer to a DXGI1_1_DDI_BASE_FUNCTIONS structure in the **pDXGIDDIBaseFunctions** member of the [DXGI_DDI_BASE_ARGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_args) structure that the **DXGIBaseDDI** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure specifies. Otherwise, if IS_DXGI1_1_BASE_FUNCTIONS returns **FALSE**, the driver expects to receive a pointer to a DXGI_DDI_BASE_FUNCTIONS structure. Windows 7 provides the IS_DXGI1_1_BASE_FUNCTIONS macro to allow newer version drivers to work on older version runtimes. The drivers can then determine whether they will corrupt memory if they attempt to fill the **pfnResolveSharedResource** member of **DXGI1_1_DDI_BASE_FUNCTIONS** with a pointer to a *ResolveSharedResourceDXGI* function.

## See also

[BltDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice)

[DXGI_DDI_BASE_ARGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_args)

[DXGI_DDI_BASE_FUNCTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)

[GetGammaCapsDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)

[PresentDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)

[QueryResourceResidencyDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)

[ResolveSharedResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_resolvesharedresource)

[ResolveSharedResourceDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_1_ddi_base_functions)

[RotateResourceIdentitiesDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)

[SetDisplayModeDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_1_ddi_base_functions)

[SetResourcePriorityDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)