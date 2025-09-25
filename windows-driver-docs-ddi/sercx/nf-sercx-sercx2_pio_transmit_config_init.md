# SERCX2_PIO_TRANSMIT_CONFIG_INIT function

## Description

The **SERCX2_PIO_TRANSMIT_CONFIG_INIT** function initializes a [SERCX2_PIO_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_pio_transmit_config) structure.

## Parameters

### `PioTransmitConfig` [out]

A pointer to the [SERCX2_PIO_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_pio_transmit_config) structure that is to be initialized.

### `EvtSerCx2PioTransmitWriteBuffer` [in]

The value to load into the **EvtSerCx2PioTransmitWriteBuffer** member of the **SERCX2_PIO_TRANSMIT_CONFIG** structure. For more information, see the description of this member in [SERCX2_PIO_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_pio_transmit_config).

### `EvtSerCx2PioTransmitEnableReadyNotification` [in]

The value to load into the **EvtSerCx2PioTransmitEnableReadyNotification** member of the **SERCX2_PIO_TRANSMIT_CONFIG** structure. For more information, see the description of this member in [SERCX2_PIO_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_pio_transmit_config).

### `EvtSerCx2PioTransmitCancelReadyNotification` [in]

The value to load into the **EvtSerCx2PioTransmitCancelReadyNotification** member of the **SERCX2_PIO_TRANSMIT_CONFIG** structure. For more information, see the description of this member in [SERCX2_PIO_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_pio_transmit_config).

## Remarks

Your serial controller driver must use this function to initialize a [SERCX2_PIO_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_pio_transmit_config) structure before passing a pointer to this structure as an input parameter to the [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) method.

**SERCX2_PIO_TRANSMIT_CONFIG_INIT** sets the **Size** member of the structure to **sizeof**(**SERCX2_PIO_TRANSMIT_CONFIG**), and sets three additional members of the structure to the values supplied as input parameters to the function. The function sets the other members of the structure to zero. The driver can, if necessary, explicitly set these other members to nonzero values after the **SERCX2_PIO_TRANSMIT_CONFIG_INIT** call.

## See also

[SERCX2_PIO_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_pio_transmit_config)

[SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate)