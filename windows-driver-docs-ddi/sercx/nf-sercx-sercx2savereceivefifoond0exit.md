# SerCx2SaveReceiveFifoOnD0Exit function

## Description

The **SerCx2SaveReceiveFifoOnD0Exit** method informs version 2 of the serial framework extension (SerCx2) that the receive FIFO of the serial controller hardware contains data that should be saved before the serial controller enters a device low-power state.

## Parameters

### `PioReceive` [in]

A [SERCX2PIORECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a PIO-receive object. The serial controller driver previously called the [SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate) method to create this object.

### `FifoSize` [in]

The number of bytes of unread data that the transmit FIFO contains.

## Remarks

When the serial controller is about to enter a low-power state, SerCx2 and the serial controller driver must save any bytes of unread data that might remain in the receive FIFO. Otherwise, this data will be lost when the serial controller enters the low-power state. To request assistance from SerCx2 to save this data, the driver calls **SerCx2SaveReceiveFifoOnD0Exit**.

The driver framework calls the driver's [EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit) or [EvtDeviceD0ExitPreInterruptsDisabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit_pre_interrupts_disabled) event callback function to tell the driver to prepare the serial controller to exit the D0 device state. In response, this function first deasserts the *ready to send* (RTS) line to tell the device on the other end of the serial connection to not send any more data. Next, the function calls **SerCx2SaveReceiveFifoOnD0Exit**.

**SerCx2SaveReceiveFifoOnD0Exit** calls the driver's [EvtSerCx2PioReceiveReadBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_read_buffer) event callback function to retrieve the data from the receive FIFO. In this call, SerCx2 supplies, as a parameter, a pointer to an internal software buffer that SerCx2 maintains for the purpose of saving unread data from the receive FIFO in preparation to enter a low-power state.

Later, after a client sends a read ([IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)) request to the serial controller, SerCx2 copies the bytes from this internal software buffer to the read buffer in the request.

## See also

[EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit)

[EvtDeviceD0ExitPreInterruptsDisabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit_pre_interrupts_disabled)

[EvtSerCx2PioReceiveReadBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_read_buffer)

[IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)

[SERCX2PIORECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate)