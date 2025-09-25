# WdfDmaTransactionInitializeUsingRequest function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionInitializeUsingRequest** method initializes a specified DMA transaction by using the parameters of a specified I/O request.

## Parameters

### `DmaTransaction` [in]

A handle to a DMA transaction object that the driver obtained from a previous call to [WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate).

### `Request` [in]

A handle to a framework request object.

### `EvtProgramDmaFunction` [in]

A pointer to the driver's [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma) event callback function.

### `DmaDirection` [in]

A [WDF_DMA_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_direction)-typed value that specifies the direction of the DMA transfer.

## Return value

**WdfDmaTransactionInitializeUsingRequest** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the values described in the Return values section of [WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfDmaTransactionInitializeUsingRequest** method prepares a DMA operation for execution, by performing initialization operations such as setting up a transaction's scatter/gather list. After your driver calls **WdfDmaTransactionInitializeUsingRequest**, the driver must call [WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute).

The driver can call [WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters) to obtain a request's type. The value that the driver specifies for the *DmaDirection* parameter must be appropriate for the request type, as follows:

* The *DmaDirection* value must be **WdfDmaDirectionReadFromDevice** if:
  + The request type is **WdfRequestTypeRead**
  + The request type is **WdfRequestTypeDeviceControl** or **WdfRequestTypeDeviceControlInternal** and the I/O control code specifies a transfer type of METHOD_OUT_DIRECT
* The *DmaDirection* value must be **WdfDmaDirectionWriteToDevice** if:

  + The request type is **WdfRequestTypeWrite**
  + The request type is **WdfRequestTypeDeviceControl** or **WdfRequestTypeDeviceControlInternal** and the I/O control code specifies a transfer type of METHOD_IN_DIRECT

For more information about transfer types for I/O control codes, see [Defining I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/defining-i-o-control-codes).

Framework-based drivers typically call **WdfDmaTransactionInitializeUsingRequest** from within an [I/O queue event callback function](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers).

Your driver should call **WdfDmaTransactionInitializeUsingRequest** if you are creating a DMA transaction that is based on information that a framework request object contains. Use [WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize) if you are creating a DMA transaction that is not based on a request object.

If the buffer that the request object describes is larger than the maximum transfer length that your driver specified when it called [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate) or [WdfDmaTransactionSetMaximumLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsetmaximumlength), the framework breaks the transaction into multiple [transfers](https://learn.microsoft.com/windows-hardware/drivers/wdf/dma-transactions-and-dma-transfers).

For more information about DMA transactions, see [Creating and Initializing a DMA Transaction](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-and-initializing-a-dma-transaction).

#### Examples

For a code example that uses **WdfDmaTransactionInitializeUsingRequest**, see [WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute).

## See also

[EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma)

[WDF_DMA_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_direction)

[WdfDmaEnablerSetMaximumScatterGatherElements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablersetmaximumscattergatherelements)

[WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate)

[WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute)

[WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize)