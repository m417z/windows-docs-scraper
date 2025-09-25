# D3DDDI_MAPGPUVIRTUALADDRESS structure

## Description

The **D3DDDI_MAPGPUVIRTUALADDRESS** structure is used with [**pfnMapGpuVirtualAddressCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_mapgpuvirtualaddresscb) to map a GPU virtual address range to a specific allocation range or to put it to the [*Invalid* or *Zero*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddigpuvirtualaddress_protection_type) state.

## Members

### `hPagingQueue`

A handle for the device paging queue, used for the operation.

### `BaseAddress`

(Optional) If non-NULL, the video memory manager will attempt to use this address as the base address for the mapping. If the range from **BaseAddress** to **BaseAddress**+**Size** isn’t free, it must belong to a range, previously obtained by calling [**pfnReserveGpuVirtualAddressCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reservegpuvirtualaddresscb) or [**pfnMapGpuVirtualAddressCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_mapgpuvirtualaddresscb).

The **BaseAddress** value is in bytes and must be aligned to CPU page boundary.
If NULL is specified, the video memory manager will pick the base address for the allocation within the specified **MinimumAddress** and **MaximumAddress**.

### `MinimumAddress`

(Optional) Specifies the minimum GPU virtual address to consider for the mapped range.

The **MinimumAddress** value is in bytes and must be aligned to 4KB page. This parameter is ignored when **BaseAddress** != NULL.

### `MaximumAddress`

(Optional) Specifies the maximum GPU virtual address to consider for the mapped range. the video memory manager will guarantee that **BaseAddress**+**Size** <= **MaximumAddress**. If **MaximumAddress** is set to NULL the video memory manager will not apply any limit.

The **MaximumAddress** value is in bytes and must be aligned to the 4KB page. This parameter is ignored when **BaseAddress** != NULL.

### `hAllocation`

Handle to the allocation being mapped into the GPU virtual address space. Must be NULL when **Protection.NoAccess** or **Protection.Zero** is specified.

### `OffsetInPages`

Specifies the offset, in 4KB, to the starting page within the specified allocation that must be mapped.

### `SizeInPages`

Specifies the size of the range to map, in 4KB pages.

### `Protection`

A [**D3DDDIGPUVIRTUALADDRESS_PROTECTION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddigpuvirtualaddress_protection_type) structure that specifies the protection on the GPU virtual address that is mapped.

### `DriverProtection`

Specifies a driver-specific, 64-bit protection value associated with the VA range being allocated. The specified driver protection will be used in call to [**DxgkDdiUpdatePageTable**](https://learn.microsoft.com/windows-hardware/drivers/display/dxgkddiupdatepagetable) for page table entries corresponding to this virtual address range.

### `Reserved0`

This member is reserved and should be set to zero.

### `Reserved1`

This member is reserved and should be set to zero.

### `VirtualAddress`

The virtual address assigned to the allocation.

### `PagingFenceValue`

The device paging fence value that the video memory manager signals when the map operation completes on the GPU. The user-mode driver must ensure that this fence is retired or explicitly wait on either the CPU or the GPU on that fence before allowing the GPU to access the mapped range or an unrecoverable fault might occur.
A zero fence value might be returned, meaning that the operation is already completed.

## See also

[**D3DDDIGPUVIRTUALADDRESS_PROTECTION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddigpuvirtualaddress_protection_type)

[**D3DKMTMapGpuVirtualAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtmapgpuvirtualaddress)

[**DxgkDdiUpdatePageTable**](https://learn.microsoft.com/windows-hardware/drivers/display/dxgkddiupdatepagetable)

[**pfnMapGpuVirtualAddressCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_mapgpuvirtualaddresscb)

[**pfnReserveGpuVirtualAddressCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reservegpuvirtualaddresscb)