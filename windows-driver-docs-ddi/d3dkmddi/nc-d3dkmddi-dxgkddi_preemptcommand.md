# DXGKDDI_PREEMPTCOMMAND callback function

## Description

The *DxgkDdiPreemptCommand* function preempts a direct memory access (DMA) buffer that was previously submitted to and currently queued in the hardware command execution unit.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pPreemptCommand` [in]

A pointer to a [DXGKARG_PREEMPTCOMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_preemptcommand) structure that describes the command that is used to preempt a DMA buffer previously submitted to the hardware command execution unit.

## Return value

 Returns **STATUS_SUCCESS** upon successful completion. If the driver instead returns an error code, the operating system causes a system bugcheck to occur. For more information, see the following Remarks section.

## Remarks

If the driver determines that the hardware is already finished processing all of the submitted DMA buffers--and that the hardware informed the graphics processing unit (GPU) scheduler about the completions--when its *DxgkDdiPreemptCommand* function is called to preempt the DMA buffers, the driver should perform the following operations instead of submitting the preempt fence that is identified by the **PreemptionFenceId** member of [DXGKARG_PREEMPTCOMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_preemptcommand) to the hardware:

* Raise IRQL to interrupt level. For example, the driver can call the [DxgkCbSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_synchronize_execution) function to synchronize with its [DxgkDdiInterruptRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_interrupt_routine) function.
* Inform the GPU scheduler about the preemption information. The driver can either call the [DxgkCbNotifyInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt) function directly or call its [DxgkDdiInterruptRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_interrupt_routine) function (for example, if the driver must perform other updates as well).

  Note that the GPU scheduler handles instances where the hardware has stopped responding because of Timeout Detection and Recovery (TDR) work.

If the driver returns an error code, the Microsoft DirectX graphics kernel subsystem causes a system bugcheck to occur. In a crash dump file, the error is noted by the message **BugCheck 0x119**, which has the following four parameters.

1. 0x2
2. The NTSTATUS error code returned from the failed driver call
3. A pointer to the [DXGKARG_PREEMPTCOMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_preemptcommand) structure
4. A pointer to an internal scheduler data structure

*DxgkDdiPreemptCommand* should be made nonpageable because it runs at IRQL = DISPATCH_LEVEL

## See also

[DXGKARG_PREEMPTCOMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_preemptcommand)

[DxgkCbNotifyInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt)

[DxgkCbSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_synchronize_execution)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiInterruptRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_interrupt_routine)