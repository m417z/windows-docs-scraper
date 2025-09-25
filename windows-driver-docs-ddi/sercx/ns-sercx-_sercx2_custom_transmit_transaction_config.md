# _SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG structure

## Description

The **SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG** structure contains information that version 2 of the serial framework extension (SerCx2) uses to configure a new custom-transmit-transaction object.

## Members

### `Size`

The size, in bytes, of this structure. The [SerCx2CustomTransmitTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmittransactioncreate) method uses this member to determine which version of the structure the caller is using. The size of this structure might change in future versions of the Sercx.h header file.

### `EvtSerCx2CustomTransmitTransactionInitialize`

A pointer to the driver-implemented [EvtSerCx2CustomTransmitTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_transmit_transaction_initialize) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function.

### `EvtSerCx2CustomTransmitTransactionStart`

A pointer to the driver-implemented [EvtSerCx2CustomTransmitTransactionStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_transmit_transaction_start) event callback function. This member must point to a valid function.

### `EvtSerCx2CustomTransmitTransactionCleanup`

A pointer to the driver-implemented [EvtSerCx2CustomTransmitTransactionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_transmit_transaction_cleanup) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function.

## Remarks

The [SerCx2CustomTransmitTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmittransactioncreate) method accepts a pointer to a **SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG** structure as an input parameter. Before calling **SerCx2CustomTransmitTransactionInitialize**, call the [SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_custom_transmit_transaction_config_init) function to initialize this structure.

## See also

[EvtSerCx2CustomTransmitTransactionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_transmit_transaction_cleanup)

[EvtSerCx2CustomTransmitTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_transmit_transaction_initialize)

[EvtSerCx2CustomTransmitTransactionStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_transmit_transaction_start)

[SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_custom_transmit_transaction_config_init)

[SerCx2CustomTransmitTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmittransactioncreate)