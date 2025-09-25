# KSPROPERTY_RTAUDIO enumeration

## Description

**KSPROPERTY_RTAUDIO** enumerates the properties of a WaveRT audio device.

## Constants

### `KSPROPERTY_RTAUDIO_GETPOSITIONFUNCTION`

This field enumerates the **KSPROPERTY_RTAUDIO_GETPOSITIONFUNCTION** property.

### `KSPROPERTY_RTAUDIO_BUFFER`

[KSPROPERTY_RTAUDIO_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-buffer) specifies a driver-allocated cyclic buffer for audio data.

### `KSPROPERTY_RTAUDIO_HWLATENCY`

[KSPROPERTY_RTAUDIO_HWLATENCY](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-hwlatency) retrieves a description of the stream latency of the audio hardware and its associated data path.

### `KSPROPERTY_RTAUDIO_POSITIONREGISTER`

[KSPROPERTY_RTAUDIO_POSITIONREGISTER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-positionregister) maps the position register of an audio device for a particular stream into a virtual memory location that the client can access.

### `KSPROPERTY_RTAUDIO_CLOCKREGISTER`

[KSPROPERTY_RTAUDIO_CLOCKREGISTER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-clockregister) maps the wall clock register of the audio device into a virtual memory location that the client can access.

### `KSPROPERTY_RTAUDIO_BUFFER_WITH_NOTIFICATION`

[KSPROPERTY_RTAUDIO_BUFFER_WITH_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-buffer-with-notification) specifies a driver-allocated cyclic buffer for audio data and identifies event notification requirements.

### `KSPROPERTY_RTAUDIO_REGISTER_NOTIFICATION_EVENT`

[KSPROPERTY_RTAUDIO_REGISTER_NOTIFICATION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-register-notification-event) registers a user-mode event for DMA-driven event notification.

### `KSPROPERTY_RTAUDIO_UNREGISTER_NOTIFICATION_EVENT`

[KSPROPERTY_RTAUDIO_UNREGISTER_NOTIFICATION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-unregister-notification-event) unregisters a user-mode event from DMA-driven event notification.

### `KSPROPERTY_RTAUDIO_QUERY_NOTIFICATION_SUPPORT`

[KSPROPERTY_RTAUDIO_QUERY_NOTIFICATION_SUPPORT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-query-notification-support) determines whether the audio driver can notify the client application when a process that is performed on the submitted buffer is completed.

### `KSPROPERTY_RTAUDIO_PACKETCOUNT`

[KSPROPERTY_RTAUDIO_PACKETCOUNT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-packetcount) returns the (1-based) count of packets completely transferred from the WaveRT buffer into hardware.

### `KSPROPERTY_RTAUDIO_PRESENTATION_POSITION`

[KSPROPERTY_RTAUDIO_PRESENTATION_POSITION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-presentation-position) returns stream presentation information.

### `KSPROPERTY_RTAUDIO_GETREADPACKET`

[KSPROPERTY_RTAUDIO_GETREADPACKET](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-getreadpacket) returns information about captured audio packets.

### `KSPROPERTY_RTAUDIO_SETWRITEPACKET`

[KSPROPERTY_RTAUDIO_SETWRITEPACKET](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-setwritepacket) informs the driver that the OS has written valid data to the WaveRT buffer.

### `KSPROPERTY_RTAUDIO_PACKETVREGISTER`

The **KSPROPERTY_RTAUDIO_PACKETVREGISTER** returns information about the packet virtual register.

## Remarks

## See also

[KSPROPSETID_RTAudio](https://learn.microsoft.com/windows-hardware/drivers/audio/kspropsetid-rtaudio)