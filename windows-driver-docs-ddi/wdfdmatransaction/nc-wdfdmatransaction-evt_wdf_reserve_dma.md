# EVT_WDF_RESERVE_DMA callback function

## Description

[Applies to KMDF only]

 The
*EvtReserveDma* event callback function is called when the framework has reserved resources to execute and release a transaction. Reserved resources include map registers and the WDM DMA adapter's lock.

## Parameters

### `DmaTransaction` [in]

A handle to the DMA transaction object that represents the transaction to which DMA resources were assigned.

### `Context` [in]

The context pointer that the driver specified in a previous call to [WdfDmaTransactionAllocateResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionallocateresources).

## Remarks

Drivers register an *EvtReserveDma* event callback function by calling [WdfDmaTransactionAllocateResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionallocateresources).

The framework calls a driver's *EvtReserveDma* event callback function when DMA resources have been assigned for exclusive use with the associated transaction object. The driver can initialize and execute the transaction multiple times while holding this reservation.

A driver typically initializes and then initiates the transaction from within its *EvtReserveDma* event callback function. For more information about the reservation sequence, see [Reserving DMA Resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/reserving-dma-resources).

The driver may call [WdfDmaTransactionFreeResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionfreeresources) from within *EvtReserveDma*.

On operating systems earlier than Windows 8, *EvtReserveDma* must be used with an enabler that specifies a packet-mode DMA enabler. Starting with Windows 8, *EvtReserveDma* can also be used with an enabler that specifies a system-mode DMA enabler.

## See also

[WdfDmaTransactionAllocateResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionallocateresources)

[WdfDmaTransactionFreeResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionfreeresources)