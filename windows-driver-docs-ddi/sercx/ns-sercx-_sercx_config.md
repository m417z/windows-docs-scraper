# _SERCX_CONFIG structure

## Description

The **SERCX_CONFIG** structure contains configuration information for the serial framework extension (SerCx).

## Members

### `Size`

The size, in bytes, of this structure. The [SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize) method uses this member to determine which version of the structure the caller is using. The size of this structure might change in future versions of the Sercx.h header file.

### `PowerManaged`

Whether the controller queue should be power-managed. If set to **WdfTrue**, the controller queue should be power-managed. If set to **WdfFalse**, the controller queue not be power-managed. If set to **WdfDefault**, the controller queue should be power-managed unless the driver calls the [WdfFdoInitSetFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetfilter) method. For more information, see the description of the **PowerManaged** member in [WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config).

### `EvtSerCxFileOpen`

A pointer to the controller driver's [EvtSerCxFileOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_fileopen) callback function. This member is optional and can be set to NULL.

### `EvtSerCxFileClose`

A pointer to the controller driver's [EvtSerCxFileClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_fileclose) callback function. This member is optional and can be set to NULL.

### `EvtSerCxFileCleanup`

A pointer to the controller driver's [EvtSerCxFileCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_filecleanup) callback function. This member is optional and can be set to NULL.

### `EvtSerCxTransmit`

A pointer to the controller driver's [EvtSerCxTransmit](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_transmit) callback function. This member is required to point to a valid callback function.

### `EvtSerCxReceive`

A pointer to the controller driver's [EvtSerCxReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_receive) callback function. This member is required to point to a valid callback function.

### `EvtSerCxWaitmask`

A pointer to the controller driver's [EvtSerCxWaitmask](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_waitmask) callback function. This member is required to point to a valid callback function.

### `EvtSerCxPurge`

A pointer to the controller driver's [EvtSerCxPurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_purge) callback function. This member is optional and can be set to NULL.

### `EvtSerCxControl`

A pointer to the controller driver's [EvtSerCxControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_control) callback function. This member is required to point to a valid callback function.

### `EvtSerCxApplyConfig`

A pointer to the controller driver's [EvtSerCxApplyConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_apply_config) callback function. This member is required to point to a valid callback function.

### `EvtSerCxTransmitCancel`

A pointer to the controller driver's [EvtSerCxTransmitCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_transmit_cancel) callback function. This member is optional and can be set to NULL.

### `EvtSerCxReceiveCancel`

A pointer to the controller driver's [EvtSerCxReceiveCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_receive_cancel) callback function. This member is optional and can be set to NULL.

## Remarks

Before this structure is passed to the [SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize) method, it must be initialized by the [SERCX_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx_config_init) function, and then modified by the controller driver to set the callback function pointers and the **PowerManaged** member.

## See also

[EvtSerCxApplyConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_apply_config)

[EvtSerCxControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_control)

[EvtSerCxFileCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_filecleanup)

[EvtSerCxFileClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_fileclose)

[EvtSerCxFileOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_fileopen)

[EvtSerCxPurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_purge)

[EvtSerCxReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_receive)

[EvtSerCxReceiveCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_receive_cancel)

[EvtSerCxTransmit](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_transmit)

[EvtSerCxTransmitCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_transmit_cancel)

[EvtSerCxWaitmask](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_waitmask)

[SERCX_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx_config_init)

[SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize)

[WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config)

[WdfFdoInitSetFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetfilter)