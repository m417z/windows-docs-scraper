# SPB_TRANSFER_DESCRIPTOR structure

## Description

The **SPB_TRANSFER_DESCRIPTOR** structure describes a single transfer in an [I/O transfer sequence](https://learn.microsoft.com/windows-hardware/drivers/spb/i-o-transfer-sequences).

## Members

### `Size`

The size, in bytes, of the entire structure. Used for versioning.

### `Direction`

The direction of the transfer. This member is set to one of the following [SPB_TRANSFER_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ne-spb-spb_transfer_direction) enumeration values:

* **SpbTransferDirectionFromDevice**
* **SpbTransferDirectionToDevice**

### `TransferLength`

The number of bytes of data to be transferred.

### `DelayInUs`

An optional delay, in microseconds, before this transfer begins. For more information, see the following Remarks section.

## Remarks

This structure is used by the [SpbRequestGetTransferParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbrequestgettransferparameters) method. Before passing an **SPB_TRANSFER_DESCRIPTOR** structure to this method, initialize the structure by calling the [SPB_TRANSFER_DESCRIPTOR_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spb_transfer_descriptor_init) function.

The **DelayInUs** member specifies a delay before the start of the transfer. In certain cases, a peripheral driver might need to insert a delay between two consecutive transfers in a sequence. For example, if a write to a target device specifies the type of information that is being requested, this device might need time to process the request before the information can be read. In addition, a peripheral driver might need to specify a delay before the first transfer in a sequence. In this case, the controller must apply the address or assert the device-select line to the target device for the specified delay interval before the start of the first transfer.

## See also

[SPB_TRANSFER_DESCRIPTOR_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spb_transfer_descriptor_init)

[SPB_TRANSFER_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ne-spb-spb_transfer_direction)

[SpbRequestGetTransferParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbrequestgettransferparameters)