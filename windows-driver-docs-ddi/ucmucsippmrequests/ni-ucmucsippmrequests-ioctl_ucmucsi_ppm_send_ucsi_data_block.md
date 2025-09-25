# IOCTL_UCMUCSI_PPM_SEND_UCSI_DATA_BLOCK IOCTL

### Major Code: [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

Sends a UCSI data block to the PPM firmware by using the supported transport.

## Parameters

### Major code

### Input buffer

A pointer to a [**UCMUCSI_PPM_SEND_UCSI_DATA_BLOCK_IN_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippmrequests/ns-ucmucsippmrequests-_ucmucsi_ppm_send_ucsi_data_block_in_params) structure that contains the UCSI data block.

### Input buffer length

Size of the **UCMUCSI_PPM_SEND_UCSI_DATA_BLOCK_IN_PARAMS** structure.

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.
Otherwise, set to the appropriate error condition as a NTSTATUS code.
For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Whenever the UcmUcsiCx class extension asynchronously needs to send a UCSI block to the PPM firmware, the class extension sends this IOCTL request to the client driver asynchronously.

## See also

[**UCMUCSI_PPM_SEND_UCSI_DATA_BLOCK_IN_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippmrequests/ns-ucmucsippmrequests-_ucmucsi_ppm_send_ucsi_data_block_in_params)