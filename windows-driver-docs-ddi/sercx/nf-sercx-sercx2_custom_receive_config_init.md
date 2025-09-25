# SERCX2_CUSTOM_RECEIVE_CONFIG_INIT function

## Description

The **SERCX2_CUSTOM_RECEIVE_CONFIG_INIT** function initializes a [SERCX2_CUSTOM_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_receive_config) structure.

## Parameters

### `Config` [out]

A pointer to the [SERCX2_CUSTOM_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_receive_config) structure that is to be initialized.

## Remarks

Your serial controller driver must use this function to initialize a [SERCX2_CUSTOM_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_receive_config) structure before passing a pointer to this structure as an input parameter to the [SerCx2CustomReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivecreate) method.

**SERCX2_CUSTOM_RECEIVE_CONFIG_INIT** sets the **Size** member of the structure to **sizeof**(**SERCX2_CUSTOM_RECEIVE_CONFIG**), and sets the other members of the structure to zero. The driver can, if necessary, explicitly set these other members to nonzero values after the **SERCX2_CUSTOM_RECEIVE_CONFIG_INIT** call.

## See also

[SERCX2_CUSTOM_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_receive_config)

[SerCx2CustomReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivecreate)