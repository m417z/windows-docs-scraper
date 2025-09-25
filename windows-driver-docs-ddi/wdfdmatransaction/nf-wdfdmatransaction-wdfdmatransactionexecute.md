# WdfDmaTransactionExecute function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionExecute** method begins the execution of a specified DMA transaction.

## Parameters

### `DmaTransaction` [in]

A handle to a DMA transaction object that the driver obtained from a previous call to [WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate).

### `Context` [in, optional]

Driver-defined context information. The framework passes the value specified for *Context*, which can be a pointer, to the driver's [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma) event callback function. This parameter is optional and can be **NULL**.

## Return value

**WdfDmaTransactionExecute** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values.

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The driver previously called [WdfDmaTransactionSetImmediateExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsetimmediateexecution) and the resources needed for the request are unavailable. |
| **STATUS_INVALID_DEVICE_REQUEST** | The call to [WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute) was not preceded by a call to [WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize) or [WdfDmaTransactionInitializeUsingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingrequest). |
| **STATUS_WDF_BUSY** | The device performs single-packet transfers, and the driver called [WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute) while another transaction was executing. |
| **STATUS_WDF_TOO_FRAGMENTED** | The number of scatter/gather elements that the operating system needed to handle the specified transfer size was greater than the value that the driver's call to [WdfDmaEnablerSetMaximumScatterGatherElements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablersetmaximumscattergatherelements) specified. For more information, see the following Remarks section. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfDmaTransactionExecute** method initializes a transaction's scatter/gather list for the first [DMA transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/dma-transactions-and-dma-transfers) that is associated with the specified [DMA transaction](https://learn.microsoft.com/windows-hardware/drivers/wdf/dma-transactions-and-dma-transfers). (For single-packet transfers, the scatter/gather list contains a single element.) Then, the method calls the driver's [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma) event callback function, and the callback function can program the device to begin the transfer.

Framework-based drivers typically call **WdfDmaTransactionExecute** from within an [I/O queue event callback function](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers).

After a driver has called [WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize) or [WdfDmaTransactionInitializeUsingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingrequest) to initialize a DMA transaction, the driver must call **WdfDmaTransactionExecute** only once before [completing the DMA transaction](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-a-dma-transaction).

If **WdfDmaTransactionInitialize*Xxx*** returns success but **WdfDmaTransactionExecute** returns an error value, your driver must call [WdfDmaTransactionRelease](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionrelease).

In framework versions prior to 1.11, if the device performs single-packet transfers, the operating system can execute only one DMA transaction at a time. In this case, **WdfDmaTransactionExecute** returns STATUS_WDF_BUSY if another transaction is executing.

In framework versions 1.11 and later, if the driver uses DMA version 3 to perform single-packet transfers, the operating system can store multiple DMA transactions in an internal queue. In this case, the driver can call **WdfDmaTransactionExecute** while another transaction is executing. To select DMA version 3, set the **WdmDmaVersionOverride** member of [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) to 3.

If the device performs scatter/gather transfers, the operating system can execute multiple DMA transactions simultaneously. In this case, the driver can call **WdfDmaTransactionExecute** while another transaction is executing.

If the driver calls [WdfDmaTransactionDmaCompletedWithLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedwithlength) to report a partial transfer, and if the driver had specified the DMA transaction's data buffer by using MDLs that it chained together (using the **Next** member of the [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) structure), **WdfDmaTransactionExecute** can return STATUS_WDF_TOO_FRAGMENTED because the framework might recalculate the number and size of fragments and might exceed the number of allowed fragments.

The **WdfDmaTransactionExecute** returns STATUS_SUCCESS if the transaction was successfully started. To determine if the framework successfully sent all of the transaction's transfers to the driver's [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma) callback function, the driver must call [WdfDmaTransactionDmaCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompleted), [WdfDmaTransactionDmaCompletedWithLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedwithlength), or [WdfDmaTransactionDmaCompletedFinal](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedfinal).

If the value that the *Context* parameter supplies is a pointer or handle, the memory that it references must be accessible in the driver's [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma) event callback function at IRQL = DISPATCH_LEVEL. You can use [framework object context](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space) to meet this requirement.

The driver can call **WdfDmaTransactionExecute** in a non-blocking manner if it has previously called [WdfDmaTransactionSetImmediateExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsetimmediateexecution).

For more information about DMA transactions, see [Starting a DMA Transaction](https://learn.microsoft.com/windows-hardware/drivers/wdf/starting-a-dma-transaction).

#### Examples

The following code example is from the [PCIDRV](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver. This example creates and initializes a DMA transfer and begins its execution.

```cpp
NTSTATUS
NICInitiateDmaTransfer(
    IN PFDO_DATA  FdoData,
    IN WDFREQUEST  Request
    )
{
    WDFDMATRANSACTION  dmaTransaction;
    NTSTATUS  status;
    BOOLEAN  bCreated = FALSE;

    do {
        status = WdfDmaTransactionCreate(
                                         FdoData->WdfDmaEnabler,
                                         WDF_NO_OBJECT_ATTRIBUTES,
                                         &dmaTransaction
                                         );
        if(!NT_SUCCESS(status)) {
            TraceEvents(TRACE_LEVEL_ERROR, DBG_WRITE,
                        "WdfDmaTransactionCreate failed %X\n", status);
            break;
        }

        bCreated = TRUE;

        status = WdfDmaTransactionInitializeUsingRequest(
                                     dmaTransaction,
                                     Request,
                                     NICEvtProgramDmaFunction,
                                     WdfDmaDirectionWriteToDevice
                                     );
        if(!NT_SUCCESS(status)) {
            TraceEvents(
                        TRACE_LEVEL_ERROR,
                        DBG_WRITE,
                        "WdfDmaTransactionInitalizeUsingRequest failed %X\n",
                        status
                        );
            break;
        }

        status = WdfDmaTransactionExecute(
                                          dmaTransaction,
                                          dmaTransaction
                                          );

        if(!NT_SUCCESS(status)) {
            TraceEvents(
                        TRACE_LEVEL_ERROR,
                        DBG_WRITE,
                        "WdfDmaTransactionExecute failed %X\n",
                        status
                        );
            break;
        }
    } while (FALSE);

    if(!NT_SUCCESS(status)){

        if(bCreated) {
            WdfObjectDelete(dmaTransaction);
        }
    }
    return status;
}
```

## See also

[EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma)

[WdfDmaEnablerSetMaximumScatterGatherElements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablersetmaximumscattergatherelements)

[WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate)

[WdfDmaTransactionDmaCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompleted)

[WdfDmaTransactionDmaCompletedFinal](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedfinal)

[WdfDmaTransactionDmaCompletedWithLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedwithlength)

[WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize)

[WdfDmaTransactionInitializeUsingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingrequest)

[WdfDmaTransactionSetImmediateExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsetimmediateexecution)