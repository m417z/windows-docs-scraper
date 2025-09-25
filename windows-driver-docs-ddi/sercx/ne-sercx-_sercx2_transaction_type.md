# _SERCX2_TRANSACTION_TYPE enumeration

## Description

The **SERCX2_TRANSACTION_TYPE** enumeration defines constants that indicate the type of data-transfer mechanism to use to perform an I/O transaction.

## Constants

### `SerCx2TransactionTypeDefault`

Let SerCx2 decide what type of data transfer to use for the I/O transaction.

### `SerCx2TransactionTypePio`

Use programmed I/O (PIO) to perform the I/O transaction.

### `SerCx2TransactionTypeSystemDma`

Use system DMA to perform the I/O transaction.

### `SerCx2TransactionTypeCustom`

Use the custom data-transfer mechanism to perform the I/O transaction.

## Remarks

The [EvtSerCx2SelectNextReceiveTransactionType](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_select_next_receive_transaction_type) and [EvtSerCx2SelectNextTransmitTransactionType](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_select_next_transmit_transaction_type) event callback functions return **SERCX2_TRANSACTION_TYPE** enumeration values.

## See also

[EvtSerCx2SelectNextReceiveTransactionType](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_select_next_receive_transaction_type)

[EvtSerCx2SelectNextTransmitTransactionType](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_select_next_transmit_transaction_type)