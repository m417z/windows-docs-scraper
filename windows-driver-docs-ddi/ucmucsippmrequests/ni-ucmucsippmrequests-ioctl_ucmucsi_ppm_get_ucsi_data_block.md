# IOCTL_UCMUCSI_PPM_GET_UCSI_DATA_BLOCK IOCTL

### Major Code: [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

Gets a UCSI data block from the PPM firmware by using the supported transport.

## Parameters

### Major code

### Input buffer

A pointer a [**UCMUCSI_PPM_GET_UCSI_DATA_BLOCK_IN_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippmrequests/ns-ucmucsippmrequests-_ucmucsi_ppm_get_ucsi_data_block_in_params) structure that contains the PPM object that managers the PPM hardware.

### Input buffer length

Size of the **UCMUCSI_PPM_GET_UCSI_DATA_BLOCK_IN_PARAMS** structure.

### Output buffer

A pointer a [**UCMUCSI_PPM_GET_UCSI_DATA_BLOCK_OUT_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippmrequests/ns-ucmucsippmrequests-_ucmucsi_ppm_get_ucsi_data_block_out_params) structure that contains the PPM object that managers the PPM hardware.

### Output buffer length

Size of the **UCMUCSI_PPM_GET_UCSI_DATA_BLOCK_OUT_PARAMS** structure.

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.
Otherwise, set to the appropriate error condition as a NTSTATUS code.
For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Certain UCSI commands do not generate notifications from the PPM firmware, such as the PPM_RESET command. When this command is received, the firmware disables all notification. The UcmUcsiCx class extension sends such commands to the client driver through this IOCTL request. The client driver is expected to poll on reset complete indicator and return the current result from the firmware to UcmUcsiCx.

## See also