# _UCMUCSI_PPM_GET_UCSI_DATA_BLOCK_OUT_PARAMS structure

## Description

Contains a USCI data block. This structure is the output buffer to the [IOCTL_UCMUCSI_PPM_GET_UCSI_DATA_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippmrequests/ni-ucmucsippmrequests-ioctl_ucmucsi_ppm_get_ucsi_data_block) I/O request.

## Members

### `UcmUcsiDataBlock`

A [**UCSI_DATA_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsispec/ns-ucmucsispec-_ucsi_data_block) structure that receives the data block with notification information.

## Remarks

## See also

[IOCTL_UCMUCSI_PPM_SEND_UCSI_DATA_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippmrequests/ni-ucmucsippmrequests-ioctl_ucmucsi_ppm_send_ucsi_data_block)