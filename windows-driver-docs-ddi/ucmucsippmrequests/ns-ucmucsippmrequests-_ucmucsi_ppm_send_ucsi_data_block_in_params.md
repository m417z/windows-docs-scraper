# _UCMUCSI_PPM_SEND_UCSI_DATA_BLOCK_IN_PARAMS structure

## Description

Contains a USCI data block. This structure is the input buffer to the [IOCTL_UCMUCSI_PPM_SEND_UCSI_DATA_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippmrequests/ni-ucmucsippmrequests-ioctl_ucmucsi_ppm_send_ucsi_data_block) I/O request.

## Members

### `PpmObject`

A handle to a Platform Policy Manager (PPM) object that the client driver received in the previous call to [**UcmUcsiPpmCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsippmcreate).

### `UcmUcsiDataBlock`

A [**UCSI_DATA_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsispec/ns-ucmucsispec-_ucsi_data_block) structure that contains the data block to send.

## Remarks

## See also

[IOCTL_UCMUCSI_PPM_SEND_UCSI_DATA_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippmrequests/ni-ucmucsippmrequests-ioctl_ucmucsi_ppm_send_ucsi_data_block)