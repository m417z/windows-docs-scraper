# IOCTL_SBAUD_STREAM_START IOCTL

## Description

On transition up to KSSTATE_RUN, send **IOCTL_SBAUD_STREAM_START**. This control code is used by an audio driver when cooperating with the audio class drivers to operate a sideband connection.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

A 0 based endpoint index value based on the number of Audio endpoints as reported by the [IOCTL_SBAUD_GET_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_get_device_descriptor).

This is a ULONG value from 0 to (N-1) where N is the number of Endpoints for the device.

### Input buffer length

Size of ULONG.

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful. Otherwise, Status to the appropriate error condition as a NTSTATUS code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

This IOCTL can only be called from kernel mode.

This is one of the IOCTLs used for KS pin state transitions. The audio driver sends these requests on certain KS pin state transitions.

- On first transition above KSSTATE_STOP (normally to KSSTATE_ACQUIRE), send [IOCTL_SBAUD_STREAM_OPEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_stream_open).
- On transition up to KSSTATE_RUN, send [IOCTL_SBAUD_STREAM_START](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_stream_start).
- On transition below KSSTATE_RUN, send [IOCTL_SBAUD_STREAM_SUSPEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_stream_suspend).
- On closure of KS pin, send [IOCTL_SBAUD_STREAM_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_stream_close).

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[Introduction to I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-i-o-control-codes)

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)