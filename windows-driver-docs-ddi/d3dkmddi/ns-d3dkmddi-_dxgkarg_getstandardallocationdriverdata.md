# DXGKARG_GETSTANDARDALLOCATIONDRIVERDATA structure

## Description

The **DXGKARG_GETSTANDARDALLOCATIONDRIVERDATA** structure describes a standard allocation type.

## Members

### `StandardAllocationType`

[in] A [**D3DKMDT_STANDARDALLOCATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_standardallocation_type)-typed value that identifies the type of standard allocation to describe.

### `pCreateSharedPrimarySurfaceData`

[in] A pointer to a [**D3DKMDT_SHAREDPRIMARYSURFACEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_sharedprimarysurfacedata) structure, if **StandardAllocationType** specifies D3DKMDT_STANDARDALLOCATION_SHAREDPRIMARYSURFACE.

### `pCreateShadowSurfaceData`

[in] A pointer to a [**D3DKMDT_SHADOWSURFACEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_shadowsurfacedata) structure, if **StandardAllocationType** specifies D3DKMDT_STANDARDALLOCATION_SHADOWSURFACE.

### `pCreateStagingSurfaceData`

[in] A pointer to a [**D3DKMDT_STAGINGSURFACEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_stagingsurfacedata) structure, if **StandardAllocationType** specifies D3DKMDT_STANDARDALLOCATION_STAGINGSURFACE.

### `pCreateGdiSurfaceData`

[in] A pointer to a [**D3DKMDT_GDISURFACEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_gdisurfacedata) structure, only available if **StandardAllocationType** specifies D3DKMDT_STANDARDALLOCATION_GDISURFACE.

This member is available beginning with Windows 7.

### `pCreateVirtualGpuSurfaceData`

Pointer to a [**D3DKMDT_VIRTUALGPUSURFACEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-d3dkmdt_virtualgpusurfacedata) structure if **StandardAllocationType** is **D3DKMDT_STANDARDALLOCATION_VIRTUALGPUSURFACE**. Available starting in WDDM 2.1.

### `pCreateFenceStorageData`

Pointer to a [**D3DKMDT_FENCESTORAGESURFACEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-d3dkmdt_fencestoragesurfacedata) structure if **StandardAllocationType** is **D3DKMDT_STANDARDALLOCATION_FENCESTORAGE**. Available starting in WDDM 3.2.

### `pAllocationPrivateDriverData`

[in/out] A pointer to a block of allocation private data that describes the standard allocation type; otherwise, this member is NULL. The allocation private data that the display miniport driver's (KMD's) [**DxgkDdiGetStandardAllocationDriverData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getstandardallocationdriverdata) function returns depends on the type that the driver requests in **StandardAllocationType**.

### `AllocationPrivateDriverDataSize`

[out] The size, in bytes, of the allocation private data that **pAllocationPrivateDriverData** points to. If the driver sets **pAllocationPrivateDriverData** to NULL, the driver should set **AllocationPrivateDriverDataSize** to the size of the buffer that the driver requires to describe the given standard allocation type.

If the driver doesn't use private data for each allocation for standard allocations types, the driver can set **AllocationPrivateDriverDataSize** to zero.

### `pResourcePrivateDriverData`

[in/out] A pointer to a block of resource private data that describes the standard allocation type; otherwise, this member is NULL. The resource private data that the display miniport driver's [**DxgkDdiGetStandardAllocationDriverData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getstandardallocationdriverdata) function returns depends on the type that the driver requests in **StandardAllocationType**.

### `ResourcePrivateDriverDataSize`

[out] The size, in bytes, of the resource private data that **pResourcePrivateDriverData** points to. If the driver sets **pResourcePrivateDriverData** to NULL, the driver should set **ResourcePrivateDriverDataSize** to the size of the buffer that the driver requires to describe the given standard allocation type.

If the driver does not use private data for each resource for standard allocations types, the driver can set **ResourcePrivateDriverDataSize** to zero.

### `PhysicalAdapterIndex`

[in] The physical adapter index in an LDA configuration where the storage will be resident.

## Remarks

*Standard allocation types* are allocations that must be created in kernel mode without communication from the user-mode display driver.

If the kernel-mode display miniport driver (KMD) returns NULL in the **pAllocationPrivateDriverData** and **pResourcePrivateDriverData** member, it should return the sizes of the buffers that it requires in the **AllocationPrivateDriverDataSize** and **ResourcePrivateDriverDataSize** members. However, the KMD shouldn't change the contents of the standard allocation structure in the union that **DXGKARG_GETSTANDARDALLOCATIONDRIVERDATA** contains to obtain the required sizes of the buffers.

Although KMD can set **ResourcePrivateDriverDataSize** or **AllocationPrivateDriverDataSize** to zero, it can't set both to zero.

## See also

[**D3DKMDT_GDISURFACEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_gdisurfacedata)

[**D3DKMDT_SHADOWSURFACEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_shadowsurfacedata)

[**D3DKMDT_SHAREDPRIMARYSURFACEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_sharedprimarysurfacedata)

[**D3DKMDT_STAGINGSURFACEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_stagingsurfacedata)

[**D3DKMDT_STANDARDALLOCATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_standardallocation_type)

[**D3DKMDT_VIRTUALGPUSURFACEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-d3dkmdt_virtualgpusurfacedata)

[**DxgkDdiGetStandardAllocationDriverData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getstandardallocationdriverdata)