# DXGKCB_UNMAP_MEMORY callback function

## Description

The **DxgkCbUnmapMemory** function unmaps a range of addresses previously mapped by [DxgkCbMapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_map_memory).

## Parameters

### `DeviceHandle` [in]

A handle that represents a display adapter. The display miniport driver previously obtained this handle in the **DeviceHandle** member of the [DXGKRNL_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

### `VirtualAddress` [in]

The beginning address of the range to be unmapped. This address can be a virtual address in system space, a virtual address in the address space of a user-mode process, or an address in I/O space.

## Return value

**DxgkCbUnmapMemory** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## See also

[DxgkCbMapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_map_memory)