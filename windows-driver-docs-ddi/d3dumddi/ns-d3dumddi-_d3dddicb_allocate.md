# _D3DDDICB_ALLOCATE structure

## Description

The D3DDDICB_ALLOCATE structure contains information for allocating memory.

## Members

### `pPrivateDriverData` [in]

A pointer to private data, which is passed to the display miniport driver. This data is per resource and not per allocation. If allocations are attached to an existing resource, the current data should overwrite the former data.

### `PrivateDriverDataSize` [in]

The size, in bytes, of the private data that is pointed to by **pPrivateDriverData**.

### `hResource` [in]

A handle to the resource that is associated with the allocations.

When the user-mode display driver calls the [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function, the driver should assign the value that was received from the **hResource** member of the [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource) structure in a call to [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource), or the **hRTResource** parameter in a call to [CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) or [CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource). It should assign the value to associate the allocations with the resource, or assign **NULL** to associate the allocations with the device. The driver must assign a non-**NULL** value for allocations that are created in response to shared resources. Shared resources might result from **CreateResource** calls with the **SharedResource** bit-field flag set in the **Flags** member of D3DDDIARG_CREATERESOURCE. They might also result from **CreateResource(D3D10)** or **CreateResource(D3D11)** calls, with the D3D10_DDI_RESOURCE_MISC_SHARED value set in the **MiscFlags** member of either [D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource) or [D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource).

The Microsoft Direct3D runtime should use this handle in driver calls to identify the resource.

### `hKMResource` [out]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the resource that is associated with the allocations.

The Direct3D runtime creates and returns a kernel-mode resource handle only if the user-mode display driver sets the **hResource** member of D3DDDICB_ALLOCATE to the user-mode runtime resource handle that was received from the **hResource** member of the [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource) structure. This handle is received in a call to [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource), or from the *hResource* parameter in a call to either [CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) or [CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource).

The Direct3D runtime generates a unique handle and passes it back to the user-mode display driver. The user-mode display driver can insert the kernel-mode resource handle in the command stream for subsequent use by the display miniport driver.

### `NumAllocations` [in]

The number of elements in the array at **pAllocationInfo**, which represents the number of allocations to allocate.

### `pAllocationInfo2` [in]

This member is reserved and should be set to zero.

This member is available beginning with Windows 7.

### `pAllocationInfo` [in]

An array of [D3DDDI_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo) structures that describe the allocations to allocate.

[in] An array of [D3DDDI_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo) structures that describe the allocations to allocate.

## See also

[CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource)

[CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource)

[CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource)

[D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource)

[D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource)

[D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource)

[D3DDDI_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo)

[pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb)