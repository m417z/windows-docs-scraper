# SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG_INIT function

## Description

The **SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG_INIT** function initializes a [SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_transmit_transaction_config) structure.

## Parameters

### `Config` [out]

A pointer to the [SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_transmit_transaction_config) structure that is to be initialized.

### `EvtSerCx2CustomTransmitTransactionStart` [in]

The value to load into the **EvtSerCx2CustomTransmitTransactionStart** member of the **SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG** structure. For more information, see the description of this member in [SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_transmit_transaction_config).

## Remarks

Your serial controller driver must use this function to initialize a [SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_transmit_transaction_config) structure before passing a pointer to this structure as an input parameter to the [SerCx2CustomTransmitTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmittransactioncreate) method.

**SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG_INIT** sets the **Size** member of the structure to **sizeof**(**SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG**), and sets the **EvtSerCx2CustomTransmitTransactionStart** member to the value supplied as an input parameter to the function. The function sets the other members of the structure to zero. The driver can, if necessary, explicitly set these other members to nonzero values after the **SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG_INIT** call.

## See also

[SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_transmit_transaction_config)

[SerCx2CustomTransmitTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmittransactioncreate)