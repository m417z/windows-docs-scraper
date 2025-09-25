# _DXGK_GENERAL_ERROR_CODE enumeration

## Description

The **DXGK_GENERAL_ERROR_CODE** enumeration specifies a set of predefined graphics processing unit (GPU) errors reported via a page fault interrupt.

## Constants

### `DXGK_GENERAL_ERROR_PAGE_FAULT`

Indicates that the GPU encountered a page fault. The **FaultedVirtualAddress** and **PageTableLevel** members of the [DXGKARGCB_NOTIFY_INTERRUPT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data) structure should be used to provide further information about the GPU virtual address operation that caused the fault.

### `DXGK_GENERAL_ERROR_INVALID_INSTRUCTION`

Indicates that the GPU encountered an invalid instruction in the DMA command buffer.

## See also

[DXGKARGCB_NOTIFY_INTERRUPT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data)