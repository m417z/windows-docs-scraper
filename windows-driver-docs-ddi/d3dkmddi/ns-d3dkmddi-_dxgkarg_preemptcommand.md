# _DXGKARG_PREEMPTCOMMAND structure

## Description

The DXGKARG_PREEMPTCOMMAND structure describes a command that a display miniport driver must use to preempt a direct memory access (DMA) buffer that the [DxgkDdiSubmitCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand) function previously submitted to the hardware command execution unit.

## Members

### `PreemptionFenceId` [in]

A unique identifier that the display miniport driver must patch into the fence command at the end of the DMA buffer to preempt the previously submitted DMA buffer. The display miniport driver uses the identifier in a call to the [DxgkCbNotifyDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_dpc) function to inform the graphics processing unit (GPU) scheduler about the preemption at deferred-procedure-call (DPC) time.

### `NodeOrdinal` [in]

The index of the node for the preemption request.

### `EngineOrdinal` [in]

The index of the engine for the preemption request.

### `Flags` [in]

A [DXGK_PREEMPTCOMMANDFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_preemptcommandflags) structure with a reserved member or a 32-bit value. No flags are currently defined for this structure.

## See also

[DXGK_PREEMPTCOMMANDFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_preemptcommandflags)

[DxgkCbNotifyDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_dpc)

[DxgkCbNotifyInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt)

[DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice)

[DxgkDdiPreemptCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_preemptcommand)

[DxgkDdiSubmitCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand)