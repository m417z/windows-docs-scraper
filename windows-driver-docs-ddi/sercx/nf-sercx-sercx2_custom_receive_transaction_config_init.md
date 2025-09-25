# SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG_INIT function

## Description

The **SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG_INIT** function initializes a [SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_receive_transaction_config) structure.

## Parameters

### `Config` [out]

A pointer to the [SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_receive_transaction_config) structure that is to be initialized.

### `EvtSerCx2CustomReceiveTransactionStart` [in]

The value to load into the **EvtSerCx2CustomReceiveTransactionStart** member of the **SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG** structure. For more information, see the description of this member in [SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_receive_transaction_config).

### `EvtSerCx2CustomReceiveTransactionEnableNewDataNotification` [in, optional]

The value to load into the **EvtSerCx2CustomReceiveTransactionEnableNewDataNotification** member of the **SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG** structure. For more information, see the description of this member in [SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_receive_transaction_config).

### `EvtSerCx2CustomReceiveTransactionQueryProgress` [in]

The value to load into the **EvtSerCx2CustomReceiveTransactionQueryProgress** member of the **SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG** structure. For more information, see the description of this member in [SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_receive_transaction_config).

## Remarks

Your serial controller driver must use this function to initialize a [SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_receive_transaction_config) structure before passing a pointer to this structure as an input parameter to the [SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate) method.

**SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG_INIT** sets the **Size** member of the structure to **sizeof**(**SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG**), and sets three additional members of the structure to the values supplied as input parameters to the function. The function sets the other members of the structure to zero. The driver can, if necessary, explicitly set these other members to nonzero values after the **SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG_INIT** call.

## See also

[SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_receive_transaction_config)

[SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate)