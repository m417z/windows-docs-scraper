# WdfDmaTransactionInitialize function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionInitialize** method initializes a specified DMA transaction.

## Parameters

### `DmaTransaction` [in]

A handle to a DMA transaction object that the driver obtained from a previous call to [WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate).

### `EvtProgramDmaFunction` [in]

A pointer to the driver's [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma) event callback function.

### `DmaDirection` [in]

A [WDF_DMA_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_direction)-typed value.

### `Mdl` [in]

A pointer to a memory descriptor list (MDL) that describes the buffer that will be used for the DMA transaction. See more information in **Remarks**.

### `VirtualAddress` [in]

The virtual address of the buffer that will be used for the DMA transaction.

### `Length` [in]

The number of bytes to be transferred.

## Return value

**WdfDmaTransactionInitialize** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values.

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | A scatter/gather list could not be allocated. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_WDF_TOO_FRAGMENTED** | The number of scatter/gather elements that was needed to handle the transaction was greater than the value that the driver's call to [WdfDmaEnablerSetMaximumScatterGatherElements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablersetmaximumscattergatherelements) specified. <br><br>For transactions that were set for [single transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/), one way to fix this is to copy the data to a physically contiguous buffer and then initialize the transaction with that buffer. For example, call [MmAllocateContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemory), copy the original buffers into the new one, and then call [WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize) again. |
| **STATUS_WDF_NOT_ENOUGH_MAP_REGISTERS** | This return value applies only to transactions that were set for [single transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/). <br><br>The number of map registers needed to map the transaction is larger than the number the DMA adapter has reserved.<br><br>To fix, the driver might reduce the number of required map registers by combining an MDL chain into a single MDL.<br><br>Drivers using packet and system DMA can call [WdfDmaTransactionAllocateResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionallocateresources) to reserve a number of map registers from the total allocated to the device. Suppose your driver reserved 4 out of 8 total map registers, but the DMA transfer requires 6. In this case, [WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize) fails. To fix, call [WdfDmaTransactionFreeResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionfreeresources) and then call **WdfDmaTransactionInitialize** again.<br><br> Drivers using scatter/gather DMA cannot reserve map registers. |
| **STATUS_WDF_TOO_MANY_TRANSFERS** | This return value applies only to transactions that were set for [single transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/). <br><br>The transaction’s total length exceeds the device’s maximum transfer size. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfDmaTransactionInitialize** method prepares a DMA operation for execution, by performing initialization operations such as allocating a transaction's scatter/gather list. After your driver calls **WdfDmaTransactionInitialize**, the driver must call [WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute) to begin executing the transaction.

Framework-based drivers typically call **WdfDmaTransactionInitialize** from within an [I/O queue event callback function](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers).

If you are creating a DMA transaction that is based on information that a framework request object contains, your driver should call [WdfDmaTransactionInitializeUsingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingrequest). If you are creating a DMA transaction that is not based on a request object, use either **WdfDmaTransactionInitialize** or [WdfDmaTransactionInitializeUsingOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingoffset).

The driver can specify an MDL chain in the *Mdl* parameter of this method. An MDL chain is a sequence of MDL structures that the driver chained together using the **Next** member of the MDL structure. In framework versions prior to 1.11, only scatter/gather DMA transfers can use MDL chains. Starting in version 1.11, if the driver is using DMA version 3, single-packet transfers can also use chained MDLs.

If the buffer that the driver specifies is larger than the maximum transfer length that your driver specified when it called [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate) or [WdfDmaTransactionSetMaximumLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsetmaximumlength), the framework breaks the transaction into multiple [transfers](https://learn.microsoft.com/windows-hardware/drivers/wdf/dma-transactions-and-dma-transfers).

For more information about DMA transactions, see [Creating and Initializing a DMA Transaction](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-and-initializing-a-dma-transaction).

#### Examples

The following code example is from the [PLX9x5x](https://learn.microsoft.com/samples/browse/?redirectedfrom=MSDN-samples) sample driver. First, the example initializes a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure and creates a DMA transaction object. Next, it obtains an MDL that represents a received I/O request's input buffer, and it obtains the virtual address and length of the buffer. Finally, the example calls **WdfDmaTransactionInitialize** to initialize the transaction.

```cpp
WDF_OBJECT_ATTRIBUTES  attributes;
PMDL  mdl;
PVOID  virtualAddress;
ULONG  length;
NTSTATUS  status;

WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(
                                        &attributes,
                                        TRANSACTION_CONTEXT
                                        );

status = WdfDmaTransactionCreate(
                                 devExt->DmaEnabler,
                                 &attributes,
                                 &dmaTransaction
                                 );
if(!NT_SUCCESS(status)) {
    goto CleanUp;
}

status = WdfRequestRetrieveInputWdmMdl(
                                       Request,
                                       &mdl
                                       );
if (!NT_SUCCESS(status)) {
    goto CleanUp;
}

virtualAddress = MmGetMdlVirtualAddress(mdl);
length = MmGetMdlByteCount(mdl);

status = WdfDmaTransactionInitialize(
                                     dmaTransaction,
                                     PLxEvtProgramWriteDma,
                                     WdfDmaDirectionWriteToDevice,
                                     mdl,
                                     virtualAddress,
                                     length
                                     );
if(!NT_SUCCESS(status)) {
    goto CleanUp;
}
```

## See also

[EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma)

[MmGetMdlByteCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlbytecount)

[MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlvirtualaddress)

[WDF_DMA_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_direction)

[WdfDmaEnablerSetMaximumScatterGatherElements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablersetmaximumscattergatherelements)

[WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate)

[WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute)

[WdfDmaTransactionInitializeUsingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingrequest)