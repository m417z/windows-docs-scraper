# _D3DDDIARG_OPENRESOURCE structure

## Description

The D3DDDIARG_OPENRESOURCE structure contains information for opening a shared resource.

## Members

### `NumAllocations` [in]

The number of elements in the array that is specified by **pOpenAllocationInfo**. **NumAllocations** represents the number of allocations to open.

### `pOpenAllocationInfo2`

This member is reserved and should be set to zero.

This member is available beginning with Windows 7.

### `pOpenAllocationInfo` [in]

An array of [D3DDDI_OPENALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_openallocationinfo) structures that describe the allocations in the resource to open.

[in] An array of [D3DDDI_OPENALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_openallocationinfo) structures that describe the allocations in the resource to open.

### `hKMResource` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the resource that is associated with the allocations.

This kernel-mode handle represents an existing shared resource that was previously created through a call to the user-mode display driver's [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource) function.

### `pPrivateDriverData` [in]

A pointer to private data that was passed to the display miniport driver when the resource was created. This data is per resource and not per allocation like the private data in each allocation's [D3DDDI_OPENALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_openallocationinfo) structure.

### `PrivateDriverDataSize` [in]

The size, in bytes, of the private data that is pointed to by **pPrivateDriverData**.

### `hResource` [in/out]

A handle to the resource that is associated with the allocations.

The user-mode display driver should save this handle and use it to identify the resource anytime that the driver calls back into the Microsoft Direct3D runtime. The user-mode display driver should generate a unique handle and pass it back to the Direct3D runtime. The Direct3D runtime uses this handle in driver calls to identify the resource.

### `Rotation` [in]

A [D3DDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_rotation)-typed value that identifies the orientation of the shared primary resource.

When the primary resource is used with a full-screen device and is rotated, the driver might be required to create interim allocations to handle the full-screen device. The **Fullscreen** bitfield flag is set in the **Flags** member to indicate that the primary resource is used with a full-screen device.

### `Flags` [in]

A [D3DDDI_OPENRESOURCEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_openresourceflags) structure that identifies the type of resource to open.

## Remarks

The **Primary** and **SharedResource** bit-field flags are set in the **Flags** member of the [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource) structure in a call to the [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource) function to create a shared primary resource.

## See also

[CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource)

[D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource)

[D3DDDI_OPENALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_openallocationinfo)

[D3DDDI_OPENRESOURCEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_openresourceflags)

[D3DDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_rotation)

[OpenResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_openresource)