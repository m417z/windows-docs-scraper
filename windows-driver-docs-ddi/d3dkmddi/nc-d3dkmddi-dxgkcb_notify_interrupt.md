# DXGKCB_NOTIFY_INTERRUPT callback function

## Description

A kernel-mode display miniport driver calls **DXGKCB_NOTIFY_INTERRUPT** to inform the graphics processing unit (GPU) scheduler about a graphics hardware update at interrupt service routine (ISR) time.

## Parameters

### `hAdapter` [in]

A handle to the adapter object for the GPU. A driver receives the handle from the **DeviceHandle** member of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure in a call to its [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `unnamedParam2` [in]

Pointer to a [**DXGKARGCB_NOTIFY_INTERRUPT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data) structure that contains notification information for an interrupt.

## Remarks

A display miniport driver calls the **DXGKCB_NOTIFY_INTERRUPT** function to report a graphics hardware interrupt that the [**DXGK_INTERRUPT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_type) enumeration type defines.

Typically, **DXGKCB_NOTIFY_INTERRUPT** is called from the display miniport driver's [**DxgkDdiInterruptRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_interrupt_routine) function (ISR), which is called when graphics hardware interrupts occur. **DXGKCB_NOTIFY_INTERRUPT** informs the GPU scheduler about an update to a fence through a direct memory access (DMA) stream to the graphics hardware.

If the display miniport driver uses multiple interrupt handlers that correspond to multiple IRQLs, the driver must not call **DXGKCB_NOTIFY_INTERRUPT** in a reentrant fashion. Therefore, in this case, the display miniport driver should always call **DXGKCB_NOTIFY_INTERRUPT** from a fixed level of the interrupt handler.

Similarly, if message-signaled interrupts are used, the display miniport driver can call **DXGKCB_NOTIFY_INTERRUPT** from an interrupt handler that corresponds to a fixed message number. The driver must report the message number that is used for notification in the **InterruptMessageNumber** member of the [**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps) structure, when the **DXGKQAITYPE_DRIVERCAPS** enumeration value is specified in the **Type** member of the [**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo) structure in a call to the driver's [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function.

After the display miniport driver calls **DXGKCB_NOTIFY_INTERRUPT** but before the driver exits its ISR, the driver must queue a deferred procedure call (DPC) by using the [**DxgkCbQueueDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_queue_dpc) function. This DPC must be queued because the GPU scheduler must also be notified, when the driver's DPC callback routine calls the [**DXGKCB_NOTIFY_DPC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_dpc) function, about the same event at DPC time. A certain amount of processing that is related to graphics hardware events can be only performed by the operating system at DPC time.

If the display miniport driver determines that more than one interrupt was triggered in hardware and the driver must call **DXGKCB_NOTIFY_INTERRUPT** for each interrupt to report the interrupt to the operating system, the driver should report DMA-type interrupts before a CRTC-type interrupt. For more information about interrupt types, see [**DXGK_INTERRUPT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_type).

Callers of **DXGKCB_NOTIFY_INTERRUPT** run at interrupt level (that is, DIRQL, which is some IRQL between DISPATCH_LEVEL and PROFILE_LEVEL, not inclusive).

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, call **DxgkCbNotifyInterrupt** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

### Examples

The following code example shows software engine code that monitors a software queue and notifies the GPU scheduler about packet completion.

```cpp
typedef struct _SubmitParams {
    HW_DEVICE_EXTENSION *pHwDeviceExtension;
    UINT                NodeOrdinal;
    UINT                FenceID;
    UINT                PreemptionFenceID;
} SubmitParams;

BOOLEAN R200TEST_SWNode_SynchronizeVidSchNotifyInt(PVOID* params)
{
    SubmitParams  *pSchNotifyParams = (SubmitParams*)params;
    DXGKCB_NOTIFY_INTERRUPT  DxgkCbNotifyInterrupt;
    DXGKARGCB_NOTIFY_INTERRUPT_DATA  notifyInt = {0};

    DxgkCbNotifyInterrupt = (DXGKCB_NOTIFY_INTERRUPT)pSchNotifyParams->pHwDeviceExtension->pVidSchINTCB;

    if(!DxgkCbNotifyInterrupt) {
        return FALSE;
    }

    if(pSchNotifyParams->PreemptionFenceID) {
        notifyInt.InterruptType = DXGK_INTERRUPT_DMA_PREEMPTED;
        notifyInt.DmaPreempted.PreemptionFenceId = pSchNotifyParams->PreemptionFenceID;
        notifyInt.DmaPreempted.LastCompletedFenceId = pSchNotifyParams->FenceID;
        notifyInt.DmaPreempted.NodeOrdinal = pSchNotifyParams->NodeOrdinal;
    }
    else {
        notifyInt.InterruptType = DXGK_INTERRUPT_DMA_COMPLETED;
        notifyInt.DmaCompleted.SubmissionFenceId = pSchNotifyParams->FenceID;
        notifyInt.DmaCompleted.NodeOrdinal = pSchNotifyParams->NodeOrdinal;
    }

    DxgkCbNotifyInterrupt(pSchNotifyParams->pHwDeviceExtension->DeviceHandle, &notifyInt);

    pSchNotifyParams->pHwDeviceExtension->PrevSubmitFenceIDArray[pSchNotifyParams->NodeOrdinal] = pSchNotifyParams->FenceID;

    if(pSchNotifyParams->PreemptionFenceID) {
        pSchNotifyParams->pHwDeviceExtension->PrevPreemptFenceIDArray[pSchNotifyParams->NodeOrdinal] = pSchNotifyParams->PreemptionFenceID;
    }

    return TRUE;
}
```

## See also

[**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[**DXGKARGCB_NOTIFY_INTERRUPT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data)

[**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)

[**DXGK_INTERRUPT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_type)

[**DXGKCB_NOTIFY_DPC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_dpc)

[**DxgkCbQueueDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_queue_dpc)

[**DxgkDdiInterruptRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_interrupt_routine)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)