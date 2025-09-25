# IOCTL_BTHHFP_SPEAKER_GET_VOLUME_STATUS_UPDATE IOCTL

## Description

The **IOCTL_BTHHFP_SPEAKER_GET_VOLUME_STATUS_UPDATE**
IOCTL Gets the volume level setting of the Bluetooth device's speaker.

## Parameters

### Major code

### Input buffer

A BOOL that is set to TRUE to request an immediate update. Otherwise, set this to FALSE.

### Input buffer length

The size of a BOOL.

### Output buffer

A LONG that represents the speaker's volume level in 1/65536 decibels.

### Output buffer length

The size of a LONG.

### Input/output buffer

### Input/output buffer length

### Status block

If a request is already pending the new request fails and a STATUS_INVALID_DEVICE_REQUEST message is returned.

## Remarks

This request will complete immediately if the input parameter is TRUE, or if the volume status has changed since the last request. Otherwise this request will remain pending until the volume status changes or the request is cancelled.

The audio driver sends this request to get the initial speaker and microphone volume levels, and sends subsequent requests "asking" to be updated when the levels change. The driver stores the volume levels in appropriate context data. When the volume level changes, the audio driver generates the [KSEVENT_CONTROL_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksevent-control-change) event for the [KSNODETYPE_VOLUME](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-volume) node in the KS topology of the speaker or microphone path.

The request’s output parameter is the same as the [KSPROPERTY_AUDIO_VOLUMELEVEL](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-volumelevel) property value.

## See also

[Bluetooth HFP DDI IOCTLs](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-ioctls)

[KSEVENT_CONTROL_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksevent-control-change)

[KSNODETYPE_VOLUME](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-volume)

[KSPROPERTY_AUDIO_VOLUMELEVEL](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-volumelevel)