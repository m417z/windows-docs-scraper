# SERCX2_PIO_RECEIVE_CONFIG_INIT function

## Description

The **SERCX2_PIO_RECEIVE_CONFIG_INIT** function initializes a [SERCX2_PIO_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_pio_receive_config) structure.

## Parameters

### `PioReceiveConfig` [out]

A pointer to the [SERCX2_PIO_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_pio_receive_config) structure that is to be initialized.

### `EvtSerCx2PioReceiveReadBuffer` [in]

The value to load into the **EvtSerCx2PioReceiveReadBuffer** member of the **SERCX2_PIO_RECEIVE_CONFIG** structure. For more information, see the description of this member in [SERCX2_PIO_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_pio_receive_config).

### `EvtSerCx2PioReceiveEnableReadyNotification` [in]

The value to load into the **EvtSerCx2PioReceiveEnableReadyNotification** member of the **SERCX2_PIO_RECEIVE_CONFIG** structure. For more information, see the description of this member in [SERCX2_PIO_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_pio_receive_config).

### `EvtSerCx2PioReceiveCancelReadyNotification` [in]

The value to load into the **EvtSerCx2PioReceiveCancelReadyNotification** member of the **SERCX2_PIO_RECEIVE_CONFIG** structure. For more information, see the description of this member in [SERCX2_PIO_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_pio_receive_config).

## Remarks

Your serial controller driver must use this function to initialize a [SERCX2_PIO_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_pio_receive_config) structure before passing a pointer to this structure as an input parameter to the [SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate) method.

**SERCX2_PIO_RECEIVE_CONFIG_INIT** sets the **Size** member of the structure to **sizeof**(**SERCX2_PIO_RECEIVE_CONFIG**), and sets three additional members of the structure to the values supplied as input parameters to the function. The function sets the other members of the structure to zero. The driver can, if necessary, explicitly set these other members to nonzero values after the **SERCX2_PIO_RECEIVE_CONFIG_INIT** call.

## See also

[SERCX2_PIO_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_pio_receive_config)

[SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate)