# _SERCX2_PIO_RECEIVE_CONFIG structure

## Description

The **SERCX2_PIO_RECEIVE_CONFIG** structure contains information that version 2 of the serial framework extension (SerCx2) uses to configure a new PIO-receive object.

## Members

### `Size`

The size, in bytes, of this structure. The [SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate) method uses this member to determine which version of the structure the caller is using. The size of this structure might change in future versions of the Sercx.h header file.

### `EvtSerCx2PioReceiveInitializeTransaction`

A pointer to the driver-implemented [EvtSerCx2PioReceiveInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_initialize_transaction) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function.

### `EvtSerCx2PioReceiveCleanupTransaction`

A pointer to the driver-implemented [EvtSerCx2PioReceiveCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_cleanup_transaction) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function.

### `EvtSerCx2PioReceiveReadBuffer`

A pointer to the driver-implemented [EvtSerCx2PioReceiveReadBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_read_buffer) event callback function. This member must point to a valid function.

### `EvtSerCx2PioReceiveEnableReadyNotification`

A pointer to the driver-implemented [EvtSerCx2PioReceiveEnableReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_enable_ready_notification) event callback function. This member must point to a valid function.

### `EvtSerCx2PioReceiveCancelReadyNotification`

A pointer to the driver-implemented [EvtSerCx2PioReceiveCancelReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_cancel_ready_notification) event callback function. This member must point to a valid function.

## Remarks

The [SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate) method accepts a pointer to a **SERCX2_PIO_RECEIVE_CONFIG** structure as an input parameter. Before calling **SerCx2PioReceiveCreate**, call the [SERCX2_PIO_RECEIVE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_pio_receive_config_init) function to initialize this structure.

## See also

[EvtSerCx2PioReceiveCancelReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_cancel_ready_notification)

[EvtSerCx2PioReceiveCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_cleanup_transaction)

[EvtSerCx2PioReceiveEnableReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_enable_ready_notification)

[EvtSerCx2PioReceiveInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_initialize_transaction)

[EvtSerCx2PioReceiveReadBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_read_buffer)

[SERCX2_PIO_RECEIVE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_pio_receive_config_init)

[SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate)