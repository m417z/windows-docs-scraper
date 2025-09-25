# WdfDmaTransactionInitializeUsingOffset function

## Description

[Applies to KMDF only]

The
**WdfDmaTransactionInitializeUsingOffset** method initializes a specified DMA transaction by using a byte offset into an MDL chain.

## Parameters

### `DmaTransaction` [in]

A handle to a DMA transaction object that the driver obtained from a previous call to [WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate).

### `EvtProgramDmaFunction` [in]

A pointer to the driver's [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma) event callback function.

### `DmaDirection` [in]

A [WDF_DMA_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_direction)-typed value.

### `Mdl` [in]

A pointer to a memory descriptor list (MDL) that describes the buffer that will be used for the DMA transaction. See more information in **Remarks**.

### `Offset` [in]

The byte offset into the MDL chain for the current transaction.

### `Length` [in]

The number of bytes to be transferred. This value must be greater than zero.

## Return value

**WdfDmaTransactionInitializeUsingOffset** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the values described in the Return values section of [WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

**WdfDmaTransactionInitializeUsingOffset** is equivalent to [WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize) except that it takes an offset into the buffer described by the MDL chain rather than a virtual address.

The driver can specify an MDL chain in the *Mdl* parameter of this method. An MDL chain is a sequence of MDL structures that the driver chained together using the **Next** member of the MDL structure.

## See also

[WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize)