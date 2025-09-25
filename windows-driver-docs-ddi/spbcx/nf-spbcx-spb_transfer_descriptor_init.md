# SPB_TRANSFER_DESCRIPTOR_INIT function

## Description

The **SPB_TRANSFER_DESCRIPTOR_INIT** function initializes an [SPB_TRANSFER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-spb_transfer_descriptor) structure.

## Parameters

### `Descriptor` [out]

A pointer to the **SPB_TRANSFER_DESCRIPTOR** structure that is to be initialized.

## Remarks

Your SPB controller driver must use this function to initialize an **SPB_TRANSFER_DESCRIPTOR** structure before passing this structure as an output parameter to the [SpbRequestGetTransferParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbrequestgettransferparameters) method. This method writes the transfer parameters for an individual transfer in an I/O transfer sequence to this structure.

## See also

[SPB_TRANSFER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-spb_transfer_descriptor)

[SpbRequestGetTransferParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbrequestgettransferparameters)