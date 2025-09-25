# WdfDmaTransactionAllocateResources function

## Description

[Applies to KMDF only]

 The **WdfDmaTransactionAllocateResources** method reserves a single-packet or system-mode DMA enabler for exclusive (and repeated) use with the specified transaction object. The driver can initialize and initiate the transaction multiple times while holding reserved resources.

## Parameters

### `DmaTransaction` [in]

A handle to the DMA transaction object for which DMA resources should be reserved.

### `DmaDirection` [in]

A [WDF_DMA_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_direction)-typed value specifying the DMA transfer direction for which the resources are being reserved. If the driver did not specify a duplex profile, the framework ignores this value.

### `RequiredMapRegisters` [in]

The number of map registers the driver wants to reserve. If zero, the framework derives the required number of map registers from the initialized transaction.

### `EvtReserveDmaFunction` [in]

A pointer to the driver's [EvtReserveDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_reserve_dma) event callback function.

### `EvtReserveDmaContext` [in]

A pointer to a buffer containing the context to be provided to the driver's [EvtReserveDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_reserve_dma) event callback function.

## Return value

**WdfDmaTransactionAllocateResources** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method returns one of the following values.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *DmaDirection* parameter contains an invalid value. |
| **STATUS_INSUFFICIENT_RESOURCES** | The number of map register requests exceeds the number assigned to the enabler, or the driver previously called [WdfDmaTransactionSetImmediateExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsetimmediateexecution) and the resources needed for the request are unavailable. |
| **STATUS_INVALID_DEVICE_REQUEST** | DMA version 3 or later is not enabled, or the driver called this method for a scatter-gather DMA enabler. |

## Remarks

**WdfDmaTransactionAllocateResources** sends a request for map registers to the system DMA engine. When the request has been fulfilled, the framework calls the driver's [EvtReserveDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_reserve_dma) event callback function. For more information about reserving resources, see [Reserving DMA Resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/reserving-dma-resources).

Framework-based drivers typically call **WdfDmaTransactionAllocateResources** from within an [I/O request handler](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers). A driver can also call **WdfDmaTransactionAllocateResources** from its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function, after creating a DMA enabler object.

 When called with a scatter/gather DMA enabler, **WdfDmaTransactionAllocateResources** causes a verifier bug check.

The driver must create the transaction specified by *DmaTransaction* prior to calling **WdfDmaTransactionAllocateResources**. After calling **WdfDmaTransactionAllocateResources**, the driver initializes and initiates the transaction. The driver can reinitialize and reinitiate the same transaction object multiple times, avoiding the delay that would otherwise occur between transactions as map registers were freed back to the HAL and then reallocated.

A driver could call **WdfDmaTransactionAllocateResources** in the following situations:

* The driver receives a set of DMA channels in its [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function. In *EvtDevicePrepareHardware*, the driver initializes a DMA transaction and calls **WdfDmaTransactionAllocateResources** to reserve the enabler for exclusive use with this transaction. Alternatively, the driver can call **WdfDmaTransactionAllocateResources** from a [request handler](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers) and then initiate the transaction multiple times.
* The driver needs to perform a series of transactions on the enabler. The driver reserves the enabler, initializes and initiates multiple transactions using the same transaction object, and then releases the enabler.

Before calling **WdfDmaTransactionAllocateResources**, the driver must determine the number of map registers needed for any transaction that it will initiate using this reservation. To do so, the driver can call either the [ADDRESS_AND_SIZE_TO_SPAN_PAGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-address_and_size_to_span_pages) macro or [WdfDmaTransactionGetTransferInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiongettransferinfo).

 When calling **WdfDmaTransactionAllocateResources**, the driver should not request more map registers than it requested when it created the enabler.

To call **WdfDmaTransactionAllocateResources** in a non-blocking manner, the driver should first call [WdfDmaTransactionSetImmediateExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsetimmediateexecution).

**WdfDmaTransactionAllocateResources** requires DMA version 3.
To select DMA version 3, set the **WdmDmaVersionOverride** member of [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) to 3.

## See also

[EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware)

[WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate)

[WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate)

[WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute)

[WdfDmaTransactionFreeResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionfreeresources)

[WdfDmaTransactionSetImmediateExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsetimmediateexecution)