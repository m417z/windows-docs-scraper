# DXGKCB_AGP_ALLOCATE_POOL callback function

## Description

The **DXGKCB_AGP_ALLOCATE_POOL** callback function reserves, commits, and maps Accelerated Graphics Port (AGP) memory.

## Parameters

### `Context` [in]

A handle to a context block associated with an AGP interface. The display miniport driver previously received this handle in the **Context** member of the DXGK_AGP_INTERFACE structure that was filled in by [**DxgkCbQueryServices**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_query_services).

### `AllocationSize` [in]

The size, in bytes, of the AGP memory to be allocated.

### `CacheType` [in]

A constant from the [**MEMORY_CACHING_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type) enumeration that specifies whether the CPU can use caching or write combining when it accesses the allocated AGP memory.

### `PhysicalAddress` [out]

A pointer to a PHYSICAL_ADDRESS structure that receives the base physical address of the AGP allocation. This is the base of the physical address range that the GPU will use to access the AGP memory.

### `VirtualAddress` [out]

A pointer to a variable that receives the base virtual address, in system space, of the AGP allocation. This is the base of the virtual address range that the CPU will use to access the AGP memory.

## Return value

**AgpAllocatePool** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

Call **AgpAllocatePool** in the display miniport driver's [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function. It is likely that **AgpAllocatePool** will fail if you call it after **DxgkDdiStartDevice** has executed.

## See also

[**AgpFreePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_agp_free_pool)

[**AgpSetCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_agp_set_command)

[**DXGK_AGP_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_agp_interface)

[**DxgkCbQueryServices**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_query_services)