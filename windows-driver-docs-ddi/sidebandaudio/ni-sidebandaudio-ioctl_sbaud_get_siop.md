# IOCTL_SBAUD_GET_SIOP IOCTL

## Description

The IOCTL_SBAUD_GET_SIOP IOCTL is used to get the SIOP. This control code is used by an audio driver when cooperating with the audio class drivers to operate a sideband connection.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

A [SIDEBANDAUDIO_SIOP_REQUEST_PARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-sidebandaudio_siop_request_param) union.

### Input buffer length

The length of the SIDEBANDAUDIO_SIOP_REQUEST_PARAM union.

### Output buffer

An output buffer to hold the returned SIOP.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful. Otherwise, Status to the appropriate error condition as a NTSTATUS code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

This IOCTL can only be called from kernel mode.

### Bluetooth A2DP

The A2DP driver saves the SIOP values in a collection of stream configuration vendor SIOPs and sends these SIOPs to the Bluetooth controller using HCI_VS_MSFT_Avdtp_Stream_Open while handling IOCTL_SBAUD_STREAM_OPEN. Any audio interface parameters returned by the Bluetooth controller are also stored in the collection of stream configuration vendor SIOPs. The audio driver can get these values at any time after the IOCTL completes.

The A2DP driver clears the collection of stream configuration vendor SIOPs when handling IOCTL_SBAUD_STREAM_CLOSE. (It does not clear the collection of system configuration vendor SIOPs.)

## Requirements

|   |   |
|------------|:----------------|
| **Header** | sidebandaudio.h |

## See also

[Introduction to I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-i-o-control-codes)

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)