# DXGI_DDI_BASE_FUNCTIONS structure

## Description

The **DXGI_DDI_BASE_FUNCTIONS** structure contains functions that the user-mode display driver can implement to perform low-level tasks like presenting rendered frames to an output, controlling gamma, and managing a full-screen transition.

## Members

### `pfnPresent`

Pointer to the [**PresentDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function that notifies the user-mode display driver that an application finished rendering and requests that the driver display to the destination surface.

The **hDevice** member of the [**DXGI_DDI_ARG_PRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_present) structure that the **pPresentData** parameter points to is the same handle that the driver's [**CreateDevice(D3D10)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function passed back to the runtime in the **hDrvDevice** member of the [**D3D10DDIARG_CREATEDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure. Therefore, driver writers must define the type of this handle carefully. In addition, drivers can supply different implementations of the [**PresentDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function based on which DDI implementation handled the call to **CreateDevice(D3D10)**. The runtime will never mix driver handles across DDI implementations. Similarly, the **hSurfaceToPresent** and **hDstResource** members of **DXGI_DDI_ARG_PRESENT** are also driver-defined resource handles that the driver returned to the runtime in previous calls to the driver's [**CreateResource(D3D10)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) function.

The **pDXGIContext** member of [**DXGI_DDI_ARG_PRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_present) is an opaque communication mechanism. The runtime passes this DXGI context to the driver. The driver should copy this DXGI context unchanged to the **pDXGIContext** member of the [**DXGIDDICB_PRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgiddicb_present) structure when the driver calls the [**pfnPresentCbDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_presentcb) function.

The driver must submit all partially built render data (command buffers) using the [**pfnRenderCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) function. Thereafter, the driver must translate the resource handle parameters into kernel handles and use those kernel handles in a call to [**pfnPresentCbDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_presentcb).

> [!NOTE]
>
> When the driver's [**PresentDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function copies sRGB-formatted content from a source surface to a non-sRGB destination surface, the driver should copy the sRGB content unchanged (that is, the driver should not perform the sRGB to linear conversion).

#### pPresentData

[in] A pointer to a [**DXGI_DDI_ARG_PRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_present) structure that describes how to display to the destination surface.

### `pfnGetGammaCaps`

The **GetGammaCapsDXGI** function retrieves gamma capabilities.

#### pGammaData

[in] A pointer to a [**DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_get_gamma_control_caps) structure that contains gamma capabilities.

### `pfnSetDisplayMode`

A pointer to the driver's [**SetDisplayModeDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_1_ddi_base_functions) function.

### `pfnSetResourcePriority`

The **SetResourcePriorityDXGI** function sets the eviction-from-memory priority for a resource.

The Microsoft Direct3D runtime calls **SetResourcePriorityDXGI** to set the priority level for a resource. The user-mode display driver should translate the resource handle that is supplied in the **hResource** member of the DXGI_DDI_ARG_SETRESOURCEPRIORITY structure that is pointed to by **pPriorityData** to an allocation handle. After the driver makes this translation, the driver should pass the resulting handle in a call to the [**pfnSetPriorityCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setprioritycb) function.

#### pPriorityData

[in] A pointer to a [**DXGI_DDI_ARG_SETRESOURCEPRIORITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_setresourcepriority) structure that describes the priority level to set a resource to.

### `pfnQueryResourceResidency`

This function determines the residency of the given list of resources.

The Microsoft Direct3D runtime calls the user-mode display driver's **QueryResourceResidencyDXGI** function for applications to determine if the operating system will incur a significant stall at draw time if the system must make resources GPU-accessible. The information that is returned from **QueryResourceResidencyDXGI** is an approximation of the residency of resources because the resources might become demoted before applications use the resources.

**QueryResourceResidencyDXGI** must call the [**pfnQueryResidencyCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryresidencycb) function. **pfnQueryResidencyCb** returns the residency status of a resource in the elements of the array that is specified by the **pResidencyStatus** member of the [**D3DDDICB_QUERYRESIDENCY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_queryresidency) structure. If **pfnQueryResidencyCb** returns D3DDDI_RESIDENCYSTATUS_NOTRESIDENT for any query, **QueryResourceResidencyDXGI** must return S_NOT_RESIDENT. If **pfnQueryResidencyCb** returns D3DDDI_RESIDENCYSTATUS_RESIDENTINSHAREDMEMORY for any query and does not return D3DDDI_RESIDENCYSTATUS_NOTRESIDENT for any query, **QueryResourceResidencyDXGI** must return S_RESIDENT_IN_SHARED_MEMORY. **QueryResourceResidencyDXGI** must return S_OK only if all calls to **pfnQueryResidencyCb** for all queries return D3DDDI_RESIDENCYSTATUS_RESIDENTINGPUMEMORY.

For each resource that the runtime queries through a call to **QueryResourceResidencyDXGI**, the user-mode display driver must determine which allocations that belong to the resource to query through a call to [**pfnQueryResidencyCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryresidencycb). For a resource that owns a single allocation, the determination is simple--the driver will query that allocation. However, if a resource owns multiple allocations, the determination is more difficult. The driver must determine which allocations that an application will likely use for rendering, and the driver must query only those allocations. For example, if a resource owns an allocation that is used for rendering and a scratch allocation that handles a lock operation, the driver should query only for the residency of the first allocation, because an application will most likely not use the second allocation for rendering.

> [!NOTE]
>
> Because the runtime does not support residency-querying of system memory resources, the runtime will always fail requests from applications for the residency status of system memory resources and will never call the user-mode display driver's **QueryResourceResidencyDXGI** function for these system memory resources.

#### pResidencyData

[in] A pointer to a [**DXGI_DDI_ARG_QUERYRESOURCERESIDENCY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_queryresourceresidency) structure that describes a list of resources that residency is verified on.

### `pfnRotateResourceIdentities`

Rotates a list of resources.

The [**RotateResourceIdentitiesDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function must exchange identities of the array of resources that are passed in the **pResources** member of the [**DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_rotate_resource_identities) structure that the **pRotateData** parameter points to. For example, if the array of resources refers to resources X, Y, and Z, in increasing array index order, **RotateResourceIdentitiesDXGI** must rotate those handles to refer to Y, Z, and X, in increasing array index order. In particular, the user-mode display driver should swap the kernel handles of the corresponding resources. However, the driver should not swap the corresponding runtime (RT) handles. The runtime calls **RotateResourceIdentitiesDXGI** to rotate back buffers during presentation. Therefore, a call to **RotateResourceIdentitiesDXGI** is infrequent. The runtime can specify the D3D10_DDI_BIND_PRESENT flag in the **BindFlags** member of the [**D3D10DDIARG_CREATERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource) structure when the runtime calls the driver's [**CreateResource(D3D10)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) function to indicate that the resource can participate in a rotate operation.

The user-mode display driver must also handle other aspects of exchanging identities. For example, in Direct3D version 10, views can refer to resources; and such views can have resource addresses embedded in them. Therefore, the driver must re-create such views. Also, the driver might be required to reapply currently bound views.

Beginning in Windows 8, the driver must support rotation of stereo back buffers.

#### pRotateData

[in] A pointer to a [**DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_rotate_resource_identities) structure that describes a list of resources to rotate.

### `pfnBlt`

Copies the contents of a source surface to a destination surface and may rotate the contents.

The Direct3D runtime might set the **Flags** member of the [**DXGI_DDI_ARG_BLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_blt) structure that the **pBltData** parameter points to in such a way as to require the [**BltDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function to perform a bit-block transfer (bitblt) operation that resolves multi-sampled resources, performs color-format conversion, and performs a stretch or shrink all at once. However, the Direct3D runtime will never set the **Flags** member of **DXGI_DDI_ARG_BLT** to zero (that is, no flags set) together with the **DXGI_DDI_MODE_ROTATION_IDENTITY** value set in the **Rotate** member of **DXGI_DDI_ARG_BLT** (that is, to indicate no rotation) to perform a straight memory copy operation. Instead, unless both resources are multi-sampled, the Direct3D runtime calls the driver's [**ResourceCopy**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcecopy) or [**ResourceCopyRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcecopyregion) function to perform a straight memory copy operation.

The quality of the stretch or shrink that the user-mode display driver performs must be as good as the stretch or shrink that a bilinear filter performs.

The Direct3D runtime will call the driver's [**BltDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function infrequently. That is, the runtime should call **BltDXGI** no more than once or twice per frame because the runtime uses **BltDXGI** primarily to support a presentation.

 When the runtime calls [**BltDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) for a presentation, the runtime sets the **Present** bit-field flag in the **Flags** member of [**DXGI_DDI_ARG_BLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_blt). The runtime sets the **Present** bit-field flag to inform the driver that there are extra requirements for the bitblt and that extra synchronization may be necessary (for example, the runtime might need to perform extra synchronization in computer configurations that contain two graphics adapters that each handle separate parts of the display). When the **Present** bit-field flag is set, the driver should perform a copy operation from an application's back buffers to the shared surface of the DWM. Because synchronization for this type of copy operation is inexact, tearing artifacts should be the worst type of artifacts that a user experiences. For this type of copy operation, the driver should not use a multi-pass approach by first resolving into the destination surface and then color converting the results in-place because the possible artifacts would be much worse.

If the driver supports returning **DXGI_DDI_ERR_UNSUPPORTED** during the creation of a primary surface (that is, returning **DXGI_DDI_ERR_UNSUPPORTED** from a call to its [**CreateResource(D3D10)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) function with the **D3D10_DDI_BIND_PRESENT** flag set in the **BindFlags** member of [**D3D10DDIARG_CREATERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource) along with the **pPrimaryDesc** member of **D3D10DDIARG_CREATERESOURCE** set to non-NULL), the driver must also support rotation during a copy operation. If the driver never returns **DXGI_DDI_ERR_UNSUPPORTED** from a call to its **CreateResource(D3D10)** function, the runtime will never pass the **DXGI_DDI_MODE_ROTATION_ROTATE90**, **DXGI_DDI_MODE_ROTATION_ROTATE180**, or **DXGI_DDI_MODE_ROTATION_ROTATE270** value to the **Rotate** member of [**DXGI_DDI_ARG_BLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_blt). Therefore, in this situation, the driver's [**BltDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function is not required to support rotation.

The runtime sets a value in the **Rotate** member of [**DXGI_DDI_ARG_BLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_blt) to indicate the number of degrees to rotate counter-clockwise the contents of the source before the driver copies the contents to the destination. Rotation is specified in increments of 90 degrees.

> [!NOTE]
>
> When the driver's [**BltDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function copies sRGB-formatted content from a source surface to a non-sRGB destination surface, the driver should copy the sRGB content unchanged (that is, the driver should not perform the sRGB to linear conversion).

#### Source restrictions

The [**BltDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function always uses a whole source subresource (versus some sub-rectangular area) to perform the bitblt operation. In addition, the source is a **D3D10DDIRESOURCE_TEXTURE2D** representation (specified in the **ResourceDimension** member of [**D3D10DDIARG_CREATERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource) when the source is created in a call to the user-mode display driver's [**CreateResource(D3D10)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) function). When the runtime sets the **Resolve** bitfield in the **Flags** member of [**DXGI_DDI_ARG_BLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_blt), the source is a multi-sampled resource. The source resource is restricted to a resource in which the **D3D10_DDI_BIND_PRESENT** flag was set in the **BindFlags** member of **D3D10DDIARG_CREATERESOURCE**. The format of the source (specified in the **Format** member of **D3D10DDIARG_CREATERESOURCE**) is restricted to display mode formats, specified by the following values from the [**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) enumeration:

* **DXGI_FORMAT_B5G6R5_UNORM**
* **DXGI_FORMAT_B5G5R5A1_UNORM**
* **DXGI_FORMAT_B8G8R8A8_UNORM** (See Note below.)
* **DXGI_FORMAT_B8G8R8X8_UNORM**
* **DXGI_FORMAT_R16G16B16A16_FLOAT**
* **DXGI_FORMAT_R10G10B10A2_UNORM**
* **DXGI_FORMAT_R8G8B8A8_UNORM**
* **DXGI_FORMAT_R8G8B8A8_UNORM_SRGB**

> [!NOTE]
>
> If the driver supports the source format **DXGI_FORMAT_B8G8R8A8_UNORM**, the following restrictions apply:
>
> * When the driver performs a bitblt operation from a floating-point format to an integer format such as BGRA8888, it must implicitly encode gamma into the results.
> * Conversely, when the driver performs a bitblt operation from an integer format to a floating-point format, it must implicitly remove gamma encoding from the results.

#### Destination restrictions

The destination is also a **D3D10DDIRESOURCE_TEXTURE2D** representation. The format of the destination is also restricted to display mode formats. The destination resource is restricted to a resource that is bound as a render target (**D3D10_DDI_BIND_RENDER_TARGET** set in the **BindFlags** member of [**D3D10DDIARG_CREATERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource) or [**D3D11DDIARG_CREATERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource)).

#### Creating a stereo back buffer

Beginning in Windows 8, if the driver must create a stereo back buffer, it should set members of the [**D3D10DDIARG_CREATERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource) or [**D3D11DDIARG_CREATERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource) structure, respectively, pointed to by the **pCreateResource** parameter of the [**CreateResource(D3D10)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) or [**CreateResource(D3D11)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource) functions, as follows:

1. Set the **ArraySize** member to a value of 2.
2. Set the **D3D10_DDI_BIND_PRESENT** flag value in the **BindFlags** member.

Additionally, to support stereo presentation, the [**BltDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function must allow any values for the **DstSubresource** and **SrcSubresource** members of the [**DXGI_DDI_ARG_BLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_blt) structure that are within the range of the source and destination resources.

#### pBltData

[in] A pointer to a [**DXGI_DDI_ARG_BLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_blt) structure that describes the parameters of a bit-block transfer (bitblt).

## See also

[**BltDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)

[**CreateDevice(D3D10)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[**D3D10DDIARG_CREATEDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice)

[**DXGI_DDI_BASE_ARGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_args)

[**GetGammaCapsDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)

[**PresentDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)

[**QueryResourceResidencyDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)

[**RotateResourceIdentitiesDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)

[**SetDisplayModeDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_1_ddi_base_functions)

[**SetResourcePriorityDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)