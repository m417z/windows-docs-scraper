# SPB_CONTROLLER_CONFIG_INIT function

## Description

The **SPB_CONTROLLER_CONFIG_INIT** function initializes an [SPB_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-_spb_controller_config) structure.

## Parameters

### `Config` [out]

A pointer to the **SPB_CONTROLLER_CONFIG** structure that is to be initialized.

## Remarks

Your SPB controller driver must use this function to initialize an **SPB_CONTROLLER_CONFIG** structure before passing this structure as an input parameter to the [SpbDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbdeviceinitialize) method. This method completes the initialization of the SPB framework extension (SpbCx).

## See also

[SPB_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-_spb_controller_config)

[SpbDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbdeviceinitialize)