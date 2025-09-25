# PFND3DDDI_MAPGPUVIRTUALADDRESSCB callback function

## Description

**pfnMapGpuVirtualAddressCb** maps GPU virtual address (VA) ranges to a specific allocation range or puts it to the [*Invalid* or *Zero*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddigpuvirtualaddress_protection_type) state.

## Parameters

### `hDevice`

A handle to the display device.

### `unnamedParam2`

[in/out] **pDate** is a pointer to a [**D3DDDI_MAPGPUVIRTUALADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_mapgpuvirtualaddress) structure that describes the operation to perform.

## Return value

**pfnMapGpuVirtualAddressCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The operation completed successfully.|
|E_PENDING|The call was successful, but the operation is not finished. The caller must wait for the returned fence value before accessing the allocation.|

This function might also return other values.

## Remarks

The user-mode driver can specify a base GPU virtual address (VA) to map or let the video memory manager automatically pick one. When specifying a non-NULL **BaseAddress** value, the entire range from **BaseAddress** to **BaseAddress**+**Size** must be in a freed state or belong to a VA range that was obtained by calling **pfnMapGpuVirtualAddressCb** or [**pfnReserveGpuVirtualAddressCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reservegpuvirtualaddresscb). When **Protection.Zero** or **Protection.NoAccess** is specified, the VA range can't belong to a range that was obtained by calling **pfnMapGpuVirtualAddressCb**.

The user-mode driver can specify whether the mapping should allow for write and execute privileges in addition to read privileges, which always exist by default.

In linked display adapter (LDA) configuration, the paging queue defines a physical GPU whose page tables are modified, and the allocation handle (if not NULL) defines where the page table entries are pointing to. The allocation can be resident in any physical GPU memory segment.

The GPU VA range, which is allocated by the API, is freed when the allocation (the GPU VA is mapped to) is destroyed. The VA range can also be freed by calling [**PFND3DDDI_FREEGPUVIRTUALADDRESSCB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_freegpuvirtualaddresscb), but this needs to be synchronized with allocation destruction if necessary.

## See also

[**D3DDDI_MAPGPUVIRTUALADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_mapgpuvirtualaddress)

[**pfnReserveGpuVirtualAddressCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reservegpuvirtualaddresscb)