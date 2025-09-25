# D3DKMTMapGpuVirtualAddress function

## Description

**D3DKMTMapGpuVirtualAddress** maps a GPU virtual address range to a specific allocation range or puts it to the [*Invalid* or *Zero*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddigpuvirtualaddress_protection_type) state.

## Parameters

### `unnamedParam1`

[in/out] **pData** is a pointer to a [**D3DDDI_MAPGPUVIRTUALADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_mapgpuvirtualaddress) structure that describes the operation.

## Return value

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The device context was successfully created.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other **NTSTATUS** values.

## Remarks

The driver can specify a base GPU virtual address (VA) to map or let the video memory manager automatically pick one. When specifying a non-NULL **BaseAddress** value, the entire range from **BaseAddress** to **BaseAddress**+**Size** must be in a freed state or belong to a VA range that was obtained by calling **D3DKMTMapGpuVirtualAddress** or [**DxgkCbReserveGpuVirtualAddressRange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_reservegpuvirtualaddressrange). When **Protection.Zero** or **Protection.NoAccess** is specified, the VA range can't belong to a range that was obtained by calling [**MapGpuVirtualAddressCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pfnd3dkmt_mapgpuvirtualaddress).

The driver can specify whether the mapping should allow for write and execute privileges in addition to read privileges, which always exist by default.

In the linked display adapter (LDA) configuration, the paging queue defines a physical GPU whose page tables are modified, and the allocation handle (if not NULL) defines where the page table entries are pointing to. The allocation can be resident in any physical GPU memory segment.

The GPU VA range, which is allocated by the API, is freed when the allocation (the GPU VA is mapped to) is destroyed. The VA range can also be freed by calling [**D3DKMTFreeGpuVirtualAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtfreegpuvirtualaddress), but this needs to be synchronized with allocation destruction if necessary.

## See also

[**DxgkCbReserveGpuVirtualAddressRange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_reservegpuvirtualaddressrange)