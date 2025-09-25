# IOCTL_SBAUD_GET_VOLUMEPROPERTYVALUES IOCTL

## Description

Audio driver can call IOCTL_SBAUD_GET_VOLUMEPROPERTYVALUES to query the volume stepped data ranges and min/max values for all of the channels. These values should then be returned for KSPROPERTY_AUDIO_VOLUMELEVEL basic support.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

Endpoint index.

### Input buffer length

Size of ULONG.

### Output buffer

KSPROPERTY_DESCRIPTION followed by KSPROPERTY_MEMBERSHEADER and Volume stepped data ranges as documented in [KSPROPERTY_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_description) and [KSPROPERTY_MEMBERSHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_membersheader).

### Output buffer length

Size of KSPROPERTY_DESCRIPTION in addition to all the KSPROPERTY_MEMBERSHEADER and step ranges. This size was returned in SIDEBANDAUDIO_ENDPOINT_DESCRIPTOR::VolumePropertyValuesSize.

### Input/output buffer

Input Endpoint Index and output KSPROPERTY_DESCRIPTION share the same buffer.

### Input/output buffer length

Allocated buffer should be of length SIDEBANDAUDIO_ENDPOINT_DESCRIPTOR::VolumePropertyValuesSize.

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful. Otherwise, Status to the appropriate error condition as a NTSTATUS code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

This IOCTL can only be called from kernel mode.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[KSPROPERTY_AUDIO_VOLUMELEVEL](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-volumelevel)

[KSNODEPROPERTY_AUDIO_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksnodeproperty_audio_channel)

[Introduction to I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-i-o-control-codes)

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)