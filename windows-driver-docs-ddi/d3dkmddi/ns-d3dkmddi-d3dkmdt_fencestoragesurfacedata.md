## Description

The **D3DKMDT_FENCESTORAGESURFACEDATA** structure describes the memory segments where the fence storage should be placed.

## Members

### `PhysicalAdapterIndex`

[in] The physical adapter index in an LDA configuration where the fence storage will be resident.

### `FenceStorageValueType`

[in] A [**DXGKARG_FENCESTORAGEVALUETYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-dxgkarg_fencestoragevaluetype) value that specifies the type of the native fence value.

### `FenceStorageType`

[in] A [**D3DDDI_NATIVEFENCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_nativefence_type) value that specifies the type of the native fence.

### `PrivateDriverDataSize`

[in] The size, in bytes, of the private driver data that **pPrivateDriverData** points to.

### `pPrivateDriverData`

[in] A pointer to the private driver data. Reserved for future use.

### `Flags`

[in] A [**DXGKARG_FENCESTORAGEFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_fencestorageflags) value that specifies the flags for the fence storage.

### `Reserved`

[in] Reserved for future use.

### `AllocationInfo`

[out] A [**DXGK_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo)
structure in which the driver should return allocation properties.

## Remarks

When the OS calls the kernel-mode driver's [**DxgkDdiGetStandardAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getstandardallocationdriverdata) function with a standard allocation type of [**D3DKMDT_STANDARDALLOCATION_FENCESTORAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_standardallocation_type), the driver must return the memory segments where the fence storage should be placed in **D3DKMDT_FENCESTORAGESURFACEDATA**.

Based on the input fields, the driver needs to fill the following allocation information in [**AllocationInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo):

* **SupportedWriteSegmentSet**
* **EvictionSegmentSet**
* **PreferredSegment**

The driver should ignore the pointer to private data. The driver shouldn't not check that the pointer is NULL and shouldn't request private data by setting its size.

Monitored values of native fences must be placed in a CPU visible memory segment, because they are updated using CPU pointers.

After the creation of a native fence object that has the [**D3DDDI_NATIVEFENCE_TYPE_INTRA_GPU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_nativefence_type) type, the user-mode driver must always set the initial value by submitting a DMA packet using a GPU virtual address. Current values are packed in a 4K memory page, which can be in a non-CPU visible local memory segment. So, the OS doesn't have a way to set the initial value.

Shared allocations are always placed in system memory.

For more information, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**D3DDDI_NATIVEFENCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_nativefence_type)

[**D3DKMDT_STANDARDALLOCATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_standardallocation_type)

[**DXGK_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo)

[**DXGKARG_FENCESTORAGEFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_fencestorageflags)

[**DXGKARG_FENCESTORAGEVALUETYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-dxgkarg_fencestoragevaluetype)

[**DXGKARG_GETSTANDARDALLOCATIONDRIVERDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_getstandardallocationdriverdata)

[**DxgkDdiGetStandardAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getstandardallocationdriverdata)