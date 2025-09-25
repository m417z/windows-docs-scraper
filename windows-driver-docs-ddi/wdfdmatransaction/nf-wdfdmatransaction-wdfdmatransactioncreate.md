# WdfDmaTransactionCreate function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionCreate** method creates a DMA transaction.

## Parameters

### `DmaEnabler` [in]

A handle to a DMA enabler object that the driver obtained from a previous call to [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate).

### `Attributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies object attributes for the new DMA transaction object. (The structure's **ParentObject** member must be **NULL**.) This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `DmaTransaction` [out]

A handle to a DMA transaction object.

## Return value

**WdfDmaTransactionCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory to create a new DMA transaction object. |

For a list of other return values that the **WdfDmaTransactionCreate** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

After your driver calls **WdfDmaTransactionCreate**, it must call [WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize) or [WdfDmaTransactionInitializeUsingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingrequest) before calling [WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute).

The specified DMA enabler object becomes the parent of the new DMA transaction object. The driver cannot change this parent, and the **ParentObject** member or the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure must be **NULL**.

For more information about DMA transactions, see [Creating and Initializing a DMA Transaction](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-and-initializing-a-dma-transaction).

#### Examples

For a code example that uses **WdfDmaTransactionCreate**, see [WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute).

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate)

[WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute)

[WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize)

[WdfDmaTransactionInitializeUsingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingrequest)