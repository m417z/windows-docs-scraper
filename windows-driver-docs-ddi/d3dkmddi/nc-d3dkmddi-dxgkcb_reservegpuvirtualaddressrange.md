# DXGKCB_RESERVEGPUVIRTUALADDRESSRANGE callback function

## Description

A kernel-mode display miniport driver can call **DXGKCB_RESERVEGPUVIRTUALADDRESSRANGE** to reserve a graphics processing unit (GPU) virtual address range during creation of a process.

## Parameters

### `hAdapter` [in]

A handle to the display adapter.

### `pArgs` [in/out]

A [**DXGKARGCB_RESERVEGPUVIRTUALADDRESSRANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_reservegpuvirtualaddressrange) structure that describes the operation.

## Return value

**DXGKCB_RESERVEGPUVIRTUALADDRESSRANGE** returns **STATUS_SUCCESS** if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

Reserving the GPU virtual address range is only possible during process creation (i.e. within the call to [**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess)) and is invalid at any other time.

Reservation is possible on both a regular process as well as the system process where the system device and context lives.

The first entry in the root page table (page table entry index 0) will always be initialized as invalid by the video memory manager and the driver reservations will start from page table entry index 1. Driver reservation must always be an exact multiple of virtual address space, covered by leaf page table, as the specific page table entry can’t be shared between the video memory manager and the kernel-mode driver. Page table entries reserved by the driver will be initialized as *invalid* by the video memory manager and may be overwritten by the driver to reference an internally allocated page table managed by the driver. The video memory manager will update the reserved page table entries as invalid every time the corresponding page table becomes resident.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the appropriate members of [**DXGKARGCB_RESERVEGPUVIRTUALADDRESSRANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_reservegpuvirtualaddressrange) and then call **DxgkCbReserveGpuVirtualAddressRange** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_RESERVEGPUVIRTUALADDRESSRANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_reservegpuvirtualaddressrange)

[**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)