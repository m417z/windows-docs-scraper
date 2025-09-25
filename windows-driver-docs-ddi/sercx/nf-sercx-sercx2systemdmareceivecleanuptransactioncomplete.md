# SerCx2SystemDmaReceiveCleanupTransactionComplete function

## Description

The **SerCx2SystemDmaReceiveCleanupTransactionComplete** method notifies version 2 of the serial framework extension (SerCx2) that the serial controller driver has finished cleaning up the serial controller's hardware state after a system-DMA-receive transaction.

## Parameters

### `SystemDmaReceive` [in]

A [SERCX2SYSTEMDMARECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a system-DMA-receive object. The serial controller driver previously called the [SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate) method to create this object.

## Remarks

After a system-DMA-receive transaction ends, SerCx2 calls the [EvtSerCx2SystemDmaReceiveCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_cleanup_transaction) event callback function, if it is implemented, to clean up the serial controller state. In response to this call, the driver should do any clean-up work that is needed; then the driver must call **SerCx2SystemDmaReceiveCleanupTransactionComplete** to notify SerCx2. SerCx2 expects this notification and does not start the next transaction until it is notified.

The serial controller driver must call **SerCx2SystemDmaReceiveCleanupTransactionComplete** only in response to a call to the *EvtSerCx2SystemDmaReceiveCleanupTransaction* function.

For more information, see [SerCx2 System-DMA-Receive Transaction](https://learn.microsoft.com/previous-versions/dn265343(v=vs.85)).

## See also

[EvtSerCx2SystemDmaReceiveCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_cleanup_transaction)

[SERCX2SYSTEMDMARECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate)