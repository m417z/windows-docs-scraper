# SERCX2_CONFIG_INIT function

## Description

The **SERCX2_CONFIG_INIT** function initializes a [SERCX2_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_config) structure.

## Parameters

### `Config` [out]

A pointer to the [SERCX2_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_config) structure that is to be initialized.

### `EvtSerCx2ApplyConfig` [in]

The value to load into the **EvtSerCx2ApplyConfig** member of the **SERCX2_CONFIG** structure. For more information, see the description of this member in [SERCX2_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_config).

### `EvtSerCx2Control` [in]

The value to load into the **EvtSerCx2Control** member of the **SERCX2_CONFIG** structure. For more information, see the description of this member in [SERCX2_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_config).

### `EvtSerCx2PurgeFifos` [in]

The value to load into the **EvtSerCx2PurgeFifos** member of the **SERCX2_CONFIG** structure. For more information, see the description of this member in [SERCX2_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_config).

## Remarks

Your serial controller driver must use this function to initialize a [SERCX2_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_config) structure before passing a pointer to this structure as an input parameter to the [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice) method.

**SERCX2_CONFIG_INIT** sets the **Size** member of the structure to **sizeof**(**SERCX2_CONFIG**), and sets three additional members of the structure to the values supplied as input parameters to the function. The function sets the other members of the structure to zero. The driver can, if necessary, explicitly set these other members to nonzero values after the **SERCX2_CONFIG_INIT** call.

## See also

[SERCX2_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_config)

[SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice)