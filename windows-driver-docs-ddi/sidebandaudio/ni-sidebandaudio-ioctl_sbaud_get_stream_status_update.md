# IOCTL_SBAUD_GET_STREAM_STATUS_UPDATE IOCTL

## Description

The **IOCTL_SBAUD_GET_STREAM_STATUS_UPDATE** IOCTL is used for stream status updates. This control code is used by an audio driver when cooperating with the audio class drivers to operate a sideband connection.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

A [SIDEBANDAUDIO_STREAM_STATUS_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_stream_status_params) structure.

### Input buffer length

The size of the SIDEBANDAUDIO_STREAM_STATUS_PARAMS structure.

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful. Otherwise, Status to the appropriate error condition as a NTSTATUS code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

This IOCTL can only be called from kernel mode.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[Introduction to I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-i-o-control-codes)

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)