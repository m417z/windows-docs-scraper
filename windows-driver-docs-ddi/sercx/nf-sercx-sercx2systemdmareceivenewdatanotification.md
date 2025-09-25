# SerCx2SystemDmaReceiveNewDataNotification function

## Description

The **SerCx2SystemDmaReceiveNewDataNotification** method notifies version 2 of the serial framework extension (SerCx2) that data is available to be read from the receive FIFO in the serial controller hardware.

## Parameters

### `SystemDmaReceive` [in]

A [SERCX2SYSTEMDMARECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a system-DMA-receive object. The serial controller driver previously called the [SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate) method to create this object.

## Remarks

If the receive FIFO in the serial controller becomes empty before a system-DMA-receive transaction can be completed, SerCx2 calls the [EvtSerCx2SystemDmaReceiveEnableNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_enable_new_data_notification) event callback function, if it is implemented, to enable SerCx2 to receive a new-data notification when data is again available to be read from the receive FIFO.

If the new-data notification is enabled, the serial controller driver must call **SerCx2SystemDmaReceiveNewDataNotification** to notify SerCx2 after the serial controller receives new data. A notification occurs when the driver detects that one or more new bytes of received data either are ready to be transferred or have already been transferred by the system DMA controller.

The serial controller must call **SerCx2SystemDmaReceiveNewDataNotification** only in response to a call to the *EvtSerCx2SystemDmaReceiveEnableNewDataNotification* function.

If a serial controller driver supports new-data notifications for system-DMA-receive transactions, SerCx uses these notifications to detect interval time-outs during the handling of read ([IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)) requests. For more information about interval time-outs, see [SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts). For more information about new-data notifications, see [SerCx2 System-DMA-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265343(v=vs.85)).

## See also

[EvtSerCx2SystemDmaReceiveEnableNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_enable_new_data_notification)

[IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)

[SERCX2SYSTEMDMARECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts)

[SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate)