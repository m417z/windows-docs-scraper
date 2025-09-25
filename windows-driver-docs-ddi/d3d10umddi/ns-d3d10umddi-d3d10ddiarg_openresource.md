# D3D10DDIARG_OPENRESOURCE structure

## Description

The D3D10DDIARG_OPENRESOURCE structure contains information for opening a shared resource.

## Members

### `NumAllocations` [in]

The number of elements in the array that the **pOpenAllocationInfo** member specifies. **NumAllocations** represents the number of allocations to open.

### `pOpenAllocationInfo2`

This member is reserved and should be set to zero.

This member is available beginning with Windows 7.

### `pOpenAllocationInfo` [in]

An array of [D3DDDI_OPENALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_openallocationinfo) structures that describe the allocations in the resource to open.

[in] An array of [D3DDDI_OPENALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_openallocationinfo) structures that describe the allocations in the resource to open.

### `hKMResource` [in]

A D3D10DDI_HKMRESOURCE data type that represents a kernel-mode handle to the resource that is associated with the allocations.

This kernel-mode handle represents an existing shared resource that was previously created through a call to the user-mode display driver's [CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) function.

The user-mode display driver can insert the kernel-mode resource handle in the command stream for subsequent use by the display miniport driver.

### `pPrivateDriverData` [in]

A pointer to private data that was passed to the display miniport driver when the resource was created. This data is per resource and not per allocation like the private data in each allocation's [D3DDDI_OPENALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_openallocationinfo) structure.

### `PrivateDriverDataSize` [in]

The size, in bytes, of the private data that **pPrivateDriverData** points to.

## See also

[CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource)

[D3DDDI_OPENALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_openallocationinfo)