# IOCTL_SBAUD_GET_MUTE_STATUS_UPDATE IOCTL

## Description

The **IOCTL_SBAUD_GET_MUTE_STATUS_UPDATE** IOCTL gets the mute level setting of the sideband audio endpoint.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

[SIDEBANDAUDIO_MUTE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_mute_params) with the 0 based endpoint index and channel number along with 'immediate' parameter indicating whether to process this IOCTL immediately or pend it for future updates.

### Input buffer length

Size of [SIDEBANDAUDIO_MUTE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_mute_params).

### Output buffer

[SIDEBANDAUDIO_MUTE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_mute_params)

### Output buffer length

Size of [SIDEBANDAUDIO_MUTE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_mute_params).

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful. Otherwise, Status to the appropriate error condition as a NTSTATUS code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

This IOCTL can only be called from kernel mode.

The mute update IOCTL can be used in two modes - update and immediate. If _**Immediate**_ parameter is set to TRUE, the IOCTL returns immediately with the current mute value for the requested channel. If the Immediate parameter is set to FALSE, the IRP is pended by the sideband audio Driver until there is a change in the device mute state. Audio driver should setup a pending mute IOCTL to get notified of any changes in hardware mute state.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[SIDEBANDAUDIO_MUTE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_mute_params)

[Introduction to I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-i-o-control-codes)

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)