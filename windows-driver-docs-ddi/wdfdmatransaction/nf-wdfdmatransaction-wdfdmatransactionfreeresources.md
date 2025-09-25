# WdfDmaTransactionFreeResources function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionFreeResources** method releases DMA resources that the driver previously allocated by calling [WdfDmaTransactionAllocateResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionallocateresources).

## Parameters

### `DmaTransaction` [in]

A handle to the DMA transaction object that the driver provided in a previous call to [WdfDmaTransactionAllocateResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionallocateresources).

## Remarks

**WdfDmaTransactionFreeResources** must be used with a DMA enabler that specifies a packet or system profile.

On operating systems earlier than Windows 8, **WdfDmaTransactionFreeResources** must be used with an enabler that specifies a single-packet DMA enabler. Starting with Windows 8, **WdfDmaTransactionFreeResources** can also be used with an enabler that specifies a system-mode DMA enabler.

 When called with a scatter/gather DMA enabler, **WdfDmaTransactionFreeResources** causes a verifier bug check.

The driver's call to **WdfDmaTransactionFreeResources** may cause the framework to call [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma) or [EvtReserveDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_reserve_dma) immediately.

For more information about system-mode DMA, see [Supporting System-Mode DMA](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-system-mode-dma).

## See also

[WdfDmaTransactionAllocateResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionallocateresources)