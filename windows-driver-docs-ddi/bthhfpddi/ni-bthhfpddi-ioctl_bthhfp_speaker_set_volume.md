# IOCTL_BTHHFP_SPEAKER_SET_VOLUME IOCTL

## Description

The **IOCTL_BTHHFP_SPEAKER_SET_VOLUME** IOCTL sets the volume level for the
speaker of the Bluetooth device.

## Parameters

### Major code

### Input buffer

A LONG that represents the volume level in 1/65536 decibels.

### Input buffer length

The size of a LONG.

### Output buffer

N/A

### Output buffer length

N/A

### Input/output buffer

### Input/output buffer length

### Status block

N/A

## Remarks

The audio driver sends this request when handling the [KSPROPERTY_AUDIO_VOLUMELEVEL](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-volumelevel) property for the [KSNODETYPE_VOLUME](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-volume) node in the KS topology of the speaker path. The request’s input parameter is the same as the **KSPROPERTY_AUDIO_VOLUMELEVEL** property value.

## See also

[Bluetooth HFP DDI IOCTLs](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-ioctls)

[KSNODETYPE_VOLUME](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-volume)

[KSPROPERTY_AUDIO_VOLUMELEVEL](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-volumelevel)