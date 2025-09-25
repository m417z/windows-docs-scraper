# IOCTL_SBAUD_GET_MUTEPROPERTYVALUES IOCTL

## Description

Audio driver can call the **IOCTL_SBAUD_GET_MUTEPROPERTYVALUES** IOCTL to query the mute stepped data ranges and min/max values for all of the channels. These values should then be returned for [KSPROPERTY_AUDIO_MUTE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-mute) basic support.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

A 0 based endpoint index value based on the number of Audio endpoints as reported by the [IOCTL_SBAUD_GET_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_get_device_descriptor). This is a ULONG value from 0 to (N-1) where N is the number of Endpoints for the device.

### Input buffer length

Size of ULONG.

### Output buffer

KSPROPERTY_DESCRIPTION followed by KSPROPERTY_MEMBERSHEADER and Mute stepped data ranges as documented in [KSPROPERTY_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_description) and [KSPROPERTY_MEMBERSHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_membersheader).

If NULL, Irp->IoStatus.Information will be set to the number of bytes required for output buffer.

### Output buffer length

Size of KSPROPERTY_DESCRIPTION in addition to all the KSPROPERTY_MEMBERSHEADER and step ranges. This size is returned in SIDEBANDAUDIO_ENDPOINT_DESCRIPTOR.MutePropertyValuesSize.

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful, otherwise, Status to the appropriate error condition as a NTSTATUS code.

If output buffer is NULL, Irp->IoStatus.Status is set to STATUS_BUFFER_TOO_SMALL and Irp->IoStatus.Information is set to the number of bytes required for the output buffer.

If properly sized output buffer is provided, Irp->IoStatus.Information is set to the number of bytes written to the output buffer.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

This IOCTL can only be called from kernel mode.

Audio drivers that implement sideband audio should advertise endpoint Mute through a mute node in their KS Filter or through the Audio Engine Node. Both methods can utilize the basic support information provided by this IOCTL.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[KSPROPERTY_AUDIO_MUTE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-mute)

[KSNODEPROPERTY_AUDIO_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksnodeproperty_audio_channel)

[IMiniportAudioEngineNode::GetDeviceChannelCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportaudioenginenode-getdevicechannelcount)

[Introduction to I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-i-o-control-codes)

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)