# _DXGK_PAGE_FAULT_FLAGS enumeration

## Description

**DXGK_PAGE_FAULT_FLAGS** enumeration describes the nature of the page fault that has occurred and the prescribed OS recovery action.

## Constants

### `DXGK_PAGE_FAULT_WRITE`

When set, this indicates that the faulted GPU virtual operation was a write operation.

### `DXGK_PAGE_FAULT_FENCE_INVALID`

When set, this indicates that a faulting packet could not be determined. In this case, the OS will have to perform a GPU reset action to clear the GPU error state, and one of the subsequent bits will have to be set.

When not set, this indicates that the DMA packet submitted with **FaultedFenceId** (in the [DXGKARGCB_NOTIFY_INTERRUPT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data) structure) was the cause of the fault. Similar to how the preemption and completion fences are handled, the OS will treat all pending packets with fence IDs less than **FaultedFenceId** as completed, and the driver will be required to advance its notion of the completed fence ID to **FaultedFenceId**.

### `DXGK_PAGE_FAULT_ADAPTER_RESET_REQUIRED`

When set, this indicates that the fault put the GPU into a state that requires a full adapter reset.

### `DXGK_PAGE_FAULT_ENGINE_RESET_REQUIRED`

When set, this indicates that the fault put the GPU into a state that requires a GPU engine reset.

### `DXGK_PAGE_FAULT_FATAL_HARDWARE_ERROR`

When set, this indicates that the system hardware, not just the GPU, cannot continue, and the OS should issue a bugcheck.

### `DXGK_PAGE_FAULT_IOMMU`

When set, this indicates that the faulting GPU's virtual address was mapped using IoMmu. When not set, the faulting GPU's virtual address was mapped using the GPU's memory management unit.

### `DXGK_PAGE_FAULT_HW_CONTEXT_VALID`

### `DXGK_PAGE_FAULT_PROCESS_HANDLE_VALID`

## See also

[DXGKARGCB_NOTIFY_INTERRUPT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data)