# _SERCX2_PIO_TRANSMIT_CONFIG structure

## Description

The **SERCX2_PIO_TRANSMIT_CONFIG** structure contains information that version 2 of the serial framework extension (SerCx2) uses to configure a new PIO-transmit object.

## Members

### `Size`

The size, in bytes, of this structure. The [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) method uses this member to determine which version of the structure the caller is using. The size of this structure might change in future versions of the Sercx.h header file.

### `EvtSerCx2PioTransmitInitializeTransaction`

A pointer to the driver-implemented [EvtSerCx2PioTransmitInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_initialize_transaction) event callback function. This member must point to a valid function.

### `EvtSerCx2PioTransmitCleanupTransaction`

A pointer to the driver-implemented [EvtSerCx2PioTransmitCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_cleanup_transaction) event callback function. This member must point to a valid function.

### `EvtSerCx2PioTransmitWriteBuffer`

A pointer to the driver-implemented [EvtSerCx2PioTransmitWriteBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_write_buffer) event callback function. This member must point to a valid function.

### `EvtSerCx2PioTransmitEnableReadyNotification`

A pointer to the driver-implemented [EvtSerCx2PioTransmitEnableReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_enable_ready_notification) event callback function. This member must point to a valid function.

### `EvtSerCx2PioTransmitCancelReadyNotification`

A pointer to the driver-implemented [EvtSerCx2PioTransmitCancelReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_cancel_ready_notification) event callback function. This member must point to a valid function.

### `EvtSerCx2PioTransmitDrainFifo`

A pointer to the driver-implemented [EvtSerCx2PioTransmitDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_drain_fifo) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function. However, a driver that implements this function must also implement *EvtSerCx2PioTransmitCancelDrainFifo* and *EvtSerCx2PioTransmitPurgeFifo* functions.

### `EvtSerCx2PioTransmitCancelDrainFifo`

A pointer to the driver-implemented [EvtSerCx2PioTransmitCancelDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_cancel_drain_fifo) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function. However, a driver that implements this function must also implement *EvtSerCx2PioTransmitDrainFifo* and *EvtSerCx2PioTransmitPurgeFifo* functions.

### `EvtSerCx2PioTransmitPurgeFifo`

A pointer to the driver-implemented [EvtSerCx2PioTransmitPurgeFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_purge_fifo) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function. However, a driver that implements this function must also implement *EvtSerCx2PioTransmitDrainFifo* and *EvtSerCx2PioTransmitCancelDrainFifo* functions.

## Remarks

The [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) method accepts a pointer to a **SERCX2_PIO_TRANSMIT_CONFIG** structure as an input parameter. Before calling **SerCx2PioTransmitCreate**, call the [SERCX2_PIO_TRANSMIT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_pio_transmit_config_init) function to initialize this structure.

## See also

[EvtSerCx2PioTransmitCancelDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_cancel_drain_fifo)

[EvtSerCx2PioTransmitCancelReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_cancel_ready_notification)

[EvtSerCx2PioTransmitCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_cleanup_transaction)

[EvtSerCx2PioTransmitDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_drain_fifo)

[EvtSerCx2PioTransmitEnableReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_enable_ready_notification)

[EvtSerCx2PioTransmitInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_initialize_transaction)

[EvtSerCx2PioTransmitPurgeFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_purge_fifo)

[EvtSerCx2PioTransmitWriteBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_write_buffer)

[SERCX2_PIO_TRANSMIT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_pio_transmit_config_init)

[SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate)