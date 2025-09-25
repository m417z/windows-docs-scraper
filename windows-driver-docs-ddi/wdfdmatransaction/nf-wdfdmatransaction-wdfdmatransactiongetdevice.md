# WdfDmaTransactionGetDevice function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionGetDevice** method returns a handle to the framework device object that is associated with a specified DMA transaction.

## Parameters

### `DmaTransaction` [in]

A handle to a DMA transaction object that the driver obtained from a previous call to [WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate).

## Return value

**WdfDmaTransactionGetDevice** returns a handle to the framework device object that the driver specified when it called [WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about completing DMA transfers, see [Completing a DMA Transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-a-dma-transfer).

#### Examples

The following code example obtains a handle to the framework device object that is associated with a specified DMA transaction.

```cpp
WDFDEVICE device;

device = WdfDmaTransactionGetDevice(DmaTransaction);
```

## See also

[WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate)