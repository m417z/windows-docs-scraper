# WdfDmaTransactionSetMaximumLength function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionSetMaximumLength** method sets the maximum length for the DMA transfers that are associated with a specified DMA transaction.

## Parameters

### `DmaTransaction` [in]

A handle to a DMA transaction object that the driver obtained from a previous call to [WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate).

### `MaximumLength` [in]

The maximum size, in bytes, that the device can handle in a single DMA transfer operation. If your driver must run on versions of the Microsoft Windows operating systems that support a maximum of 16 [map registers](https://learn.microsoft.com/windows-hardware/drivers/kernel/map-registers), *MaximumLength* must be less than 65536.

The *MaximumLength* value applies only to the specified DMA transaction, as follows:

* If the specified value is less than the default value that the driver specified in its [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) structure, the specified value overrides the default value.
* If the specified value is greater than the default value, the specified value is ignored.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

Your driver must initialize the DMA transaction before calling **WdfDmaTransactionSetMaximumLength**.

For information about initializing a DMA transaction, see [Creating and Initializing a DMA Transaction](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-and-initializing-a-dma-transaction).

#### Examples

The following code example sets the maximum transfer length to a driver-defined value, for a specified DMA transaction.

```cpp
WdfDmaTransactionSetMaximumLength(
                                 dmaTransaction,
                                 MAX_TRANSFER_LENGTH/2,
                                 );
```

## See also

[WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config)

[WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate)