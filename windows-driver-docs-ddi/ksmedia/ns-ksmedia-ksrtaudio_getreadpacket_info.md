# KSRTAUDIO_GETREADPACKET_INFO structure

## Description

The KSRTAUDIO_GETREADPACKET_INFO structure describes information for an audio packet.

## Members

### `PacketNumber`

Returns the packet number relative to the start of capture.

### `Flags`

Reserved for future use. Must be set to 0.

### `PerformanceCounterValue`

Returns the performance counter value corresponding to the sampling instance of the first sample in the packet.

### `MoreData`

Returns TRUE if there is more data ready immediately. The OS may optionally immediately call this routine again after processing the packet to get the next packet information. If the driver returns FALSE, then capture is operating at real time.

## See also

[KSPROPERTY_RTAUDIO_GETREADPACKET](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-getreadpacket)