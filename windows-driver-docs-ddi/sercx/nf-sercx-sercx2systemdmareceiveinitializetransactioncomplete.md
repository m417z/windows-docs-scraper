# SerCx2SystemDmaReceiveInitializeTransactionComplete function

## Description

The **SerCx2SystemDmaReceiveInitializeTransactionComplete** method notifies version 2 of the serial framework extension (SerCx2) that the serial driver has finished initializing the serial controller hardware in preparation for a new system-DMA-receive transaction.

## Parameters

### `SystemDmaReceive` [in]

A [SERCX2SYSTEMDMARECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a system-DMA-receive object. The serial controller driver previously called the [SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate) method to create this object.

### `InitSuccess` [in]

Whether the initialization was successful. If **TRUE**, the initialization succeeded. If **FALSE**, the initialization failed.

## Remarks

Before SerCx2 initiates a system-DMA-receive transaction, SerCx2 calls the [EvtSerCx2SystemDmaReceiveInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_initialize_transaction) event callback function, if it is implemented, to initialize the serial controller to perform the transaction. In response to this call, the driver should do any initialization that is needed; then the driver must call **SerCx2SystemDmaReceiveInitializeTransactionComplete** to notify SerCx2. SerCx2 expects this notification and does not start the transaction until it is notified.

The serial controller driver must call **SerCx2SystemDmaReceiveInitializeTransactionComplete** only in response to a call to the [EvtSerCx2SystemDmaReceiveInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_initialize_transaction) function.

For more information, see [SerCx2 System-DMA-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265343(v=vs.85)).

## See also

[EvtSerCx2SystemDmaReceiveInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_initialize_transaction)

[SERCX2SYSTEMDMARECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate)