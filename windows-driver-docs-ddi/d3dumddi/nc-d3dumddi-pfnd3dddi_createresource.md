# PFND3DDDI_CREATERESOURCE callback function

## Description

The **CreateResource** function creates a resource.

## Parameters

### `hDevice`

A handle to the display device (graphics context) that is used to create the resource.

### `unnamedParam2`

*pResource* [in, out]

A pointer to a [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource) structure that describes the resource that is created.

## Return value

**CreateResource** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The resource is successfully created. |
| **E_OUTOFMEMORY** | [CreateResource]() could not allocate the required memory for it to complete. |
| **D3DERR_NOTAVAILABLE** | [CreateResource]() could not create the resource for reasons other than not being able to allocate memory. CreateResourcecan return this error only when creating vertex or index buffers. |

## Remarks

The call to **CreateResource** can contain a list of surfaces. The **SurfCount** member of the [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource) structure that is specified by the *pResource* parameter specifies the number of surfaces--including MIP-map levels--to create. For example, a 256x256x9 texture MIP-map resource contains a list of nine surfaces where the **SurfCount** member and number of MIP-map levels are both set to 9. A cube map that contains nine MIP-map levels should have the number of MIP-map levels set to 9 and **SurfCount** set to 54. A three-surface swap chain should have **SurfCount** set to 3 and the number of MIP-map levels set to 0. Note that the number of MIP-map levels is always less than or equal to the value in **SurfCount**.

In response to the **CreateResource** call, the user-mode display driver can call the [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function to create one or more memory allocations. The user-mode display driver must determine whether it must create multiple allocations per surface, one allocation for all surfaces, or one allocation per surface. For more information about allocations, see [Video Memory Management and GPU Scheduling](https://learn.microsoft.com/windows-hardware/drivers/display/video-memory-management-and-gpu-scheduling).

**Note** The driver's **CreateResource** function is not required to call [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) before returning; instead, the driver can defer allocation creation.

**Note** A resource can be shared only if all of the allocations for the resource are made atomically in a single call to [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb).

The **hResource** member in the D3DDDIARG_CREATERESOURCE structure is a handle that is used to identify the resource. The user-mode display driver should store the value of **hResource** that was passed in the **CreateResource** call and overwrite the value with another value that the Microsoft Direct3D runtime can use when the **CreateResource** call returns. In other words, in calls to the runtime, the user-mode display driver uses the **hResource** value that was passed to **CreateResource**; in calls to the user-mode display driver (for example, in calls to the [SetTexture](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_settexture) or [SetStreamSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setstreamsource) functions), the runtime uses the **hResource** value that was returned from **CreateResource**. Note that each surface does not have an explicit handle; if the surface must be referred to individually (for example in a call to the [Blt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_blt) function), it is referred to by a handle and an index. The index identifies the surface within the resource. The index is the same as the index of the surface in the array that is contained in the **pSurfList** member of D3DDDIARG_CREATERESOURCE.

Resources can be shared by multiple devices (**hDevice**) and processes. The runtime specifies that a resource is shared by setting the **SharedResource** bit-field flag in the **Flags** member of [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource). If this bit-field flag is set, the user-mode display driver must adhere to the following restrictions on shared resources:

* The user-mode display driver can call the [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) and [pfnDeallocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocatecb) functions exactly once each.
* The user-mode display driver cannot create additional allocations for the resource after the resource is initially created and likewise can destroy the resource allocations only at the time that the resource itself is destroyed.
* When the user-mode display driver's [DestroyResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyresource) function is called for a shared resource that was created or opened through a call to the driver's **CreateResource** or [OpenResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_openresource) function, the driver must set the **hResource** member of the [D3DDDICB_DEALLOCATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_deallocate) structure to non-NULL and the **NumAllocations** member of D3DDDICB_DEALLOCATE to zero in a call to the [pfnDeallocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocatecb) function to destroy or close the resource. That is, allocations that are associated with a shared resource cannot be destroyed or closed individually; the resource must be destroyed or closed atomically in one call to *pfnDeallocateCb*.
* The number of allocations must be consistent for the resource type (that is, another process that is creating the same resource type should generate the same number and type of allocations). Furthermore, renaming is not allowed for these resources.

The bit-field flags that are specified in the [D3DDDI_RESOURCEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_resourceflags) structure are passed in the **Flags** member of D3DDDIARG_CREATERESOURCE.

**Note** A resource can be created without specifying any flags. Surfaces that are associated with such a resource can potentially be locked and can be a source or destination in a bit-block transfer (bitblt) operation. However, such surfaces cannot be used for anything else.

**Note** Plain surfaces are differentiated from textures or stand-alone render targets by the absence of the **Texture** or **Primary** bit-field flag. For example, the presence of the **Primary** bit-field flag indicates a stand-alone render target and the absence of this flag indicates a render target that is a back buffer.

**Note** To ensure that changes to the runtime do not break existing drivers, the drivers must not use the following reserved members of the [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource) structure in calls to their **CreateResource** function to affect the behavior of the drivers:

* The undefined bits of the **Flags** member are reserved.
* If the **Primary** bit-field flag is not set in **Flags**, the **RefreshRate** and **Output** members are reserved.
* If the **RenderTarget**, **DecodeRenderTarget**, or **VideoProcessRenderTarget** bit-field flag is not set in **Flags**, the **MultisampleType** and **MultisampleQuality** members are reserved.
* If the **VertexBuffer** bit-field flag is not set in **Flags**, the **Fvf** member is reserved.
* If the **Texture**, **CubeMap**, and **Volume** bit-field flags are not set in **Flags**, the **MipLevels** member is reserved.

For more information about creating and destroying resources, see [Handling Resource Creation and Destruction](https://learn.microsoft.com/windows-hardware/drivers/display/handling-resource-creation-and-destruction).

The new **CreateResource** DDI differs from the [DdCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549263(v=vs.85)) DDI for the [Microsoft Windows 2000 display driver model](https://learn.microsoft.com/windows-hardware/drivers/display/windows-2000-display-driver-model-design-guide) in the following ways:

* In the new **CreateResource** DDI, surfaces are never explicitly attached. All of the attachments are implied by the atomic create.
* In the new **CreateResource** DDI, partial creation of cube maps is not allowed.

For a system memory resource, the display miniport driver can chose to wrap an allocation around the system memory if the system memory is properly aligned for direct access by the graphics processing unit (GPU). The display miniport driver wraps an allocation around the system memory by setting the **ExistingSysMem** flag in the **Flags** member of the [DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo) structure when creating the allocation by using its [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function. If the display miniport driver cannot wrap an allocation around the system memory or the wrapping fails, the driver should still succeed the creation of the resource and use the CPU to access the resource.

If the runtime requests to create a vertex or index buffer and if the user-mode display driver cannot create the buffer for reasons other than out of memory (for example, a lack of hardware support), the driver must fail with D3DERR_NOTAVAILABLE.

## See also

[Blt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_blt)

[D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[D3DDDI_RESOURCEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_resourceflags)

[SetStreamSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setstreamsource)

[SetTexture](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_settexture)

[pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb)

[pfnDeallocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocatecb)