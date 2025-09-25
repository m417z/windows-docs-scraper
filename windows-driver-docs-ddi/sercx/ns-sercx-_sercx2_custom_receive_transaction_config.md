# _SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG structure

## Description

The **SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG** structure contains information that version 2 of the serial framework extension (SerCx2) uses to configure a new custom-receive-transaction object.

## Members

### `Size`

The size, in bytes, of this structure. The [SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate) method uses this member to determine which version of the structure the caller is using. The size of this structure might change in future versions of the Sercx.h header file.

### `EvtSerCx2CustomReceiveTransactionInitialize`

A pointer to the driver-implemented [EvtSerCx2CustomReceiveTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_receive_transaction_initialize) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function.

### `EvtSerCx2CustomReceiveTransactionStart`

A pointer to the driver-implemented [EvtSerCx2CustomReceiveTransactionStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_receive_transaction_start) event callback function. This member must point to a valid function.

### `EvtSerCx2CustomReceiveTransactionCleanup`

A pointer to the driver-implemented [EvtSerCx2CustomReceiveTransactionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_receive_transaction_cleanup) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function.

### `EvtSerCx2CustomReceiveTransactionEnableNewDataNotification`

A pointer to the driver-implemented [EvtSerCx2CustomReceiveTransactionEnableNewDataNotification](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn265201(v=vs.85)) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function.

### `EvtSerCx2CustomReceiveTransactionQueryProgress`

A pointer to the driver-implemented [EvtSerCx2CustomReceiveTransactionQueryProgress](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn265203(v=vs.85)) event callback function. This member must point to a valid function.

## Remarks

The [SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate) method accepts a pointer to a **SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG** structure as an input parameter. Before calling **SerCx2CustomReceiveTransactionInitialize**, call the [SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_custom_receive_transaction_config_init) function to initialize this structure.

## See also

[EvtSerCx2CustomReceiveTransactionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_receive_transaction_cleanup)

[EvtSerCx2CustomReceiveTransactionEnableNewDataNotification](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn265201(v=vs.85))

[EvtSerCx2CustomReceiveTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_receive_transaction_initialize)

[EvtSerCx2CustomReceiveTransactionQueryProgress](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn265203(v=vs.85))

[EvtSerCx2CustomReceiveTransactionStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_receive_transaction_start)

[SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_custom_receive_transaction_config_init)

[SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate)