# _D3DDDI_UPDATEGPUVIRTUALADDRESS_OPERATION structure

## Description

**D3DDDI_UPDATEGPUVIRTUALADDRESS_OPERATION** describes a virtual address update operation.

## Members

### `OperationType`

### `Map`

Maps the given virtual address range to the given allocation range. The allocation does not have to be resident at the time of submission or at the time of mapping. The read-write protection is set to the pages. **DriverProtection** for the pages is set to zero.

### `Map.BaseAddress`

Specifies the **BaseAddress** of the GPU virtual address range to update. The value is in bytes and must be 4KB aligned.

The entire range from **BaseAddress** to **BaseAddress**+**SizeInBytes** must be in the *reserved (zero)* or *mapped* state, or the [pfnUpdateGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updategpuvirtualaddresscb) operation will fail. The virtual address ranges for all operations must belong to a virtual address range which is reserved by the same [pfnReserveGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reservegpuvirtualaddresscb) call.

### `Map.SizeInBytes`

Specifies the size, in bytes, for the range being updated. The value must be 4KB aligned.

### `Map.hAllocation`

Specifies the allocation the range needs to be mapped to.

### `Map.AllocationOffsetInBytes`

Specifies the offset, in bytes, to the first page in the allocation to map. The value must be 4KB aligned.

### `Map.AllocationSizeInBytes`

Specifies the size of the allocation range to map, in bytes. The value must be 4KB aligned and must be less than **Map.SizeInBytes**. If this value is zero, **Map.SizeInBytes** is used.

When this value is than **Map.SizeInBytes**, **Map.SizeInBytes** must be a multiple of it. In this case **Map.SizeInBytes**/**Map.AllocationSizeInBytes** virtual address ranges will be mapped to the same allocation range.

### `MapProtect`

Maps the given virtual address range to the given allocation range. The allocation does not have to be resident at the time of submission or at the time of mapping. The page protection is specified in the operation.

### `MapProtect.BaseAddress`

Specifies the **BaseAddress** of the GPU virtual address range to update. The value is in bytes and must be 4KB aligned.

The entire range from **BaseAddress** to **BaseAddress**+**SizeInBytes** must be in the *reserved (zero)* or *mapped* state, or [pfnUpdateGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updategpuvirtualaddresscb) will fail. The virtual address ranges for all operations must belong to a virtual address range which is reserved by the same [pfnReserveGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reservegpuvirtualaddresscb) call.

### `MapProtect.SizeInBytes`

Specifies the size, in bytes, for the range being updated. The value must be 4KB aligned.

### `MapProtect.hAllocation`

Specifies the allocation the range needs to be mapped to.

### `MapProtect.AllocationOffsetInBytes`

Specifies the offset, in bytes, to the first page in the allocation to map. The value must be 4KB aligned.

### `MapProtect.AllocationSizeInBytes`

Specifies the size of the allocation range to map, in bytes. The value must be 4KB aligned and must be less than Map.**SizeInBytes**. If this value is zero, **Map.SizeInBytes** is used.

When this value is less than **Map.SizeInBytes**, **Map.SizeInBytes** must be a multiple of it. In this case **Map.SizeInBytes**/**Map.AllocationSizeInBytes** virtual address ranges will be mapped to the same allocation range.

### `MapProtect.Protection`

Specifies API defined protection for the pages.

### `MapProtect.DriverProtection`

Specifies driver specific protection for the pages.

### `Unmap`

Puts the specified virtual address range to the *zero* state or to the *invalid* state.

### `Unmap.BaseAddress`

Specifies the **BaseAddress** of the GPU virtual address range to put back into the *zero* state. The value is in bytes and must be 4KB aligned.

### `Unmap.SizeInBytes`

Specifies the size, in bytes, for the range to be freed. The value must be 4KB aligned.

### `Unmap.Protection`

Defines is the page table entry state after un-mapping, either *Zero* or *NoAccess*.

### `Copy`

The copy operation copies all mappings from source GPU virtual address range to the destination range. The source and destination ranges are allowed to intersect. Both ranges must belong to a reserved (zero) virtual address range.

#### BaseAddress

Specifies the start virtual address of the source virtual address range. The value is in bytes and must be 4KB aligned.

### `Copy.SourceAddress`

### `Copy.SizeInBytes`

Specifies the size, in bytes, for the range being copied. The value must be 4KB aligned.

### `Copy.DestAddress`

Specifies the start virtual address of the destination virtual address range. The value is in bytes and must be 4KB aligned.

## See also

[pfnReserveGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reservegpuvirtualaddresscb)

[pfnUpdateGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updategpuvirtualaddresscb)