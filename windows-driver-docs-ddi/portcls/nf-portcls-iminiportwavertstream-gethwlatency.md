# IMiniportWaveRTStream::GetHWLatency

## Description

The GetHWLatency method retrieves information about sources of stream latency in the audio hardware.

## Parameters

### `hwLatency`

A pointer to a KSRTAUDIO_HWLATENCY structure into which the driver writes the hardware latency parameters.

## Remarks

The port driver calls this method in response to a KSPROPERTY_RTAUDIO_HWLATENCY property request from a client.
For more information about the sources of hardware latency in an audio stream, see [Stream Latency during Playback](https://learn.microsoft.com/windows-hardware/drivers/audio/stream-latency-during-playback) and [Stream Latency during Recording](https://learn.microsoft.com/windows-hardware/drivers/audio/stream-latency-during-recording).

## See also

[IMiniPortWaveRTStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavertstream)