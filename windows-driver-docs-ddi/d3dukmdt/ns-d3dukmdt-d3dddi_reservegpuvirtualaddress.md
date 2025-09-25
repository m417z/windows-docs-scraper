# D3DDDI_RESERVEGPUVIRTUALADDRESS structure

## Description

The user-mode graphics driver passes **D3DDDI_RESERVEGPUVIRTUALADDRESS** to the D3D runtime's [**pfnReserveGpuVirtualAddressCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reservegpuvirtualaddresscb) callback to reserve an address range in the GPU virtual address space of the current process.

## Members

### `hPagingQueue`

This member is obsolete. Don't use it.

### `hAdapter`

[in] DirectX graphics adapter handle or zero (0). If UMD sets **hAdapter** set to 0, the D3D runtime will set **hAdapter** to the kernel's D3DKMT_HANDLE before calling the [**D3DKMTReserveGpuVirtualAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtreservegpuvirtualaddress) kernel interface.

### `BaseAddress`

[in/optional] The number of bytes to reserve in the GPU virtual address space. **BaseAddress** must be aligned to a 64KB boundary.

If **BaseAddress** is non-NULL, the video memory manager attempts to use this address as the base address for the reserved range. If the range from **BaseAddress** to **BaseAddress**+**Size** isn’t free, the call fails. When **BaseAddress** is non-NULL, **MinimumAddress** and **MaximumAddress** are ignored.

If NULL is specified the video memory manager picks the base address for the allocation within the specified **MinimumAddress** and **MaximumAddress**.

### `MinimumAddress`

[in/optional] The minimum GPU virtual address to consider for the reserved range. **MinimumAddress** is in bytes and must be aligned to 64KB boundary. It's ignored when **BaseAddress** is non-NULL.

### `MaximumAddress`

[in/optional] The maximum GPU virtual address to consider for the reserved range. The video memory manager guarantees that **BaseAddress**+**Size** <= **MaximumAddress**. If **MaximumAddress** is set to NULL the video memory manager will not apply any limit.

**MaximumAddress** is in bytes and must be aligned to 64KB boundary. It's ignored when **BaseAddress** is non-NULL.

### `Size`

[in] The size of the range to reserve, in bytes. Must be a multiple of 64KB.

### `ReservationType`

This member is obsolete. Don't use it.

### `Reserved0`

This member is reserved and should be set to zero.

### `DriverProtection`

This member is obsolete. Don't use it.

### `Reserved1`

This member is reserved and should be set to zero.

### `VirtualAddress`

[out] The reserved virtual address.

### `PagingFenceValue`

This member is obsolete. Don't use it.

### `Reserved2`

This member is reserved and should be set to zero.

## See also

[**pfnReserveGpuVirtualAddressCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reservegpuvirtualaddresscb)