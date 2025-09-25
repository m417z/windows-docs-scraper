# SPB_CONNECTION_PARAMETERS_INIT function

## Description

The **SPB_CONNECTION_PARAMETERS_INIT** function initializes an [SPB_CONNECTION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-_spb_connection_parameters) structure.

## Parameters

### `Parameters` [out]

A pointer to the **SPB_CONNECTION_PARAMETERS** structure that is to be initialized.

## Remarks

Your SPB controller driver must use this function to initialize an **SPB_CONNECTION_PARAMETERS** structure before passing this structure as an output parameter to the [SpbTargetGetConnectionParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbtargetgetconnectionparameters) method. This method writes the connection parameters for a target device on the bus to this structure.

## See also

[SPB_CONNECTION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-_spb_connection_parameters)

[SpbTargetGetConnectionParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbtargetgetconnectionparameters)