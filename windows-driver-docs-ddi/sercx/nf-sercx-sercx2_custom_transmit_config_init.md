# SERCX2_CUSTOM_TRANSMIT_CONFIG_INIT function

## Description

The **SERCX2_CUSTOM_TRANSMIT_CONFIG_INIT** function initializes a [SERCX2_CUSTOM_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_transmit_config) structure.

## Parameters

### `Config` [out]

A pointer to the [SERCX2_CUSTOM_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_transmit_config) structure that is to be initialized.

## Remarks

Your serial controller driver must use this function to initialize a [SERCX2_CUSTOM_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_transmit_config) structure before passing a pointer to this structure as an input parameter to the [SerCx2CustomTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmitcreate) method.

**SERCX2_CUSTOM_TRANSMIT_CONFIG_INIT** sets the **Size** member of the structure to **sizeof**(**SERCX2_CUSTOM_TRANSMIT_CONFIG**), and sets the other members of the structure to zero. The driver can, if necessary, explicitly set these other members to nonzero values after the **SERCX2_CUSTOM_TRANSMIT_CONFIG_INIT** call.

## See also

[SERCX2_CUSTOM_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_transmit_config)

[SerCx2CustomTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmitcreate)