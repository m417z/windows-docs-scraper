# DXGKCB_AGP_FREE_POOL callback function

## Description

The **DXGKCB_AGP_FREE_POOL** callback function frees AGP memory that was previously allocated by [**AgpAllocatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_agp_allocate_pool).

## Parameters

### `Context` [in]

A handle to a context block that is associated with an AGP interface. The display miniport driver previously received this handle in the **Context** member of the DXGK_AGP_INTERFACE structure that was filled in by [**DxgkCbQueryServices**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_query_services).

### `VirtualAddress` [in]

The base virtual address of the AGP allocation that is to be freed. This is the virtual address that was previously returned in the **VirtualAddress** output parameter of the [**AgpAllocatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_agp_allocate_pool) function.

## Return value

**AgpFreePool** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

None.

## See also

[**AgpAllocatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_agp_allocate_pool)

[**AgpSetCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_agp_set_command)

[**DXGK_AGP_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_agp_interface)

[**DxgkCbQueryServices**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_query_services)