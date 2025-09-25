# SPB_REQUEST_PARAMETERS_INIT function

## Description

The **SPB_REQUEST_PARAMETERS_INIT** function initializes an [SPB_REQUEST_PARAMETERS](https://learn.microsoft.com/previous-versions/hh406209(v=vs.85)) structure.

## Parameters

### `Parameters` [out]

A pointer to the **SPB_REQUEST_PARAMETERS** structure that is to be initialized.

## Remarks

Your SPB controller driver must use this function to initialize an **SPB_REQUEST_PARAMETERS** structure before passing this structure as an output parameter to the [SpbRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbrequestgetparameters) method. This method writes the SPB-specific parameters from an I/O request to this structure.

## See also

[SPB_REQUEST_PARAMETERS](https://learn.microsoft.com/previous-versions/hh406209(v=vs.85))

[SpbRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbrequestgetparameters)